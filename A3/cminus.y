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
static char * savedName;
static int savedLineNo;
static TreeNode * savedTree; /* stores syntax tree for later return */
static int savedNumber;
static char * savedName;
static char * type;

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
%token LET GET EQ NQ ASSIGN LT GT PLUS MINUS TIMES OVER LPAREN RPAREN  LBRKT RBRKT LBRC RBRC SEMI COMMA
%token ERROR

%nonassoc LT LET GT GET EQ NQ
%left PLUS MINUS
%left TIMES OVER

%% /* Grammar for C Minus */

program     : dec_list
                 { savedTree = $1;}
            ;
dec_list    : dec_list dec
                 { YYSTYPE tree = $1;
                   if(tree != NULL){
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
saveName   : ID
                  { $$ = newExpNode(IdK);
                    savedName = copyString(tokenString);
                    $$->attr.name = savedName;
                  }
            ;
saveNumber  : NUM
                  {savedNumber = atoi(tokenString);
                    savedLineNo = lineno;
                  }
            ;
var_dec     : type_spec saveName SEMI
                  {   $$ = newDecNode(VarK);
                      $$->child[0] = $1;
                      $$->lineno = lineno;
                      $$->attr.name = savedName;
                  }
            | type_spec saveName LBRKT saveNumber RBRKT SEMI
                  {   $$ = newDecNode(ArrK);
                      $$->child[0] = $1;
                      $$->lineno = lineno;
                      $$->attr.arr.name = savedName;
                      $$->attr.arr.size = savedNumber;
                  }
            ;
fun_dec     : type_spec saveName
                  { $$ = newDecNode(FuncK);
                    $$->lineno = lineno;
                    $$->child[0]=$1;
                    $$->attr.name = savedName;
                  }
              LPAREN params RPAREN comp_stmt
                  { $$ = $3;
                   $$->child[1] = $5;
                   $$->child[2] = $7;
                  }
            ;
type_spec   : INT
                {   $$ = newTypeNode(TypeNameK);
                    $$->attr.type = INT;
                    savedLineNo = lineno;
                }
            | VOID
                {   $$ = newTypeNode(TypeNameK);
                    $$->attr.type = VOID;
                    savedLineNo = lineno;
                }
            ;
params      : param_list  { $$ = $1; }
            | VOID
            ;
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
                 { if(type == "void"){
                     yyerror("declare variable as void");
                   }else{
                     $$ = newParamNode(NonArrParamK);
                     $$->child[0] = $1;
                     $$->attr.name = savedName;
                   }
                 }
            | type_spec saveName LBRKT RBRKT
                 { if(type == "void"){
                     yyerror("declare parameter as void");
                   }else{
                     $$ = newParamNode(ArrParamK);
                     $$->child[0] = $1;
                     $$->attr.name = savedName;
                   }
                 }
            ;
comp_stmt   : LBRC local_decs stmt_list RBRC
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
exp         : exp ASSIGN exp
                 { $$ = newExpNode(OpK);
                   $$->child[0] = $1;
                   $$->child[1] = $3;
                   $$->attr.op = ASSIGN;
                 }
            |exp LET exp
                 { $$ = newExpNode(OpK);
                   $$->child[0] = $1;
                   $$->child[1] = $3;
                   $$->attr.op = LET;
                 }
            | exp LT exp
                 { $$ = newExpNode(OpK);
                   $$->child[0] = $1;
                   $$->child[1] = $3;
                   $$->attr.op = LT;
                 }
            | exp GT exp
                 { $$ = newExpNode(OpK);
                   $$->child[0] = $1;
                   $$->child[1] = $3;
                   $$->attr.op = GT;
                 }
            | exp GET exp
                 { $$ = newExpNode(OpK);
                   $$->child[0] = $1;
                   $$->child[1] = $3;
                   $$->attr.op = GET;
                 }
            | exp EQ exp
                 { $$ = newExpNode(OpK);
                   $$->child[0] = $1;
                   $$->child[1] = $3;
                   $$->attr.op = EQ;
                 }
            | exp NQ exp
                 { $$ = newExpNode(OpK);
                   $$->child[0] = $1;
                   $$->child[1] = $3;
                   $$->attr.op = NQ;
                 }
            | exp PLUS exp
                 { $$ = newExpNode(OpK);
                   $$->child[0] = $1;
                   $$->child[1] = $3;
                   $$->attr.op = PLUS;
                 }
            | exp MINUS exp
                 { $$ = newExpNode(OpK);
                   $$->child[0] = $1;
                   $$->child[1] = $3;
                   $$->attr.op = MINUS;
                 }
            | exp TIMES exp
                 { $$ = newExpNode(OpK);
                   $$->child[0] = $1;
                   $$->child[1] = $3;
                   $$->attr.op = TIMES;
                 }
            | exp OVER exp
                 { $$ = newExpNode(OpK);
                   $$->child[0] = $1;
                   $$->child[1] = $3;
                   $$->attr.op = OVER;
                 }
            | LPAREN exp RPAREN { $$ = $2; }
            | call {$$ = $1;}
            | var {$$ = $1; }
            | saveNumber
                 { $$ = newExpNode(ConstK);
                   $$->attr.val = atoi(tokenString);
                 }
            ;
var         : saveName
                 { //printf("in saveName\n");
                   $$->attr.name = savedName;
                 }
            | saveName
                 { $$ = newExpNode(ArrIdK);
                 //printf("after new ArrIdK\n");
                   $$->attr.name = savedName;
                 }
              LBRKT exp RBRKT
                 { $$->child[0] = $4;
                 //printf("back here\n");
                 }
            ;
call        : saveName
                  {
                  $$ = newExpNode(CallK);
                    $$->attr.name = savedName;
                  }
              LPAREN args RPAREN
                 {$$=$2;
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
