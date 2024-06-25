/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 2

/* Push parsers.  */
#define YYPUSH 1

/* Pull parsers.  */
#define YYPULL 0




/* First part of user prologue.  */
#line 1 "parser.y"

#include <iostream>
#include <map>
#include <algorithm> // Incluir para std::find
#include <cstring>
#include <sstream> // Para usar std::stringstream
#include <string>  // Para usar std::string

#include "parser.hpp"

std::map<std::string, std::string> symbol_table; // Tabla de símbolos
std::string* goalStr;
//std::string funcProcStr[2];

void yyerror(YYLTYPE* loc, const char* err);
extern int yylex();
extern int yylineno;

int tipo_actual = 0;
int tipo_actual2 = 0;


#line 94 "parser.cpp"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "parser.hpp"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_IDENTIFIER = 3,                 /* IDENTIFIER  */
  YYSYMBOL_INTEGER = 4,                    /* INTEGER  */
  YYSYMBOL_TBOOLEAN = 5,                   /* TBOOLEAN  */
  YYSYMBOL_FBOOLEAN = 6,                   /* FBOOLEAN  */
  YYSYMBOL_FLOAT = 7,                      /* FLOAT  */
  YYSYMBOL_STRING = 8,                     /* STRING  */
  YYSYMBOL_DOUBLE = 9,                     /* DOUBLE  */
  YYSYMBOL_CONSTANT = 10,                  /* CONSTANT  */
  YYSYMBOL_EQUALS = 11,                    /* EQUALS  */
  YYSYMBOL_PLUS = 12,                      /* PLUS  */
  YYSYMBOL_MINUS = 13,                     /* MINUS  */
  YYSYMBOL_TIMES = 14,                     /* TIMES  */
  YYSYMBOL_DIVIDEDBY = 15,                 /* DIVIDEDBY  */
  YYSYMBOL_EQ = 16,                        /* EQ  */
  YYSYMBOL_NEQ = 17,                       /* NEQ  */
  YYSYMBOL_GT = 18,                        /* GT  */
  YYSYMBOL_GTE = 19,                       /* GTE  */
  YYSYMBOL_LT = 20,                        /* LT  */
  YYSYMBOL_LTE = 21,                       /* LTE  */
  YYSYMBOL_RETURN = 22,                    /* RETURN  */
  YYSYMBOL_INDENT = 23,                    /* INDENT  */
  YYSYMBOL_DEDENT = 24,                    /* DEDENT  */
  YYSYMBOL_NEWLINE = 25,                   /* NEWLINE  */
  YYSYMBOL_IF = 26,                        /* IF  */
  YYSYMBOL_COLON = 27,                     /* COLON  */
  YYSYMBOL_AND = 28,                       /* AND  */
  YYSYMBOL_BREAK = 29,                     /* BREAK  */
  YYSYMBOL_ELIF = 30,                      /* ELIF  */
  YYSYMBOL_ELSE = 31,                      /* ELSE  */
  YYSYMBOL_FOR = 32,                       /* FOR  */
  YYSYMBOL_IN = 33,                        /* IN  */
  YYSYMBOL_RANGE = 34,                     /* RANGE  */
  YYSYMBOL_NOT = 35,                       /* NOT  */
  YYSYMBOL_OR = 36,                        /* OR  */
  YYSYMBOL_WHILE = 37,                     /* WHILE  */
  YYSYMBOL_DEF = 38,                       /* DEF  */
  YYSYMBOL_SEMICOLON = 39,                 /* SEMICOLON  */
  YYSYMBOL_LPAREN = 40,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 41,                    /* RPAREN  */
  YYSYMBOL_COMMA = 42,                     /* COMMA  */
  YYSYMBOL_LBRACK = 43,                    /* LBRACK  */
  YYSYMBOL_RBRACK = 44,                    /* RBRACK  */
  YYSYMBOL_YYACCEPT = 45,                  /* $accept  */
  YYSYMBOL_goal = 46,                      /* goal  */
  YYSYMBOL_program = 47,                   /* program  */
  YYSYMBOL_statement = 48,                 /* statement  */
  YYSYMBOL_expression = 49,                /* expression  */
  YYSYMBOL_list = 50,                      /* list  */
  YYSYMBOL_elements = 51,                  /* elements  */
  YYSYMBOL_conditionalExpr = 52,           /* conditionalExpr  */
  YYSYMBOL_conditional = 53,               /* conditional  */
  YYSYMBOL_ifelse = 54,                    /* ifelse  */
  YYSYMBOL_flowcontrol = 55                /* flowcontrol  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

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
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE) \
             + YYSIZEOF (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  30
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   143

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  45
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  11
/* YYNRULES -- Number of rules.  */
#define YYNRULES  47
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  93

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   299


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    54,    54,    57,    61,    65,    66,    67,    68,    70,
      71,   115,   153,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   188,   189,   192,
     193,   196,   197,   198,   199,   200,   201,   202,   203,   207,
     208,   209,   210,   214,   215,   219,   220,   224
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "IDENTIFIER",
  "INTEGER", "TBOOLEAN", "FBOOLEAN", "FLOAT", "STRING", "DOUBLE",
  "CONSTANT", "EQUALS", "PLUS", "MINUS", "TIMES", "DIVIDEDBY", "EQ", "NEQ",
  "GT", "GTE", "LT", "LTE", "RETURN", "INDENT", "DEDENT", "NEWLINE", "IF",
  "COLON", "AND", "BREAK", "ELIF", "ELSE", "FOR", "IN", "RANGE", "NOT",
  "OR", "WHILE", "DEF", "SEMICOLON", "LPAREN", "RPAREN", "COMMA", "LBRACK",
  "RBRACK", "$accept", "goal", "program", "statement", "expression",
  "list", "elements", "conditionalExpr", "conditional", "ifelse",
  "flowcontrol", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-41)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      52,    -8,     0,    48,    26,   129,   -21,    21,   129,    27,
      52,   -41,   -41,   -41,    25,    25,   -41,   -41,    12,    52,
     -41,   -41,   -41,   -41,   -41,   -41,    92,    13,     6,   104,
     -41,   -41,   -41,   -41,   -41,   -41,   -41,   -41,   -41,   -41,
      25,    10,    78,   -41,    82,    32,    35,   129,   129,   129,
     129,   129,   129,    36,   -41,    33,    41,    -5,   -41,    86,
     -40,    25,    25,    25,    25,   -41,   -41,    45,    46,   122,
     122,   122,   122,   122,   122,   -41,    20,   -41,   -41,    25,
     -41,     8,     8,   -41,   -41,   -41,   -41,    69,    86,    40,
      55,    61,   -41
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     7,     0,     0,     0,     0,     0,
       2,     4,     5,    43,     0,     0,    47,     8,     0,     0,
      31,    32,    34,    35,    33,    36,     0,     0,     0,     0,
       1,     3,    18,    13,    16,    17,    14,    20,    15,    19,
       0,     0,     0,    26,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    46,     0,     0,     0,    27,    29,
       0,     0,     0,     0,     0,    10,    11,     0,     0,    42,
      41,    38,    40,    37,    39,    45,     0,    44,    21,     0,
      28,    22,    23,    24,    25,     9,     6,     0,    30,     0,
       0,     0,    12
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -41,   -41,   -41,     2,   -15,   -41,   -41,    -7,    83,   -41,
     -41
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     9,    10,    11,    42,    43,    60,    26,    12,    13,
      18
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      44,    29,    79,    14,    80,    17,    27,    61,    62,    63,
      64,    15,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    46,    63,    64,    28,    57,    59,    30,    32,    33,
      34,    35,    36,    37,    38,    39,    78,    45,    54,    55,
      69,    70,    71,    72,    73,    74,    81,    82,    83,    84,
      40,     1,     5,    41,    58,     1,    67,     6,     2,    68,
      87,    75,     2,     8,    88,    40,    77,    76,    41,    85,
      86,     3,     4,    89,     5,     3,     4,    16,     5,     6,
       7,    90,    91,     6,     7,     8,    92,    19,     0,     8,
      61,    62,    63,    64,    61,    62,    63,    64,    61,    62,
      63,    64,     0,    65,     0,     0,     0,    66,    47,    48,
      49,    50,    51,    52,     0,     0,     0,     0,     0,    53,
      47,    48,    49,    50,    51,    52,     0,     0,     0,     0,
       0,    56,    20,    21,    22,    23,    24,    25,    47,    48,
      49,    50,    51,    52
};

