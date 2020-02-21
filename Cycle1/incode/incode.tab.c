/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 3 "incode.y" /* yacc.c:339  */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
extern int yylex();
extern int yyparse();
extern FILE *yyin;
void yyerror();

struct symbol{
	char name[20];
	int type;
};

#define NHASH 9997
struct symbol symtab[NHASH];
int nh=0;

struct symbol * lookup(char* sym)
{
	for(int i=0;i<nh;i++)
	{
		if(!strcmp(symtab[i].name,sym))
			return &symtab[i];
	}
	return NULL;
	/*struct symbol *sp=&symtab[n];
	n++;
	if(n>=NHASH)
	{
		fputs("symbol table overflow\n", stderr);
		abort();
	}
	sp->name=strdup(sym);
	return sp;*/
}

void addref(char* name,int type)
{
	struct ref *r;
	struct symbol *sp= lookup(name);
	
	if(sp==NULL)
	{
		printf("here\n");
		strcpy(symtab[nh].name,name);
		printf("here\n");
		symtab[nh].type=type;
		printf("here\n");
		nh++;
		printf("here\n");
	}
	else
	{
		printf("redeclaration\n");
	}
}

struct exprType{

	char *addr;
	char *code;
	
};

int n=1;
int nl = 1;
char *var;
char num_to_concatinate[15];
char num_to_concatinate_l[15];
char *ret,*ret2;
char *temp;

char *label;
char *label2;
char *check;

char *begin, *begin2, *begin3;

char *b1;
char *b2;

char *s1;
char *s2;

struct exprType *to_return_expr;

char * newTemp(){
	
	char *newTemp = (char *)malloc(20);
	strcpy(newTemp,"t");
	sprintf(num_to_concatinate,"%d",n);
	strcat(newTemp,num_to_concatinate);
		
	n++;
	return newTemp;
}

char * newLabel(){
	
	char *newLabel = (char *)malloc(50);
	strcpy(newLabel,"L");
	sprintf(num_to_concatinate_l,"%d",nl);
	strcat(newLabel,num_to_concatinate_l);
		
	nl++;
	return newLabel;
}

#line 177 "incode.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "incode.tab.h".  */
#ifndef YY_YY_INCODE_TAB_H_INCLUDED
# define YY_YY_INCODE_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    DIGIT = 258,
    FLOAT = 259,
    ID = 260,
    IF = 261,
    ELSE = 262,
    WHILE = 263,
    FOR = 264,
    TYPES = 265,
    REL_OPT = 266,
    OR = 267,
    AND = 268,
    NOT = 269,
    TRUE = 270,
    FALSE = 271,
    MAIN = 272,
    EOL = 273
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 116 "incode.y" /* yacc.c:355  */

	int ival;
	float fval;
	char *sval;
	struct exprType *EXPRTYPE;

#line 243 "incode.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_INCODE_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 260 "incode.tab.c" /* yacc.c:358  */

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
#else
typedef signed char yytype_int8;
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
# elif ! defined YYSIZE_T
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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
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
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

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
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   423

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  36
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  15
/* YYNRULES -- Number of rules.  */
#define YYNRULES  60
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  148

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   273

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      25,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    24,    34,     2,
      30,    31,    21,    19,     2,    20,     2,    22,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    29,    27,
       2,    26,     2,    28,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    23,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    32,    35,    33,     2,     2,     2,     2,
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
      15,    16,    17,    18
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   141,   141,   177,   213,   220,   228,   233,   238,   325,
     375,   410,   455,   501,   507,   513,   515,   523,   530,   545,
     552,   557,   595,   635,   642,   656,   705,   753,   801,   851,
     863,   869,   883,   927,   969,  1018,  1066,  1114,  1164,  1171,
    1201,  1231,  1261,  1300,  1306,  1318,  1333,  1338,  1381,  1424,
    1466,  1507,  1548,  1590,  1632,  1674,  1691,  1703,  1719,  1736,
    1745
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "DIGIT", "FLOAT", "ID", "IF", "ELSE",
  "WHILE", "FOR", "TYPES", "REL_OPT", "OR", "AND", "NOT", "TRUE", "FALSE",
  "MAIN", "EOL", "'+'", "'-'", "'*'", "'/'", "'^'", "'%'", "'\\n'", "'='",
  "';'", "'?'", "':'", "'('", "')'", "'{'", "'}'", "'&'", "'|'", "$accept",
  "startSym", "program", "construct", "block", "list2", "list", "stat2",
  "stat", "dec", "bool", "expr", "text", "text2", "number", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,    43,
      45,    42,    47,    94,    37,    10,    61,    59,    63,    58,
      40,    41,   123,   125,    38,   124
};
# endif

#define YYPACT_NINF -75

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-75)))

#define YYTABLE_NINF -7

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -14,   -23,    10,   -16,   -75,     0,   256,   -75,   -75,   -75,
     -12,    -5,     6,    11,     9,   -75,   -75,   -75,   171,   194,
     225,   -75,   -75,   130,   -75,    77,    62,   257,   129,   -75,
     171,   171,    66,   -75,   -75,   171,    -4,   274,   -75,   -75,
       8,    79,   -75,   -75,   163,    39,     1,   -75,   297,     1,
     -75,   171,   171,    66,     1,     1,     1,     1,     1,     1,
       1,   -75,     1,     1,    42,    51,    53,    55,     1,    47,
     291,    85,    66,    46,   -75,    59,   382,   162,   106,   -75,
     -75,   -75,   -75,   -75,   314,   320,    75,   -75,    70,   382,
     388,   388,   119,   119,   119,   119,   382,   382,     1,     1,
       1,     1,   337,    69,    69,    60,   314,   171,     1,    82,
      89,    91,    94,     1,   -75,   -75,    66,   346,   355,   364,
     373,   -75,   104,   -75,   -75,   101,   382,     1,     1,     1,
       1,   382,    98,   -75,   -75,   -75,   -75,    69,    66,   382,
     382,   382,   382,   -75,   -75,    95,    69,   -75
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,     0,    59,    60,    57,
       0,     0,     0,     0,     0,    44,    45,    29,     0,     0,
       0,     4,     7,     0,    17,     0,     0,     0,    55,    56,
       0,     0,     0,    58,    38,     0,     0,     0,    55,    15,
       0,     0,     2,     3,     0,     0,     0,    18,     0,     0,
      31,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    30,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    16,    24,    23,    55,     0,    43,
      46,    14,    13,    19,     0,     0,    40,    41,     0,    39,
      51,    52,    48,    49,    47,    50,    53,    54,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    42,    33,     0,     0,     0,     0,
       0,    32,    10,     9,    20,     0,    21,     0,     0,     0,
       0,    22,     0,    34,    35,    36,    37,     0,     0,    25,
      26,    27,    28,    12,    11,     0,     0,     8
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -75,   -75,   -75,   139,   -74,   -51,   172,    57,   -22,   -11,
      -7,    -6,    14,   -75,   -75
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,    20,    21,    22,    73,    23,    74,    24,    25,
      26,    70,    38,    34,    29
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      27,    47,    88,     1,     7,     8,     9,     3,    51,    52,
       4,    36,    37,    27,    27,     5,    33,    48,    30,    47,
      28,    75,    47,    69,    71,    31,    76,    79,    78,   122,
     123,    46,     6,    28,    28,    48,    32,    28,    48,    35,
      84,    81,    75,    85,    86,    87,    77,    76,    89,    90,
      91,    92,    93,    94,    95,    28,    96,    97,    28,    51,
      52,    75,   102,   144,    83,   132,   106,    77,    98,     7,
       8,     9,   147,   107,    51,    52,    13,    99,   103,   100,
      45,   101,     7,     8,     9,   108,    77,   145,    52,    13,
      53,   124,   117,   118,   119,   120,    72,    51,    52,   116,
     125,    19,   126,    49,    50,    75,    17,   131,   127,    46,
      76,   137,    82,    51,    52,   128,   104,   129,    51,    52,
     130,   139,   140,   141,   142,   143,   146,    75,   138,   105,
      77,    45,    76,     7,     8,     9,    -5,   114,    -5,    -5,
      13,     0,    59,     0,    -5,    -5,    -5,     0,    64,    65,
      66,    67,    77,    62,    63,    68,     0,    17,    40,    43,
      46,     0,    -5,    -5,    45,     0,     7,     8,     9,    -6,
       0,    -6,    -6,    13,     7,     8,     9,    -6,    -6,    -6,
       0,   109,   110,   111,   112,    14,    15,    16,   113,     0,
      17,    41,    44,    46,     0,    -6,    -6,     7,     8,     9,
      10,    18,    11,    12,    13,     0,     0,     0,    14,    15,
      16,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    17,     0,     0,    18,     0,    19,    39,     7,     8,
       9,    10,     0,    11,    12,    13,     0,     0,     0,    14,
      15,    16,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    17,     0,     0,    18,     0,    19,    42,     7,
       8,     9,    10,     0,    11,    12,    13,     0,    54,     0,
      14,    15,    16,     0,     0,     0,    55,    56,    57,    58,
      59,    60,     0,    17,    61,    54,    18,     0,    19,     0,
       0,    62,    63,    55,    56,    57,    58,    59,    60,     0,
       0,     0,    54,     0,     0,    80,     0,     0,    62,    63,
      55,    56,    57,    58,    59,    60,    55,    56,    57,    58,
      59,    60,     0,     0,    61,    62,    63,     0,     0,     0,
       0,    62,    63,    55,    56,    57,    58,    59,    60,    55,
      56,    57,    58,    59,    60,    80,     0,   115,    62,    63,
       0,     0,     0,     0,    62,    63,    55,    56,    57,    58,
      59,    60,     0,     0,   121,    55,    56,    57,    58,    59,
      60,    62,    63,   133,    55,    56,    57,    58,    59,    60,
      62,    63,   134,    55,    56,    57,    58,    59,    60,    62,
      63,   135,    55,    56,    57,    58,    59,    60,    62,    63,
     136,    55,    56,    57,    58,    59,    60,    62,    63,    57,
      58,    59,    60,     0,     0,     0,    62,    63,     0,     0,
       0,     0,    62,    63
};

