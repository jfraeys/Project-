/****************************************************/
/* File: analyze.c                                  */
/* Semantic analyzer implementation                 */
/* for the TINY compiler                            */
/* Compiler Construction: Principles and Practice   */
/* Kenneth C. Louden                                */
/****************************************************/

#include "globals.h"
#include "symtable.h"
#include "analyze.h"
#include "util.h"

#define VOID "void"
#define INT "int"

static char * funcName;
static int preserveLastScope = FALSE;

/* counter for variable memory locations */

/* Procedure traverse is a generic recursive
 * syntax tree traversal routine:
 * it applies preProc in preorder and postProc
 * in postorder to tree pointed to by tree
 */
static void traverse( TreeNode * tree,
               void (* preProc) (TreeNode *),
               void (* postProc) (TreeNode *) )
{ if (tree != NULL)
  { preProc(tree);
    { int i;
      for (i=0; i < MAXCHILDREN; i++)
        traverse(tree->child[i],preProc,postProc);
    }
    postProc(tree);
    traverse(tree->sibling,preProc,postProc);
  }
}

static void insertIOFunc(void)
{ TreeNode *func;
  TreeNode *typeSpec;
  TreeNode *param;
  TreeNode *compStmt;

  func = newDecNode(FuncK);

  typeSpec = newDecNode(TypeNameK);
  typeSpec->attr.name = INT;
  func->type = Integer;

  compStmt = newStmtNode(CompK);
  compStmt->child[0] = NULL;      // no local var
  compStmt->child[1] = NULL;      // no stmt

  func->lineno = 0;
  func->attr.name = "input";
  func->child[0] = typeSpec;
  func->child[1] = NULL;          // no param
  func->child[2] = compStmt;

  st_insert("input", -1, add_location(), func);

  func = newDecNode(FuncK);

  typeSpec = newDecNode(TypeNameK);
  typeSpec->attr.name = VOID;

  param = newParamNode(NonArrParamK);
  param->attr.name = "arg";
  param->child[0] = newDecNode(TypeNameK);
  param->child[0]->attr.name = INT;

  compStmt = newStmtNode(CompK);
  compStmt->child[0] = NULL;      // no local var
  compStmt->child[1] = NULL;      // no stmt

  func->lineno = 0;
  func->attr.name = "output";
  func->child[0] = typeSpec;
  func->child[1] = param;
  func->child[2] = compStmt;

  st_insert("output", -1, add_location(), func);
}

static void symbolError(TreeNode * tree, char * message)
{ fprintf(listing,"Symbol error at line %d: %s\n",tree->lineno,message);
  errorFlag = TRUE;
}

/* Procedure insertNode inserts
 * identifiers stored in tree into
 * the symbol table
 */
static void insertNode( TreeNode * tree)
{ switch (tree->nodekind)
  { case StmtK:
      switch (tree->kind.stmt)
      { case CompK:
          if (preserveLastScope) {
            preserveLastScope = FALSE;
          } else {
            Scope scope = s_create(funcName);
            s_push(scope);
          }
          tree->attr.scope = s_top();
          break;
        default:
          break;
      }
      break;
    case ExpK:
      switch (tree->kind.exp)
      { case IdK:
        case ArrIdK:
        case CallK:
          if (st_lookup(tree->attr.name) == -1)
          /* not yet in table, error */
            symbolError(tree, "undlecared symbol");
          break;
        default:
          break;
      }
      break;
    case DecK:
      switch (tree->kind.dec)
      { case FuncK:
          funcName = tree->attr.name;
          if (st_lookup_top(funcName) >= 0) {
            symbolError(tree,"function already declared");
            break;
          }
          st_insert(funcName,tree->lineno,add_location(),tree);
          s_push(s_create(funcName));
          preserveLastScope = TRUE;

          if(strcmp(tree->child[0]->attr.name, INT) == 0){
              tree->type = Integer;
          } else {
              tree->type = Void;
          }

          break;
        case VarK:
        case ArrK:
          { char *name;

            if (tree->child[0]->attr.name == VOID) {
              symbolError(tree,"variable should have non-void type");
              break;
            }

            if (tree->kind.dec == VarK) {
              name = tree->attr.name;
              tree->type = Integer;
            } else {
              name = tree->attr.arr.name;
              tree->type = IntArr;
            }

            if (st_lookup_top(name) < 0)
              st_insert(name,tree->lineno,add_location(),tree);
            else
              symbolError(tree,"symbol already declared for current scope");
          }
          break;
        default:
          break;
      }
      break;
    case ParamK:
      if (tree->child[0]->attr.type == VOID)
        symbolError(tree->child[0],"void type parameter is not allowed");
      if (st_lookup(tree->attr.name) == -1) {
        st_insert(tree->attr.name,tree->lineno,add_location(),tree);
        if (tree->kind.param == NonArrParamK)
          tree->type = Integer;
        else
        symbolError(tree,"symbol already declared for current scope");
      }
      break;
    default:
      break;
  }
}

static void afterInsertNode( TreeNode * tree )
{ switch (tree->nodekind)
  { case StmtK:
      switch (tree->kind.stmt)
      { case CompK:
          s_pop();
          break;
        default:
          break;
      }
      break;
    default:
      break;
  }
}

/* Function buildSymtab constructs the symbol
 * table by preorder traversal of the syntax tree
 */
void buildSymTab(TreeNode * syntaxTree)
{ globalScope = s_create(NULL);
  s_push(globalScope);
  insertIOFunc();
  traverse(syntaxTree,insertNode,afterInsertNode);
  s_pop();

  if (TraceAnalyze)
  { fprintf(listing,"\nSymbol table:\n\n");
    st_print(listing);
  }
}

