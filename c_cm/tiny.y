/****************************************************/
/* File: tiny.y                                     */
/* The C Minus Yacc/Bison specification file        */
/* Jeremie Fraeys and Joel Klemens                  */
/****************************************************/
%{
#define YYPARSER /* distinguishes Yacc output from other code files */

#include "globals.h"
#include "util.h"
#include "scan.h"
#include "parse.h"

#define YYSTYPE TreeNode *
static char * savedName; /* for use in assignments */
static int savedLineNo;  /* ditto */
static TreeNode * savedTree; /* stores syntax tree for later return */
static int savedNumber;
static char * savedName; 

extern int yychar;

extern int yyparse ();

int yyerror(char * message)
{ fprintf(listing,"Syntax error at line %d: %s\n",lineno,message);
  fprintf(listing,"Current token: ");
  printToken(yychar,tokenString);
  return 0;
}

/* yylex calls getToken to make Yacc/Bison output
 * compatible with the TINY scanner
 */
static int yylex(void)
{ return getToken(); }

TreeNode * parse(void) {
  yyparse();
  return savedTree;
}

%}

%token IF ELSE INT RETURN VOID WHILE
%token ID NUM
%token LET GET EQ NEQ OEQ LT GT PLUS MINUS TIMES OVER LPAREN RPAREN  LBRKT RBRKT LBRC RBRC SEMI COMMA
%token ERROR

%% /* Grammar for C Minus */

program     : dec_list
                 { savedTree = $1;}
            ;
dec_list    : dec_list decl
                 { YYSTYPE tree = $1;
                   if(tree) != NULL){
                     while(tree->sibling != NULL){
                       tree = tree->sibling;
                     }
                     tree->sibling = $2;
                     $$ = $1;
                   }else{
                      $$ = $2;
                   }
                 }
            | dec { $$ = $1; }
            ;
dec         : var_dec { $$ = $1; }
            | fun_dec { $$ = $1; }
            ;
saveNumber  : NUM 
                  { savedNumber = atoi(tokenString);
                    savedLineno = lineno;
                  }
            ;
saveName   : ID
                  { savedName = copyString(tokenString)
                    savedLineNo = lineno;
                  }
            ;
type_spec   : INT
                  { $$ = newTypeNode(TypeNameK);
                    $$->attr.type = INT;
                  }
            | VOID
                  { $$ = newTypeNode(TypeNameK);
                    $$->attr.type = VOID;
                  }
            ;
var_dec     : type_spec saveNumber SEMI
                  { $$ = newDecNode(VarK);
                    $$->child[0] = $1;
                    $$->lineno = lineno;
                    $$->attr.name = savedName;
                  }
            | type_spec saveName LBRKT saveNumber RBRKT SEMI
                  { $$ = newDecNode(VarK);
                    $$->child[0] = $1;
                    $$->lineno = lineno;
                    $$->attr.name = savedName;
                  }
            ;
fun_dec     : type_spec saveName 
                  { $$ = newDecNode(FuncK);
                    $$->lineno = lineno;
                    $$->attr.name = savedName;
                  }
              LPAREN params RPAREN comp_stmt
                 { $$ = $3;
                   $$->child[0] = $1;
                   $$->child[1] = $5;
                   $$->child[2] = $7;
                 }
            ;
params      : param_list  { $$ = $1; }
            | VOID
                 { $$ = newTypeNode(TypeNameK);
                   $$->attr.type = VOID;
                 }
param_list  : param_list COMMA param
                 { YYSTYPE tree = $1;
                   if (tree != NULL)
                   { while (tree->sibling != NULL)
                        tree = tree->sibling;
                     tree->sibling = $3;
                     $$ = $1; }
                    else $$ = $3; 
                 }
            | param { $$ = $1; };
param       : type_spec saveName
                 { $$ = newParamNode(NonArrParamK);
                   $$->child[0] = $1;
                   $$->attr.name = savedName;
                 }
            | type_spec saveName LBRKT RBRKT
                 { $$ = newParamNode(ArrParamK);
                   $$->child[0] = $1;
                   $$->attr.name = savedName;
                 }
            ;
comp_stmt   : LBRAC local_decs stmt_list RBRAC
                 { $$ = newStmtNode(CompK);
                   $$->child[0] = $2; 
                   $$->child[1] = $3; 
                 }
            ;
local_decs : local_decs var_dec
                 { YYSTYPE tree = $1;
                   if (tree != NULL)
                   { while (tree->sibling != NULL)
                        tree = tree->sibling;
                     tree->sibling = $2;
                     $$ = $1; }
                     else $$ = $2;
                 }
            |    { $$ = NULL; }
            ;
stmt_list   : stmt_list stmt
                  { YYSTYPE tree = $1;
                   if (tree != NULL)
                   { while (tree->sibling != NULL)
                        tree = tree->sibling;
                     tree->sibling = $2;
                     $$ = $1; 
                    }
                     else $$ = $2;
                  }
            | { $$ = NULL; }
            ;
