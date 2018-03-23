Jeremie Fraeys 0892019
Joel Klemens 0895223
CIS 4650: Compiler
March 22th, 2018

CMINUS SCANNER AND PARSER

---------DESCRIPTION---------

This program is a cminus scanner and parser coded in C using flex and yacc as support tools. It also inludes a symbol table and Semantic Error handling. The program will accept CMinus(.cm) files and return the compilation list, the syntax tree, symentic error and if "-s" is used it will return a symbol table.

---------HOW TO RUN---------

   This directory contains all the required files for building a parser
for the C minus language.

   To build the parser, type "make" in the current directory, which will
generate an executable program called "cm".

   To test source code like "fac.cm", type "./cm <testfile>.cm" and the syntax
tree will be displayed on the screen.

   To rebuild the parser, type "make clean" and type "make" again.

   To display symbol table use "-s" flag as an argument.

---------ADDITIONAL INFORMATION---------

The test [1, 2, 3, 4, 5].cm files are in the bin folder.

   There is a parameter "NO_PARSE" in "main.c".  Its default setting is
FALSE, and the "make" will generate a parser using this value.  If we change
the value to TRUE, the "make" will only generate a scanner.

   Note that it's important to use the option "-d" in "yacc -d cminus.y".  This
will generate a list of token type values in "y.tab.h", which will be used
in "lex.yy.c" and "util.c".  Otherwise, the parser may not connect to the
scanner properly and util.c may not display the syntax tree correctly.

---------REFERENCES---------
https://stackoverflow.com/questions/16911792/how-to-continue-parser-after-syntax-error
https://stackoverflow.com/questions/1737460/how-to-find-shift-reduce-conflict-in-this-yacc-file
https://github.com/isairz/cminus
https://codereview.stackexchange.com/questions/101694/implementation-of-symbol-table-in-c
http://www.sci.tamucc.edu/~sking/Courses/Compilers/Slides/Semantics.pdf
https://stackoverflow.com/questions/9410/how-do-you-pass-a-function-as-a-parameter-in-c
https://www.tutorialspoint.com/cprogramming/switch_statement_in_c.htm
