/****************************************************/
/* File: main.c                                     */
/* Main program for TINY compiler                   */
/****************************************************/

#include "globals.h"

/* set NO_PARSE to TRUE to get a scanner-only compiler */
#define NO_PARSE FALSE

/* set NO_ANALYZE to TRUE to get a analyze-only compiler */
#define NO_ANALYZE FALSE

#define MAX_MATCHES 1
#define tofind_correct_file "^.*\\.(cm|CM)$"
#define tofind_file "^.*\\.*$"

#include "util.h"
#if NO_PARSE
#include "scan.h"
#else
#include "parse.h"
#if !NO_ANALYZE
#include "analyze.h"
#endif
#endif

/* allocate global variables */
int lineno = 0;
int col = 0;
FILE * source;
FILE * listing;
FILE * code;

/* allocate and set tracing flags */
int TraceScan = TRUE;
int TraceParse = TRUE;
int TraceAnalyze = FALSE;
int TraceCode = FALSE;

int errorFlag = FALSE;

int match (regex_t *exp, char *sz){
    regmatch_t matches[MAX_MATCHES];
    int retval;

    retval = regexec(exp, sz, 0, NULL, 0);

    return retval;
}

int main( int argc, char * argv[] ) {
    TreeNode * syntaxTree;
    int ttype, i;
    char pgm[120]; /* source code file name */
    regex_t correctFile, file;

    if (argc < 2) {
        fprintf(stderr,"usage: %s <filename>\n",argv[0]);
        exit(1);
    }

    if (regcomp(&correctFile, tofind_correct_file, REG_EXTENDED) != 0){
        fprintf(stderr, "Regcomp failed\n");
        return EXIT_FAILURE;
    }

    if (regcomp(&file, tofind_file, REG_EXTENDED) != 0){
        fprintf(stderr, "Regcomp failed\n");
        return EXIT_FAILURE;
    }

    for(i = 1; i < argc; i++){
        if (strcmp(argv[i], "-s") == 0){
            TraceAnalyze = TRUE;
        } else if(match(&correctFile, argv[i]) == 0){
            strcpy(pgm, argv[i]);
        } else if(match(&file, argv[i]) == 0){
            fprintf(stderr, "File %s: wrong type\n", argv[i]);
            return EXIT_FAILURE;
        }
    }

    regfree(&correctFile);
    regfree(&file);

    source = fopen(pgm,"r");
    if (source==NULL) {
        fprintf(stderr,"File %s not found\n",argv[i]);
        exit(1);
    }

    listing = stdout; /* send listing to screen */
    fprintf(listing,"\nCMINUS COMPILATION: %s\n",pgm);
#if NO_PARSE
    while( (ttype=getToken())!= 0 );
#else
    syntaxTree = parse();
    if (TraceParse) {
        fprintf(listing,"\nSyntax tree:\n");
        printTree(syntaxTree);
    }
#if !NO_ANALYZE
    printf("%d\n", errorFlag);
    if(!errorFlag) {
        buildSymTab(syntaxTree);
        //typeCheck(syntaxTree);
    }
#endif
#endif
    fclose(source);
    return 0;
}
