/****************************************************/
/* File: util.c                                     */
/* Utility function implementation                  */
/* for the TINY compiler                            */
/****************************************************/

#include "globals.h"
#include "util.h"
#include "y.tab.h"

/* prints a token and its lexeme to the listing file
 */
void printToken( int token, const char* tokenString ){
    switch (token){
        case IF:
        case ELSE:
        case INT:
        case RETURN:
        case VOID:
        case WHILE:
            fprintf(listing, "%s\n", tokenString);break;
        case LET: fprintf(listing, "<=\n"); break;
        case GET: fprintf(listing, ">=\n"); break;
        case ASSIGN: fprintf(listing,"=\n"); break;
        case NQ: fprintf(listing, "!=\n"); break;
        case EQ: fprintf(listing, "==\n"); break;
        case LT: fprintf(listing,"<\n"); break;
        case GT: fprintf(listing,">\n"); break;
        case LPAREN: fprintf(listing,"(\n"); break;
        case RPAREN: fprintf(listing,")\n"); break;
        case LBRC: fprintf(listing,"{\n"); break;
        case RBRC: fprintf(listing,"}\n"); break;
        case LBRKT: fprintf(listing,"[\n"); break;
        case RBRKT: fprintf(listing,"]\n"); break;
        case SEMI: fprintf(listing,";\n"); break;
        case COMMA: fprintf(listing, ",\n"); break;
        case PLUS: fprintf(listing,"+\n"); break;
        case MINUS: fprintf(listing,"-\n"); break;
        case TIMES: fprintf(listing,"*\n"); break;
        case OVER: fprintf(listing,"/\n"); break;
        case 0: fprintf(listing,"EOF\n"); break;
        case NUM:
            fprintf(listing,
            "NUM, val = %s\n",tokenString);
            break;
        case ID:
            fprintf(listing,
            "ID, name = %s\n",tokenString);
            break;
        case ERROR:
            fprintf(listing,
            "%s\n",tokenString);
            break;
        default: /* should never happen */
            break;
    }
}

/* creates a new statement node for syntax tree construction
 */
TreeNode * newStmtNode(StmtKind kind){
    TreeNode * t = (TreeNode *) malloc(sizeof(TreeNode));
    int i;
    if (t==NULL)
        fprintf(listing,"Out of memory error at line %d\n",lineno);
    else {
        for (i=0;i<MAXCHILDREN;i++) t->child[i] = NULL;
        t->sibling = NULL;
        t->nodekind = StmtK;
        t->kind.stmt = kind;
        t->lineno = lineno;
    }
    return t;
}

/* newExpNode creates a new expression node for syntax tree construction
 */
TreeNode * newExpNode(ExpKind kind){
    TreeNode * t = (TreeNode *) malloc(sizeof(TreeNode));
    int i;
    if (t==NULL)
        fprintf(listing,"Out of memory error at line %d\n",lineno);
    else {
        for (i=0;i<MAXCHILDREN;i++) t->child[i] = NULL;
        t->sibling = NULL;
        t->nodekind = ExpK;
        t->kind.exp = kind;
        t->lineno = lineno;
        t->type = Void;
    }
    return t;
}

 /* newExpNode creates a new expression node for syntax tree construction
  */
 TreeNode * newDecNode(DecKind kind){
     TreeNode * t = (TreeNode *) malloc(sizeof(TreeNode));
     int i;
     if (t==NULL)
        fprintf(listing,"Out of memory error at line %d\n",lineno);
     else {
        for (i=0;i<MAXCHILDREN;i++) t->child[i] = NULL;
        t->sibling = NULL;
        t->nodekind = DecK;
        t->kind.exp = kind;
        t->lineno = lineno;
    }
    return t;
}

 TreeNode * newParamNode(ParamKind kind){
    TreeNode * t = (TreeNode *) malloc(sizeof(TreeNode));
    int i;
    if (t==NULL)
        fprintf(listing,"Out of memory error at line %d\n",lineno);
    else {
        for (i=0;i<MAXCHILDREN;i++) t->child[i] = NULL;
        t->sibling = NULL;
        t->nodekind = ParamK;
        t->kind.param = kind;
        t->lineno = lineno;
    }
    return t;
}

