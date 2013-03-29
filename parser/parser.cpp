/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2012 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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
#define YYBISON_VERSION "2.7"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
/* Line 371 of yacc.c  */
#line 2 "shimmr.y"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include "Absyn.H"
int yyparse(void);
int yylex(void);
int yy_mylinenumber;
int initialize_lexer(FILE * inp);
int yywrap(void)
{
  return 1;
}
void yyerror(const char *str)
{
  std::cout << "line " << yy_mylinenumber + 1 << std::endl ;
  fprintf(stderr,"error: %s\n",str);
}


Program* YY_RESULT_Program_ = 0;
Program* pProgram(FILE *inp)
{
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_Program_;
  }
}

StatementBlock* YY_RESULT_StatementBlock_ = 0;
StatementBlock* pStatementBlock(FILE *inp)
{
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_StatementBlock_;
  }
}

ListStatement* YY_RESULT_ListStatement_ = 0;
ListStatement* pListStatement(FILE *inp)
{
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_ListStatement_;
  }
}

Statement* YY_RESULT_Statement_ = 0;
Statement* pStatement(FILE *inp)
{
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_Statement_;
  }
}

Decl* YY_RESULT_Decl_ = 0;
Decl* pDecl(FILE *inp)
{
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_Decl_;
  }
}

ElseBlock* YY_RESULT_ElseBlock_ = 0;
ElseBlock* pElseBlock(FILE *inp)
{
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_ElseBlock_;
  }
}

Exp* YY_RESULT_Exp_ = 0;
Exp* pExp(FILE *inp)
{
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_Exp_;
  }
}

Argument* YY_RESULT_Argument_ = 0;
Argument* pArgument(FILE *inp)
{
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_Argument_;
  }
}

ListArgument* YY_RESULT_ListArgument_ = 0;
ListArgument* pListArgument(FILE *inp)
{
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_ListArgument_;
  }
}

ListExp* YY_RESULT_ListExp_ = 0;
ListExp* pListExp(FILE *inp)
{
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_ListExp_;
  }
}

Type* YY_RESULT_Type_ = 0;
Type* pType(FILE *inp)
{
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_Type_;
  }
}

SetTypeElem* YY_RESULT_SetTypeElem_ = 0;
SetTypeElem* pSetTypeElem(FILE *inp)
{
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_SetTypeElem_;
  }
}

ListSetTypeElem* YY_RESULT_ListSetTypeElem_ = 0;
ListSetTypeElem* pListSetTypeElem(FILE *inp)
{
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_ListSetTypeElem_;
  }
}

LExpr* YY_RESULT_LExpr_ = 0;
LExpr* pLExpr(FILE *inp)
{
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_LExpr_;
  }
}


ListStatement* reverseListStatement(ListStatement *l)
{
  ListStatement *prev = 0;
  ListStatement *tmp = 0;
  while (l)
  {
    tmp = l->liststatement_;
    l->liststatement_ = prev;
    prev = l;
    l = tmp;
  }
  return prev;
}
ListArgument* reverseListArgument(ListArgument *l)
{
  ListArgument *prev = 0;
  ListArgument *tmp = 0;
  while (l)
  {
    tmp = l->listargument_;
    l->listargument_ = prev;
    prev = l;
    l = tmp;
  }
  return prev;
}
ListExp* reverseListExp(ListExp *l)
{
  ListExp *prev = 0;
  ListExp *tmp = 0;
  while (l)
  {
    tmp = l->listexp_;
    l->listexp_ = prev;
    prev = l;
    l = tmp;
  }
  return prev;
}
ListSetTypeElem* reverseListSetTypeElem(ListSetTypeElem *l)
{
  ListSetTypeElem *prev = 0;
  ListSetTypeElem *tmp = 0;
  while (l)
  {
    tmp = l->listsettypeelem_;
    l->listsettypeelem_ = prev;
    prev = l;
    l = tmp;
  }
  return prev;
}


/* Line 371 of yacc.c  */
#line 341 "parser.cpp"

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     _ERROR_ = 258,
     _SYMB_0 = 259,
     _SYMB_1 = 260,
     _SYMB_2 = 261,
     _SYMB_3 = 262,
     _SYMB_4 = 263,
     _SYMB_5 = 264,
     _SYMB_6 = 265,
     _SYMB_7 = 266,
     _SYMB_8 = 267,
     _SYMB_9 = 268,
     _SYMB_10 = 269,
     _SYMB_11 = 270,
     _SYMB_12 = 271,
     _SYMB_13 = 272,
     _SYMB_14 = 273,
     _SYMB_15 = 274,
     _SYMB_16 = 275,
     _SYMB_17 = 276,
     _SYMB_18 = 277,
     _SYMB_19 = 278,
     _SYMB_20 = 279,
     _SYMB_21 = 280,
     _SYMB_22 = 281,
     _SYMB_23 = 282,
     _SYMB_24 = 283,
     _SYMB_25 = 284,
     _SYMB_26 = 285,
     _SYMB_27 = 286,
     _SYMB_28 = 287,
     _SYMB_29 = 288,
     _SYMB_30 = 289,
     _SYMB_31 = 290,
     __STRING_ = 291,
     _INTEGER_ = 292,
     _DOUBLE_ = 293,
     _IDENT_ = 294
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 387 of yacc.c  */
#line 276 "shimmr.y"

  int int_;
  char char_;
  double double_;
  char* string_;
  Program* program_;
  StatementBlock* statementblock_;
  ListStatement* liststatement_;
  Statement* statement_;
  Decl* decl_;
  ElseBlock* elseblock_;
  Exp* exp_;
  Argument* argument_;
  ListArgument* listargument_;
  ListExp* listexp_;
  Type* type_;
  SetTypeElem* settypeelem_;
  ListSetTypeElem* listsettypeelem_;
  LExpr* lexpr_;



