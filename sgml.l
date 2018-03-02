/****************************************************/
/* File: sgml.l                                     */
/* Flex specification for SGML                      */
/* Joel Klemens 0895223                             */
/****************************************************/

%{
#include <stdio.h>
#include "globals.h"
#include "util.h"
#include "scan.h"

/* lexeme of identifier or reserved word */
char tokenString[MAXTOKENLEN+1];

/* global stack can be declared here */

%}
open          <[^\/][^>]*>
close         <\/[^>]*>
digit         [0-9]
number        [+-]?{digit}?\.?{digit}+
letter        [a-zA-Z]
word          ({letter}|{digit})+({letter}|{digit})*
punctuation   [/\[.,\/#!$%\^&\*;:{}=\-_`"'<>\?~()\]]
hyphenated    {word}+(-{word}*)+
apostrophized {word}\'{word}(\'{word})?
newline       \n
whitespace    [ \t]+

%%
{open}                      {return OPEN;}
{close}                     {return CLOSE;}
{word}                      {return WORD;}
{number}                    {return NUMBER;}
{apostrophized}             {return APOSTROPHIZED;}
{hyphenated}                {return HYPHENATED;}
{punctuation}               {return PUNCTUATION;}
{newline}                   {lineno++;}
{whitespace}                {/* skip whitespace */}
.                           {return ERROR;}

%%

TokenType getToken(void)
{ static int firstTime = TRUE;
  TokenType currentToken;
  if (firstTime)
  { firstTime = FALSE;
    lineno++;
    yyin = source;
    yyout = listing;
  }
  currentToken = yylex();
  strncpy(tokenString, yytext, MAXTOKENLEN);
  return currentToken;
}
