/****************************************************/
/* File: tiny.l                                     */
/* Lex specification for TINY                       */
/* Jeremie Fraeys and Joel Klemens                  */
/****************************************************/

%{
#include "globals.h"
#include "util.h"
#include "scan.h"
#include "y.tab.h"

/* lexeme of identifier or reserved word */
char tokenString[MAXTOKENLEN+1];
char currentPos[100];
%}

%x CMNT

digit       [0-9]
number      {digit}+
letter      [a-zA-Z]
identifier  {letter}+
newline     \n
whitespace  [ \t]+

%%

"if"            {col += 2; return IF;}
"else"          {col += 4; return ELSE;}
"int"           {col += 3; return INT;}
"return"        {col += 6; return RETURN;}
"void"          {col += 4; return VOID;}
"while"         {col += 5; return WHILE;}
"<="            {col += 2; return LET;}
">="            {col += 2; return GET;}
"="             {col += 1; return ASSIGN;}
"!="            {col += 2; return NQ;}
"=="            {col += 2; return EQ;}
"<"             {col += 1; return LT;}
">"		        {col += 1; return GT;}
"+"             {col += 1; return PLUS;}
"-"             {col += 1; return MINUS;}
"*"             {col += 1; return TIMES;}
"/"             {col += 1; return OVER;}
"("             {col += 1; return LPAREN;}
")"             {col += 1; return RPAREN;}
"["             {col += 1; return LBRKT;}
"]"             {col += 1; return RBRKT;}
"{"             {col += 1; return LBRC;}
"}"             {col += 1; return RBRC;}
";"             {col += 1; return SEMI;}
","             {col += 1; return COMMA;}
{number}        {col += strlen(yytext); return NUM;}
{identifier}    {col += strlen(yytext); return ID;}
{newline}       {col = 0; memset(currentPos, 0, 100); lineno++;}
{whitespace}    {col += strlen(yytext); strcat(currentPos, yytext);/* skip whitespace */}
.               {col += strlen(yytext); return ERROR;}
"/*"             { BEGIN CMNT; }
<CMNT>"*/"       { BEGIN    INITIAL; }
<CMNT>.          {/* skip content */}
<CMNT>"\n"      {lineno++;}

%%

int getToken(void)
{ static int firstTime = TRUE;
  int currentToken;
  if (firstTime)
  { firstTime = FALSE;
    lineno++;
    yyin = source;
    yyout = listing;
  }
  currentToken = yylex();
  strcat(currentPos, yytext);
  strncpy(tokenString, yytext, MAXTOKENLEN);
  if (TraceScan) {
    fprintf(listing,"\t%d:%d: ",lineno, col);
    printToken(currentToken,tokenString);
  }
  return currentToken;
}
