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
     CONST = 258,
     ID = 259,
     IF = 260,
     THEN = 261,
     ELSE = 262,
     LT = 263,
     CIN = 264,
     COUT = 265,
     GG = 266,
     LL = 267,
     INCLUDE = 268,
     USING = 269,
     RETURN = 270,
     NAMESPACE = 271,
     GT = 272,
     INT = 273,
     EE = 274,
     NE = 275
   };
#endif
/* Tokens.  */
#define CONST 258
#define ID 259
#define IF 260
#define THEN 261
#define ELSE 262
#define LT 263
#define CIN 264
#define COUT 265
#define GG 266
#define LL 267
#define INCLUDE 268
#define USING 269
#define RETURN 270
#define NAMESPACE 271
#define GT 272
#define INT 273
#define EE 274
#define NE 275




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 71 "a.y"
{
    struct{
        char* code;
        char* varn;
    } attributes;
    struct {
        char* code;
        char* lbl_Else;
        char* lbl_After;
    } ifAttr;
    struct {
        char* code;
        char* varn;
        char* op;
    } exprAttr;

    int intval;
}
/* Line 1529 of yacc.c.  */
#line 108 "a.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

