/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



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




/* Copy the first part of user declarations.  */
#line 1 "a.y"

    #include <string.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include "decl.h"
    extern int yylex();
    extern int yyparse();
    extern FILE *yyin;
    extern int line;
    extern void printAll();
    void yyerror(const char *s);
    int t = 1;
    int lbl = 1;
    char * NewTempName()
    {
        char tc[10];
		sprintf(tc,"t%d",t++);
        return strdup(tc);
    }
    char * NewLabelName()
    {
        char temp[10];
        char l[10];
        sprintf(l,"label");
        
		lbl = lbl + 1;
        sprintf(temp,"%d",lbl);
        return strdup(strcat(l,temp));
    }
    char* result;
    char* display_function = "\ndisp proc\nMOV BX, 10\nMOV DX, 0000H\nMOV CX, 0000H\n.Dloop1:\nMOV DX, 0000H\ndiv BX\nPUSH DX\nINC CX\nCMP AX, 0\nJNE .Dloop1\n.Dloop2:\nPOP DX\nADD DX, 30H\nMOV AH, 02H\nINT 21H\nLOOP .Dloop2\nmov dx,offset newl\nmov ah,09h\nint 21h\nRET\n disp ENDP"
                            "\nreadInput proc"
                            "\nmov  ah, 0Ah"
                            "\nmov  dx, offset string"
                            "\nint  21H"
                            "\ncall string2number"
                            "\nret"
                            "\nreadInput endp"

                            "\nstring2number proc"
                            "\n;MAKE SI TO POINT TO THE LEAST SIGNIFICANT DIGIT."
                              "\nmov  si, offset string + 1 ;NUMBER OF CHARACTERS ENTERED."
                              "\nmov  cl, [ si ] ;NUMBER OF CHARACTERS ENTERED.\nmov  ch, 0 ;CLEAR CH, NOW CX==CL."
                              "\nadd  si, cx ;NOW SI POINTS TO LEAST SIGNIFICANT DIGIT."
                            "\n;CONVERT STRING."
                              "\nmov  bx, 0"
                              "\nmov  bp, 1 ;MULTIPLE OF 10 TO MULTIPLY EVERY DIGIT."
                            "\nrepeat:"
                            "\n;CONVERT CHARACTER."
                              "\nmov  al, [ si ] ;CHARACTER TO PROCESS."
                              "\nsub  al, 48 ;CONVERT ASCII CHARACTER TO DIGIT."
                              "\nmov  ah, 0 ;CLEAR AH, NOW AX==AL."
                              "\nmul  bp ;AX*BP = DX:AX."
                              "\nadd  bx,ax ;ADD RESULT TO BX"
                            "\n;INCREASE MULTIPLE OF 10 (1, 10, 100...)."
                              "\nmov  ax, bp"
                              "\nmov  bp, 10"
                              "\nmul  bp ;AX*10 = DX:AX."
                              "\nmov  bp, ax ;NEW MULTIPLE OF 10."
                            "\n;CHECK IF WE HAVE FINISHED"
                              "\ndec  si ;NEXT DIGIT TO PROCESS."
                              "\nloop repeat ;COUNTER CX-1, IF NOT ZERO, REPEAT."
                              "\nret"
                            "\nstring2number endp";
    char* vars= "\t\nnewl db "  ",13,10,\"$\""
                "\n\t\tstring db 5"
                    "\n\t\tdb ?"
                    "\n\t\tdb 5 dup (?)";


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

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
/* Line 193 of yacc.c.  */
#line 225 "a.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 238 "a.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   67

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  31
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  17
/* YYNRULES -- Number of rules.  */
#define YYNRULES  31
/* YYNRULES -- Number of states.  */
#define YYNSTATES  75

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   275

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      24,    25,    28,    26,     2,    27,     2,    29,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    22,
       2,    30,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    21,     2,    23,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,    11,    24,    27,    29,    30,    32,    34,
      36,    38,    41,    44,    47,    48,    51,    54,    57,    58,
      60,    62,    66,    74,    79,    84,    89,    93,    97,    99,
     101,   103
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      32,     0,    -1,    33,    21,    34,    15,     3,    22,    23,
      -1,    13,     8,     4,    17,    14,    16,     4,    22,    18,
       4,    24,    25,    -1,    36,    35,    -1,    34,    -1,    -1,
      42,    -1,    43,    -1,    44,    -1,    45,    -1,    39,    38,
      -1,    26,    37,    -1,    27,    37,    -1,    -1,    41,    40,
      -1,    28,    39,    -1,    29,    39,    -1,    -1,     4,    -1,
       3,    -1,    24,    37,    25,    -1,     5,    24,    46,    25,
      21,    34,    23,    -1,     4,    30,    37,    22,    -1,    10,
      12,     4,    22,    -1,     9,    11,     4,    22,    -1,    18,
       4,    22,    -1,    37,    47,    37,    -1,    17,    -1,     8,
      -1,    19,    -1,    20,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   124,   124,   145,   151,   158,   164,   168,   175,   181,
     186,   193,   210,   218,   227,   231,   247,   255,   264,   267,
     272,   279,   288,   308,   317,   326,   333,   348,   364,   369,
     375,   381
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "CONST", "ID", "IF", "THEN", "ELSE",
  "LT", "CIN", "COUT", "GG", "LL", "INCLUDE", "USING", "RETURN",
  "NAMESPACE", "GT", "INT", "EE", "NE", "'{'", "';'", "'}'", "'('", "')'",
  "'+'", "'-'", "'*'", "'/'", "'='", "$accept", "program", "antet",
  "stmt_list", "stmt_list1", "stmt", "expression", "expression1", "term",
  "term1", "factor", "ifstmt", "assign_stmt", "iostmt", "declstmt", "cond",
  "boolOp", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   123,    59,   125,    40,    41,    43,    45,    42,    47,
      61
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    31,    32,    33,    34,    35,    35,    36,    36,    36,
      36,    37,    38,    38,    38,    39,    40,    40,    40,    41,
      41,    41,    42,    43,    44,    44,    45,    46,    47,    47,
      47,    47
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     7,    12,     2,     1,     0,     1,     1,     1,
       1,     2,     2,     2,     0,     2,     2,     2,     0,     1,
       1,     3,     7,     4,     4,     4,     3,     3,     1,     1,
       1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     1,     0,     0,     0,     0,
       0,     0,     0,     0,     6,     7,     8,     9,    10,     0,
       0,     0,     0,     0,     0,     0,     5,     4,     0,    20,
      19,     0,     0,    14,    18,     0,     0,     0,     0,    26,
       0,     0,     0,    23,     0,     0,    11,     0,     0,    15,
      29,    28,    30,    31,     0,     0,    25,    24,     0,     0,
      21,    12,    13,    16,    17,    27,     0,     2,     0,     0,
       0,    22,     0,     0,     3
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     3,    13,    27,    14,    32,    46,    33,    49,
      34,    15,    16,    17,    18,    36,    54
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -34
static const yytype_int8 yypact[] =
{
      -7,     8,    19,     1,    16,   -34,     0,     4,    -3,     6,
      20,    21,    28,    22,     0,   -34,   -34,   -34,   -34,    24,
      -1,    -1,    31,    32,    17,    37,   -34,   -34,    25,   -34,
     -34,    -1,    23,   -19,   -16,     9,    18,    26,    27,   -34,
      29,    38,    30,   -34,    -1,    -1,   -34,    -1,    -1,   -34,
     -34,   -34,   -34,   -34,    -1,    33,   -34,   -34,    34,    36,
     -34,   -34,   -34,   -34,   -34,   -34,     0,   -34,    35,    39,
      40,   -34,    41,    42,   -34
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -34,   -34,   -34,   -14,   -34,   -34,   -20,   -34,   -33,   -34,
     -34,   -34,   -34,   -34,   -34,   -34,   -34
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      26,    35,    29,    30,     8,     9,     1,    44,    45,    10,
      11,    42,    47,    48,    63,    64,     4,    50,    12,     5,
       7,    19,     6,    31,    61,    62,    51,    20,    52,    53,
      21,    22,    24,    23,    65,    37,    38,    25,    28,    39,
      40,    41,    59,    55,    72,    43,     0,     0,    56,    57,
       0,    58,    69,    70,    66,    60,     0,    67,    68,     0,
       0,     0,    71,     0,     0,    73,     0,    74
};

