/****************************************************/
/* File: symtab.h                                   */
/* Jeremie Fraeys and Joel Klemens                  */
/* Exampl of Tiny Symtable.c and Symtable.h         */
/* Compiler Construction: Principles and Practice   */
/* Kenneth C. Louden                                */
/****************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symtable.h"

#define SIZE 211
#define SHIFT 4
#define MAX_SCOPE 1000

/* the hash function */
static int hash ( char * key ){
	int temp = 0;
  	int i = 0;

  	while (key[i] != '\0'){
  		temp = ((temp << SHIFT) + key[i]) % SIZE;
    	++i;
  	}

  	return temp;
}

static Scope scopes[MAX_SCOPE];
static int nScope = 0;
static Scope scopeStack[MAX_SCOPE];
static int nScopeStack = 0;
static int location[MAX_SCOPE];

/* Insert function */
void st_insert( char * name, int lineno, int loc, TreeNode * treeNode ){
	int h = hash(name);
  	Scope top = s_top();
  	BucketList l =  top->hashTable[h];

  	while ((l != NULL) && (strcmp(name,l->name) != 0)){
  		l = l->next;
  	}

  	if (l == NULL){
	   	l = (BucketList) malloc(sizeof(struct BucketListRec));
	    l->name = name;
	    l->tree_node = treeNode;
	    l->lines = (LineList) malloc(sizeof(struct LineListRec));
	    l->lines->lineno = lineno;
	    l->memloc = loc;
	    l->lines->next = NULL;
	    l->next = top->hashTable[h];
	    top->hashTable[h] = l;
	} else{
	  // ERROR!
	}
}

/* Lookup function */
int st_lookup ( char * name ){
	BucketList l = st_bucket(name);
 	if (l != NULL){
 		return l->memloc;
 	}
  	return -1;
}

/* Function for printing out the sym table */
void st_print(FILE * listing){
	int i;
	int j;
	for (i = 0; i < nScope; ++i) {
    	Scope scope = scopes[i];
    	BucketList * hashTable = scope->hashTable;

    	if (i == 0) {     // global scope
      		fprintf(listing, "<global scope> ");
    	} else {
      		fprintf(listing, "function name: %s ", scope->funcName);
    	}

	    fprintf(listing, "(nested level: %d)\n", scope->nestedLevel);

	    fprintf(listing,"Symbol Name    Sym.Type  Data Type    Line Numbers\n");
	    fprintf(listing,"-------------  --------  -----------  ------------\n");

	    /*********** one row at a time ******/
	    for (j=0;j<SIZE;++j){
	    	if (hashTable[j] != NULL){
	    		BucketList l = hashTable[j];
      			TreeNode *node = l->tree_node;

      			while (l != NULL){
      				LineList t = l->lines;

        			fprintf(listing,"%-14s ",l->name);

        			switch (node->nodekind) {
				        case DecK:
				          	switch (node->kind.dec) {
					          	case FuncK:
					            	fprintf(listing, "Function  ");
					            	break;
					          	case VarK:
					          	  	fprintf(listing, "Variable  ");
					           	 	break;
					          	case ArrK:
					            	fprintf(listing, "Array Var.");
					            	break;
					          	default:
					            	break;
				          	}
				          	break;
				        case ParamK:
				          	switch (node->kind.param) {
					          	case NonArrParamK:
					            	fprintf(listing, "Variable  ");
					            	break;
					          	case ArrParamK:
					            	fprintf(listing, "Array Var.");
					            	break;
					          	default:
					            	break;
				          	}
				          	break;
				        default:
				          	break;
	        		}

				    switch (node->type) {
				    	case Void:
				          	fprintf(listing, "Void         ");
				         	break;
				        case Integer:
				          	fprintf(listing, "Integer      ");
				          	break;
				        case Boolean:
				          	fprintf(listing, "Boolean      ");
				          	break;
				        default:
				          	break;
				    }

				    while (t != NULL){
				        fprintf(listing,"%4d ",t->lineno);
				        t = t->next;
				    }

				    fprintf(listing,"\n");
				    l = l->next;
	      		}
	    	}
	  	}//end of for loop
	    fputc('\n', listing);
  	}//end of for loop
}//end of print sym table

/* add lineno function */
void st_add_lineno(char * name, int lineno){
	//Match the name and finc the bucket
	BucketList l = st_bucket(name);
	//Set line list equal to the buckets lines
  	LineList ll = l->lines;

  	while (ll->next != NULL){
  		ll = ll->next;
  	}

  	ll->next = (LineList) malloc(sizeof(struct LineListRec));
  	ll->next->lineno = lineno;
  	ll->next->next = NULL;
}

int st_lookup_top(char * name){
	int h = hash(name);
  	Scope sc = s_top();

  	while(sc) {
    	BucketList l = sc->hashTable[h];
    	while ((l != NULL) && (strcmp(name,l->name) != 0)){
      		l = l->next;
    	}
    	if (l != NULL){
    		return l->memloc;
    	}
   	 	break;
  	}

  	return -1;
}

BucketList st_bucket(char * name){
	int h = hash(name);
  	Scope sc = s_top();
 	while(sc) {
    	BucketList l = sc->hashTable[h];
    	while ((l != NULL) && (strcmp(name,l->name) != 0)){
      		l = l->next;
    	}
    	if (l != NULL){
    		return l;
    	}
    	sc = sc->parent;
  	}

  	return NULL;
}

/************ Scope stack functions ****************/
Scope s_create(char *funcName){
	Scope newScope;

  	newScope = (Scope) malloc(sizeof(struct ScopeRec));
  	newScope->funcName = funcName;
  	newScope->nestedLevel = nScopeStack;
  	newScope->parent = s_top();

  	scopes[nScope++] = newScope;

 	return newScope;
}

Scope s_top(void){
	return scopeStack[nScopeStack - 1];
}

void s_pop(void){
	--nScopeStack;
}

void s_push(Scope scope){
	scopeStack[nScopeStack] = scope;
  	location[nScopeStack++] = 0;
}

int add_location(void){
	return location[nScopeStack - 1]++;
}