/* Line 387 of yacc.c  */
#line 443 "parser.cpp"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

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



/* Copy the second part of user declarations.  */

/* Line 390 of yacc.c  */
#line 471 "parser.cpp"

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
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(N) (N)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
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
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
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
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  38
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   151

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  40
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  22
/* YYNRULES -- Number of rules.  */
#define YYNRULES  71
/* YYNRULES -- Number of states.  */
#define YYNSTATES  142

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   294

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     9,    10,    12,    16,    18,    26,
      32,    39,    47,    56,    62,    66,    68,    73,    79,    86,
      94,    98,   105,   113,   120,   128,   131,   134,   138,   140,
     144,   146,   150,   154,   156,   160,   164,   168,   172,   174,
     178,   182,   184,   188,   192,   194,   197,   199,   201,   206,
     208,   210,   212,   216,   219,   220,   222,   226,   227,   229,
     233,   235,   240,   244,   248,   250,   252,   254,   255,   257,
     261,   263
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      41,     0,    -1,    43,    -1,     4,    43,     5,    -1,    -1,
      44,    -1,    44,     6,    43,    -1,    45,    -1,    30,     8,
      39,    32,    47,     9,    42,    -1,    31,     8,    47,     9,
      42,    -1,    31,     8,    47,     9,    42,    46,    -1,    33,
       8,    39,    32,    47,     9,    42,    -1,    33,     8,    39,
      32,    47,     9,    42,    46,    -1,    61,     7,    47,    35,
      47,    -1,    61,     7,    47,    -1,    47,    -1,    34,    39,
       7,    47,    -1,    34,    58,    39,     7,    47,    -1,    34,
      39,     7,    47,    35,    47,    -1,    34,    58,    39,     7,
      47,    35,    47,    -1,    34,    58,    39,    -1,    27,    39,
       8,    56,     9,    42,    -1,    27,    58,    39,     8,    56,
       9,    42,    -1,    28,    31,     8,    47,     9,    42,    -1,
      28,    31,     8,    47,     9,    42,    46,    -1,    28,    42,
      -1,    28,    29,    -1,    47,    10,    48,    -1,    48,    -1,
      48,    11,    49,    -1,    49,    -1,    49,    12,    50,    -1,
      49,    13,    50,    -1,    50,    -1,    50,    14,    51,    -1,
      50,    15,    51,    -1,    50,    16,    51,    -1,    50,    17,
      51,    -1,    51,    -1,    51,    18,    52,    -1,    51,    19,
      52,    -1,    52,    -1,    52,    20,    53,    -1,    52,    21,
      53,    -1,    53,    -1,    22,    54,    -1,    54,    -1,    39,
      -1,    39,     8,    57,     9,    -1,    37,    -1,    38,    -1,
      36,    -1,     8,    47,     9,    -1,    58,    39,    -1,    -1,
      55,    -1,    55,    23,    56,    -1,    -1,    47,    -1,    47,
      23,    57,    -1,    39,    -1,    58,    24,    58,    25,    -1,
      37,    26,    37,    -1,     4,    60,     5,    -1,    37,    -1,
      38,    -1,    36,    -1,    -1,    59,    -1,    59,    23,    60,
      -1,    39,    -1,    61,    24,    57,    25,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   360,   360,   362,   364,   365,   366,   368,   369,   370,
     371,   372,   373,   374,   375,   376,   378,   379,   380,   381,
     382,   383,   384,   386,   387,   388,   389,   391,   392,   394,
     395,   397,   398,   399,   401,   402,   403,   404,   405,   407,
     408,   409,   411,   412,   413,   415,   416,   418,   419,   420,
     421,   422,   423,   425,   427,   428,   429,   431,   432,   433,
     435,   436,   437,   438,   440,   441,   442,   444,   445,   446,
     448,   449
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "_ERROR_", "_SYMB_0", "_SYMB_1",
  "_SYMB_2", "_SYMB_3", "_SYMB_4", "_SYMB_5", "_SYMB_6", "_SYMB_7",
  "_SYMB_8", "_SYMB_9", "_SYMB_10", "_SYMB_11", "_SYMB_12", "_SYMB_13",
  "_SYMB_14", "_SYMB_15", "_SYMB_16", "_SYMB_17", "_SYMB_18", "_SYMB_19",
  "_SYMB_20", "_SYMB_21", "_SYMB_22", "_SYMB_23", "_SYMB_24", "_SYMB_25",
  "_SYMB_26", "_SYMB_27", "_SYMB_28", "_SYMB_29", "_SYMB_30", "_SYMB_31",
  "__STRING_", "_INTEGER_", "_DOUBLE_", "_IDENT_", "$accept", "Program",
  "StatementBlock", "ListStatement", "Statement", "Decl", "ElseBlock",
  "Exp", "Exp1", "Exp2", "Exp3", "Exp4", "Exp5", "Exp6", "Exp7",
  "Argument", "ListArgument", "ListExp", "Type", "SetTypeElem",
  "ListSetTypeElem", "LExpr", YY_NULL
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    40,    41,    42,    43,    43,    43,    44,    44,    44,
      44,    44,    44,    44,    44,    44,    45,    45,    45,    45,
      45,    45,    45,    46,    46,    46,    46,    47,    47,    48,
      48,    49,    49,    49,    50,    50,    50,    50,    50,    51,
      51,    51,    52,    52,    52,    53,    53,    54,    54,    54,
      54,    54,    54,    55,    56,    56,    56,    57,    57,    57,
      58,    58,    58,    58,    59,    59,    59,    60,    60,    60,
      61,    61
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     3,     0,     1,     3,     1,     7,     5,
       6,     7,     8,     5,     3,     1,     4,     5,     6,     7,
       3,     6,     7,     6,     7,     2,     2,     3,     1,     3,
       1,     3,     3,     1,     3,     3,     3,     3,     1,     3,
       3,     1,     3,     3,     1,     2,     1,     1,     4,     1,
       1,     1,     3,     2,     0,     1,     3,     0,     1,     3,
       1,     4,     3,     3,     1,     1,     1,     0,     1,     3,
       1,     4
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,     0,     0,     0,     0,     0,     0,    51,    49,
      50,    47,     0,     2,     5,     7,    15,    28,    30,    33,
      38,    41,    44,    46,     0,    47,     0,    45,    67,     0,
      60,     0,     0,     0,     0,    60,     0,    57,     1,     4,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    57,    52,    66,    64,    65,    68,     0,
       0,    54,     0,     0,     0,     0,     0,     0,    20,    58,
       0,     6,    27,    29,    31,    32,    34,    35,    36,    37,
      39,    40,    42,    43,    14,     0,    67,    63,    62,    60,
      55,     0,     0,     0,    54,     0,     0,     0,    16,     0,
      57,    48,     0,    71,    69,    54,     0,    53,    61,     0,
       0,     4,     9,     0,     0,    17,    59,    13,    56,    21,
       0,     0,     0,     0,    10,     0,    18,     0,    22,     8,
       3,    26,     0,    25,    11,    19,     0,    12,     0,     0,
      23,    24
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    12,   112,    13,    14,    15,   124,    16,    17,    18,
      19,    20,    21,    22,    23,    90,    91,    70,    92,    58,
      59,    24
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -103
static const yytype_int16 yypact[] =
{
      38,    42,    17,     1,     9,    16,    20,     2,  -103,  -103,
    -103,     3,    48,  -103,    57,  -103,    76,    84,    90,    68,
      86,    87,  -103,  -103,     6,    89,   100,  -103,    55,   -14,
      92,   -10,    67,    42,    75,   118,    -8,    42,  -103,    38,
      42,    42,    42,    42,    42,    42,    42,    42,    42,    42,
      42,    42,    42,    42,  -103,  -103,  -103,  -103,   106,   127,
      96,     5,     5,   126,   104,   102,   105,    42,   131,    47,
     130,  -103,    84,    90,    68,    68,    86,    86,    86,    86,
      87,    87,  -103,  -103,    10,   115,    55,  -103,  -103,  -103,
     119,   132,    19,    91,     5,    42,   139,    42,    12,    42,
      42,  -103,    42,  -103,  -103,     5,   139,  -103,  -103,   135,
     108,    38,   117,   110,    42,    24,  -103,    76,  -103,  -103,
     139,   139,   141,     4,  -103,   139,    76,    42,  -103,  -103,
    -103,  -103,   140,  -103,   117,    76,    42,  -103,   112,   139,
     117,  -103
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -103,  -103,  -102,   -38,  -103,  -103,   -73,    -1,   107,   109,
      81,    43,    79,    80,   147,  -103,   -79,   -51,     0,  -103,
      65,  -103
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -71
static const yytype_int16 yytable[] =
{
      26,    71,    85,    31,   119,    28,    28,    36,   111,    28,
     -70,    37,    60,    52,    62,   109,    62,    32,   128,   129,
      40,   133,    40,   134,    33,     1,   118,   -70,    34,    63,
      53,    68,    65,   131,    40,   132,    69,   140,    29,    29,
      30,    35,    29,    62,    89,   102,     1,   114,    38,   116,
       1,    84,    69,     8,     9,    10,    25,    40,   107,   127,
       2,   137,    93,    39,     2,     3,    98,   141,     4,     5,
     100,     6,     7,   122,     8,     9,    10,    11,     8,     9,
      10,    25,    44,    45,    46,    47,    40,    76,    77,    78,
      79,    55,    56,    57,   110,    41,   113,    37,   115,    69,
      61,   117,    42,    43,    48,    49,    64,    50,    51,    54,
      40,    96,    40,   126,    66,    62,   108,   121,    40,   125,
      40,   139,    40,    74,    75,    67,   135,    80,    81,    86,
      82,    83,    87,    88,    94,   138,    95,    97,    99,   101,
     103,   106,   105,   111,   120,   123,   130,    72,   136,    27,
      73,   104
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-103)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_uint8 yycheck[] =
{
       1,    39,    53,     3,   106,     4,     4,     7,     4,     4,
       7,     8,    26,     7,    24,    94,    24,     8,   120,   121,
      10,   123,    10,   125,     8,     8,   105,    24,     8,    39,
      24,    39,    33,    29,    10,    31,    37,   139,    37,    37,
      39,    39,    37,    24,    39,    35,     8,    35,     0,   100,
       8,    52,    53,    36,    37,    38,    39,    10,    39,    35,
      22,   134,    62,     6,    22,    27,    67,   140,    30,    31,
      23,    33,    34,   111,    36,    37,    38,    39,    36,    37,
      38,    39,    14,    15,    16,    17,    10,    44,    45,    46,
      47,    36,    37,    38,    95,    11,    97,     8,    99,   100,
       8,   102,    12,    13,    18,    19,    39,    20,    21,     9,
      10,     9,    10,   114,    39,    24,    25,     9,    10,     9,
      10,     9,    10,    42,    43,     7,   127,    48,    49,    23,
      50,    51,     5,    37,     8,   136,    32,    32,     7,     9,
      25,     9,    23,     4,     9,    28,     5,    40,     8,     2,
      41,    86
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     8,    22,    27,    30,    31,    33,    34,    36,    37,
      38,    39,    41,    43,    44,    45,    47,    48,    49,    50,
      51,    52,    53,    54,    61,    39,    47,    54,     4,    37,
      39,    58,     8,     8,     8,    39,    58,     8,     0,     6,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,     7,    24,     9,    36,    37,    38,    59,    60,
      26,     8,    24,    39,    39,    47,    39,     7,    39,    47,
      57,    43,    48,    49,    50,    50,    51,    51,    51,    51,
      52,    52,    53,    53,    47,    57,    23,     5,    37,    39,
      55,    56,    58,    58,     8,    32,     9,    32,    47,     7,
      23,     9,    35,    25,    60,    23,     9,    39,    25,    56,
      47,     4,    42,    47,    35,    47,    57,    47,    56,    42,
       9,     9,    43,    28,    46,     9,    47,    35,    42,    42,
       5,    29,    31,    42,    42,    47,     8,    46,    47,     9,
      42,    46
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
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))