static const yytype_int8 yycheck[] =
{
      14,    21,     3,     4,     4,     5,    13,    26,    27,     9,
      10,    31,    28,    29,    47,    48,     8,     8,    18,     0,
       4,    17,    21,    24,    44,    45,    17,    30,    19,    20,
      24,    11,     4,    12,    54,     4,     4,    15,    14,    22,
       3,    16,     4,    25,     4,    22,    -1,    -1,    22,    22,
      -1,    22,    66,    18,    21,    25,    -1,    23,    22,    -1,
      -1,    -1,    23,    -1,    -1,    24,    -1,    25
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    13,    32,    33,     8,     0,    21,     4,     4,     5,
       9,    10,    18,    34,    36,    42,    43,    44,    45,    17,
      30,    24,    11,    12,     4,    15,    34,    35,    14,     3,
       4,    24,    37,    39,    41,    37,    46,     4,     4,    22,
       3,    16,    37,    22,    26,    27,    38,    28,    29,    40,
       8,    17,    19,    20,    47,    25,    22,    22,    22,     4,
      25,    37,    37,    39,    39,    37,    21,    23,    22,    34,
      18,    23,     4,    24,    25
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 125 "a.y"
    {
                char temp[10000];
                char ids[500];
				int i;
                for(i = 1;i<t;i++)
                {
                    strcat(ids,"\tt");
                    char no[10];
                    sprintf(no,"%d",i);
                    strcat(ids,no);
                    strcat(ids," dw ?\n");
                }

                strcat(ids,vars);
                sprintf(temp,"assume cs:code,ds:data\ndata segment\n%s\ndata ends\ncode segment\nstart:\nmov ax,data\nmov ds,ax\n%s\nmov ah,4ch\nint 21h\n%s\ncode ends\nend start\n",ids,(yyvsp[(3) - (7)].attributes).code,display_function);
                (yyval.attributes).code = strdup(temp);
                printf("Assembly code:\n\n%s\n",(yyval.attributes).code);
                result = strdup((yyval.attributes).code);
            ;}
    break;

  case 3:
#line 146 "a.y"
    {
                (yyval.attributes).code="";
                (yyval.attributes).varn="";
            ;}
    break;

  case 4:
#line 152 "a.y"
    {
                char temp[10000];
                sprintf(temp,"%s\n%s\n",(yyvsp[(1) - (2)].attributes).code,(yyvsp[(2) - (2)].attributes).code);
                (yyval.attributes).code=strdup(temp);
                (yyval.attributes).varn="";
            ;}
    break;

  case 5:
#line 159 "a.y"
    {
                (yyval.attributes).code=strdup((yyvsp[(1) - (1)].attributes).code);
                (yyval.attributes).varn="";
            ;}
    break;

  case 6:
#line 164 "a.y"
    {
                (yyval.attributes).code="";
                (yyval.attributes).varn="";
            ;}
    break;

  case 7:
#line 169 "a.y"
    {
                
                (yyval.attributes).code=strdup((yyvsp[(1) - (1)].attributes).code);
                (yyval.attributes).varn="";
            ;}
    break;

  case 8:
#line 176 "a.y"
    {
             
                (yyval.attributes).code=strdup((yyvsp[(1) - (1)].attributes).code);
            ;}
    break;

  case 9:
#line 182 "a.y"
    {
                (yyval.attributes).code=strdup((yyvsp[(1) - (1)].attributes).code);
            ;}
    break;

  case 10:
#line 187 "a.y"
    {
                
                (yyval.attributes).code ="";
                (yyval.attributes).varn="";
            ;}
    break;

  case 11:
#line 194 "a.y"
    {
                
                char temp[5000];
                if(strcmp((yyvsp[(2) - (2)].exprAttr).op,"-")==0)
                {
                    (yyval.attributes).varn = (yyvsp[(1) - (2)].attributes).varn;
                    sprintf(temp,"%s\n",(yyvsp[(1) - (2)].attributes).code);
                    //sprintf(temp,"%s\n%s\nmov ax,%s\nmov %s,ax\n",$1.code,$2.code,$1.varn,$$.varn);
                }
                else
                {
                    (yyval.attributes).varn = NewTempName();
                    sprintf(temp,"%s\n%s\nmov ax,%s\nmov bx,%s\n%s ax,bx\nmov %s,ax",(yyvsp[(1) - (2)].attributes).code,(yyvsp[(2) - (2)].exprAttr).code,(yyvsp[(1) - (2)].attributes).varn,(yyvsp[(2) - (2)].exprAttr).varn,(yyvsp[(2) - (2)].exprAttr).op,(yyval.attributes).varn);
                }
                (yyval.attributes).code=strdup(temp);
            ;}
    break;

  case 12:
#line 211 "a.y"
    {
                (yyval.exprAttr).op="add";
                (yyval.exprAttr).varn=NewTempName();
                char temp[5000];
                sprintf(temp,"%s\nmov ax,%s\nmov %s,ax\n",(yyvsp[(2) - (2)].attributes).code,(yyvsp[(2) - (2)].attributes).varn,(yyval.exprAttr).varn);
                (yyval.exprAttr).code=strdup(temp);
            ;}
    break;

  case 13:
#line 219 "a.y"
    {
                (yyval.exprAttr).op="sub";
                (yyval.exprAttr).varn=NewTempName();
                char temp[1000];
                sprintf(temp,"%s\nmov ax,%s\nmov %s,ax\n",(yyvsp[(2) - (2)].attributes).code,(yyvsp[(2) - (2)].attributes).varn,(yyval.exprAttr).varn);
                (yyval.exprAttr).code=strdup(temp);
            ;}
    break;

  case 14:
#line 227 "a.y"
    {
                (yyval.exprAttr).varn="",(yyval.exprAttr).code="";(yyval.exprAttr).op="-";
            ;}
    break;

  case 15:
#line 232 "a.y"
    {
                
                char temp[5000];
                if(strcmp((yyvsp[(2) - (2)].exprAttr).op,"-")==0)
                {
                    sprintf(temp,"%s\n",(yyvsp[(1) - (2)].attributes).code);
                    (yyval.attributes).varn = (yyvsp[(1) - (2)].attributes).varn;
                }
                else
                {
                    (yyval.attributes).varn=NewTempName();
                    sprintf(temp,"%s\n%s\nmov ax,%s\nmov bx,%s\n%s bx\nmov %s,ax\n",(yyvsp[(1) - (2)].attributes).code,(yyvsp[(2) - (2)].exprAttr).code,(yyvsp[(1) - (2)].attributes).varn,(yyvsp[(2) - (2)].exprAttr).varn,(yyvsp[(2) - (2)].exprAttr).op,(yyval.attributes).varn);
                }
                (yyval.attributes).code=strdup(temp);
            ;}
    break;

  case 16:
#line 248 "a.y"
    {
                (yyval.exprAttr).op="mul";
                (yyval.exprAttr).varn=NewTempName();
                char temp[5000];
                sprintf(temp,"%s\nmov ax,%s\nmov %s,ax\n",(yyvsp[(2) - (2)].attributes).code,(yyvsp[(2) - (2)].attributes).varn,(yyval.exprAttr).varn);
                (yyval.exprAttr).code=strdup(temp);
            ;}
    break;

  case 17:
#line 256 "a.y"
    {
                (yyval.exprAttr).op="div";
                (yyval.exprAttr).varn=NewTempName();
                char temp[5000];
                sprintf(temp,"%s\nmov ax,%s\nmov %s,ax\n",(yyvsp[(2) - (2)].attributes).code,(yyvsp[(2) - (2)].attributes).varn,(yyval.exprAttr).varn);
                (yyval.exprAttr).code=strdup(temp);   
            ;}
    break;

  case 18:
#line 264 "a.y"
    {   
                (yyval.exprAttr).varn="";(yyval.exprAttr).code="";(yyval.exprAttr).op="-";
            ;}
    break;

  case 19:
#line 268 "a.y"
    {
                (yyval.attributes).varn = strdup((yyvsp[(1) - (1)].attributes).varn);
                (yyval.attributes).code="";
            ;}
    break;

  case 20:
#line 273 "a.y"
    {   
                char temp[10];
                sprintf(temp,"%d",(yyvsp[(1) - (1)].intval));
                (yyval.attributes).varn = strdup(temp);
                (yyval.attributes).code="";
            ;}
    break;

  case 21:
#line 280 "a.y"
    {
                char temp[1000];
                (yyval.attributes).varn=NewTempName();
                sprintf(temp,"%s\nmov ax,%s\nmov %s,ax",(yyvsp[(2) - (3)].attributes).code,(yyvsp[(2) - (3)].attributes).varn,(yyval.attributes).varn);
                (yyval.attributes).code=strdup(temp);

            ;}
    break;

  case 22:
#line 289 "a.y"
    {
            /*  
                mov ax,expression1.varn
                mov bx,expression2.varn
                cmp ax,bx
                j.. labeli
                stmt_list.code
                labeli:
            */
                
                char* temp = malloc(1000*sizeof(char));
                char* lbl = NewLabelName();
                sprintf(temp,"%s%s\n%s\n%s:\n",(yyvsp[(3) - (7)].attributes).code,lbl,(yyvsp[(6) - (7)].attributes).code,lbl);
                (yyval.attributes).code=strdup(temp);
                //free(temp);
                //$$.varn="";
        ;}
    break;

  case 23:
#line 309 "a.y"
    {
            
            char temp[500];
            
            sprintf(temp,"%s\nmov ax,%s\nmov %s,ax\n",(yyvsp[(3) - (4)].attributes).code,(yyvsp[(3) - (4)].attributes).varn,(yyvsp[(1) - (4)].attributes).varn);
            (yyval.attributes).code=strdup(temp);
        ;}
    break;

  case 24:
#line 318 "a.y"
    {
            
            (yyval.attributes).varn="";
            char temp[100];
            sprintf(temp,"mov ax,%s\ncall disp",(yyvsp[(3) - (4)].attributes).varn);
            (yyval.attributes).code=strdup(temp);
        ;}
    break;

  case 25:
#line 327 "a.y"
    {
            (yyval.attributes).varn="";
            char temp[100];
            sprintf(temp,"call readInput\nmov %s,bx\n",(yyvsp[(3) - (4)].attributes).varn);
            (yyval.attributes).code=strdup(temp);
        ;}
    break;

  case 26:
#line 334 "a.y"
    {   
            
            char* temp = malloc(1000*sizeof(char));

            sprintf(temp,"\t%s dw ?\n",(yyvsp[(2) - (3)].attributes).varn);
            
            strcat(temp,vars);
            
            vars = strdup(temp);
            (yyval.attributes).code="";
            (yyval.attributes).varn="";
            free(temp);
        ;}
    break;

  case 27:
#line 349 "a.y"
    {
            /*
                mov ax,expression1.varn
                mov bx,expression2.varn
                cmp ax,bx
                boolOp.code 
            */
            
            char* temp =malloc(1000*sizeof(char));
            sprintf(temp,"%s\n%s\nmov ax,%s\nmov bx,%s\ncmp ax,bx\n%s ",(yyvsp[(1) - (3)].attributes).code,(yyvsp[(3) - (3)].attributes).code,(yyvsp[(1) - (3)].attributes).varn,(yyvsp[(3) - (3)].attributes).varn,(yyvsp[(2) - (3)].attributes).code);
            (yyval.attributes).code=strdup(temp);
            free(temp);
            (yyval.attributes).varn="";
        ;}
    break;

  case 28:
#line 365 "a.y"
    {
            (yyval.attributes).code = "jle";
            (yyval.attributes).varn="";
         ;}
    break;

  case 29:
#line 370 "a.y"
    {
            (yyval.attributes).code = "jge";
            (yyval.attributes).varn="";
        ;}
    break;

  case 30:
#line 376 "a.y"
    {
            (yyval.attributes).code = "jne";
            (yyval.attributes).varn="";
        ;}
    break;

  case 31:
#line 382 "a.y"
    {
            (yyval.attributes).code = "je";
            (yyval.attributes).varn="";
        ;}
    break;


/* Line 1267 of yacc.c.  */
#line 1820 "a.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 386 "a.y"

int main(int argc, char *argv[]) {
    ++argv, --argc; 

    if (argc > 0){
        yyin = fopen(argv[0], "r"); 
        int c;
        FILE *file;
//        printf("Source code: \n");
//        file = fopen(argv[0], "r");
//        if (file) {
//            while ((c = getc(file)) != EOF)
//                putchar(c);
//            fclose(file);
//        }
    }
    else 
        yyin = stdin; 
    while (!feof(yyin)) {
        yyparse();
    }
    printf("The file is syntactically correct!\n");
    FILE *file = fopen("out.asm", "w");
    
    int results = fputs(result, file);
    if (results == EOF) {
        //error
    }
    fclose(file);
    return 0;
}

void yyerror(const char *s) {
    printf("Error: %s at line -> %d ! \n", s, line);
    exit(1);
}