static const yytype_int16 yycheck[] =
{
       6,    23,    53,    17,     3,     4,     5,    30,    12,    13,
       0,    18,    18,    19,    20,    31,     5,    23,    30,    41,
       6,    32,    44,    30,    31,    30,    32,    31,    35,   103,
     104,    30,    32,    19,    20,    41,    30,    23,    44,    30,
      46,    33,    53,    49,    51,    52,    32,    53,    54,    55,
      56,    57,    58,    59,    60,    41,    62,    63,    44,    12,
      13,    72,    68,   137,    25,   116,    72,    53,    26,     3,
       4,     5,   146,    27,    12,    13,    10,    26,    31,    26,
       1,    26,     3,     4,     5,    26,    72,   138,    13,    10,
      28,    31,    98,    99,   100,   101,    30,    12,    13,    29,
     107,    32,   108,    26,    27,   116,    27,   113,    26,    30,
     116,     7,    33,    12,    13,    26,    31,    26,    12,    13,
      26,   127,   128,   129,   130,    27,    31,   138,    27,    72,
     116,     1,   138,     3,     4,     5,     6,    31,     8,     9,
      10,    -1,    23,    -1,    14,    15,    16,    -1,    19,    20,
      21,    22,   138,    34,    35,    26,    -1,    27,    19,    20,
      30,    -1,    32,    33,     1,    -1,     3,     4,     5,     6,
      -1,     8,     9,    10,     3,     4,     5,    14,    15,    16,
      -1,    19,    20,    21,    22,    14,    15,    16,    26,    -1,
      27,    19,    20,    30,    -1,    32,    33,     3,     4,     5,
       6,    30,     8,     9,    10,    -1,    -1,    -1,    14,    15,
      16,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    27,    -1,    -1,    30,    -1,    32,    33,     3,     4,
       5,     6,    -1,     8,     9,    10,    -1,    -1,    -1,    14,
      15,    16,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    27,    -1,    -1,    30,    -1,    32,    33,     3,
       4,     5,     6,    -1,     8,     9,    10,    -1,    11,    -1,
      14,    15,    16,    -1,    -1,    -1,    19,    20,    21,    22,
      23,    24,    -1,    27,    27,    11,    30,    -1,    32,    -1,
      -1,    34,    35,    19,    20,    21,    22,    23,    24,    -1,
      -1,    -1,    11,    -1,    -1,    31,    -1,    -1,    34,    35,
      19,    20,    21,    22,    23,    24,    19,    20,    21,    22,
      23,    24,    -1,    -1,    27,    34,    35,    -1,    -1,    -1,
      -1,    34,    35,    19,    20,    21,    22,    23,    24,    19,
      20,    21,    22,    23,    24,    31,    -1,    27,    34,    35,
      -1,    -1,    -1,    -1,    34,    35,    19,    20,    21,    22,
      23,    24,    -1,    -1,    27,    19,    20,    21,    22,    23,
      24,    34,    35,    27,    19,    20,    21,    22,    23,    24,
      34,    35,    27,    19,    20,    21,    22,    23,    24,    34,
      35,    27,    19,    20,    21,    22,    23,    24,    34,    35,
      27,    19,    20,    21,    22,    23,    24,    34,    35,    21,
      22,    23,    24,    -1,    -1,    -1,    34,    35,    -1,    -1,
      -1,    -1,    34,    35
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    17,    37,    30,     0,    31,    32,     3,     4,     5,
       6,     8,     9,    10,    14,    15,    16,    27,    30,    32,
      38,    39,    40,    42,    44,    45,    46,    47,    48,    50,
      30,    30,    30,     5,    49,    30,    46,    47,    48,    33,
      39,    42,    33,    39,    42,     1,    30,    44,    47,    26,
      27,    12,    13,    28,    11,    19,    20,    21,    22,    23,
      24,    27,    34,    35,    19,    20,    21,    22,    26,    46,
      47,    46,    30,    41,    43,    45,    47,    48,    46,    31,
      31,    33,    33,    25,    47,    47,    46,    46,    41,    47,
      47,    47,    47,    47,    47,    47,    47,    47,    26,    26,
      26,    26,    47,    31,    31,    43,    47,    27,    26,    19,
      20,    21,    22,    26,    31,    27,    29,    47,    47,    47,
      47,    27,    40,    40,    31,    46,    47,    26,    26,    26,
      26,    47,    41,    27,    27,    27,    27,     7,    27,    47,
      47,    47,    47,    27,    40,    41,    31,    40
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    36,    37,    38,    38,    38,    39,    39,    39,    39,
      39,    39,    39,    40,    40,    40,    41,    42,    42,    42,
      43,    43,    43,    43,    43,    43,    43,    43,    43,    44,
      44,    44,    44,    44,    44,    44,    44,    44,    45,    46,
      46,    46,    46,    46,    46,    46,    47,    47,    47,    47,
      47,    47,    47,    47,    47,    47,    47,    48,    49,    50,
      50
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     6,     2,     1,     1,     1,     1,     9,     5,
       5,     7,     6,     3,     3,     2,     1,     1,     2,     3,
       3,     3,     3,     1,     1,     4,     4,     4,     4,     1,
       2,     2,     4,     4,     5,     5,     5,     5,     2,     3,
       3,     3,     4,     3,     1,     1,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     1,     1,     1,     1,     1,
       1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


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
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

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
#ifndef YYINITDEPTH
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
static YYSIZE_T
yystrlen (const char *yystr)
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
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

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

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
      yychar = yylex ();
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
     '$$ = $1'.

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
#line 142 "incode.y" /* yacc.c:1646  */
    {
			printf("hello\n");
			s1 = (yyvsp[-1].sval);
			label = newLabel();

			check = strstr (s1,"NE");
			
			while(check!=NULL){
				strncpy (check,label,strlen(label));
				strncpy (check+strlen(label),"    ",(4-strlen(label)));
				check = strstr (s1,"NE");
				}
			check = strstr (s1,"NEXT");
			
			while(check!=NULL){
				strncpy (check,label,strlen(label));
				strncpy (check+strlen(label),"    ",(4-strlen(label)));
				check = strstr (s1,"NEXT");
				}

			ret = (char *)malloc(strlen(s1)+50);
			ret[0] = 0;

			strcat(ret,s1);
			strcat(ret,"\n");
			strcat(ret,label);
			strcat(ret," : end !!!!!\n");
			
			printf("\n----------  INTERMEDIATE CODE ----------\nmain:\n");
			puts(ret);

			(yyval.sval) = ret;
		}
#line 1512 "incode.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 178 "incode.y" /* yacc.c:1646  */
    {

			s1 = (yyvsp[-1].sval);
			s2 = (yyvsp[0].sval);

			label = newLabel();

			check = strstr (s1,"NE");
			
			while(check!=NULL){
				strncpy (check,label,strlen(label));
				strncpy (check+strlen(label),"    ",(4-strlen(label)));
				check = strstr (s1,"NE");
				}
			check = strstr (s1,"NEXT");
			
			while(check!=NULL){
				strncpy (check,label,strlen(label));
				strncpy (check+strlen(label),"    ",(4-strlen(label)));
				check = strstr (s1,"NEXT");
				}
			ret = (char *)malloc(strlen((yyvsp[-1].sval))+strlen((yyvsp[0].sval))+40);
			ret[0] = 0;
			strcat(ret,(yyvsp[-1].sval));
			strcat(ret,"\n");
			strcat(ret,label);
			strcat(ret," : ");
			strcat(ret,(yyvsp[0].sval));

			printf("program construct\n");

			puts(ret);
			(yyval.sval) = ret;
		}
#line 1551 "incode.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 214 "incode.y" /* yacc.c:1646  */
    {
			printf("Final Construct \n");
			puts((yyvsp[0].sval));
			(yyval.sval) = (yyvsp[0].sval);
		}
#line 1561 "incode.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 221 "incode.y" /* yacc.c:1646  */
    {	
			printf("Final list \n");
			puts((yyvsp[0].sval));
			(yyval.sval) = (yyvsp[0].sval);
		}
#line 1571 "incode.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 229 "incode.y" /* yacc.c:1646  */
    {
			(yyval.sval)=(yyvsp[0].sval);
		}
#line 1579 "incode.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 234 "incode.y" /* yacc.c:1646  */
    {
			(yyval.sval) = (yyvsp[0].sval);
		}
#line 1587 "incode.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 239 "incode.y" /* yacc.c:1646  */
    {
				printf("Inside FOR\n");
				begin = newLabel();
				begin2 = newLabel();
				begin3 = newLabel();
				label = newLabel();
				b1=(yyvsp[-4].sval);
				s1=(yyvsp[-6].sval);
			check = strstr (s1,"NEXT");
			while(check!=NULL){
				strncpy (check,begin,strlen(begin));
				strncpy (check+strlen(begin),"    ",(4-strlen(begin)));
				check = strstr (s1,"NEXT");
				}

			ret = (char *)malloc(strlen(b1)+strlen(s1)+40);
			ret[0] = 0;
			ret2 = (char *)malloc(strlen(b1)+strlen(s1)+60);
			ret2[0] = 0;
			strcat(ret,begin);
			strcat(ret," : ");
			strcat(ret,s1);
			strcat(ret,"\n");
			strcpy(ret2,ret);
			b1 = (yyvsp[-4].sval);
			s1 = (yyvsp[0].sval);
			
			label = newLabel();
			check = strstr (b1,"TRUE");
			
			while(check!=NULL){
				strncpy (check,label,strlen(label));
				strncpy (check+strlen(label),"    ",(4-strlen(label)));
				check = strstr (b1,"TRUE");
				}

			check = strstr (b1,"FAIL");
			while(check!=NULL){
				strncpy (check,"NEXT",4);
				strncpy (check+strlen(label),"    ",(4-strlen(label)));
				check = strstr (b1,"FAIL");
				}

			check = strstr (s1,"NEXT");
			while(check!=NULL){
				strncpy (check,begin2,strlen(begin2));
				strncpy (check+strlen(begin2),"    ",(4-strlen(begin2)));
				check = strstr (s1,"NEXT");
				}

			ret = (char *)malloc(strlen(b1)+strlen(s1)+40);
			ret[0] = 0;
			strcat(ret,begin3);
			strcat(ret," : ");
			strcat(ret,b1);
			strcat(ret,"\n");
			strcat(ret,label);
			strcat(ret," : ");
			strcat(ret,s1);

			strcat(ret2,ret);
			s1[0]=0;
			s1=(yyvsp[-2].sval);
			check = strstr (s1,"NEXT");
			while(check!=NULL){
				strncpy (check,begin2,strlen(begin));
				strncpy (check+strlen(begin2),"    ",(4-strlen(begin)));
				check = strstr (s1,"NEXT");
				}

			ret = (char *)malloc(strlen(b1)+strlen(s1)+40);
			ret[0] = 0;
			strcat(ret,"\n");
			strcat(ret,begin2);
			strcat(ret," : ");
			
			strcat(ret,s1);
			strcat(ret,"\n");
			strcat(ret,"goto ");
			strcat(ret,begin3);
			
			strcat(ret2,ret);
			
			(yyval.sval) = ret2;
		}
#line 1677 "incode.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 326 "incode.y" /* yacc.c:1646  */
    {
			printf("Inside WHILE\n");
			b1 = (yyvsp[-2].sval);
			s1 = (yyvsp[0].sval);
			begin = newLabel();
			label = newLabel();
			check = strstr (b1,"TRUE");
			
			while(check!=NULL){
				strncpy (check,label,strlen(label));
				strncpy (check+strlen(label),"    ",(4-strlen(label)));
				check = strstr (b1,"TRUE");
				}

			check = strstr (b1,"FAIL");
			while(check!=NULL){
				strncpy (check,"NEXT",4);
				strncpy (check+strlen(label),"    ",(4-strlen(label)));
				check = strstr (b1,"FAIL");
				}

			check = strstr (s1,"NEXT");
			while(check!=NULL){
				strncpy (check,begin,strlen(begin));
				strncpy (check+strlen(begin),"    ",(4-strlen(begin)));
				check = strstr (s1,"NEXT");
				}

			ret = (char *)malloc(strlen(b1)+strlen(s1)+40);
			ret[0] = 0;
			strcat(ret,begin);
			strcat(ret," : ");
			strcat(ret,b1);
			strcat(ret,"\n");
			strcat(ret,label);
			strcat(ret," : ");
			strcat(ret,s1);

			strcat(ret,"\n");
			strcat(ret,"goto ");
			strcat(ret,begin);
			puts((yyvsp[0].sval));
			printf("\nFinal return from while\n");
			puts(ret);

			(yyval.sval) = ret;
	
		}
#line 1730 "incode.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 376 "incode.y" /* yacc.c:1646  */
    {
			printf("Inside IF\n");
			
			label = newLabel();
			b1 = (yyvsp[-2].sval);

			check = strstr (b1,"TRUE");
			
			while(check!=NULL){
				strncpy (check,label,strlen(label));
				strncpy (check+strlen(label),"    ",(4-strlen(label)));
				check = strstr (b1,"TRUE");
				}
			
			check = strstr (b1,"FAIL");
			
			while(check!=NULL){
				strncpy (check,"NEXT",4);
				//strncpy (check+strlen(label),"    ",(4-strlen(label)));
				check = strstr (b1,"FAIL");
				}

			ret = (char *)malloc(strlen(b1)+strlen((yyvsp[0].sval))+4);
			ret[0] = 0;
			strcat(ret,b1);
			strcat(ret,"\n");
			strcat(ret,label);
			strcat(ret," : ");
			strcat(ret,(yyvsp[0].sval));
			
			puts(ret);
			(yyval.sval) = ret;
		}
#line 1768 "incode.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 411 "incode.y" /* yacc.c:1646  */
    {
			printf("Inside if then else\n");

			b1 = (yyvsp[-4].sval);
			label = newLabel();

			check = strstr (b1,"TRUE");
			
			while(check!=NULL){
				strncpy (check,label,strlen(label));
				strncpy (check+strlen(label),"    ",(4-strlen(label)));
				check = strstr (b1,"TRUE");
				}
			

			label2 = newLabel();
			check = strstr (b1,"FAIL");

			while(check!=NULL){
				strncpy (check,label2,strlen(label2));
				strncpy (check+strlen(label2),"    ",(4-strlen(label2)));
				check = strstr (b1,"FAIL");
				}

			ret = (char *)malloc(strlen(b1)+strlen((yyvsp[-2].sval))+strlen((yyvsp[0].sval))+20);
			ret[0] = 0;
			strcat(ret,b1);
			strcat(ret,"\n");
			strcat(ret,label);
			strcat(ret," : ");
			strcat(ret,(yyvsp[-2].sval));
			strcat(ret,"\n");
			strcat(ret,"goto NEXT");
			strcat(ret,"\n");
			strcat(ret,label2);
			strcat(ret," : ");
			strcat(ret,(yyvsp[0].sval));
			
			puts(ret);

			(yyval.sval) = ret;
	
		}
#line 1816 "incode.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 456 "incode.y" /* yacc.c:1646  */
    {
			printf("Inside ternary\n");

			b1 = (yyvsp[-5].sval);
			label = newLabel();

			check = strstr (b1,"TRUE");
			
			while(check!=NULL){
				strncpy (check,label,strlen(label));
				strncpy (check+strlen(label),"    ",(4-strlen(label)));
				check = strstr (b1,"TRUE");
				}
			

			label2 = newLabel();
			check = strstr (b1,"FAIL");

			while(check!=NULL){
				strncpy (check,label2,strlen(label2));
				strncpy (check+strlen(label2),"    ",(4-strlen(label2)));
				check = strstr (b1,"FAIL");
				}

			ret = (char *)malloc(strlen(b1)+strlen((yyvsp[-3].sval))+strlen((yyvsp[-1].sval))+20);
			ret[0] = 0;
			strcat(ret,b1);
			strcat(ret,"\n");
			strcat(ret,label);
			strcat(ret," : ");
			strcat(ret,(yyvsp[-3].sval));
			strcat(ret,"\n");
			strcat(ret,"goto NEXT");
			//strcat(ret,label2);
			strcat(ret,"\n");
			strcat(ret,label2);
			strcat(ret," : ");
			strcat(ret,(yyvsp[-1].sval));
			
			puts(ret);

			(yyval.sval) = ret;
		}
#line 1864 "incode.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 502 "incode.y" /* yacc.c:1646  */
    {
			printf("Inside block\n");
			(yyval.sval) = (yyvsp[-1].sval);
		}
#line 1873 "incode.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 508 "incode.y" /* yacc.c:1646  */
    {
			printf("Inside block\n");
			(yyval.sval) = (yyvsp[-1].sval);
		}
#line 1882 "incode.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 516 "incode.y" /* yacc.c:1646  */
    {
			printf("Inside list stat2\n");
			(yyval.sval) = (yyvsp[0].EXPRTYPE)->code;
			printf("Exit list stat2\n");
		}
#line 1892 "incode.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 524 "incode.y" /* yacc.c:1646  */
    {
			printf("Inside list stat\n");
			(yyval.sval) = (yyvsp[0].EXPRTYPE)->code;
			printf("Exit list stat\n");
		}
#line 1902 "incode.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 531 "incode.y" /* yacc.c:1646  */
    {
			printf("Inside list\n");
			ret = (char *)malloc(strlen((yyvsp[-1].sval))+strlen((yyvsp[0].EXPRTYPE)->code)+4);
			ret[0] = 0;

			strcat(ret,(yyvsp[-1].sval));
			strcat(ret,"\n");
			strcat(ret,(yyvsp[0].EXPRTYPE)->code);
		
			printf("Inside list stat \n");
			puts(ret);
			(yyval.sval) = ret;
		}
#line 1920 "incode.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 546 "incode.y" /* yacc.c:1646  */
    {
		printf("Inside list\n");
           yyerrok;
         }
#line 1929 "incode.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 553 "incode.y" /* yacc.c:1646  */
    {
		(yyval.EXPRTYPE)=(yyvsp[-1].EXPRTYPE);
	}
#line 1937 "incode.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 558 "incode.y" /* yacc.c:1646  */
    {
		printf("stat2 Dec and Assignment statement \n");
	    
		to_return_expr = (struct exprType *)malloc(sizeof(struct exprType));
		to_return_expr->addr = (char *)malloc(20);
		to_return_expr->addr = newTemp();
		
		ret = (char *)malloc(20);
		ret[0] = 0;

		//strcat(ret,to_return_expr->addr);
		
		strcat(ret,(yyvsp[-2].sval));
		strcat(ret,"=");
		strcat(ret,(yyvsp[0].EXPRTYPE)->addr);
		printf("RET  = \n");
		puts(ret);

		temp = (char *)malloc(strlen((yyvsp[-2].sval))+strlen((yyvsp[0].EXPRTYPE)->code)+strlen(ret)+6);

		temp[0] = 0;
		
		if ((yyvsp[0].EXPRTYPE)->code[0]!=0){
			strcat(temp,(yyvsp[0].EXPRTYPE)->code);
			strcat(temp,"\n");
			}
		strcat(temp,ret);
		printf("TEMP = \n");

		puts(temp);

		to_return_expr->code = temp;

           	(yyval.EXPRTYPE) = to_return_expr;
		printf("Exiting stat2\n");
	}
#line 1978 "incode.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 596 "incode.y" /* yacc.c:1646  */
    {
		printf("stat2 blah Assignment statement \n");
	    if(strcmp((yyvsp[-2].sval),"undeclared")!=0){
		to_return_expr = (struct exprType *)malloc(sizeof(struct exprType));
		to_return_expr->addr = (char *)malloc(20);
		to_return_expr->addr = newTemp();
		
		ret = (char *)malloc(20);
		ret[0] = 0;

		//strcat(ret,to_return_expr->addr);
		
		strcat(ret,(yyvsp[-2].sval));
		strcat(ret,"=");
		strcat(ret,(yyvsp[0].EXPRTYPE)->addr);
		printf("RET  = \n");
		puts(ret);

		temp = (char *)malloc(strlen((yyvsp[-2].sval))+strlen((yyvsp[0].EXPRTYPE)->code)+strlen(ret)+6);

		temp[0] = 0;
		
		if ((yyvsp[0].EXPRTYPE)->code[0]!=0){
			strcat(temp,(yyvsp[0].EXPRTYPE)->code);
			strcat(temp,"\n");
			}
		strcat(temp,ret);
		printf("TEMP = \n");

		puts(temp);

		to_return_expr->code = temp;

           	(yyval.EXPRTYPE) = to_return_expr;
		}
		else
			exit(0);
	}
#line 2021 "incode.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 636 "incode.y" /* yacc.c:1646  */
    {
		printf("inside stat2 expr\n");
		(yyval.EXPRTYPE) = (yyvsp[0].EXPRTYPE);
           
         }
#line 2031 "incode.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 643 "incode.y" /* yacc.c:1646  */
    {
		printf("stat2 dec\n");
		to_return_expr = (struct exprType *)malloc(sizeof(struct exprType));
		to_return_expr->addr = (char *)malloc(20);
		to_return_expr->addr = (yyvsp[0].sval);
		
		to_return_expr->code = (char *)malloc(2);
		to_return_expr->code[0] = 0;
		
		(yyval.EXPRTYPE) = to_return_expr;
           
         }
#line 2048 "incode.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 657 "incode.y" /* yacc.c:1646  */
    {
		printf("$$$$$$$$$$$$$$$$$$$$ %s\n",(yyvsp[-3].sval));
		if(strcmp((yyvsp[-3].sval),"undeclared")!=0){
		to_return_expr = (struct exprType *)malloc(sizeof(struct exprType));
		to_return_expr->addr = (char *)malloc(20);
		to_return_expr->addr = newTemp();
		
		ret = (char *)malloc(20);
		ret[0] = 0;

		
		strcat(ret,to_return_expr->addr);
		strcat(ret,"=");
		strcat(ret,(yyvsp[-3].sval));
		strcat(ret,"+");
		strcat(ret,(yyvsp[0].EXPRTYPE)->addr);
		printf("RET  = \n");
		puts(ret);

		temp = (char *)malloc(strlen((yyvsp[0].EXPRTYPE)->code)+strlen(ret)+6);

		temp[0] = 0;
		
		if ((yyvsp[0].EXPRTYPE)->code[0]!=0){
			strcat(temp,(yyvsp[0].EXPRTYPE)->code);
			strcat(temp,"\n");
			}
		else
		{
			strcat(ret,"\n");
			strcat(ret,(yyvsp[-3].sval));
			strcat(ret,"=");
			strcat(ret,to_return_expr->addr);
		}
		strcat(temp,ret);
		printf("TEMP = \n");

		puts(temp);

		to_return_expr->code = temp;

           	(yyval.EXPRTYPE) = to_return_expr;
		}
		else
			exit(0);
	    
	}
#line 2100 "incode.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 706 "incode.y" /* yacc.c:1646  */
    {
		printf("$$$$$$$$$$$$$$$$$$$$\n");
		if(strcmp((yyvsp[-3].sval),"undeclared")!=0){
		to_return_expr = (struct exprType *)malloc(sizeof(struct exprType));
		to_return_expr->addr = (char *)malloc(20);
		to_return_expr->addr = newTemp();
		
		ret = (char *)malloc(20);
		ret[0] = 0;

		
		strcat(ret,to_return_expr->addr);
		strcat(ret,"=");
		strcat(ret,(yyvsp[-3].sval));
		strcat(ret,"-");
		strcat(ret,(yyvsp[0].EXPRTYPE)->addr);
		printf("RET  = \n");
		puts(ret);

		temp = (char *)malloc(strlen((yyvsp[0].EXPRTYPE)->code)+strlen(ret)+6);

		temp[0] = 0;
		
		if ((yyvsp[0].EXPRTYPE)->code[0]!=0){
			strcat(temp,(yyvsp[0].EXPRTYPE)->code);
			strcat(temp,"\n");
			}
		else
		{
			strcat(ret,"\n");
			strcat(ret,(yyvsp[-3].sval));
			strcat(ret,"=");
			strcat(ret,to_return_expr->addr);
		}
		strcat(temp,ret);
		printf("TEMP = \n");

		puts(temp);

		to_return_expr->code = temp;

           	(yyval.EXPRTYPE) = to_return_expr;
		}
		else
			exit(0);
	    }
#line 2151 "incode.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 754 "incode.y" /* yacc.c:1646  */
    {
		printf("$$$$$$$$$$$$$$$$$$$$\n");
		if(strcmp((yyvsp[-3].sval),"undeclared")!=0){
		to_return_expr = (struct exprType *)malloc(sizeof(struct exprType));
		to_return_expr->addr = (char *)malloc(20);
		to_return_expr->addr = newTemp();
		
		ret = (char *)malloc(20);
		ret[0] = 0;

		
		strcat(ret,to_return_expr->addr);
		strcat(ret,"=");
		strcat(ret,(yyvsp[-3].sval));
		strcat(ret,"*");
		strcat(ret,(yyvsp[0].EXPRTYPE)->addr);
		printf("RET  = \n");
		puts(ret);

		temp = (char *)malloc(strlen((yyvsp[0].EXPRTYPE)->code)+strlen(ret)+6);

		temp[0] = 0;
		
		if ((yyvsp[0].EXPRTYPE)->code[0]!=0){
			strcat(temp,(yyvsp[0].EXPRTYPE)->code);
			strcat(temp,"\n");
			}
		else
		{
			strcat(ret,"\n");
			strcat(ret,(yyvsp[-3].sval));
			strcat(ret,"=");
			strcat(ret,to_return_expr->addr);
		}
		strcat(temp,ret);
		printf("TEMP = \n");

		puts(temp);

		to_return_expr->code = temp;

           	(yyval.EXPRTYPE) = to_return_expr;
		}
		else
			exit(0);
		}
#line 2202 "incode.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 802 "incode.y" /* yacc.c:1646  */
    {
		printf("$$$$$$$$$$$$$$$$$$$$\n");
		if(strcmp((yyvsp[-3].sval),"undeclared")!=0){
		to_return_expr = (struct exprType *)malloc(sizeof(struct exprType));
		to_return_expr->addr = (char *)malloc(20);
		to_return_expr->addr = newTemp();
		
		ret = (char *)malloc(20);
		ret[0] = 0;

		
		strcat(ret,to_return_expr->addr);
		strcat(ret,"=");
		strcat(ret,(yyvsp[-3].sval));
		strcat(ret,"/");
		strcat(ret,(yyvsp[0].EXPRTYPE)->addr);
		printf("RET  = \n");
		puts(ret);

		temp = (char *)malloc(strlen((yyvsp[0].EXPRTYPE)->code)+strlen(ret)+6);

		temp[0] = 0;
		
		if ((yyvsp[0].EXPRTYPE)->code[0]!=0){
			strcat(temp,(yyvsp[0].EXPRTYPE)->code);
			strcat(temp,"\n");
			}
		else
		{
			strcat(ret,"\n");
			strcat(ret,(yyvsp[-3].sval));
			strcat(ret,"=");
			strcat(ret,to_return_expr->addr);
		}
		strcat(temp,ret);
		printf("TEMP = \n");

		puts(temp);

		to_return_expr->code = temp;

           	(yyval.EXPRTYPE) = to_return_expr;
		}
		else
			exit(0);
	    
         }
#line 2254 "incode.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 852 "incode.y" /* yacc.c:1646  */
    {
		to_return_expr = (struct exprType *)malloc(sizeof(struct exprType));
		to_return_expr->addr = (char *)malloc(20);
		to_return_expr->addr = (yyvsp[0].sval);
		
		to_return_expr->code = (char *)malloc(2);
		to_return_expr->code[0] = 0;
		
		(yyval.EXPRTYPE) = to_return_expr;
	 }
#line 2269 "incode.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 864 "incode.y" /* yacc.c:1646  */
    {
		(yyval.EXPRTYPE) = (yyvsp[-1].EXPRTYPE);
           
         }
#line 2278 "incode.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 870 "incode.y" /* yacc.c:1646  */
    {
		printf("stat dec\n");
		to_return_expr = (struct exprType *)malloc(sizeof(struct exprType));
		to_return_expr->addr = (char *)malloc(20);
		to_return_expr->addr = (yyvsp[-1].sval);
		
		to_return_expr->code = (char *)malloc(2);
		to_return_expr->code[0] = 0;
		
		(yyval.EXPRTYPE) = to_return_expr;
           
         }
#line 2295 "incode.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 884 "incode.y" /* yacc.c:1646  */
    {
		if(strcmp((yyvsp[-3].sval),"undeclared")!=0){
	    printf("Assignment statement \n");

		to_return_expr = (struct exprType *)malloc(sizeof(struct exprType));
		to_return_expr->addr = (char *)malloc(20);
		to_return_expr->addr = newTemp();
		
		ret = (char *)malloc(20);
		ret[0] = 0;

		strcat(ret,(yyvsp[-3].sval));

		strcat(ret,"=");
		strcat(ret,(yyvsp[-1].EXPRTYPE)->addr);
		printf("RET  = \n");
		puts(ret);

		temp = (char *)malloc(strlen((yyvsp[-1].EXPRTYPE)->code)+strlen(ret)+6);

		temp[0] = 0;
		
		if ((yyvsp[-1].EXPRTYPE)->code[0]!=0){
			strcat(temp,(yyvsp[-1].EXPRTYPE)->code);
			strcat(temp,"\n");
			}
		strcat(temp,ret);
		printf("TEMP = \n");

		puts(temp);

		to_return_expr->code = temp;

           	(yyval.EXPRTYPE) = to_return_expr;
	    
		}
		else
			exit(0);
		//printf(" %s = %s \n",$1,$3->addr);
          
	    
         }
#line 2342 "incode.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 928 "incode.y" /* yacc.c:1646  */
    {
	    printf("Dec and Assignment statement \n");
	    
		to_return_expr = (struct exprType *)malloc(sizeof(struct exprType));
		to_return_expr->addr = (char *)malloc(20);
		to_return_expr->addr = newTemp();
		
		ret = (char *)malloc(20);
		ret[0] = 0;

		//strcat(ret,to_return_expr->addr);
		
		strcat(ret,(yyvsp[-3].sval));
		strcat(ret,"=");
		strcat(ret,(yyvsp[-1].EXPRTYPE)->addr);
		printf("RET  = \n");
		puts(ret);

		temp = (char *)malloc(strlen((yyvsp[-3].sval))+strlen((yyvsp[-1].EXPRTYPE)->code)+strlen(ret)+6);

		temp[0] = 0;
		
		if ((yyvsp[-1].EXPRTYPE)->code[0]!=0){
			strcat(temp,(yyvsp[-1].EXPRTYPE)->code);
			strcat(temp,"\n");
			}
		strcat(temp,ret);
		printf("TEMP = \n");

		puts(temp);

		to_return_expr->code = temp;

           	(yyval.EXPRTYPE) = to_return_expr;
			
		//printf(" %s = %s \n",$1,$3->addr);
          printf("Exit Dec and Assignment statement \n");
	    
         }
#line 2386 "incode.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 970 "incode.y" /* yacc.c:1646  */
    {
		printf("$$$$$$$$$$$$$$$$$$$$\n");
		if(strcmp((yyvsp[-4].sval),"undeclared")!=0){
		to_return_expr = (struct exprType *)malloc(sizeof(struct exprType));
		to_return_expr->addr = (char *)malloc(20);
		to_return_expr->addr = newTemp();
		
		ret = (char *)malloc(20);
		ret[0] = 0;

		
		strcat(ret,to_return_expr->addr);
		strcat(ret,"=");
		strcat(ret,(yyvsp[-4].sval));
		strcat(ret,"+");
		strcat(ret,(yyvsp[-1].EXPRTYPE)->addr);
		printf("RET  = \n");
		puts(ret);

		temp = (char *)malloc(strlen((yyvsp[-1].EXPRTYPE)->code)+strlen(ret)+6);

		temp[0] = 0;
		
		if ((yyvsp[-1].EXPRTYPE)->code[0]!=0){
			strcat(temp,(yyvsp[-1].EXPRTYPE)->code);
			strcat(temp,"\n");
			}
		else
		{
			strcat(ret,"\n");
			strcat(ret,(yyvsp[-4].sval));
			strcat(ret,"=");
			strcat(ret,to_return_expr->addr);
		}
		strcat(temp,ret);
		printf("TEMP = \n");

		puts(temp);

		to_return_expr->code = temp;

           	(yyval.EXPRTYPE) = to_return_expr;
		}
		else
			exit(0);
	    
	}
#line 2438 "incode.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 1019 "incode.y" /* yacc.c:1646  */
    {
		printf("$$$$$$$$$$$$$$$$$$$$\n");
		if(strcmp((yyvsp[-4].sval),"undeclared")!=0){
		to_return_expr = (struct exprType *)malloc(sizeof(struct exprType));
		to_return_expr->addr = (char *)malloc(20);
		to_return_expr->addr = newTemp();
		
		ret = (char *)malloc(20);
		ret[0] = 0;

		
		strcat(ret,to_return_expr->addr);
		strcat(ret,"=");
		strcat(ret,(yyvsp[-4].sval));
		strcat(ret,"-");
		strcat(ret,(yyvsp[-1].EXPRTYPE)->addr);
		printf("RET  = \n");
		puts(ret);

		temp = (char *)malloc(strlen((yyvsp[-1].EXPRTYPE)->code)+strlen(ret)+6);

		temp[0] = 0;
		
		if ((yyvsp[-1].EXPRTYPE)->code[0]!=0){
			strcat(temp,(yyvsp[-1].EXPRTYPE)->code);
			strcat(temp,"\n");
			}
		else
		{
			strcat(ret,"\n");
			strcat(ret,(yyvsp[-4].sval));
			strcat(ret,"=");
			strcat(ret,to_return_expr->addr);
		}
		strcat(temp,ret);
		printf("TEMP = \n");

		puts(temp);

		to_return_expr->code = temp;

           	(yyval.EXPRTYPE) = to_return_expr;
		}
		else
			exit(0);
	    }
#line 2489 "incode.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 1067 "incode.y" /* yacc.c:1646  */
    {
		printf("$$$$$$$$$$$$$$$$$$$$\n");
		if(strcmp((yyvsp[-4].sval),"undeclared")!=0){
		to_return_expr = (struct exprType *)malloc(sizeof(struct exprType));
		to_return_expr->addr = (char *)malloc(20);
		to_return_expr->addr = newTemp();
		
		ret = (char *)malloc(20);
		ret[0] = 0;

		
		strcat(ret,to_return_expr->addr);
		strcat(ret,"=");
		strcat(ret,(yyvsp[-4].sval));
		strcat(ret,"*");
		strcat(ret,(yyvsp[-1].EXPRTYPE)->addr);
		printf("RET  = \n");
		puts(ret);

		temp = (char *)malloc(strlen((yyvsp[-1].EXPRTYPE)->code)+strlen(ret)+6);

		temp[0] = 0;
		
		if ((yyvsp[-1].EXPRTYPE)->code[0]!=0){
			strcat(temp,(yyvsp[-1].EXPRTYPE)->code);
			strcat(temp,"\n");
			}
		else
		{
			strcat(ret,"\n");
			strcat(ret,(yyvsp[-4].sval));
			strcat(ret,"=");
			strcat(ret,to_return_expr->addr);
		}
		strcat(temp,ret);
		printf("TEMP = \n");

		puts(temp);

		to_return_expr->code = temp;

           	(yyval.EXPRTYPE) = to_return_expr;
		}
		else
			exit(0);
		}
#line 2540 "incode.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 1115 "incode.y" /* yacc.c:1646  */
    {
		printf("$$$$$$$$$$$$$$$$$$$$\n");
		if(strcmp((yyvsp[-4].sval),"undeclared")!=0){
		to_return_expr = (struct exprType *)malloc(sizeof(struct exprType));
		to_return_expr->addr = (char *)malloc(20);
		to_return_expr->addr = newTemp();
		
		ret = (char *)malloc(20);
		ret[0] = 0;

		
		strcat(ret,to_return_expr->addr);
		strcat(ret,"=");
		strcat(ret,(yyvsp[-4].sval));
		strcat(ret,"/");
		strcat(ret,(yyvsp[-1].EXPRTYPE)->addr);
		printf("RET  = \n");
		puts(ret);

		temp = (char *)malloc(strlen((yyvsp[-1].EXPRTYPE)->code)+strlen(ret)+6);

		temp[0] = 0;
		
		if ((yyvsp[-1].EXPRTYPE)->code[0]!=0){
			strcat(temp,(yyvsp[-1].EXPRTYPE)->code);
			strcat(temp,"\n");
			}
		else
		{
			strcat(ret,"\n");
			strcat(ret,(yyvsp[-4].sval));
			strcat(ret,"=");
			strcat(ret,to_return_expr->addr);
		}
		strcat(temp,ret);
		printf("TEMP = \n");

		puts(temp);

		to_return_expr->code = temp;

           	(yyval.EXPRTYPE) = to_return_expr;
		}
		else
			exit(0);
	    
         }
#line 2592 "incode.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 1165 "incode.y" /* yacc.c:1646  */
    {	printf("hellllllllllllooooooooooo\n");
			(yyval.sval) = (yyvsp[0].sval);
			addref((yyvsp[0].sval),TYPES);
		}
#line 2601 "incode.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 1172 "incode.y" /* yacc.c:1646  */
    {
			printf("Inside rel opt\n");

			temp = (char *)malloc(strlen((yyvsp[-2].EXPRTYPE)->code)+strlen((yyvsp[0].EXPRTYPE)->code)+50);
			temp[0] = 0;
	
			if((yyvsp[-2].EXPRTYPE)->code[0]!=0){
				strcat(temp,(yyvsp[-2].EXPRTYPE)->code);
				strcat(temp,"\n");
				}
			if((yyvsp[0].EXPRTYPE)->code[0]!=0){
				strcat(temp,(yyvsp[0].EXPRTYPE)->code);
				strcat(temp,"\n");
				}

			ret = (char *)malloc(50);
			ret[0] = 0;
			strcat(ret,"if(");
			strcat(ret,(yyvsp[-2].EXPRTYPE)->addr);
			strcat(ret,(yyvsp[-1].sval));
			strcat(ret,(yyvsp[0].EXPRTYPE)->addr);
			strcat(ret,") goto TRUE \n goto FAIL");

			strcat(temp,ret);

			(yyval.sval) = temp;
			printf("exiting bool relop\n");
		}
#line 2634 "incode.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 1202 "incode.y" /* yacc.c:1646  */
    {
			printf("Inside OR\n");
			
			b1 = (yyvsp[-2].sval);
			b2 = (yyvsp[0].sval);

			label = newLabel();

			check = strstr (b1,"FAIL");
			
			while(check!=NULL){
				strncpy (check,label,strlen(label));
				strncpy (check+strlen(label),"    ",(4-strlen(label)));
				check = strstr (b1,"FAIL");
				}
			
			temp = (char *)malloc(strlen(b1)+strlen(b2)+10);
			temp[0] = 0;

			strcat(temp,b1);
			strcat(temp,"\n");
			strcat(temp,label);
			strcat(temp," : ");
			strcat(temp,b2);

			(yyval.sval) = temp;
			printf("exiting bool\n");
		}
#line 2667 "incode.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 1232 "incode.y" /* yacc.c:1646  */
    {
			printf("Inside AND\n");

			b1 = (yyvsp[-2].sval);
			b2 = (yyvsp[0].sval);

			label = newLabel();

			check = strstr (b1,"TRUE");
			
			while(check!=NULL){
				strncpy (check,label,strlen(label));
				strncpy (check+strlen(label),"    ",(4-strlen(label)));
				check = strstr (b1,"TRUE");
				}
			
			temp = (char *)malloc(strlen(b1)+strlen(b2)+10);
			temp[0] = 0;

			strcat(temp,b1);
			strcat(temp,"\n");
			strcat(temp,label);
			strcat(temp," : ");
			strcat(temp,b2);

			(yyval.sval) = temp;
			printf("exiting bool\n");
		}
#line 2700 "incode.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 1262 "incode.y" /* yacc.c:1646  */
    {
			printf("Inside NOT\n");
			puts((yyvsp[-1].sval));

			b1 = (yyvsp[-1].sval);

			label = "TEFS";

			check = strstr (b1,"TRUE");
			
			while(check!=NULL){
				strncpy (check,label,strlen(label));
				//strncpy (check+strlen(label),"    ",(4-strlen(label)));
				check = strstr (b1,"TRUE");
				}
			
			label = "TRUE";
			check = strstr (b1,"FAIL");
			
			while(check!=NULL){
				strncpy (check,label,strlen(label));
				//strncpy (check+strlen(label),"    ",(4-strlen(label)));
				check = strstr (b1,"FAIL");
				}

			label = "FAIL";
			check = strstr (b1,"TEFS");
			
			while(check!=NULL){
				strncpy (check,label,strlen(label));
				//strncpy (check+strlen(label),"    ",(4-strlen(label)));
				check = strstr (b1,"TEFS");
				}
			
			(yyval.sval) = b1;
			printf("exiting bool\n");
		}
#line 2742 "incode.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 1301 "incode.y" /* yacc.c:1646  */
    {
			(yyval.sval) = (yyvsp[-1].sval);
			printf("exiting bool bracket\n");
		}
#line 2751 "incode.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 1307 "incode.y" /* yacc.c:1646  */
    {
			printf("Inside TRUE\n");

			ret = (char *)malloc(20);
			ret[0] = 0;
			strcat(ret,"\ngoto TRUE");
			
			(yyval.sval) = ret;
			printf("exiting bool\n");
		}
#line 2766 "incode.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 1319 "incode.y" /* yacc.c:1646  */
    {
			printf("Inside FALSE\n");
			
			printf("Inside TRUE\n");

			ret = (char *)malloc(20);
			ret[0] = 0;
			strcat(ret,"\ngoto FAIL");
			
			(yyval.sval) = ret;
			printf("exiting bool\n");
		}
#line 2783 "incode.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 1334 "incode.y" /* yacc.c:1646  */
    {
           (yyval.EXPRTYPE) = (yyvsp[-1].EXPRTYPE);
         }
#line 2791 "incode.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 1339 "incode.y" /* yacc.c:1646  */
    {
		printf("Exponential : ");
		
		to_return_expr = (struct exprType *)malloc(sizeof(struct exprType));
		to_return_expr->addr = (char *)malloc(20);
		to_return_expr->addr = newTemp();
		
		ret = (char *)malloc(20);
		ret[0] = 0;

		strcat(ret,to_return_expr->addr);

		strcat(ret,"=");
		strcat(ret,(yyvsp[-2].EXPRTYPE)->addr);
		strcat(ret,"^");
		strcat(ret,(yyvsp[0].EXPRTYPE)->addr);
		printf("RET  = \n");
		puts(ret);

		temp = (char *)malloc(strlen((yyvsp[-2].EXPRTYPE)->code)+strlen((yyvsp[0].EXPRTYPE)->code)+strlen(ret)+6);

		temp[0] = 0;
		
		if ((yyvsp[-2].EXPRTYPE)->code[0]!=0){
			strcat(temp,(yyvsp[-2].EXPRTYPE)->code);
			strcat(temp,"\n");
			}
		if ((yyvsp[0].EXPRTYPE)->code[0]!=0){
			strcat(temp,(yyvsp[0].EXPRTYPE)->code);
			strcat(temp,"\n");
			}
		strcat(temp,ret);
		printf("TEMP = \n");

		puts(temp);

		to_return_expr->code = temp;

           	(yyval.EXPRTYPE) = to_return_expr;
	
         }
#line 2837 "incode.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 1382 "incode.y" /* yacc.c:1646  */
    {

           printf("Multiplication : ");
	   	to_return_expr = (struct exprType *)malloc(sizeof(struct exprType));
		to_return_expr->addr = (char *)malloc(20);
		to_return_expr->addr = newTemp();
		
		ret = (char *)malloc(20);
		ret[0] = 0;

		strcat(ret,to_return_expr->addr);

		strcat(ret,"=");
		strcat(ret,(yyvsp[-2].EXPRTYPE)->addr);
		strcat(ret,"*");
		strcat(ret,(yyvsp[0].EXPRTYPE)->addr);
		printf("RET  = \n");
		puts(ret);

		temp = (char *)malloc(strlen((yyvsp[-2].EXPRTYPE)->code)+strlen((yyvsp[0].EXPRTYPE)->code)+strlen(ret)+6);

		temp[0] = 0;
		
		if ((yyvsp[-2].EXPRTYPE)->code[0]!=0){
			strcat(temp,(yyvsp[-2].EXPRTYPE)->code);
			strcat(temp,"\n");
			}
		if ((yyvsp[0].EXPRTYPE)->code[0]!=0){
			strcat(temp,(yyvsp[0].EXPRTYPE)->code);
			strcat(temp,"\n");
			}
		strcat(temp,ret);
		printf("TEMP = \n");

		puts(temp);

		to_return_expr->code = temp;

           	(yyval.EXPRTYPE) = to_return_expr;
           
         }
#line 2883 "incode.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 1425 "incode.y" /* yacc.c:1646  */
    {
           printf("Division : ");
	  	to_return_expr = (struct exprType *)malloc(sizeof(struct exprType));
		to_return_expr->addr = (char *)malloc(20);
		to_return_expr->addr = newTemp();
		
		ret = (char *)malloc(20);
		ret[0] = 0;

		strcat(ret,to_return_expr->addr);

		strcat(ret,"=");
		strcat(ret,(yyvsp[-2].EXPRTYPE)->addr);
		strcat(ret,"/");
		strcat(ret,(yyvsp[0].EXPRTYPE)->addr);
		printf("RET  = \n");
		puts(ret);

		temp = (char *)malloc(strlen((yyvsp[-2].EXPRTYPE)->code)+strlen((yyvsp[0].EXPRTYPE)->code)+strlen(ret)+6);

		temp[0] = 0;
		
		if ((yyvsp[-2].EXPRTYPE)->code[0]!=0){
			strcat(temp,(yyvsp[-2].EXPRTYPE)->code);
			strcat(temp,"\n");
			}
		if ((yyvsp[0].EXPRTYPE)->code[0]!=0){
			strcat(temp,(yyvsp[0].EXPRTYPE)->code);
			strcat(temp,"\n");
			}
		strcat(temp,ret);
		printf("TEMP = \n");

		puts(temp);

		to_return_expr->code = temp;

           	(yyval.EXPRTYPE) = to_return_expr;
	   
         }
#line 2928 "incode.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 1467 "incode.y" /* yacc.c:1646  */
    {
           printf("Modulo Division : ");
	   	to_return_expr = (struct exprType *)malloc(sizeof(struct exprType));
		to_return_expr->addr = (char *)malloc(20);
		to_return_expr->addr = newTemp();
		
		ret = (char *)malloc(20);
		ret[0] = 0;

		strcat(ret,to_return_expr->addr);

		strcat(ret,"=");
		strcat(ret,(yyvsp[-2].EXPRTYPE)->addr);
		strcat(ret,"%");
		strcat(ret,(yyvsp[0].EXPRTYPE)->addr);
		printf("RET  = \n");
		puts(ret);

		temp = (char *)malloc(strlen((yyvsp[-2].EXPRTYPE)->code)+strlen((yyvsp[0].EXPRTYPE)->code)+strlen(ret)+6);

		temp[0] = 0;
		
		if ((yyvsp[-2].EXPRTYPE)->code[0]!=0){
			strcat(temp,(yyvsp[-2].EXPRTYPE)->code);
			strcat(temp,"\n");
			}
		if ((yyvsp[0].EXPRTYPE)->code[0]!=0){
			strcat(temp,(yyvsp[0].EXPRTYPE)->code);
			strcat(temp,"\n");
			}
		strcat(temp,ret);
		printf("TEMP = \n");

		puts(temp);

		to_return_expr->code = temp;

           	(yyval.EXPRTYPE) = to_return_expr;
         }
#line 2972 "incode.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 1508 "incode.y" /* yacc.c:1646  */
    {
           printf("Addition : ");
	   	to_return_expr = (struct exprType *)malloc(sizeof(struct exprType));
		to_return_expr->addr = (char *)malloc(20);
		to_return_expr->addr = newTemp();

		ret = (char *)malloc(20);
		ret[0] = 0;

		strcat(ret,to_return_expr->addr);

		strcat(ret,"=");
		strcat(ret,(yyvsp[-2].EXPRTYPE)->addr);
		strcat(ret,"+");
		strcat(ret,(yyvsp[0].EXPRTYPE)->addr);
		printf("RET  = \n");
		puts(ret);

		temp = (char *)malloc(strlen((yyvsp[-2].EXPRTYPE)->code)+strlen((yyvsp[0].EXPRTYPE)->code)+strlen(ret)+6);

		temp[0] = 0;
		
		if ((yyvsp[-2].EXPRTYPE)->code[0]!=0){
			strcat(temp,(yyvsp[-2].EXPRTYPE)->code);
			strcat(temp,"\n");
			}
		if ((yyvsp[0].EXPRTYPE)->code[0]!=0){
			strcat(temp,(yyvsp[0].EXPRTYPE)->code);
			strcat(temp,"\n");
			}
		strcat(temp,ret);
		printf("TEMP = \n");

		puts(temp);

		to_return_expr->code = temp;

           	(yyval.EXPRTYPE) = to_return_expr;
         }
#line 3016 "incode.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 1549 "incode.y" /* yacc.c:1646  */
    {
	   printf("Subtraction : ");
           	to_return_expr = (struct exprType *)malloc(sizeof(struct exprType));
		to_return_expr->addr = (char *)malloc(20);
		to_return_expr->addr = newTemp();

		ret = (char *)malloc(20);
		ret[0] = 0;

		strcat(ret,to_return_expr->addr);

		strcat(ret,"=");
		strcat(ret,(yyvsp[-2].EXPRTYPE)->addr);
		strcat(ret,"-");
		strcat(ret,(yyvsp[0].EXPRTYPE)->addr);
		printf("RET  = \n");
		puts(ret);

		temp = (char *)malloc(strlen((yyvsp[-2].EXPRTYPE)->code)+strlen((yyvsp[0].EXPRTYPE)->code)+strlen(ret)+6);

		temp[0] = 0;
		
		if ((yyvsp[-2].EXPRTYPE)->code[0]!=0){
			strcat(temp,(yyvsp[-2].EXPRTYPE)->code);
			strcat(temp,"\n");
			}
		if ((yyvsp[0].EXPRTYPE)->code[0]!=0){
			strcat(temp,(yyvsp[0].EXPRTYPE)->code);
			strcat(temp,"\n");
			}
		strcat(temp,ret);
		printf("TEMP = \n");

		puts(temp);
		
		to_return_expr->code = temp;

           	(yyval.EXPRTYPE) = to_return_expr;
		
         }
#line 3061 "incode.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 1591 "incode.y" /* yacc.c:1646  */
    {
	   printf("And : ");
           	to_return_expr = (struct exprType *)malloc(sizeof(struct exprType));
		to_return_expr->addr = (char *)malloc(20);
		to_return_expr->addr = newTemp();

		ret = (char *)malloc(20);
		ret[0] = 0;

		strcat(ret,to_return_expr->addr);

		strcat(ret,"=");
		strcat(ret,(yyvsp[-2].EXPRTYPE)->addr);
		strcat(ret,"&");
		strcat(ret,(yyvsp[0].EXPRTYPE)->addr);
		printf("RET  = \n");
		puts(ret);

		temp = (char *)malloc(strlen((yyvsp[-2].EXPRTYPE)->code)+strlen((yyvsp[0].EXPRTYPE)->code)+strlen(ret)+6);

		temp[0] = 0;
		
		if ((yyvsp[-2].EXPRTYPE)->code[0]!=0){
			strcat(temp,(yyvsp[-2].EXPRTYPE)->code);
			strcat(temp,"\n");
			}
		if ((yyvsp[0].EXPRTYPE)->code[0]!=0){
			strcat(temp,(yyvsp[0].EXPRTYPE)->code);
			strcat(temp,"\n");
			}
		strcat(temp,ret);
		printf("TEMP = \n");

		puts(temp);
		
		to_return_expr->code = temp;

           	(yyval.EXPRTYPE) = to_return_expr;
		
         }
#line 3106 "incode.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 1633 "incode.y" /* yacc.c:1646  */
    {
	   printf("Or : ");
           	to_return_expr = (struct exprType *)malloc(sizeof(struct exprType));
		to_return_expr->addr = (char *)malloc(20);
		to_return_expr->addr = newTemp();

		ret = (char *)malloc(20);
		ret[0] = 0;

		strcat(ret,to_return_expr->addr);

		strcat(ret,"=");
		strcat(ret,(yyvsp[-2].EXPRTYPE)->addr);
		strcat(ret,"|");
		strcat(ret,(yyvsp[0].EXPRTYPE)->addr);
		printf("RET  = \n");
		puts(ret);

		temp = (char *)malloc(strlen((yyvsp[-2].EXPRTYPE)->code)+strlen((yyvsp[0].EXPRTYPE)->code)+strlen(ret)+6);

		temp[0] = 0;
		
		if ((yyvsp[-2].EXPRTYPE)->code[0]!=0){
			strcat(temp,(yyvsp[-2].EXPRTYPE)->code);
			strcat(temp,"\n");
			}
		if ((yyvsp[0].EXPRTYPE)->code[0]!=0){
			strcat(temp,(yyvsp[0].EXPRTYPE)->code);
			strcat(temp,"\n");
			}
		strcat(temp,ret);
		printf("TEMP = \n");

		puts(temp);
		
		to_return_expr->code = temp;

           	(yyval.EXPRTYPE) = to_return_expr;
		
         }
#line 3151 "incode.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 1674 "incode.y" /* yacc.c:1646  */
    {
		if(strcmp((yyvsp[0].sval),"undeclared")!=0){
		printf("Inside text\n");
		to_return_expr = (struct exprType *)malloc(sizeof(struct exprType));
		to_return_expr->addr = (char *)malloc(20);
		to_return_expr->addr = (yyvsp[0].sval);

		to_return_expr->code = (char *)malloc(2);
		to_return_expr->code[0] = 0;

		(yyval.EXPRTYPE) = to_return_expr;
		printf("Exit text\n");
		}
		else
			exit(0);
		}
#line 3172 "incode.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 1691 "incode.y" /* yacc.c:1646  */
    {
		printf("Inside Number\n");
		to_return_expr = (struct exprType *)malloc(sizeof(struct exprType));
		to_return_expr->addr = (char *)malloc(20);
		to_return_expr->addr = (yyvsp[0].sval);
		
		to_return_expr->code = (char *)malloc(2);
		to_return_expr->code[0] = 0;
		
		(yyval.EXPRTYPE) = to_return_expr;}
#line 3187 "incode.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 1704 "incode.y" /* yacc.c:1646  */
    {
		printf("Inside Identifier11111 : %s\n",(yyvsp[0].sval));
		if(lookup((yyvsp[0].sval))==NULL)
		{
			printf("variable undeclared : %s\n",(yyvsp[0].sval));
			strcpy((yyval.sval),"undeclared");
		}
		else
		{
           		(yyval.sval) = (yyvsp[0].sval);
			printf("Exit Identifier : %s\n",(yyvsp[0].sval));
		}
         }
#line 3205 "incode.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 1720 "incode.y" /* yacc.c:1646  */
    {
		printf("Inside Identifier22222 : %s\n",(yyvsp[0].sval));
		/*if(lookup($1)==NULL)
		{
			printf("variable undeclared : %s\n",$1);
			strcpy($$,"undeclared");
			
		}*/
		//else
		{
           		(yyval.sval) = (yyvsp[0].sval);
			printf("Exit Identifier : %s\n",(yyvsp[0].sval));
		}
         }
#line 3224 "incode.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 1737 "incode.y" /* yacc.c:1646  */
    {
		printf("Inside DIGIT : %d\n",(yyvsp[0].ival));
		var = (char *)malloc(20);
           	snprintf(var, 10,"%d",(yyvsp[0].ival));
		(yyval.sval) = var;
           
         }
#line 3236 "incode.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 1746 "incode.y" /* yacc.c:1646  */
    {
		printf("Inside FLOAT : %f\n",(yyvsp[0].fval));
		var = (char *)malloc(20);
           	snprintf(var, 10,"%f",(yyvsp[0].fval));
		(yyval.sval) = var;
           
         }
#line 3248 "incode.tab.c" /* yacc.c:1646  */
    break;


#line 3252 "incode.tab.c" /* yacc.c:1646  */
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

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
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

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

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
  /* Do not reclaim the symbols of the rule whose action triggered
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
  return yyresult;
}
#line 1755 "incode.y" /* yacc.c:1906  */


int main() {
	// open a file handle to a particular file:
	FILE *myfile = fopen("input.txt", "r");
	// make sure it is valid:
	if (!myfile) {
		printf("I can't open a.snazzle.file!");
		return -1;
	}
	// set lex to read from it instead of defaulting to STDIN:
	yyin = myfile;
	
	// parse through the input until there is no more:
	do {
		yyparse();
	} while (!feof(yyin));
	
}

void yyerror(const char *s) {
	printf("EEK, parse error!  Message: ");
	puts(s);
	
	exit(-1);
}

