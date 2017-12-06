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
     FUNCTION = 260,
     CONST = 261,
     VAR = 262,
     BEGINN = 263,
     END = 264,
     IF = 265,
     ELSE = 266,
     FOR = 267,
     WHILE = 268,
     INTEGER = 269,
     REAL = 270,
     ARRAY = 271,
     OF = 272,
     READ = 273,
     WRITE = 274,
     CALL = 275,
     GT = 276,
     LT = 277,
     GE = 278,
     LE = 279,
     ASSIGN = 280,
     NEQ = 281,
     EQ = 282,
     OR = 283,
     AND = 284,
     NO_PARAMS = 285
   };
#endif
/* Tokens.  */
#define IDENTIFICATOR 258
#define CONSTANT 259
#define FUNCTION 260
#define CONST 261
#define VAR 262
#define BEGINN 263
#define END 264
#define IF 265
#define ELSE 266
#define FOR 267
#define WHILE 268
#define INTEGER 269
#define REAL 270
#define ARRAY 271
#define OF 272
#define READ 273
#define WRITE 274
#define CALL 275
#define GT 276
#define LT 277
#define GE 278
#define LE 279
#define ASSIGN 280
#define NEQ 281
#define EQ 282
#define OR 283
#define AND 284
#define NO_PARAMS 285




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