/* Error token number */
#define YYTERROR	1
#define YYERRCODE	256


/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
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
  FILE *yyo = yyoutput;
  YYUSE (yyo);
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
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
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
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
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
#  if defined __GLIBC__ && defined __STRING_H
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
#  if defined __GLIBC__ && defined __STRING_H && defined _GNU_SOURCE
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

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
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




/* The lookahead symbol.  */
int yychar;


#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval YY_INITIAL_VALUE(yyval_default);

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
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
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
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
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

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
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
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
/* Line 1792 of yacc.c  */
#line 360 "shimmr.y"
    { (yyval.program_) = new Statements((yyvsp[(1) - (1)].liststatement_)); YY_RESULT_Program_= (yyval.program_); }
    break;

  case 3:
/* Line 1792 of yacc.c  */
#line 362 "shimmr.y"
    { (yyval.statementblock_) = new StatementBlockStat((yyvsp[(2) - (3)].liststatement_)); YY_RESULT_StatementBlock_= (yyval.statementblock_); }
    break;

  case 4:
/* Line 1792 of yacc.c  */
#line 364 "shimmr.y"
    { (yyval.liststatement_) = 0; YY_RESULT_ListStatement_= (yyval.liststatement_); }
    break;

  case 5:
/* Line 1792 of yacc.c  */
#line 365 "shimmr.y"
    { (yyval.liststatement_) = new ListStatement((yyvsp[(1) - (1)].statement_)); YY_RESULT_ListStatement_= (yyval.liststatement_); }
    break;

  case 6:
/* Line 1792 of yacc.c  */
#line 366 "shimmr.y"
    { (yyval.liststatement_) = new ListStatement((yyvsp[(1) - (3)].statement_), (yyvsp[(3) - (3)].liststatement_)); YY_RESULT_ListStatement_= (yyval.liststatement_); }
    break;

  case 7:
/* Line 1792 of yacc.c  */
#line 368 "shimmr.y"
    { (yyval.statement_) = new DeclStat((yyvsp[(1) - (1)].decl_)); YY_RESULT_Statement_= (yyval.statement_); }
    break;

  case 8:
/* Line 1792 of yacc.c  */
#line 369 "shimmr.y"
    { (yyval.statement_) = new ForStatement((yyvsp[(3) - (7)].string_), (yyvsp[(5) - (7)].exp_), (yyvsp[(7) - (7)].statementblock_)); YY_RESULT_Statement_= (yyval.statement_); }
    break;

  case 9:
/* Line 1792 of yacc.c  */
#line 370 "shimmr.y"
    { (yyval.statement_) = new IfStatement((yyvsp[(3) - (5)].exp_), (yyvsp[(5) - (5)].statementblock_)); YY_RESULT_Statement_= (yyval.statement_); }
    break;

  case 10:
/* Line 1792 of yacc.c  */
#line 371 "shimmr.y"
    { (yyval.statement_) = new IfElseStatement((yyvsp[(3) - (6)].exp_), (yyvsp[(5) - (6)].statementblock_), (yyvsp[(6) - (6)].elseblock_)); YY_RESULT_Statement_= (yyval.statement_); }
    break;

  case 11:
/* Line 1792 of yacc.c  */
#line 372 "shimmr.y"
    { (yyval.statement_) = new SomeStatement((yyvsp[(3) - (7)].string_), (yyvsp[(5) - (7)].exp_), (yyvsp[(7) - (7)].statementblock_)); YY_RESULT_Statement_= (yyval.statement_); }
    break;

  case 12:
/* Line 1792 of yacc.c  */
#line 373 "shimmr.y"
    { (yyval.statement_) = new SomeElseStatement((yyvsp[(3) - (8)].string_), (yyvsp[(5) - (8)].exp_), (yyvsp[(7) - (8)].statementblock_), (yyvsp[(8) - (8)].elseblock_)); YY_RESULT_Statement_= (yyval.statement_); }
    break;

  case 13:
/* Line 1792 of yacc.c  */
#line 374 "shimmr.y"
    { (yyval.statement_) = new ConditionalStatement((yyvsp[(1) - (5)].lexpr_), (yyvsp[(3) - (5)].exp_), (yyvsp[(5) - (5)].exp_)); YY_RESULT_Statement_= (yyval.statement_); }
    break;

  case 14:
/* Line 1792 of yacc.c  */
#line 375 "shimmr.y"
    { (yyval.statement_) = new AbsoluteStatement((yyvsp[(1) - (3)].lexpr_), (yyvsp[(3) - (3)].exp_)); YY_RESULT_Statement_= (yyval.statement_); }
    break;

  case 15:
/* Line 1792 of yacc.c  */
#line 376 "shimmr.y"
    { (yyval.statement_) = new ExpAsStatement((yyvsp[(1) - (1)].exp_)); YY_RESULT_Statement_= (yyval.statement_); }
    break;

  case 16:
/* Line 1792 of yacc.c  */
#line 378 "shimmr.y"
    { (yyval.decl_) = new SimpleDecl((yyvsp[(2) - (4)].string_), (yyvsp[(4) - (4)].exp_)); YY_RESULT_Decl_= (yyval.decl_); }
    break;

  case 17:
/* Line 1792 of yacc.c  */
#line 379 "shimmr.y"
    { (yyval.decl_) = new TypedDecl((yyvsp[(2) - (5)].type_), (yyvsp[(3) - (5)].string_), (yyvsp[(5) - (5)].exp_)); YY_RESULT_Decl_= (yyval.decl_); }
    break;

  case 18:
/* Line 1792 of yacc.c  */
#line 380 "shimmr.y"
    { (yyval.decl_) = new SimpleDeclWith((yyvsp[(2) - (6)].string_), (yyvsp[(4) - (6)].exp_), (yyvsp[(6) - (6)].exp_)); YY_RESULT_Decl_= (yyval.decl_); }
    break;

  case 19:
/* Line 1792 of yacc.c  */
#line 381 "shimmr.y"
    { (yyval.decl_) = new TypedDeclWith((yyvsp[(2) - (7)].type_), (yyvsp[(3) - (7)].string_), (yyvsp[(5) - (7)].exp_), (yyvsp[(7) - (7)].exp_)); YY_RESULT_Decl_= (yyval.decl_); }
    break;

  case 20:
/* Line 1792 of yacc.c  */
#line 382 "shimmr.y"
    { (yyval.decl_) = new BareDecl((yyvsp[(2) - (3)].type_), (yyvsp[(3) - (3)].string_)); YY_RESULT_Decl_= (yyval.decl_); }
    break;

  case 21:
