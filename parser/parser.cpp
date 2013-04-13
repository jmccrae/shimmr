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
#include <algorithm>
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
  std::cout << "line " << yy_mylinenumber << std::endl ;
  fprintf(stderr,"error: %s\n",str);
}


Program* YY_RESULT_Program_ = 0;
Program* pProgram(FILE *inp)
{
  yy_mylinenumber = 1;
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
  yy_mylinenumber = 1;
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
  yy_mylinenumber = 1;
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
  yy_mylinenumber = 1;
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
  yy_mylinenumber = 1;
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
  yy_mylinenumber = 1;
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
  yy_mylinenumber = 1;
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
  yy_mylinenumber = 1;
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
  yy_mylinenumber = 1;
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
  yy_mylinenumber = 1;
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
  yy_mylinenumber = 1;
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
  yy_mylinenumber = 1;
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
  yy_mylinenumber = 1;
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



/* Line 371 of yacc.c  */
#line 287 "parser.cpp"

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
     __STRING_ = 290,
     _INTEGER_ = 291,
     _DOUBLE_ = 292,
     _IDENT_ = 293
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 387 of yacc.c  */
#line 222 "shimmr.y"

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



/* Line 387 of yacc.c  */
#line 387 "parser.cpp"
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
#line 415 "parser.cpp"

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
#define YYFINAL  44
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   153

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  39
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  21
/* YYNRULES -- Number of rules.  */
#define YYNRULES  71
/* YYNRULES -- Number of states.  */
#define YYNSTATES  143

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   293

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
      35,    36,    37,    38
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     9,    10,    12,    16,    18,    26,
      32,    39,    47,    56,    60,    62,    67,    73,    80,    88,
      92,    99,   107,   114,   122,   125,   128,   132,   134,   138,
     140,   144,   148,   150,   154,   158,   162,   166,   168,   172,
     176,   178,   182,   186,   188,   191,   193,   195,   200,   205,
     209,   213,   215,   217,   219,   223,   226,   227,   229,   233,
     234,   236,   240,   242,   247,   251,   255,   257,   259,   261,
     262,   264
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      40,     0,    -1,    42,    -1,     4,    42,     5,    -1,    -1,
      43,    -1,    43,     6,    42,    -1,    44,    -1,    29,     8,
      38,    31,    46,     9,    41,    -1,    30,     8,    46,     9,
      41,    -1,    30,     8,    46,     9,    41,    45,    -1,    32,
       8,    38,    31,    46,     9,    41,    -1,    32,     8,    38,
      31,    46,     9,    41,    45,    -1,    46,    34,    46,    -1,
      46,    -1,    33,    38,     7,    46,    -1,    33,    57,    38,
       7,    46,    -1,    33,    38,     7,    46,    34,    46,    -1,
      33,    57,    38,     7,    46,    34,    46,    -1,    33,    57,
      38,    -1,    26,    38,     8,    55,     9,    41,    -1,    26,
      57,    38,     8,    55,     9,    41,    -1,    27,    30,     8,
      46,     9,    41,    -1,    27,    30,     8,    46,     9,    41,
      45,    -1,    27,    41,    -1,    27,    28,    -1,    46,    10,
      47,    -1,    47,    -1,    47,    11,    48,    -1,    48,    -1,
      48,     7,    49,    -1,    48,    12,    49,    -1,    49,    -1,
      49,    13,    50,    -1,    49,    14,    50,    -1,    49,    15,
      50,    -1,    49,    16,    50,    -1,    50,    -1,    50,    17,
      51,    -1,    50,    18,    51,    -1,    51,    -1,    51,    19,
      52,    -1,    51,    20,    52,    -1,    52,    -1,    21,    53,
      -1,    53,    -1,    38,    -1,    38,    22,    56,    23,    -1,
      38,     8,    56,     9,    -1,    36,    25,    36,    -1,     4,
      59,     5,    -1,    36,    -1,    37,    -1,    35,    -1,     8,
      46,     9,    -1,    57,    38,    -1,    -1,    54,    -1,    54,
      24,    55,    -1,    -1,    46,    -1,    46,    24,    56,    -1,
      38,    -1,    57,    22,    57,    23,    -1,    36,    25,    36,
      -1,     4,    59,     5,    -1,    36,    -1,    37,    -1,    35,
      -1,    -1,    58,    -1,    58,    24,    59,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   303,   303,   305,   307,   308,   309,   311,   312,   313,
     314,   315,   316,   317,   318,   320,   321,   322,   323,   324,
     325,   326,   328,   329,   330,   331,   333,   334,   336,   337,
     339,   340,   341,   343,   344,   345,   346,   347,   349,   350,
     351,   353,   354,   355,   357,   358,   360,   361,   362,   363,
     364,   365,   366,   367,   368,   370,   372,   373,   374,   376,
     377,   378,   380,   381,   382,   383,   385,   386,   387,   389,
     390,   391
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
  "_SYMB_26", "_SYMB_27", "_SYMB_28", "_SYMB_29", "_SYMB_30", "__STRING_",
  "_INTEGER_", "_DOUBLE_", "_IDENT_", "$accept", "Program",
  "StatementBlock", "ListStatement", "Statement", "Decl", "ElseBlock",
  "Exp", "Exp1", "Exp2", "Exp3", "Exp4", "Exp5", "Exp6", "Exp7",
  "Argument", "ListArgument", "ListExp", "Type", "SetTypeElem",
  "ListSetTypeElem", YY_NULL
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
     285,   286,   287,   288,   289,   290,   291,   292,   293
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    39,    40,    41,    42,    42,    42,    43,    43,    43,
      43,    43,    43,    43,    43,    44,    44,    44,    44,    44,
      44,    44,    45,    45,    45,    45,    46,    46,    47,    47,
      48,    48,    48,    49,    49,    49,    49,    49,    50,    50,
      50,    51,    51,    51,    52,    52,    53,    53,    53,    53,
      53,    53,    53,    53,    53,    54,    55,    55,    55,    56,
      56,    56,    57,    57,    57,    57,    58,    58,    58,    59,
      59,    59
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     3,     0,     1,     3,     1,     7,     5,
       6,     7,     8,     3,     1,     4,     5,     6,     7,     3,
       6,     7,     6,     7,     2,     2,     3,     1,     3,     1,
       3,     3,     1,     3,     3,     3,     3,     1,     3,     3,
       1,     3,     3,     1,     2,     1,     1,     4,     4,     3,
       3,     1,     1,     1,     3,     2,     0,     1,     3,     0,
       1,     3,     1,     4,     3,     3,     1,     1,     1,     0,
       1,     3
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,    69,     0,     0,     0,     0,     0,     0,     0,    53,
      51,    52,    46,     0,     2,     5,     7,    14,    27,    29,
      32,    37,    40,    43,    45,    68,    66,    67,    70,     0,
       0,    44,    69,     0,    62,     0,     0,     0,     0,    62,
       0,     0,    59,    59,     1,     4,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    69,
      50,    54,     0,     0,    56,     0,     0,     0,     0,     0,
       0,    19,    49,    60,     0,     0,     6,    26,    13,    28,
      30,    31,    33,    34,    35,    36,    38,    39,    41,    42,
      71,    65,    64,    62,    57,     0,     0,     0,    56,     0,
       0,     0,    15,     0,    59,    48,    47,    56,     0,    55,
      63,     0,     0,     4,     9,     0,     0,    16,    61,    58,
      20,     0,     0,     0,     0,    10,     0,    17,     0,    21,
       8,     3,    25,     0,    24,    11,    18,     0,    12,     0,
       0,    22,    23
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    13,   114,    14,    15,    16,   125,    17,    18,    19,
      20,    21,    22,    23,    24,    94,    95,    74,    96,    28,
      29
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -130
static const yytype_int16 yypact[] =
{
       1,    68,    11,    16,     6,    10,    13,    48,    19,  -130,
     -11,  -130,     3,    67,  -130,    65,  -130,    -6,    85,    71,
      74,    62,    87,  -130,  -130,  -130,  -130,  -130,    76,    93,
      99,  -130,    68,    98,   121,    -9,    92,    11,    94,   124,
      43,    97,    11,    11,  -130,     1,    11,    11,    11,    11,
      11,    11,    11,    11,    11,    11,    11,    11,    11,    68,
    -130,  -130,   129,   100,    22,    22,   130,   109,   101,   111,
      11,   132,  -130,    60,   128,   118,  -130,    85,   133,    71,
      74,    74,    62,    62,    62,    62,    87,    87,  -130,  -130,
    -130,  -130,  -130,  -130,   120,   136,    44,    90,    22,    11,
     142,    11,    51,    11,    11,  -130,  -130,    22,   142,  -130,
    -130,   138,   106,     1,   122,   108,    11,    52,  -130,  -130,
    -130,   142,   142,   143,    46,  -130,   142,   133,    11,  -130,
    -130,  -130,  -130,   144,  -130,   122,   133,    11,  -130,   110,
     142,   122,  -130
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -130,  -130,   -49,   -44,  -130,  -130,  -129,    -2,   104,   103,
      72,    41,    69,    70,   150,  -130,   -90,   -41,    -1,  -130,
     -16
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      30,    76,    75,    35,    46,     1,   138,    40,   111,     2,
      32,    42,   142,    65,    41,     1,    62,   119,    36,     2,
       1,    37,     3,    32,     2,    43,    32,     4,    47,    66,
       5,     6,     3,     7,     8,    68,     9,    10,    11,    12,
      73,    73,    33,    90,    34,    78,     9,    10,    11,    12,
     113,     9,    10,    11,    12,    33,    38,    39,    33,   120,
      93,    46,    46,   118,    97,    65,    65,    44,   102,   123,
      46,    45,   129,   130,   132,   134,   133,   135,    49,    55,
      56,    71,   109,    50,   104,   116,   128,    51,    52,    53,
      54,   141,    82,    83,    84,    85,    48,   112,    60,   115,
      59,   117,    73,    25,    26,    27,    57,    58,    61,    46,
     100,    46,    65,   110,   127,   122,    46,   126,    46,   140,
      46,    80,    81,    63,    86,    87,   136,    88,    89,    64,
      67,    70,    69,    72,    91,   139,    92,   105,    98,   103,
      99,   106,   101,    46,   107,   108,   113,   121,   131,   124,
      77,    79,   137,    31
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-130)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_uint8 yycheck[] =
{
       2,    45,    43,     4,    10,     4,   135,     8,    98,     8,
       4,     8,   141,    22,    25,     4,    32,   107,     8,     8,
       4,     8,    21,     4,     8,    22,     4,    26,    34,    38,
      29,    30,    21,    32,    33,    37,    35,    36,    37,    38,
      42,    43,    36,    59,    38,    47,    35,    36,    37,    38,
       4,    35,    36,    37,    38,    36,     8,    38,    36,   108,
      38,    10,    10,   104,    65,    22,    22,     0,    70,   113,
      10,     6,   121,   122,    28,   124,    30,   126,     7,    17,
      18,    38,    38,    12,    24,    34,    34,    13,    14,    15,
      16,   140,    51,    52,    53,    54,    11,    99,     5,   101,
      24,   103,   104,    35,    36,    37,    19,    20,     9,    10,
       9,    10,    22,    23,   116,     9,    10,     9,    10,     9,
      10,    49,    50,    25,    55,    56,   128,    57,    58,     8,
      38,     7,    38,    36,     5,   137,    36,     9,     8,     7,
      31,    23,    31,    10,    24,     9,     4,     9,     5,    27,
      46,    48,     8,     3
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     4,     8,    21,    26,    29,    30,    32,    33,    35,
      36,    37,    38,    40,    42,    43,    44,    46,    47,    48,
      49,    50,    51,    52,    53,    35,    36,    37,    58,    59,
      46,    53,     4,    36,    38,    57,     8,     8,     8,    38,
      57,    25,     8,    22,     0,     6,    10,    34,    11,     7,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    24,
       5,     9,    59,    25,     8,    22,    38,    38,    46,    38,
       7,    38,    36,    46,    56,    56,    42,    47,    46,    48,
      49,    49,    50,    50,    50,    50,    51,    51,    52,    52,
      59,     5,    36,    38,    54,    55,    57,    57,     8,    31,
       9,    31,    46,     7,    24,     9,    23,    24,     9,    38,
      23,    55,    46,     4,    41,    46,    34,    46,    56,    55,
      41,     9,     9,    42,    27,    45,     9,    46,    34,    41,
      41,     5,    28,    30,    41,    41,    46,     8,    45,    46,
       9,    41,    45
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
#line 303 "shimmr.y"
    {  std::reverse((yyvsp[(1) - (1)].liststatement_)->begin(),(yyvsp[(1) - (1)].liststatement_)->end()) ;(yyval.program_) = new Statements((yyvsp[(1) - (1)].liststatement_)); (yyval.program_)->line_number = yy_mylinenumber; YY_RESULT_Program_= (yyval.program_); }
    break;

  case 3:
/* Line 1792 of yacc.c  */
#line 305 "shimmr.y"
    {  std::reverse((yyvsp[(2) - (3)].liststatement_)->begin(),(yyvsp[(2) - (3)].liststatement_)->end()) ;(yyval.statementblock_) = new StatementBlockStat((yyvsp[(2) - (3)].liststatement_)); (yyval.statementblock_)->line_number = yy_mylinenumber; YY_RESULT_StatementBlock_= (yyval.statementblock_); }
    break;

  case 4:
/* Line 1792 of yacc.c  */
#line 307 "shimmr.y"
    {  (yyval.liststatement_) = new ListStatement(); YY_RESULT_ListStatement_= (yyval.liststatement_); }
    break;

  case 5:
/* Line 1792 of yacc.c  */
#line 308 "shimmr.y"
    {  (yyval.liststatement_) = new ListStatement() ; (yyval.liststatement_)->push_back((yyvsp[(1) - (1)].statement_)); YY_RESULT_ListStatement_= (yyval.liststatement_); }
    break;

  case 6:
/* Line 1792 of yacc.c  */
#line 309 "shimmr.y"
    {  (yyvsp[(3) - (3)].liststatement_)->push_back((yyvsp[(1) - (3)].statement_)) ; (yyval.liststatement_) = (yyvsp[(3) - (3)].liststatement_) ; YY_RESULT_ListStatement_= (yyval.liststatement_); }
    break;

  case 7:
/* Line 1792 of yacc.c  */
#line 311 "shimmr.y"
    {  (yyval.statement_) = new DeclStat((yyvsp[(1) - (1)].decl_)); (yyval.statement_)->line_number = yy_mylinenumber; YY_RESULT_Statement_= (yyval.statement_); }
    break;

  case 8:
/* Line 1792 of yacc.c  */
#line 312 "shimmr.y"
    {  (yyval.statement_) = new ForStatement((yyvsp[(3) - (7)].string_), (yyvsp[(5) - (7)].exp_), (yyvsp[(7) - (7)].statementblock_)); (yyval.statement_)->line_number = yy_mylinenumber; YY_RESULT_Statement_= (yyval.statement_); }
    break;

  case 9:
/* Line 1792 of yacc.c  */
#line 313 "shimmr.y"
    {  (yyval.statement_) = new IfStatement((yyvsp[(3) - (5)].exp_), (yyvsp[(5) - (5)].statementblock_)); (yyval.statement_)->line_number = yy_mylinenumber; YY_RESULT_Statement_= (yyval.statement_); }
    break;

  case 10:
/* Line 1792 of yacc.c  */
#line 314 "shimmr.y"
    {  (yyval.statement_) = new IfElseStatement((yyvsp[(3) - (6)].exp_), (yyvsp[(5) - (6)].statementblock_), (yyvsp[(6) - (6)].elseblock_)); (yyval.statement_)->line_number = yy_mylinenumber; YY_RESULT_Statement_= (yyval.statement_); }
    break;

  case 11:
/* Line 1792 of yacc.c  */
#line 315 "shimmr.y"
    {  (yyval.statement_) = new SomeStatement((yyvsp[(3) - (7)].string_), (yyvsp[(5) - (7)].exp_), (yyvsp[(7) - (7)].statementblock_)); (yyval.statement_)->line_number = yy_mylinenumber; YY_RESULT_Statement_= (yyval.statement_); }
    break;

  case 12:
/* Line 1792 of yacc.c  */
#line 316 "shimmr.y"
    {  (yyval.statement_) = new SomeElseStatement((yyvsp[(3) - (8)].string_), (yyvsp[(5) - (8)].exp_), (yyvsp[(7) - (8)].statementblock_), (yyvsp[(8) - (8)].elseblock_)); (yyval.statement_)->line_number = yy_mylinenumber; YY_RESULT_Statement_= (yyval.statement_); }
    break;

  case 13:
/* Line 1792 of yacc.c  */
#line 317 "shimmr.y"
    {  (yyval.statement_) = new ConditionalStatement((yyvsp[(1) - (3)].exp_), (yyvsp[(3) - (3)].exp_)); (yyval.statement_)->line_number = yy_mylinenumber; YY_RESULT_Statement_= (yyval.statement_); }
    break;

  case 14:
/* Line 1792 of yacc.c  */
#line 318 "shimmr.y"
    {  (yyval.statement_) = new ExpAsStatement((yyvsp[(1) - (1)].exp_)); (yyval.statement_)->line_number = yy_mylinenumber; YY_RESULT_Statement_= (yyval.statement_); }
    break;

  case 15:
/* Line 1792 of yacc.c  */
#line 320 "shimmr.y"
    {  (yyval.decl_) = new SimpleDecl((yyvsp[(2) - (4)].string_), (yyvsp[(4) - (4)].exp_)); (yyval.decl_)->line_number = yy_mylinenumber; YY_RESULT_Decl_= (yyval.decl_); }
    break;

  case 16:
/* Line 1792 of yacc.c  */
#line 321 "shimmr.y"
    {  (yyval.decl_) = new TypedDecl((yyvsp[(2) - (5)].type_), (yyvsp[(3) - (5)].string_), (yyvsp[(5) - (5)].exp_)); (yyval.decl_)->line_number = yy_mylinenumber; YY_RESULT_Decl_= (yyval.decl_); }
    break;

  case 17:
/* Line 1792 of yacc.c  */
#line 322 "shimmr.y"
    {  (yyval.decl_) = new SimpleDeclWith((yyvsp[(2) - (6)].string_), (yyvsp[(4) - (6)].exp_), (yyvsp[(6) - (6)].exp_)); (yyval.decl_)->line_number = yy_mylinenumber; YY_RESULT_Decl_= (yyval.decl_); }
    break;

  case 18:
/* Line 1792 of yacc.c  */
#line 323 "shimmr.y"
    {  (yyval.decl_) = new TypedDeclWith((yyvsp[(2) - (7)].type_), (yyvsp[(3) - (7)].string_), (yyvsp[(5) - (7)].exp_), (yyvsp[(7) - (7)].exp_)); (yyval.decl_)->line_number = yy_mylinenumber; YY_RESULT_Decl_= (yyval.decl_); }
    break;

  case 19:
/* Line 1792 of yacc.c  */
#line 324 "shimmr.y"
    {  (yyval.decl_) = new BareDecl((yyvsp[(2) - (3)].type_), (yyvsp[(3) - (3)].string_)); (yyval.decl_)->line_number = yy_mylinenumber; YY_RESULT_Decl_= (yyval.decl_); }
    break;

  case 20:
/* Line 1792 of yacc.c  */
#line 325 "shimmr.y"
    {  std::reverse((yyvsp[(4) - (6)].listargument_)->begin(),(yyvsp[(4) - (6)].listargument_)->end()) ;(yyval.decl_) = new EFuncDecl((yyvsp[(2) - (6)].string_), (yyvsp[(4) - (6)].listargument_), (yyvsp[(6) - (6)].statementblock_)); (yyval.decl_)->line_number = yy_mylinenumber; YY_RESULT_Decl_= (yyval.decl_); }
    break;

  case 21:
/* Line 1792 of yacc.c  */
#line 326 "shimmr.y"
    {  std::reverse((yyvsp[(5) - (7)].listargument_)->begin(),(yyvsp[(5) - (7)].listargument_)->end()) ;(yyval.decl_) = new EFuncDeclWithType((yyvsp[(2) - (7)].type_), (yyvsp[(3) - (7)].string_), (yyvsp[(5) - (7)].listargument_), (yyvsp[(7) - (7)].statementblock_)); (yyval.decl_)->line_number = yy_mylinenumber; YY_RESULT_Decl_= (yyval.decl_); }
    break;

  case 22:
/* Line 1792 of yacc.c  */
#line 328 "shimmr.y"
    {  (yyval.elseblock_) = new ElseIfBlock((yyvsp[(4) - (6)].exp_), (yyvsp[(6) - (6)].statementblock_)); (yyval.elseblock_)->line_number = yy_mylinenumber; YY_RESULT_ElseBlock_= (yyval.elseblock_); }
    break;

  case 23:
/* Line 1792 of yacc.c  */
#line 329 "shimmr.y"
    {  (yyval.elseblock_) = new ElseIf2Block((yyvsp[(4) - (7)].exp_), (yyvsp[(6) - (7)].statementblock_), (yyvsp[(7) - (7)].elseblock_)); (yyval.elseblock_)->line_number = yy_mylinenumber; YY_RESULT_ElseBlock_= (yyval.elseblock_); }
    break;

  case 24:
/* Line 1792 of yacc.c  */
#line 330 "shimmr.y"
    {  (yyval.elseblock_) = new ElseBlockStat((yyvsp[(2) - (2)].statementblock_)); (yyval.elseblock_)->line_number = yy_mylinenumber; YY_RESULT_ElseBlock_= (yyval.elseblock_); }
    break;

  case 25:
/* Line 1792 of yacc.c  */
#line 331 "shimmr.y"
    {  (yyval.elseblock_) = new ElseFailStat(); (yyval.elseblock_)->line_number = yy_mylinenumber; YY_RESULT_ElseBlock_= (yyval.elseblock_); }
    break;

  case 26:
/* Line 1792 of yacc.c  */
#line 333 "shimmr.y"
    {  (yyval.exp_) = new EOr((yyvsp[(1) - (3)].exp_), (yyvsp[(3) - (3)].exp_)); (yyval.exp_)->line_number = yy_mylinenumber; YY_RESULT_Exp_= (yyval.exp_); }
    break;

  case 27:
/* Line 1792 of yacc.c  */
#line 334 "shimmr.y"
    {  (yyval.exp_) = (yyvsp[(1) - (1)].exp_); YY_RESULT_Exp_= (yyval.exp_); }
    break;

  case 28:
/* Line 1792 of yacc.c  */
#line 336 "shimmr.y"
    {  (yyval.exp_) = new EAnd((yyvsp[(1) - (3)].exp_), (yyvsp[(3) - (3)].exp_)); (yyval.exp_)->line_number = yy_mylinenumber; YY_RESULT_Exp_= (yyval.exp_); }
    break;

  case 29:
/* Line 1792 of yacc.c  */
#line 337 "shimmr.y"
    {  (yyval.exp_) = (yyvsp[(1) - (1)].exp_); YY_RESULT_Exp_= (yyval.exp_); }
    break;

  case 30:
/* Line 1792 of yacc.c  */
#line 339 "shimmr.y"
    {  (yyval.exp_) = new EEquals((yyvsp[(1) - (3)].exp_), (yyvsp[(3) - (3)].exp_)); (yyval.exp_)->line_number = yy_mylinenumber; YY_RESULT_Exp_= (yyval.exp_); }
    break;

  case 31:
/* Line 1792 of yacc.c  */
#line 340 "shimmr.y"
    {  (yyval.exp_) = new ENEq((yyvsp[(1) - (3)].exp_), (yyvsp[(3) - (3)].exp_)); (yyval.exp_)->line_number = yy_mylinenumber; YY_RESULT_Exp_= (yyval.exp_); }
    break;

  case 32:
/* Line 1792 of yacc.c  */
#line 341 "shimmr.y"
    {  (yyval.exp_) = (yyvsp[(1) - (1)].exp_); YY_RESULT_Exp_= (yyval.exp_); }
    break;

  case 33:
/* Line 1792 of yacc.c  */
#line 343 "shimmr.y"
    {  (yyval.exp_) = new ELeq((yyvsp[(1) - (3)].exp_), (yyvsp[(3) - (3)].exp_)); (yyval.exp_)->line_number = yy_mylinenumber; YY_RESULT_Exp_= (yyval.exp_); }
    break;

  case 34:
/* Line 1792 of yacc.c  */
#line 344 "shimmr.y"
    {  (yyval.exp_) = new EGeq((yyvsp[(1) - (3)].exp_), (yyvsp[(3) - (3)].exp_)); (yyval.exp_)->line_number = yy_mylinenumber; YY_RESULT_Exp_= (yyval.exp_); }
    break;

  case 35:
/* Line 1792 of yacc.c  */
#line 345 "shimmr.y"
    {  (yyval.exp_) = new ELessThan((yyvsp[(1) - (3)].exp_), (yyvsp[(3) - (3)].exp_)); (yyval.exp_)->line_number = yy_mylinenumber; YY_RESULT_Exp_= (yyval.exp_); }
    break;

  case 36:
/* Line 1792 of yacc.c  */
#line 346 "shimmr.y"
    {  (yyval.exp_) = new EGreaterThan((yyvsp[(1) - (3)].exp_), (yyvsp[(3) - (3)].exp_)); (yyval.exp_)->line_number = yy_mylinenumber; YY_RESULT_Exp_= (yyval.exp_); }
    break;

  case 37:
/* Line 1792 of yacc.c  */
#line 347 "shimmr.y"
    {  (yyval.exp_) = (yyvsp[(1) - (1)].exp_); YY_RESULT_Exp_= (yyval.exp_); }
    break;

  case 38:
/* Line 1792 of yacc.c  */
#line 349 "shimmr.y"
    {  (yyval.exp_) = new EAdd((yyvsp[(1) - (3)].exp_), (yyvsp[(3) - (3)].exp_)); (yyval.exp_)->line_number = yy_mylinenumber; YY_RESULT_Exp_= (yyval.exp_); }
    break;

  case 39:
/* Line 1792 of yacc.c  */
#line 350 "shimmr.y"
    {  (yyval.exp_) = new ESub((yyvsp[(1) - (3)].exp_), (yyvsp[(3) - (3)].exp_)); (yyval.exp_)->line_number = yy_mylinenumber; YY_RESULT_Exp_= (yyval.exp_); }
    break;

  case 40:
/* Line 1792 of yacc.c  */
#line 351 "shimmr.y"
    {  (yyval.exp_) = (yyvsp[(1) - (1)].exp_); YY_RESULT_Exp_= (yyval.exp_); }
    break;

  case 41:
/* Line 1792 of yacc.c  */
#line 353 "shimmr.y"
    {  (yyval.exp_) = new EMul((yyvsp[(1) - (3)].exp_), (yyvsp[(3) - (3)].exp_)); (yyval.exp_)->line_number = yy_mylinenumber; YY_RESULT_Exp_= (yyval.exp_); }
    break;

  case 42:
/* Line 1792 of yacc.c  */
#line 354 "shimmr.y"
    {  (yyval.exp_) = new EDiv((yyvsp[(1) - (3)].exp_), (yyvsp[(3) - (3)].exp_)); (yyval.exp_)->line_number = yy_mylinenumber; YY_RESULT_Exp_= (yyval.exp_); }
    break;

  case 43:
/* Line 1792 of yacc.c  */
#line 355 "shimmr.y"
    {  (yyval.exp_) = (yyvsp[(1) - (1)].exp_); YY_RESULT_Exp_= (yyval.exp_); }
    break;

  case 44:
/* Line 1792 of yacc.c  */
#line 357 "shimmr.y"
    {  (yyval.exp_) = new ENot((yyvsp[(2) - (2)].exp_)); (yyval.exp_)->line_number = yy_mylinenumber; YY_RESULT_Exp_= (yyval.exp_); }
    break;

  case 45:
/* Line 1792 of yacc.c  */
#line 358 "shimmr.y"
    {  (yyval.exp_) = (yyvsp[(1) - (1)].exp_); YY_RESULT_Exp_= (yyval.exp_); }
    break;

  case 46:
/* Line 1792 of yacc.c  */
#line 360 "shimmr.y"
    {  (yyval.exp_) = new EIdent((yyvsp[(1) - (1)].string_)); (yyval.exp_)->line_number = yy_mylinenumber; YY_RESULT_Exp_= (yyval.exp_); }
    break;

  case 47:
/* Line 1792 of yacc.c  */
#line 361 "shimmr.y"
    {  std::reverse((yyvsp[(3) - (4)].listexp_)->begin(),(yyvsp[(3) - (4)].listexp_)->end()) ;(yyval.exp_) = new EVector((yyvsp[(1) - (4)].string_), (yyvsp[(3) - (4)].listexp_)); (yyval.exp_)->line_number = yy_mylinenumber; YY_RESULT_Exp_= (yyval.exp_); }
    break;

  case 48:
/* Line 1792 of yacc.c  */
#line 362 "shimmr.y"
    {  std::reverse((yyvsp[(3) - (4)].listexp_)->begin(),(yyvsp[(3) - (4)].listexp_)->end()) ;(yyval.exp_) = new EFuncCall((yyvsp[(1) - (4)].string_), (yyvsp[(3) - (4)].listexp_)); (yyval.exp_)->line_number = yy_mylinenumber; YY_RESULT_Exp_= (yyval.exp_); }
    break;

  case 49:
/* Line 1792 of yacc.c  */
#line 363 "shimmr.y"
    {  (yyval.exp_) = new ERange((yyvsp[(1) - (3)].int_), (yyvsp[(3) - (3)].int_)); (yyval.exp_)->line_number = yy_mylinenumber; YY_RESULT_Exp_= (yyval.exp_); }
    break;

  case 50:
/* Line 1792 of yacc.c  */
#line 364 "shimmr.y"
    {  std::reverse((yyvsp[(2) - (3)].listsettypeelem_)->begin(),(yyvsp[(2) - (3)].listsettypeelem_)->end()) ;(yyval.exp_) = new ESet((yyvsp[(2) - (3)].listsettypeelem_)); (yyval.exp_)->line_number = yy_mylinenumber; YY_RESULT_Exp_= (yyval.exp_); }
    break;

  case 51:
/* Line 1792 of yacc.c  */
#line 365 "shimmr.y"
    {  (yyval.exp_) = new EInt((yyvsp[(1) - (1)].int_)); (yyval.exp_)->line_number = yy_mylinenumber; YY_RESULT_Exp_= (yyval.exp_); }
    break;

  case 52:
/* Line 1792 of yacc.c  */
#line 366 "shimmr.y"
    {  (yyval.exp_) = new EFloat((yyvsp[(1) - (1)].double_)); (yyval.exp_)->line_number = yy_mylinenumber; YY_RESULT_Exp_= (yyval.exp_); }
    break;

  case 53:
/* Line 1792 of yacc.c  */
#line 367 "shimmr.y"
    {  (yyval.exp_) = new EString((yyvsp[(1) - (1)].string_)); (yyval.exp_)->line_number = yy_mylinenumber; YY_RESULT_Exp_= (yyval.exp_); }
    break;

  case 54:
/* Line 1792 of yacc.c  */
#line 368 "shimmr.y"
    {  (yyval.exp_) = (yyvsp[(2) - (3)].exp_); YY_RESULT_Exp_= (yyval.exp_); }
    break;

  case 55:
/* Line 1792 of yacc.c  */
#line 370 "shimmr.y"
    {  (yyval.argument_) = new ArgumentDef((yyvsp[(1) - (2)].type_), (yyvsp[(2) - (2)].string_)); (yyval.argument_)->line_number = yy_mylinenumber; YY_RESULT_Argument_= (yyval.argument_); }
    break;

  case 56:
/* Line 1792 of yacc.c  */
#line 372 "shimmr.y"
    {  (yyval.listargument_) = new ListArgument(); YY_RESULT_ListArgument_= (yyval.listargument_); }
    break;

  case 57:
/* Line 1792 of yacc.c  */
#line 373 "shimmr.y"
    {  (yyval.listargument_) = new ListArgument() ; (yyval.listargument_)->push_back((yyvsp[(1) - (1)].argument_)); YY_RESULT_ListArgument_= (yyval.listargument_); }
    break;

  case 58:
/* Line 1792 of yacc.c  */
#line 374 "shimmr.y"
    {  (yyvsp[(3) - (3)].listargument_)->push_back((yyvsp[(1) - (3)].argument_)) ; (yyval.listargument_) = (yyvsp[(3) - (3)].listargument_) ; YY_RESULT_ListArgument_= (yyval.listargument_); }
    break;

  case 59:
/* Line 1792 of yacc.c  */
#line 376 "shimmr.y"
    {  (yyval.listexp_) = new ListExp(); YY_RESULT_ListExp_= (yyval.listexp_); }
    break;

  case 60:
/* Line 1792 of yacc.c  */
#line 377 "shimmr.y"
    {  (yyval.listexp_) = new ListExp() ; (yyval.listexp_)->push_back((yyvsp[(1) - (1)].exp_)); YY_RESULT_ListExp_= (yyval.listexp_); }
    break;

  case 61:
/* Line 1792 of yacc.c  */
#line 378 "shimmr.y"
    {  (yyvsp[(3) - (3)].listexp_)->push_back((yyvsp[(1) - (3)].exp_)) ; (yyval.listexp_) = (yyvsp[(3) - (3)].listexp_) ; YY_RESULT_ListExp_= (yyval.listexp_); }
    break;

  case 62:
/* Line 1792 of yacc.c  */
#line 380 "shimmr.y"
    {  (yyval.type_) = new EType((yyvsp[(1) - (1)].string_)); (yyval.type_)->line_number = yy_mylinenumber; YY_RESULT_Type_= (yyval.type_); }
    break;

  case 63:
/* Line 1792 of yacc.c  */
#line 381 "shimmr.y"
    {  (yyval.type_) = new VectorType((yyvsp[(1) - (4)].type_), (yyvsp[(3) - (4)].type_)); (yyval.type_)->line_number = yy_mylinenumber; YY_RESULT_Type_= (yyval.type_); }
    break;

  case 64:
/* Line 1792 of yacc.c  */
#line 382 "shimmr.y"
    {  (yyval.type_) = new RangeType((yyvsp[(1) - (3)].int_), (yyvsp[(3) - (3)].int_)); (yyval.type_)->line_number = yy_mylinenumber; YY_RESULT_Type_= (yyval.type_); }
    break;

  case 65:
/* Line 1792 of yacc.c  */
#line 383 "shimmr.y"
    {  std::reverse((yyvsp[(2) - (3)].listsettypeelem_)->begin(),(yyvsp[(2) - (3)].listsettypeelem_)->end()) ;(yyval.type_) = new SetType((yyvsp[(2) - (3)].listsettypeelem_)); (yyval.type_)->line_number = yy_mylinenumber; YY_RESULT_Type_= (yyval.type_); }
    break;

  case 66:
/* Line 1792 of yacc.c  */
#line 385 "shimmr.y"
    {  (yyval.settypeelem_) = new EIntSTE((yyvsp[(1) - (1)].int_)); (yyval.settypeelem_)->line_number = yy_mylinenumber; YY_RESULT_SetTypeElem_= (yyval.settypeelem_); }
    break;

  case 67:
/* Line 1792 of yacc.c  */
#line 386 "shimmr.y"
    {  (yyval.settypeelem_) = new EFloatSTE((yyvsp[(1) - (1)].double_)); (yyval.settypeelem_)->line_number = yy_mylinenumber; YY_RESULT_SetTypeElem_= (yyval.settypeelem_); }
    break;

  case 68:
/* Line 1792 of yacc.c  */
#line 387 "shimmr.y"
    {  (yyval.settypeelem_) = new EStringSTE((yyvsp[(1) - (1)].string_)); (yyval.settypeelem_)->line_number = yy_mylinenumber; YY_RESULT_SetTypeElem_= (yyval.settypeelem_); }
    break;

  case 69:
/* Line 1792 of yacc.c  */
#line 389 "shimmr.y"
    {  (yyval.listsettypeelem_) = new ListSetTypeElem(); YY_RESULT_ListSetTypeElem_= (yyval.listsettypeelem_); }
    break;

  case 70:
/* Line 1792 of yacc.c  */
#line 390 "shimmr.y"
    {  (yyval.listsettypeelem_) = new ListSetTypeElem() ; (yyval.listsettypeelem_)->push_back((yyvsp[(1) - (1)].settypeelem_)); YY_RESULT_ListSetTypeElem_= (yyval.listsettypeelem_); }
    break;

  case 71:
/* Line 1792 of yacc.c  */
#line 391 "shimmr.y"
    {  (yyvsp[(3) - (3)].listsettypeelem_)->push_back((yyvsp[(1) - (3)].settypeelem_)) ; (yyval.listsettypeelem_) = (yyvsp[(3) - (3)].listsettypeelem_) ; YY_RESULT_ListSetTypeElem_= (yyval.listsettypeelem_); }
    break;


/* Line 1792 of yacc.c  */
#line 2156 "parser.cpp"
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


