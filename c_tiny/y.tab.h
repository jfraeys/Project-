/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     IF = 258,
     THEN = 259,
     ELSE = 260,
     END = 261,
     REPEAT = 262,
     UNTIL = 263,
     READ = 264,
     WRITE = 265,
     ID = 266,
     NUM = 267,
     ASSIGN = 268,
     EQ = 269,
     LT = 270,
     GT = 271,
     PLUS = 272,
     MINUS = 273,
     TIMES = 274,
     OVER = 275,
     LPAREN = 276,
     RPAREN = 277,
     SEMI = 278,
     ERROR = 279
   };
#endif
/* Tokens.  */
#define IF 258
#define THEN 259
#define ELSE 260
#define END 261
#define REPEAT 262
#define UNTIL 263
#define READ 264
#define WRITE 265
#define ID 266
#define NUM 267
#define ASSIGN 268
#define EQ 269
#define LT 270
#define GT 271
#define PLUS 272
#define MINUS 273
#define TIMES 274
#define OVER 275
#define LPAREN 276
#define RPAREN 277
#define SEMI 278
#define ERROR 279




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

