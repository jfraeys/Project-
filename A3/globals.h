/****************************************************/
/* File: globals.h                                  */
/* Global types and vars for TINY compiler          */
/* must come before other include files             */
/****************************************************/

#ifndef _GLOBALS_H_
#define _GLOBALS_H_

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <regex.h>

#ifndef FALSE
#define FALSE 0
#endif

#ifndef TRUE
#define TRUE 1
#endif

typedef int TokenType;

extern FILE* source; /* source code text file */
extern FILE* listing; /* listing output text file */
extern FILE* code; /* code text file for TM simulator */
extern int lineno; /* source line number for listing */
extern int col; /*source column number for listing*/

/**************************************************/
/***********   Syntax tree for parsing ************/
/**************************************************/

typedef enum {StmtK, ExpK, DecK, ParamK, TypeK, Error} NodeKind;
typedef enum {CompK, IfK, ReturnK, WhileK} StmtKind;
typedef enum {OpK, ConstK, IdK, SubsK, CallK, ArrIdK} ExpKind;
typedef enum {FuncK, VarK, ArrK, TypeNameK} DecKind;
typedef enum {ArrParamK, NonArrParamK} ParamKind;

typedef struct arrAttr{
    TokenType type;
    char * name;
    int size;
}ArrAttr;

/* ExpType is used for type checking */
typedef enum {Void,Integer,Boolean, IntArr} ExpType;

#define MAXCHILDREN 3

typedef struct treeNode
   { struct treeNode * child[MAXCHILDREN];
     struct treeNode * sibling;
     int lineno;
     int col;
     char * correction;
     NodeKind nodekind;
     union { StmtKind stmt;
             ExpKind exp;
             DecKind dec;
             ParamKind param;} kind;
     union { int op;
             char * type;
             int val;
             char * name;
             ArrAttr arr;
             struct ScopeRec * scope;} attr;
     ExpType type; /* for type checking of exps */
   } TreeNode;

/**************************************************/
/***********   Flags for tracing       ************/
/**************************************************/

/* TraceScan = TRUE causes token information to be
 * printed to the listing file as each token is
 * recognized by the scanner
 */
extern int TraceScan;

/* TraceParse = TRUE causes the syntax tree to be
 * printed to the listing file in linearized form
 * (using indents for children)
 */
extern int TraceParse;

/* TraceAnalyze = TRUE causes symbol table inserts
 * and lookups to be reported to the listing file
 */
extern int TraceAnalyze;

/* TraceCode = TRUE causes comments to be written
 * to the TM code file as code is generated
 */
extern int TraceCode;

#endif
