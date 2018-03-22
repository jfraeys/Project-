Jeremie Fraeys 0892019
Joel Klemens 0895223
CIS 4650: Compiler
March 6th, 2018

CMINUS SCANNER AND PARSER

---------DESCRIPTION---------

This program is a cminus scanner and parser coded in C using flex and yacc as support tools. The program will accept CMinus(.cm)
files and return the compilation list and the syntax tree.

---------HOW TO RUN---------

   This directory contains all the required files for building a parser
for the C minus language.

   To build the parser, type "make" in the current directory, which will
generate an executable program called "cm".

   To test source code like "fac.cm", type "./cm fac.cm" and the syntax
tree will be displayed on the screen.

   To rebuild the parser, type "make clean" and type "make" again.

---------ADDITIONAL INFORMATION---------

The test [1, 2, 3, 4, 5].cm files are in the bin folder.

   There is a parameter "NO_PARSE" in "main.c".  Its default setting is
FALSE, and the "make" will generate a parser using this value.  If we change
the value to TRUE, the "make" will only generate a scanner.

   Note that it's important to use the option "-d" in "yacc -d cminus.y".  This
will generate a list of token type values in "y.tab.h", which will be used
in "lex.yy.c" and "util.c".  Otherwise, the parser may not connect to the
scanner properly and util.c may not display the syntax tree correctly.