static const yytype_int8 yycheck[] =
{
      15,     8,    42,    11,    44,     3,    27,    12,    13,    14,
      15,    11,    10,     3,     4,     5,     6,     7,     8,     9,
      10,    19,    14,    15,     3,    40,    41,     0,     3,     4,
       5,     6,     7,     8,     9,    10,    41,    25,    25,    33,
      47,    48,    49,    50,    51,    52,    61,    62,    63,    64,
      40,     3,    26,    43,    44,     3,    24,    31,    10,    24,
      40,    25,    10,    37,    79,    40,    25,    34,    43,    24,
      24,    23,    24,     4,    26,    23,    24,    29,    26,    31,
      32,    41,    27,    31,    32,    37,    25,     4,    -1,    37,
      12,    13,    14,    15,    12,    13,    14,    15,    12,    13,
      14,    15,    -1,    25,    -1,    -1,    -1,    25,    16,    17,
      18,    19,    20,    21,    -1,    -1,    -1,    -1,    -1,    27,
      16,    17,    18,    19,    20,    21,    -1,    -1,    -1,    -1,
      -1,    27,     3,     4,     5,     6,     7,     8,    16,    17,
      18,    19,    20,    21
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    10,    23,    24,    26,    31,    32,    37,    46,
      47,    48,    53,    54,    11,    11,    29,    48,    55,    53,
       3,     4,     5,     6,     7,     8,    52,    27,     3,    52,
       0,    48,     3,     4,     5,     6,     7,     8,     9,    10,
      40,    43,    49,    50,    49,    25,    48,    16,    17,    18,
      19,    20,    21,    27,    25,    33,    27,    49,    44,    49,
      51,    12,    13,    14,    15,    25,    25,    24,    24,    52,
      52,    52,    52,    52,    52,    25,    34,    25,    41,    42,
      44,    49,    49,    49,    49,    24,    24,    40,    49,     4,
      41,    27,    25
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    45,    46,    47,    47,    48,    48,    48,    48,    48,
      48,    48,    48,    49,    49,    49,    49,    49,    49,    49,
      49,    49,    49,    49,    49,    49,    49,    50,    50,    51,
      51,    52,    52,    52,    52,    52,    52,    52,    52,    52,
      52,    52,    52,    53,    53,    54,    54,    55
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     5,     1,     2,     5,
       4,     4,     9,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     3,     3,     3,     3,     1,     2,     3,     1,
       3,     1,     1,     1,     1,     1,     1,     3,     3,     3,
       3,     3,     3,     1,     4,     4,     3,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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
        yyerror (&yylloc, YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF

/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


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


/* YYLOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

# ifndef YYLOCATION_PRINT

#  if defined YY_LOCATION_PRINT

   /* Temporary convenience wrapper in case some people defined the
      undocumented and private YY_LOCATION_PRINT macros.  */
#   define YYLOCATION_PRINT(File, Loc)  YY_LOCATION_PRINT(File, *(Loc))

#  elif defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
}

#   define YYLOCATION_PRINT  yy_location_print_

    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT(File, Loc)  YYLOCATION_PRINT(File, &(Loc))

#  else

#   define YYLOCATION_PRINT(File, Loc) ((void) 0)
    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT  YYLOCATION_PRINT

#  endif
# endif /* !defined YYLOCATION_PRINT */


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (yylocationp);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  YYLOCATION_PRINT (yyo, yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yykind, yyvaluep, yylocationp);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)],
                       &(yylsp[(yyi + 1) - (yynrhs)]));
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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
/* Parser data structure.  */
struct yypstate
  {
    /* Number of syntax errors so far.  */
    int yynerrs;

    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    /* The location stack: array, bottom, top.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;
    /* Whether this instance has not started parsing yet.
     * If 2, it corresponds to a finished parsing.  */
    int yynew;
  };






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YY_USE (yyvaluep);
  YY_USE (yylocationp);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}





