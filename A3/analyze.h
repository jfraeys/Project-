/****************************************************/
/* File: analyze.h                                  */
/* Jeremie Fraeys and Joel Klemens                  */
/* Example of Tiny analyze.c and analyze.h          */
/* Compiler Construction: Principles and Practice   */
/* Kenneth C. Louden                                */
/****************************************************/

#ifndef _ANALYZE_H_
#define _ANALYZE_H_

#define VOID "void"
#define INT "int"
#define MINUS 274
#define PLUS 273
#define TIMES 275
#define OVER 276

/* Function buildSymtab constructs the symbol
 * table by preorder traversal of the syntax tree
 */
void buildSymTab(TreeNode *);

/* Procedure typeCheck performs type checking
 * by a postorder syntax tree traversal
 */
void typeCheck(TreeNode *);

#endif
