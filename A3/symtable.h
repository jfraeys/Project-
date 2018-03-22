/****************************************************/
/* File: symtab.c                                   */
/* Jeremie Fraeys and Joel Klemens                  */
/* Exampl of Tiny Symtable.c and Symtable.h         */
/* Compiler Construction: Principles and Practice   */
/* Kenneth C. Louden                                */
/****************************************************/

#ifndef _SYMTABLE_H_
#define _SYMTABLE_H_

#include "globals.h"

/* Functino from text book for how to make symtable 
	Symtable insert */ 
void st_insert(char * name, int lineno, int loc, TreeNode * treeNode);

/* Functino from text book for how to make symtable
	Sym table lookup  returns the memory location or -1 */ 
int st_lookup (char * name);

/* Function from text book for how to print the symtable
	print Sym Table */
void st_print(FILE * listing);

/* Return the mem location of the variable or -1 for top scope element of a bucket */
int st_lookup_top(char * name);

/* Return the bucket that has the matching search name */
BucketList st_bucket(char * name);

/************ Scope functions ****************/
/* Create new scope struct variable */ 
Scope s_create(char *funcName);

/* Return the top element of the scope stack */
Scope s_top(void);

/* Remove top element from the scope stack, no return value */
void s_pop(void);

/* Push and element onto the scope stack */
void s_push(Scope scope);

/* Add 1 to the location variable */
int add_location(void); 

#endif