#define yynerrs yyps->yynerrs
#define yystate yyps->yystate
#define yyerrstatus yyps->yyerrstatus
#define yyssa yyps->yyssa
#define yyss yyps->yyss
#define yyssp yyps->yyssp
#define yyvsa yyps->yyvsa
#define yyvs yyps->yyvs
#define yyvsp yyps->yyvsp
#define yylsa yyps->yylsa
#define yyls yyps->yyls
#define yylsp yyps->yylsp
#define yystacksize yyps->yystacksize

/* Initialize the parser data structure.  */
static void
yypstate_clear (yypstate *yyps)
{
  yynerrs = 0;
  yystate = 0;
  yyerrstatus = 0;

  yyssp = yyss;
  yyvsp = yyvs;
  yylsp = yyls;

  /* Initialize the state stack, in case yypcontext_expected_tokens is
     called before the first call to yyparse. */
  *yyssp = 0;
  yyps->yynew = 1;
}

/* Initialize the parser data structure.  */
yypstate *
yypstate_new (void)
{
  yypstate *yyps;
  yyps = YY_CAST (yypstate *, YYMALLOC (sizeof *yyps));
  if (!yyps)
    return YY_NULLPTR;
  yystacksize = YYINITDEPTH;
  yyss = yyssa;
  yyvs = yyvsa;
  yyls = yylsa;
  yypstate_clear (yyps);
  return yyps;
}