// static void typeError(TreeNode * tree, char * message)
// { fprintf(listing,"Type error at line %d: %s\n",tree->lineno,message);
//   Error = TRUE;
// }
//
// static void beforeCheckNode(TreeNode * tree)
// { switch (tree->nodekind)
//   { case DeclK:
//       switch (tree->kind.decl)
//       { case FuncK:
//           funcName = tree->attr.name;
//           break;
//         default:
//           break;
//       }
//       break;
//     case StmtK:
//       switch (tree->kind.stmt)
//       { case CompK:
//           s_push(tree->attr.scope);
//           break;
//         default:
//           break;
//       }
//     default:
//       break;
//   }
// }
//
// /* Procedure checkNode performs
//  * type checking at a single tree node
//  */
// static void checkNode(TreeNode * tree)
// { switch (tree->nodekind)
//   { case StmtK:
//       switch (tree->kind.stmt)
//       { case CompK:
//           s_pop();
//           break;
//         case IterK:
//           if (tree->child[0]->type == Void)
//           /* while test should be void function call */
//             typeError(tree->child[0],"while test has void value");
//           break;
//         case RetK:
//           { const TreeNode * funcDecl =
//                 st_bucket(funcName)->treeNode;
//             const ExpType funcType = funcDecl->type;
//             const TreeNode * expr = tree->child[0];
//
//             if (funcType == Void &&
//                 (expr != NULL && expr->type != Void)) {
//               typeError(tree,"expected no return value");
//               //ValueReturned = TRUE;
//             } else if (funcType == Integer &&
//                 (expr == NULL || expr->type == Void)) {
//               typeError(tree,"expected return value");
//             }
//           }
//           break;
//         default:
//           break;
//       }
//       break;
//     case ExpK:
//       switch (tree->kind.exp)
//       { case AssignK:
//           if (tree->child[0]->type == IntegerArray)
//           /* no value can be assigned to array variable */
//             typeError(tree->child[0],"assignment to array variable");
//           else if (tree->child[1]->type == Void)
//           /* r-value cannot have void type */
//             typeError(tree->child[0],"assignment of void value");
//           else
//             tree->type = tree->child[0]->type;
//           break;
//         case OpK:
//           { ExpType leftType, rightType;
//             TokenType op;
//
//             leftType = tree->child[0]->type;
//             rightType = tree->child[1]->type;
//             op = tree->attr.op;
//
//             if (leftType == Void ||
//                 rightType == Void)
//               typeError(tree,"two operands should have non-void type");
//             else if (leftType == IntegerArray &&
//                 rightType == IntegerArray)
//               typeError(tree,"not both of operands can be array");
//             else if (op == MINUS &&
//                 leftType == Integer &&
//                 rightType == IntegerArray)
//               typeError(tree,"invalid operands to binary expression");
//             else if ((op == TIMES || op == OVER) &&
//                 (leftType == IntegerArray ||
//                  rightType == IntegerArray))
//               typeError(tree,"invalid operands to binary expression");
//             else {
//               tree->type = Integer;
//             }
//           }
//           break;
//         case ConstK:
//           tree->type = Integer;
//           break;
//         case IdK:
//         case ArrIdK:
//           { const char *symbolName = tree->attr.name;
//             const BucketList bucket =
//                 st_bucket(symbolName);
//             TreeNode *symbolDecl = NULL;
//
//             if (bucket == NULL)
//               break;
//             symbolDecl = bucket->tree_node;
//
//             if (tree->kind.exp == ArrIdK) {
//               if (symbolDecl->kind.dec != ArrK &&
//                   symbolDecl->kind.param != ArrParamK)
//                 typeError(tree,"expected array symbol");
//               else if (tree->child[0]->type != Integer)
//                 typeError(tree,"index expression should have integer type");
//               else
//                 tree->type = Integer;
//             } else {
//               tree->type = symbolDecl->type;
//             }
//           }
//           break;
//         case CallK:
//           { const char *callingFuncName = tree->attr.name;
//             const TreeNode * funcDecl = st_bucket(callingFuncName)->tree_node;
//             TreeNode *arg;
//             TreeNode *param;
//
//             if (funcDecl == NULL)
//               break;
//
//             arg = tree->child[0];
//             param = funcDecl->child[1];
//
//             if (funcDecl->kind.dec != FuncK)
//             { typeError(tree,"expected function symbol");
//               break;
//             }
//
//             while (arg != NULL)
//             { if (param == NULL)
//               /* the number of arguments does not match to
//                  that of parameters */
//                 typeError(arg,"the number of parameters is wrong");
//               /*else if (arg->type == IntegerArray &&
//                   param->type != IntegerArray)
//                 typeError(arg,"expected non-array value");
//               else if (arg->type == Integer &&
//                   param->type == IntegerArray)
//                 typeError(arg,"expected array value");*/
//               else if (arg->type == Void)
//                 typeError(arg,"void value cannot be passed as an argument");
//               else {  // no problem!
//                 arg = arg->sibling;
//                 param = param->sibling;
//                 continue;
//               }
//               /* any problem */
//               break;
//             }
//
//             if (arg == NULL && param != NULL)
//             /* the number of arguments does not match to
//                that of parameters */
//               typeError(tree->child[0],"the number of parameters is wrong");
//
//             tree->type = funcDecl->type;
//           }
//           break;
//         default:
//           break;
//       }
//       break;
//     default:
//       break;
//   }
// }

/* Procedure typeCheck performs type checking
 * by a postorder syntax tree traversal
 */
// void typeCheck(TreeNode * syntaxTree)
// { s_push(globalScope);
//   traverse(syntaxTree,beforeCheckNode,checkNode);
//   s_pop();
// }
