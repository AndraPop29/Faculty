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
     IDENTIFICATOR = 258,
     CONSTANT = 259,
     USING = 260,
     NAMESPACE = 261,
     INCLUDE = 262,
     MAIN = 263,
     ENDL = 264,
     IF = 265,
     ELSE = 266,
     FOR = 267,
     WHILE = 268,
     INT = 269,
     COUT = 270,
     CIN = 271,
     STRUCT = 272,
     DOUBLE = 273,
     RETURN = 274,
     GT = 275,
     LT = 276,
     GE = 277,
     LE = 278,
     ASSIGN = 279,
     NEQ = 280,
     EQ = 281,
     AND = 282,
     IN = 283,
     OUT = 284,
     PLUS = 285
   };
#endif
/* Tokens.  */
#define IDENTIFICATOR 258
#define CONSTANT 259
#define USING 260
#define NAMESPACE 261
#define INCLUDE 262
#define MAIN 263
#define ENDL 264
#define IF 265
#define ELSE 266
#define FOR 267
#define WHILE 268
#define INT 269
#define COUT 270
#define CIN 271
#define STRUCT 272
#define DOUBLE 273
#define RETURN 274
#define GT 275
#define LT 276
#define GE 277
#define LE 278
#define ASSIGN 279
#define NEQ 280
#define EQ 281
#define AND 282
#define IN 283
#define OUT 284
#define PLUS 285




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