void
yypstate_delete (yypstate *yyps)
{
  if (yyps)
    {
#ifndef yyoverflow
      /* If the stack was reallocated but the parse did not complete, then the
         stack still needs to be freed.  */
      if (yyss != yyssa)
        YYSTACK_FREE (yyss);
#endif
      YYFREE (yyps);
    }
}



/*---------------.
| yypush_parse.  |
`---------------*/

int
yypush_parse (yypstate *yyps,
              int yypushed_char, YYSTYPE const *yypushed_val, YYLTYPE *yypushed_loc)
{
/* Lookahead token kind.  */
int yychar;


/* The semantic value of the lookahead symbol.  */
/* Default value used for initialization, for pacifying older GCCs
   or non-GCC compilers.  */
YY_INITIAL_VALUE (static YYSTYPE yyval_default;)
YYSTYPE yylval YY_INITIAL_VALUE (= yyval_default);

/* Location data for the lookahead symbol.  */
static YYLTYPE yyloc_default
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
YYLTYPE yylloc = yyloc_default;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

  /* The locations where the error started and ended.  */
  YYLTYPE yyerror_range[3];



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  switch (yyps->yynew)
    {
    case 0:
      yyn = yypact[yystate];
      goto yyread_pushed_token;

    case 2:
      yypstate_clear (yyps);
      break;

    default:
      break;
    }

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  yylsp[0] = *yypushed_loc;
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yyls1, yysize * YYSIZEOF (*yylsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      if (!yyps->yynew)
        {
          YYDPRINTF ((stderr, "Return for a new token:\n"));
          yyresult = YYPUSH_MORE;
          goto yypushreturn;
        }
      yyps->yynew = 0;
yyread_pushed_token:
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yypushed_char;
      if (yypushed_val)
        yylval = *yypushed_val;
      if (yypushed_loc)
        yylloc = *yypushed_loc;
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      yyerror_range[1] = yylloc;
      goto yyerrlab1;
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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
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

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* goal: program  */
#line 54 "parser.y"
            { }
#line 1399 "parser.cpp"
    break;

  case 3: /* program: program statement  */
#line 57 "parser.y"
                      {(yyval.str) = new std::string(*(yyvsp[-1].str) + *(yyvsp[0].str));
                      goalStr = new std::string(*(yyval.str));
                      delete (yyvsp[-1].str); delete (yyvsp[0].str); 
                       }
#line 1408 "parser.cpp"
    break;

  case 4: /* program: statement  */
#line 61 "parser.y"
              { (yyval.str) = new std::string(*(yyvsp[0].str)); delete (yyvsp[0].str); }
#line 1414 "parser.cpp"
    break;

  case 5: /* statement: conditional  */
#line 65 "parser.y"
                {(yyval.str) = new std::string(*(yyvsp[0].str)); delete (yyvsp[0].str); }
#line 1420 "parser.cpp"
    break;

  case 6: /* statement: DEDENT conditional statement DEDENT DEDENT  */
#line 66 "parser.y"
                                               { (yyval.str) = new std::string("} " + *(yyvsp[-3].str) + "\n" + *(yyvsp[-2].str) + "}\n}\n"); delete (yyvsp[-3].str); delete (yyvsp[-2].str);}
#line 1426 "parser.cpp"
    break;

  case 7: /* statement: DEDENT  */
#line 67 "parser.y"
           { (yyval.str) = new std::string("}"); }
#line 1432 "parser.cpp"
    break;

  case 8: /* statement: INDENT statement  */
#line 68 "parser.y"
                     {(yyval.str) = new std::string(*(yyvsp[0].str)); delete (yyvsp[0].str); }
#line 1438 "parser.cpp"
    break;

  case 9: /* statement: INDENT flowcontrol NEWLINE DEDENT DEDENT  */
#line 70 "parser.y"
                                             { (yyval.str) = new std::string(*(yyvsp[-3].str) + "; \n}\n}\n"); delete (yyvsp[-3].str); }
#line 1444 "parser.cpp"
    break;

  case 10: /* statement: IDENTIFIER EQUALS expression NEWLINE  */
#line 71 "parser.y"
                                         {
        // Si no existe el id, se genera una declaracion
        if (symbol_table.find(*(yyvsp[-3].str)) == symbol_table.end()) {
            // Determina el tipo del identificador
            std::string type;
            if (tipo_actual == 1 | tipo_actual == 6 ) type = "int";
            else if (tipo_actual == 2) type = "float";
            else if (tipo_actual == 3) type = "bool";
            else if (tipo_actual == 4) type = "char";
            else if (tipo_actual == 5) type = "lista";
            else if (tipo_actual == 7) type = "double";
            else {
                std::cerr << "Error: Tipo no reconocido para el identificador '" << *(yyvsp[-3].str) << "'. En linea: " << yylineno << std::endl;
                exit(1);
            }
            // Agrega el identificador a la tabla de símbolos con su tipo
            symbol_table[*(yyvsp[-3].str)] = type;
            // Construye la cadena de asignación para el output.c
            std::stringstream ss;
            if (type == "char"){
                ss << type << " " << *(yyvsp[-3].str) << "[] = " << *(yyvsp[-1].str) << ";\n";
                (yyval.str) = new std::string(ss.str());
            }else if(type == "lista" && tipo_actual2 == 1){ // ES UN ARRAY INT
                ss << "int " << *(yyvsp[-3].str) << "[] = " << *(yyvsp[-1].str) << ";\n";
                (yyval.str) = new std::string(ss.str());
            }else if(type == "lista" && tipo_actual2 == 2){ // ES UN ARRAY FLOAT
                ss << "float " << *(yyvsp[-3].str) << "[] = " << *(yyvsp[-1].str) << ";\n";
                (yyval.str) = new std::string(ss.str());
            }
            else if(type == "lista" && tipo_actual2 == 3){ // ES UN ARRAY CHAR ARRAY (ojo que acepta sitring tb y deberia ser otra declaracion)
                ss << "char " << *(yyvsp[-3].str) << "[] = " << *(yyvsp[-1].str) << ";\n";
                (yyval.str) = new std::string(ss.str());
            }
            else{
                ss << type << " " << *(yyvsp[-3].str) << " = " << *(yyvsp[-1].str) << ";\n";
                (yyval.str) = new std::string(ss.str());
            }

        } else { (yyval.str) = new std::string(*(yyvsp[-3].str) + " = " + *(yyvsp[-1].str) + ";\n"); } // Ya existe entonces, se asigna nada mas
          tipo_actual = 0;
          tipo_actual2 = 0;
        // Limpia la memoria de los punteros utilizados
        delete (yyvsp[-3].str); delete (yyvsp[-1].str);
    }
#line 1493 "parser.cpp"
    break;

  case 11: /* statement: CONSTANT EQUALS expression NEWLINE  */
#line 115 "parser.y"
                                         {
        // Si no existe el id, se genera una declaracion
        if (symbol_table.find(*(yyvsp[-3].str)) == symbol_table.end()) {
            // Determina el tipo de la constante
            std::string type;
            std::stringstream ss;
            if(tipo_actual2 == 1){ 
                type = "const int";
                ss << "const int " << *(yyvsp[-3].str) << " = " << *(yyvsp[-1].str) << ";\n";
                (yyval.str) = new std::string(ss.str());
                // Agrega el identificador a la tabla de símbolos con su tipo
                symbol_table[*(yyvsp[-3].str)] = type;
            }else if(tipo_actual2 == 2){ 
                type = "const float";
                ss << "const float " << *(yyvsp[-3].str) << " = " << *(yyvsp[-1].str) << ";\n";
                (yyval.str) = new std::string(ss.str());
                // Agrega el identificador a la tabla de símbolos con su tipo
                symbol_table[*(yyvsp[-3].str)] = type;
            }
            else if(tipo_actual2 == 3){ 
                type = "const char";
                ss << "const char " << *(yyvsp[-3].str) << " = " << *(yyvsp[-1].str) << ";\n";
                (yyval.str) = new std::string(ss.str());
                // Agrega el identificador a la tabla de símbolos con su tipo
                symbol_table[*(yyvsp[-3].str)] = type;
            }
            else{
              std::cerr << "Error: Asignacion no valida a constante " << *(yyvsp[-3].str) << ". En linea: " << yylineno << std::endl;
            }
        }else{
          // Si existe no se puede modificar
          std::cerr << "Error: Modificacion no valida a constante " << *(yyvsp[-3].str) << ". En linea: " << yylineno << std::endl;
        }
        tipo_actual = 0;
        tipo_actual2 = 0;
        // Limpia la memoria de los punteros utilizados
        delete (yyvsp[-3].str); delete (yyvsp[-1].str);
    }
#line 1536 "parser.cpp"
    break;

  case 12: /* statement: FOR IDENTIFIER IN RANGE LPAREN INTEGER RPAREN COLON NEWLINE  */
#line 153 "parser.y"
                                                                 {
        (yyval.str) = new std::string("for (int " + *(yyvsp[-7].str) + " = 0; " + *(yyvsp[-7].str) + " <  " + *(yyvsp[-3].str) + "; " + *(yyvsp[-7].str) + "++) {\n"); delete (yyvsp[-7].str); delete (yyvsp[-3].str);
    }
#line 1544 "parser.cpp"
    break;

  case 13: /* expression: INTEGER  */
#line 172 "parser.y"
            { tipo_actual = 1; tipo_actual2 = 1; (yyval.str) = (yyvsp[0].str); }
#line 1550 "parser.cpp"
    break;

  case 14: /* expression: FLOAT  */
#line 173 "parser.y"
          { tipo_actual = 2; tipo_actual2 = 2; (yyval.str) = (yyvsp[0].str); }
#line 1556 "parser.cpp"
    break;

  case 15: /* expression: DOUBLE  */
#line 174 "parser.y"
           { tipo_actual = 7; (yyval.str) = (yyvsp[0].str); }
#line 1562 "parser.cpp"
    break;

  case 16: /* expression: TBOOLEAN  */
#line 175 "parser.y"
             { tipo_actual = 3; (yyval.str) = (yyvsp[0].str); }
#line 1568 "parser.cpp"
    break;

  case 17: /* expression: FBOOLEAN  */
#line 176 "parser.y"
             { tipo_actual = 3; (yyval.str) = (yyvsp[0].str); }
#line 1574 "parser.cpp"
    break;

  case 18: /* expression: IDENTIFIER  */
#line 177 "parser.y"
               {tipo_actual = 6;(yyval.str) = (yyvsp[0].str); }
#line 1580 "parser.cpp"
    break;

  case 19: /* expression: CONSTANT  */
#line 178 "parser.y"
             {tipo_actual = 8;(yyval.str) = (yyvsp[0].str); }
#line 1586 "parser.cpp"
    break;

  case 20: /* expression: STRING  */
#line 179 "parser.y"
           {  tipo_actual = 4; tipo_actual2 = 3; (yyval.str) = (yyvsp[0].str); }
#line 1592 "parser.cpp"
    break;

  case 21: /* expression: LPAREN expression RPAREN  */
#line 180 "parser.y"
                             {  (yyval.str) = new std::string("(" + *(yyvsp[-1].str) + ")"); delete (yyvsp[-1].str);}
#line 1598 "parser.cpp"
    break;

  case 22: /* expression: expression PLUS expression  */
#line 181 "parser.y"
                               { (yyval.str) =  new std::string(*(yyvsp[-2].str) + " + " + *(yyvsp[0].str)); delete (yyvsp[-2].str); delete (yyvsp[0].str);}
#line 1604 "parser.cpp"
    break;

  case 23: /* expression: expression MINUS expression  */
#line 182 "parser.y"
                                { (yyval.str) =  new std::string(*(yyvsp[-2].str) + " - " + *(yyvsp[0].str)); delete (yyvsp[-2].str); delete (yyvsp[0].str);}
#line 1610 "parser.cpp"
    break;

  case 24: /* expression: expression TIMES expression  */
#line 183 "parser.y"
                                { (yyval.str) =  new std::string(*(yyvsp[-2].str) + " * " + *(yyvsp[0].str)); delete (yyvsp[-2].str); delete (yyvsp[0].str);}
#line 1616 "parser.cpp"
    break;

  case 25: /* expression: expression DIVIDEDBY expression  */
#line 184 "parser.y"
                                    { (yyval.str) =  new std::string(*(yyvsp[-2].str) + " / " + *(yyvsp[0].str)); delete (yyvsp[-2].str); delete (yyvsp[0].str);}
#line 1622 "parser.cpp"
    break;

  case 26: /* expression: list  */
#line 185 "parser.y"
         { tipo_actual = 5; (yyval.str) = (yyvsp[0].str); }
#line 1628 "parser.cpp"
    break;

  case 27: /* list: LBRACK RBRACK  */
#line 188 "parser.y"
                  { (yyval.str) = new std::string("[]"); }
#line 1634 "parser.cpp"
    break;

  case 28: /* list: LBRACK elements RBRACK  */
#line 189 "parser.y"
                           { (yyval.str) = new std::string("[" + *(yyvsp[-1].str) + "]"); delete (yyvsp[-1].str); }
#line 1640 "parser.cpp"
    break;

  case 29: /* elements: expression  */
#line 192 "parser.y"
               { (yyval.str) = new std::string(*(yyvsp[0].str)); delete (yyvsp[0].str); }
#line 1646 "parser.cpp"
    break;

  case 30: /* elements: elements COMMA expression  */
#line 193 "parser.y"
                              { (yyval.str) = new std::string(*(yyvsp[-2].str) + ", " + *(yyvsp[0].str)); delete (yyvsp[-2].str); delete (yyvsp[0].str); }
#line 1652 "parser.cpp"
    break;

  case 31: /* conditionalExpr: IDENTIFIER  */
#line 196 "parser.y"
               { (yyval.str) = (yyvsp[0].str); }
#line 1658 "parser.cpp"
    break;

  case 32: /* conditionalExpr: INTEGER  */
#line 197 "parser.y"
            { (yyval.str) = (yyvsp[0].str); }
#line 1664 "parser.cpp"
    break;

  case 33: /* conditionalExpr: FLOAT  */
#line 198 "parser.y"
          { (yyval.str) = (yyvsp[0].str); }
#line 1670 "parser.cpp"
    break;

  case 34: /* conditionalExpr: TBOOLEAN  */
#line 199 "parser.y"
             { (yyval.str) = (yyvsp[0].str); }
#line 1676 "parser.cpp"
    break;

  case 35: /* conditionalExpr: FBOOLEAN  */
#line 200 "parser.y"
             { (yyval.str) = (yyvsp[0].str); }
#line 1682 "parser.cpp"
    break;

  case 36: /* conditionalExpr: STRING  */
#line 201 "parser.y"
           { (yyval.str) = (yyvsp[0].str); }
#line 1688 "parser.cpp"
    break;

  case 37: /* conditionalExpr: conditionalExpr LT conditionalExpr  */
#line 202 "parser.y"
                                       { (yyval.str) = new std::string(*(yyvsp[-2].str) + " < " + *(yyvsp[0].str));  delete (yyvsp[-2].str); delete (yyvsp[0].str);}
#line 1694 "parser.cpp"
    break;

  case 38: /* conditionalExpr: conditionalExpr GT conditionalExpr  */
#line 203 "parser.y"
                                       { 
                                        (yyval.str) = new std::string(*(yyvsp[-2].str) + " > " + *(yyvsp[0].str));
                                        delete (yyvsp[-2].str); delete (yyvsp[0].str);
                                      }
#line 1703 "parser.cpp"
    break;

  case 39: /* conditionalExpr: conditionalExpr LTE conditionalExpr  */
#line 207 "parser.y"
                                        {  (yyval.str) = new std::string(*(yyvsp[-2].str) + " <= " + *(yyvsp[0].str)); delete (yyvsp[-2].str); delete (yyvsp[0].str);}
#line 1709 "parser.cpp"
    break;

  case 40: /* conditionalExpr: conditionalExpr GTE conditionalExpr  */
#line 208 "parser.y"
                                        {  (yyval.str) = new std::string(*(yyvsp[-2].str) + " >= " + *(yyvsp[0].str)); delete (yyvsp[-2].str); delete (yyvsp[0].str);}
#line 1715 "parser.cpp"
    break;

  case 41: /* conditionalExpr: conditionalExpr NEQ conditionalExpr  */
#line 209 "parser.y"
                                        {  (yyval.str) = new std::string(*(yyvsp[-2].str) + " != " + *(yyvsp[0].str)); delete (yyvsp[-2].str); delete (yyvsp[0].str);}
#line 1721 "parser.cpp"
    break;

  case 42: /* conditionalExpr: conditionalExpr EQ conditionalExpr  */
#line 210 "parser.y"
                                       {  (yyval.str) = new std::string(*(yyvsp[-2].str) + " == " + *(yyvsp[0].str)); delete (yyvsp[-2].str); delete (yyvsp[0].str);}
#line 1727 "parser.cpp"
    break;

  case 44: /* conditional: WHILE conditionalExpr COLON NEWLINE  */
#line 215 "parser.y"
                                        { (yyval.str) = new std::string("while (" + *(yyvsp[-2].str) + ") {\n"); delete (yyvsp[-2].str);}
#line 1733 "parser.cpp"
    break;

  case 45: /* ifelse: IF conditionalExpr COLON NEWLINE  */
#line 219 "parser.y"
                                     {  (yyval.str) = new std::string("if(" + *(yyvsp[-2].str) + ") {\n"); delete (yyvsp[-2].str);}
#line 1739 "parser.cpp"
    break;

  case 46: /* ifelse: ELSE COLON NEWLINE  */
#line 220 "parser.y"
                       { (yyval.str) = new std::string("else {"); }
#line 1745 "parser.cpp"
    break;

  case 47: /* flowcontrol: BREAK  */
#line 224 "parser.y"
          { (yyval.str) = new std::string("break"); }
#line 1751 "parser.cpp"
    break;


#line 1755 "parser.cpp"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (&yylloc, YY_("syntax error"));
    }

  yyerror_range[1] = yylloc;
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
                      yytoken, &yylval, &yylloc);
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  ++yylsp;
  YYLLOC_DEFAULT (*yylsp, yyerror_range, 2);

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (&yylloc, YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, yylsp);
      YYPOPSTACK (1);
    }
  yyps->yynew = 2;
  goto yypushreturn;


/*-------------------------.
| yypushreturn -- return.  |
`-------------------------*/
yypushreturn:

  return yyresult;
}
#undef yynerrs
#undef yystate
#undef yyerrstatus
#undef yyssa
#undef yyss
#undef yyssp
#undef yyvsa
#undef yyvs
#undef yyvsp
#undef yylsa
#undef yyls
#undef yylsp
#undef yystacksize
#line 227 "parser.y"


void yyerror(YYLTYPE* loc, const char* err) {
  std::cerr << "Error: " << err << std::endl;

}
