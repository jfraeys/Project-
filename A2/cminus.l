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
%}

%x CMNT

digit       [0-9]
number      {digit}+
letter      [a-zA-Z]
identifier  {letter}+
newline     \n
whitespace  [ \t]+

%%

"if"            {return IF;}
"else"          {return ELSE;}
"int"           {return INT;}
"return"        {return RETURN;}
"void"          {return VOID;}
"while"         {return WHILE;}
"<="            {return LET;}
">="            {return GET;}
"="             {return ASSIGN;}
"!="            {return NQ;}
"=="            {return EQ;}
"<"             {return LT;}
">"		        {return GT;}
"+"             {return PLUS;}
"-"             {return MINUS;}
"*"             {return TIMES;}
"/"             {return OVER;}
"("             {return LPAREN;}
")"             {return RPAREN;}
"["             {return LBRKT;}
"]"             {return RBRKT;}
"{"             {return LBRC;}
"}"             {return RBRC;}
";"             {return SEMI;}
","             {return COMMA;}
{number}        {return NUM;}
{identifier}    {return ID;}
{newline}       {lineno++;}
{whitespace}    {/* skip whitespace */}
.               {return ERROR;}
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
  strncpy(tokenString, yytext, MAXTOKENLEN);
  if (TraceScan) {
    fprintf(listing,"\t%d: ",lineno);
    printToken(currentToken,tokenString);
  }
  return currentToken;
}