/* Line 1792 of yacc.c  */
#line 383 "shimmr.y"
    { (yyval.decl_) = new EFuncDecl((yyvsp[(2) - (6)].string_), (yyvsp[(4) - (6)].listargument_), (yyvsp[(6) - (6)].statementblock_)); YY_RESULT_Decl_= (yyval.decl_); }
    break;

  case 22:
/* Line 1792 of yacc.c  */
#line 384 "shimmr.y"
    { (yyval.decl_) = new EFuncDeclWithType((yyvsp[(2) - (7)].type_), (yyvsp[(3) - (7)].string_), (yyvsp[(5) - (7)].listargument_), (yyvsp[(7) - (7)].statementblock_)); YY_RESULT_Decl_= (yyval.decl_); }
    break;

  case 23:
/* Line 1792 of yacc.c  */
#line 386 "shimmr.y"
    { (yyval.elseblock_) = new ElseIfBlock((yyvsp[(4) - (6)].exp_), (yyvsp[(6) - (6)].statementblock_)); YY_RESULT_ElseBlock_= (yyval.elseblock_); }
    break;

  case 24:
/* Line 1792 of yacc.c  */
#line 387 "shimmr.y"
    { (yyval.elseblock_) = new ElseIf2Block((yyvsp[(4) - (7)].exp_), (yyvsp[(6) - (7)].statementblock_), (yyvsp[(7) - (7)].elseblock_)); YY_RESULT_ElseBlock_= (yyval.elseblock_); }
    break;

  case 25:
/* Line 1792 of yacc.c  */
#line 388 "shimmr.y"
    { (yyval.elseblock_) = new ElseBlockStat((yyvsp[(2) - (2)].statementblock_)); YY_RESULT_ElseBlock_= (yyval.elseblock_); }
    break;

  case 26:
/* Line 1792 of yacc.c  */
#line 389 "shimmr.y"
    { (yyval.elseblock_) = new ElseFailStat(); YY_RESULT_ElseBlock_= (yyval.elseblock_); }
    break;

  case 27:
/* Line 1792 of yacc.c  */
#line 391 "shimmr.y"
    { (yyval.exp_) = new EOr((yyvsp[(1) - (3)].exp_), (yyvsp[(3) - (3)].exp_)); YY_RESULT_Exp_= (yyval.exp_); }
    break;

  case 28:
/* Line 1792 of yacc.c  */
#line 392 "shimmr.y"
    { (yyval.exp_) = (yyvsp[(1) - (1)].exp_); YY_RESULT_Exp_= (yyval.exp_); }
    break;

  case 29:
/* Line 1792 of yacc.c  */
#line 394 "shimmr.y"
    { (yyval.exp_) = new EAnd((yyvsp[(1) - (3)].exp_), (yyvsp[(3) - (3)].exp_)); YY_RESULT_Exp_= (yyval.exp_); }
    break;

  case 30:
/* Line 1792 of yacc.c  */
#line 395 "shimmr.y"
    { (yyval.exp_) = (yyvsp[(1) - (1)].exp_); YY_RESULT_Exp_= (yyval.exp_); }
    break;

  case 31:
/* Line 1792 of yacc.c  */
#line 397 "shimmr.y"
    { (yyval.exp_) = new EEquals((yyvsp[(1) - (3)].exp_), (yyvsp[(3) - (3)].exp_)); YY_RESULT_Exp_= (yyval.exp_); }
    break;

  case 32:
/* Line 1792 of yacc.c  */
#line 398 "shimmr.y"
    { (yyval.exp_) = new ENEq((yyvsp[(1) - (3)].exp_), (yyvsp[(3) - (3)].exp_)); YY_RESULT_Exp_= (yyval.exp_); }
    break;

  case 33:
/* Line 1792 of yacc.c  */
#line 399 "shimmr.y"
    { (yyval.exp_) = (yyvsp[(1) - (1)].exp_); YY_RESULT_Exp_= (yyval.exp_); }
    break;

  case 34:
/* Line 1792 of yacc.c  */
#line 401 "shimmr.y"
    { (yyval.exp_) = new ELeq((yyvsp[(1) - (3)].exp_), (yyvsp[(3) - (3)].exp_)); YY_RESULT_Exp_= (yyval.exp_); }
    break;

  case 35:
/* Line 1792 of yacc.c  */
#line 402 "shimmr.y"
    { (yyval.exp_) = new EGeq((yyvsp[(1) - (3)].exp_), (yyvsp[(3) - (3)].exp_)); YY_RESULT_Exp_= (yyval.exp_); }
    break;

  case 36:
/* Line 1792 of yacc.c  */
#line 403 "shimmr.y"
    { (yyval.exp_) = new ELessThan((yyvsp[(1) - (3)].exp_), (yyvsp[(3) - (3)].exp_)); YY_RESULT_Exp_= (yyval.exp_); }
    break;

  case 37:
/* Line 1792 of yacc.c  */
#line 404 "shimmr.y"
    { (yyval.exp_) = new EGreaterThan((yyvsp[(1) - (3)].exp_), (yyvsp[(3) - (3)].exp_)); YY_RESULT_Exp_= (yyval.exp_); }
    break;

  case 38:
/* Line 1792 of yacc.c  */
#line 405 "shimmr.y"
    { (yyval.exp_) = (yyvsp[(1) - (1)].exp_); YY_RESULT_Exp_= (yyval.exp_); }
    break;

  case 39:
/* Line 1792 of yacc.c  */
#line 407 "shimmr.y"
    { (yyval.exp_) = new EAdd((yyvsp[(1) - (3)].exp_), (yyvsp[(3) - (3)].exp_)); YY_RESULT_Exp_= (yyval.exp_); }
    break;

  case 40:
/* Line 1792 of yacc.c  */
#line 408 "shimmr.y"
    { (yyval.exp_) = new ESub((yyvsp[(1) - (3)].exp_), (yyvsp[(3) - (3)].exp_)); YY_RESULT_Exp_= (yyval.exp_); }
    break;

  case 41:
/* Line 1792 of yacc.c  */
#line 409 "shimmr.y"
    { (yyval.exp_) = (yyvsp[(1) - (1)].exp_); YY_RESULT_Exp_= (yyval.exp_); }
    break;

  case 42:
/* Line 1792 of yacc.c  */
#line 411 "shimmr.y"
    { (yyval.exp_) = new EMul((yyvsp[(1) - (3)].exp_), (yyvsp[(3) - (3)].exp_)); YY_RESULT_Exp_= (yyval.exp_); }
    break;

  case 43:
/* Line 1792 of yacc.c  */
#line 412 "shimmr.y"
    { (yyval.exp_) = new EDiv((yyvsp[(1) - (3)].exp_), (yyvsp[(3) - (3)].exp_)); YY_RESULT_Exp_= (yyval.exp_); }
    break;

  case 44:
/* Line 1792 of yacc.c  */
#line 413 "shimmr.y"
    { (yyval.exp_) = (yyvsp[(1) - (1)].exp_); YY_RESULT_Exp_= (yyval.exp_); }
    break;

  case 45:
/* Line 1792 of yacc.c  */
#line 415 "shimmr.y"
    { (yyval.exp_) = new ENot((yyvsp[(2) - (2)].exp_)); YY_RESULT_Exp_= (yyval.exp_); }
    break;

  case 46:
/* Line 1792 of yacc.c  */
#line 416 "shimmr.y"
    { (yyval.exp_) = (yyvsp[(1) - (1)].exp_); YY_RESULT_Exp_= (yyval.exp_); }
    break;

  case 47:
/* Line 1792 of yacc.c  */
#line 418 "shimmr.y"
    { (yyval.exp_) = new EIdent((yyvsp[(1) - (1)].string_)); YY_RESULT_Exp_= (yyval.exp_); }
    break;

  case 48:
/* Line 1792 of yacc.c  */
#line 419 "shimmr.y"
    { (yyval.exp_) = new EFuncCall((yyvsp[(1) - (4)].string_), (yyvsp[(3) - (4)].listexp_)); YY_RESULT_Exp_= (yyval.exp_); }
    break;

  case 49:
/* Line 1792 of yacc.c  */
#line 420 "shimmr.y"
    { (yyval.exp_) = new EInt((yyvsp[(1) - (1)].int_)); YY_RESULT_Exp_= (yyval.exp_); }
    break;

  case 50:
/* Line 1792 of yacc.c  */
#line 421 "shimmr.y"
    { (yyval.exp_) = new EFloat((yyvsp[(1) - (1)].double_)); YY_RESULT_Exp_= (yyval.exp_); }
    break;

  case 51:
/* Line 1792 of yacc.c  */
#line 422 "shimmr.y"
    { (yyval.exp_) = new EString((yyvsp[(1) - (1)].string_)); YY_RESULT_Exp_= (yyval.exp_); }
    break;

  case 52:
/* Line 1792 of yacc.c  */
#line 423 "shimmr.y"
    { (yyval.exp_) = (yyvsp[(2) - (3)].exp_); YY_RESULT_Exp_= (yyval.exp_); }
    break;

  case 53:
/* Line 1792 of yacc.c  */
#line 425 "shimmr.y"
    { (yyval.argument_) = new ArgumentDef((yyvsp[(1) - (2)].type_), (yyvsp[(2) - (2)].string_)); YY_RESULT_Argument_= (yyval.argument_); }
    break;

  case 54:
/* Line 1792 of yacc.c  */
#line 427 "shimmr.y"
    { (yyval.listargument_) = 0; YY_RESULT_ListArgument_= (yyval.listargument_); }
    break;

  case 55:
/* Line 1792 of yacc.c  */
#line 428 "shimmr.y"
    { (yyval.listargument_) = new ListArgument((yyvsp[(1) - (1)].argument_)); YY_RESULT_ListArgument_= (yyval.listargument_); }
    break;

  case 56:
/* Line 1792 of yacc.c  */
#line 429 "shimmr.y"
    { (yyval.listargument_) = new ListArgument((yyvsp[(1) - (3)].argument_), (yyvsp[(3) - (3)].listargument_)); YY_RESULT_ListArgument_= (yyval.listargument_); }
    break;

  case 57:
/* Line 1792 of yacc.c  */
#line 431 "shimmr.y"
    { (yyval.listexp_) = 0; YY_RESULT_ListExp_= (yyval.listexp_); }
    break;

  case 58:
/* Line 1792 of yacc.c  */
#line 432 "shimmr.y"
    { (yyval.listexp_) = new ListExp((yyvsp[(1) - (1)].exp_)); YY_RESULT_ListExp_= (yyval.listexp_); }
    break;

  case 59:
/* Line 1792 of yacc.c  */
#line 433 "shimmr.y"
    { (yyval.listexp_) = new ListExp((yyvsp[(1) - (3)].exp_), (yyvsp[(3) - (3)].listexp_)); YY_RESULT_ListExp_= (yyval.listexp_); }
    break;

  case 60:
/* Line 1792 of yacc.c  */
#line 435 "shimmr.y"
    { (yyval.type_) = new EType((yyvsp[(1) - (1)].string_)); YY_RESULT_Type_= (yyval.type_); }
    break;

  case 61:
/* Line 1792 of yacc.c  */
#line 436 "shimmr.y"
    { (yyval.type_) = new VectorType((yyvsp[(1) - (4)].type_), (yyvsp[(3) - (4)].type_)); YY_RESULT_Type_= (yyval.type_); }
    break;

  case 62:
/* Line 1792 of yacc.c  */
#line 437 "shimmr.y"
    { (yyval.type_) = new RangeType((yyvsp[(1) - (3)].int_), (yyvsp[(3) - (3)].int_)); YY_RESULT_Type_= (yyval.type_); }
    break;

  case 63:
/* Line 1792 of yacc.c  */
#line 438 "shimmr.y"
    { (yyval.type_) = new SetType((yyvsp[(2) - (3)].listsettypeelem_)); YY_RESULT_Type_= (yyval.type_); }
    break;

  case 64:
/* Line 1792 of yacc.c  */
#line 440 "shimmr.y"
    { (yyval.settypeelem_) = new EIntSTE((yyvsp[(1) - (1)].int_)); YY_RESULT_SetTypeElem_= (yyval.settypeelem_); }
    break;

  case 65:
/* Line 1792 of yacc.c  */
#line 441 "shimmr.y"
    { (yyval.settypeelem_) = new EFloatSTE((yyvsp[(1) - (1)].double_)); YY_RESULT_SetTypeElem_= (yyval.settypeelem_); }
    break;

  case 66:
/* Line 1792 of yacc.c  */
#line 442 "shimmr.y"
    { (yyval.settypeelem_) = new EStringSTE((yyvsp[(1) - (1)].string_)); YY_RESULT_SetTypeElem_= (yyval.settypeelem_); }
    break;

  case 67:
/* Line 1792 of yacc.c  */
#line 444 "shimmr.y"
    { (yyval.listsettypeelem_) = 0; YY_RESULT_ListSetTypeElem_= (yyval.listsettypeelem_); }
    break;

  case 68:
/* Line 1792 of yacc.c  */
#line 445 "shimmr.y"
    { (yyval.listsettypeelem_) = new ListSetTypeElem((yyvsp[(1) - (1)].settypeelem_)); YY_RESULT_ListSetTypeElem_= (yyval.listsettypeelem_); }
    break;

  case 69:
/* Line 1792 of yacc.c  */
#line 446 "shimmr.y"
    { (yyval.listsettypeelem_) = new ListSetTypeElem((yyvsp[(1) - (3)].settypeelem_), (yyvsp[(3) - (3)].listsettypeelem_)); YY_RESULT_ListSetTypeElem_= (yyval.listsettypeelem_); }
    break;

  case 70:
/* Line 1792 of yacc.c  */
#line 448 "shimmr.y"
    { (yyval.lexpr_) = new VarAsLExpr((yyvsp[(1) - (1)].string_)); YY_RESULT_LExpr_= (yyval.lexpr_); }
    break;

  case 71:
/* Line 1792 of yacc.c  */
#line 449 "shimmr.y"
    { (yyval.lexpr_) = new VectorAsLExpr((yyvsp[(1) - (4)].lexpr_), (yyvsp[(3) - (4)].listexp_)); YY_RESULT_LExpr_= (yyval.lexpr_); }
    break;


/* Line 1792 of yacc.c  */
#line 2212 "parser.cpp"
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
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
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
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

  /* Else will try to reuse lookahead token after shifting the error
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
      if (!yypact_value_is_default (yyn))
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

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
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