stmt        : exp_stmt { $$ = $1; }
            | comp_stmt { $$ = $1; }
            | sel_stmt { $$ = $1; }
            | iter_stmt { $$ = $1; }
            | ret_stmt { $$ = $1; }
            ;
exp_stmt    : exp SEMI { $$ = $1; }
            | SEMI { $$ = NULL; }
            ;
sel_stmt    : IF LPAREN exp RPAREN stmt
                 { $$ = newStmtNode(IfK);
                   $$->child[0] = $3;
                   $$->child[1] = $5;
                   $$->child[2] = NULL;
                 }
            | IF LPAREN exp RPAREN stmt ELSE stmt
                 { $$ = newStmtNode(IfK);
                   $$->child[0] = $3;
                   $$->child[1] = $5;
                   $$->child[2] = $7;
                 }
            ;
iter_stmt   : WHILE LPAREN exp RPAREN stmt
                 { $$ = newStmtNode(WhileK);
                   $$->child[0] = $3;
                   $$->child[1] = $5;
                 }
            ;
ret_stmt    : RETURN SEMI
                 { $$ = newStmtNode(ReturnK);
                   $$->child[0] = NULL;
                 }
            | RETURN exp SEMI
                 { $$ = newStmtNode(ReturnK);
                   $$->child[0] = $2;
                 }
            ;
var         : saveName
                 { $$ = newExpNode(IdK);
                   $$->attr.name = savedName;
                 }
            | saveName
                 { $$ = newExpNode(ArrIdK);
                   $$->attr.name = savedName;
                 }
              LBRKT exp RBRKT
                 { $$->child[0] = $3;
                 }
            ;
exp         : var ASSIGN exp
                 { $$ = newExpNode(AssignK);
                   $$->child[0] = $1;
                   $$->child[1] = $3;
                 }
            |add_exp LTEQ add_exp
                 { $$ = newExpNode(OpK);
                   $$->child[0] = $1;
                   $$->child[1] = $3;
                   $$->attr.op = LTEQ;
                 }
            | add_exp LT add_exp
                 { $$ = newExpNode(OpK);
                   $$->child[0] = $1;
                   $$->child[1] = $3;
                   $$->attr.op = LT;
                 }
            | add_exp GT add_exp
                 { $$ = newExpNode(OpK);
                   $$->child[0] = $1;
                   $$->child[1] = $3;
                   $$->attr.op = GT;
                 }
            | add_exp GTEQ add_exp
                 { $$ = newExpNode(OpK);
                   $$->child[0] = $1;
                   $$->child[1] = $3;
                   $$->attr.op = GTEQ;
                 }
            | add_exp EQ add_exp
                 { $$ = newExpNode(OpK);
                   $$->child[0] = $1;
                   $$->child[1] = $3;
                   $$->attr.op = EQ;
                 }
            | add_exp NEQ add_exp
                 { $$ = newExpNode(OpK);
                   $$->child[0] = $1;
                   $$->child[1] = $3;
                   $$->attr.op = NEQ;
                 }
            |add_exp PLUS term
                 { $$ = newExpNode(OpK);
                   $$->child[0] = $1;
                   $$->child[1] = $3;
                   $$->attr.op = PLUS;
                 }
            | add_exp MINUS term
                 { $$ = newExpNode(OpK);
                   $$->child[0] = $1;
                   $$->child[1] = $3;
                   $$->attr.op = MINUS;
                 }
            | term TIMES factor
                 { $$ = newExpNode(OpK);
                   $$->child[0] = $1;
                   $$->child[1] = $3;
                   $$->attr.op = TIMES;
                 }
            | term OVER factor
                 { $$ = newExpNode(OpK);
                   $$->child[0] = $1;
                   $$->child[1] = $3;
                   $$->attr.op = OVER;
                 }
            | LPAREN exp RPAREN { $$ = $2; }
            | var { $$ = $1; }
            | call { $$ = $1; }
            | NUM
                 { $$ = newExpNode(ConstK);
                   $$->attr.val = atoi(tokenString);
                 }
            ;
call        : saveName 
              { $$ = newExpNode(CallK);
                $$->attr.name = savedName;
              }
              LPAREN args RPAREN
                 { $$ = $2;
                   $$->child[0] = $4;
                 }
            ;
args        : arg_list { $$ = $1; }
            | /* empty */ { $$ = NULL; }
            ;
arg_list    : arg_list COMMA exp
                 { YYSTYPE tree = $1;
                   if (tree != NULL)
                   { while (tree->sibling != NULL)
                        tree = tree->sibling;
                     tree-> sibling = $3;
                     $$ = $1; }
                     else $$ = $3;
                 }
            | exp { $$ = $1; }
            ;
%%