TreeNode * newErrNode(){
    TreeNode * t = (TreeNode *) malloc(sizeof(TreeNode));
    int i;
    if (t==NULL)
	   fprintf(listing,"Out of memory error at line %d\n",lineno);
    else {
    	for (i=0;i<MAXCHILDREN;i++) t->child[i] = NULL;
    	   t->sibling = NULL;
    	   t->nodekind = Error;
    	   t->lineno = lineno;
           t->col = col;
    }
    return t;
}

/* allocates and makes a new copy of an existing string
 */
char * copyString(char * s){
    int n;
    char * t;
    if (s==NULL) return NULL;
    n = strlen(s)+1;
    t = malloc(n);
    if (t==NULL)
        fprintf(listing,"Out of memory error at line %d\n",lineno);
    else strcpy(t,s);
    return t;
}

/* used by printTree to store current number of spaces to indent
 */
static int indentno = 0;

/* macros to increase/decrease indentation */
#define INDENT indentno+=2
#define UNINDENT indentno-=2

/* printSpaces indents by printing spaces */
static void printSpaces(void){
    int i;
    for (i=0;i<indentno;i++)
    fprintf(listing," ");
}

/* prints a syntax tree to the listing file using indentation to indicate subtrees
 */
void printTree( TreeNode * tree ){
    int i;
    INDENT;
    while (tree != NULL) {
        printSpaces();
        if (tree->nodekind==StmtK){
            switch (tree->kind.stmt) {
                case IfK:
                    fprintf(listing,"If\n");
                    break;
                case ReturnK:
                    fprintf(listing,"Return\n");
                    break;
                case WhileK:
                    fprintf(listing,"While\n");
                    break;
                case CompK:
                    fprintf(listing,"Compound statement\n");
                    break;
                default:
                    fprintf(listing,"Unknown StmtNode kind\n");
                    break;
            }
        }
        else if (tree->nodekind==ExpK) {
            switch (tree->kind.exp) {
                case OpK:
                    fprintf(listing,"Op: ");
                    printToken(tree->attr.op,"\0");
                    break;
                case ConstK:
                    fprintf(listing,"Const: %d\n",tree->attr.val);
                    break;
                case IdK:
                    //printf("printing IdK ");
                    fprintf(listing,"Id: %s\n",tree->attr.name);
                    break;
                case ArrIdK:
                    //printf("printing ArrIdK\n");
                    fprintf(listing, "ArrId: %s\n", tree->attr.name);
                    break;
                case CallK:
                    fprintf(listing, "Call: %s\n", tree->attr.name);
                    break;
                default:
                    fprintf(listing,"Unknown ExpNode kind\n");
                    break;
            }
        }
        else if (tree->nodekind==DecK){
            switch (tree->kind.dec) {
                case FuncK:
                  fprintf(listing,"Function declarion: %s\n", tree->attr.name);
                  printToken(tree->attr.op,"\0");
                  break;
                case ArrK:
                    fprintf(listing,"Array declarion: %s, size: [%d]\n", tree->attr.arr.name, tree->attr.arr.size);
                    printToken(tree->attr.op,"\0");
                    break;
                case VarK:
                    fprintf(listing,"Variable declarion: %s\n",tree->attr.name);
                    break;
                case TypeNameK:
                    fprintf(listing,"Type: %s\n", tree->attr.type);
                    break;
                default:
                    fprintf(listing,"Unknown DecNode kind\n");
                    break;
            }
        }
        else if (tree->nodekind==ParamK) {
            switch (tree->kind.param) {
                case ArrParamK:
                    fprintf(listing, "Array Parameter: %s\n", tree->attr.name);
                    break;
                case NonArrParamK:
                    fprintf(listing, "parameter: %s\n", tree->attr.name);
                    break;
                default:
                    fprintf(listing, "Unknown TypeNode kind\n");
            }
        }
        else if (tree->nodekind == Error){
                fprintf(listing, "Error:\n%s\n", tree->attr.name);
                for (int i = 0; i < tree->col-1; i++) {
                    printf(" ");
                }

                printf("^\nExpect: %s\n", tree->correction);

        }
        else fprintf(listing,"Unknown node kind\n");

        for (i=0;i<MAXCHILDREN;i++)
             printTree(tree->child[i]);
        tree = tree->sibling;
    }
    UNINDENT;
}
