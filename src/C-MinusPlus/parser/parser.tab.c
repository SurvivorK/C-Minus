/* A Bison parser, made by GNU Bison 3.7.6.  */

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
#define YYBISON 30706

/* Bison version string.  */
#define YYBISON_VERSION "3.7.6"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1





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

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_IDENTIFIER = 3,                 /* IDENTIFIER  */
  YYSYMBOL_INTEGER_LITERAL = 4,            /* INTEGER_LITERAL  */
  YYSYMBOL_FLOATING_LITERAL = 5,           /* FLOATING_LITERAL  */
  YYSYMBOL_CHARACTER_LITERAL = 6,          /* CHARACTER_LITERAL  */
  YYSYMBOL_STRING_LITERAL = 7,             /* STRING_LITERAL  */
  YYSYMBOL_AND = 8,                        /* AND  */
  YYSYMBOL_OR = 9,                         /* OR  */
  YYSYMBOL_LEQ = 10,                       /* LEQ  */
  YYSYMBOL_GEQ = 11,                       /* GEQ  */
  YYSYMBOL_EQ = 12,                        /* EQ  */
  YYSYMBOL_NE = 13,                        /* NE  */
  YYSYMBOL_MOD = 14,                       /* MOD  */
  YYSYMBOL_PLUS = 15,                      /* PLUS  */
  YYSYMBOL_MINUS = 16,                     /* MINUS  */
  YYSYMBOL_STAR = 17,                      /* STAR  */
  YYSYMBOL_DIV = 18,                       /* DIV  */
  YYSYMBOL_ASSIGNOP = 19,                  /* ASSIGNOP  */
  YYSYMBOL_LE = 20,                        /* LE  */
  YYSYMBOL_GE = 21,                        /* GE  */
  YYSYMBOL_DOT = 22,                       /* DOT  */
  YYSYMBOL_COMMA = 23,                     /* COMMA  */
  YYSYMBOL_MAO = 24,                       /* MAO  */
  YYSYMBOL_SEMI = 25,                      /* SEMI  */
  YYSYMBOL_WEN = 26,                       /* WEN  */
  YYSYMBOL_LP = 27,                        /* LP  */
  YYSYMBOL_RP = 28,                        /* RP  */
  YYSYMBOL_LB = 29,                        /* LB  */
  YYSYMBOL_RB = 30,                        /* RB  */
  YYSYMBOL_LC = 31,                        /* LC  */
  YYSYMBOL_RC = 32,                        /* RC  */
  YYSYMBOL_NOT = 33,                       /* NOT  */
  YYSYMBOL_INV = 34,                       /* INV  */
  YYSYMBOL_T_AUTO = 35,                    /* T_AUTO  */
  YYSYMBOL_T_BREAK = 36,                   /* T_BREAK  */
  YYSYMBOL_T_CASE = 37,                    /* T_CASE  */
  YYSYMBOL_T_CHAR = 38,                    /* T_CHAR  */
  YYSYMBOL_T_CONST = 39,                   /* T_CONST  */
  YYSYMBOL_T_CONTINUE = 40,                /* T_CONTINUE  */
  YYSYMBOL_T_DEFAULT = 41,                 /* T_DEFAULT  */
  YYSYMBOL_T_DO = 42,                      /* T_DO  */
  YYSYMBOL_T_DOUBLE = 43,                  /* T_DOUBLE  */
  YYSYMBOL_T_ELSE = 44,                    /* T_ELSE  */
  YYSYMBOL_T_ENUM = 45,                    /* T_ENUM  */
  YYSYMBOL_T_EXTERN = 46,                  /* T_EXTERN  */
  YYSYMBOL_T_FLOAT = 47,                   /* T_FLOAT  */
  YYSYMBOL_T_FOR = 48,                     /* T_FOR  */
  YYSYMBOL_T_GOTO = 49,                    /* T_GOTO  */
  YYSYMBOL_T_IF = 50,                      /* T_IF  */
  YYSYMBOL_T_INLINE = 51,                  /* T_INLINE  */
  YYSYMBOL_T_INT = 52,                     /* T_INT  */
  YYSYMBOL_T_LONG = 53,                    /* T_LONG  */
  YYSYMBOL_T_REGISTER = 54,                /* T_REGISTER  */
  YYSYMBOL_T_RESTRICT = 55,                /* T_RESTRICT  */
  YYSYMBOL_T_RETURN = 56,                  /* T_RETURN  */
  YYSYMBOL_T_SHORT = 57,                   /* T_SHORT  */
  YYSYMBOL_T_SIGNED = 58,                  /* T_SIGNED  */
  YYSYMBOL_T_SIZEOF = 59,                  /* T_SIZEOF  */
  YYSYMBOL_T_STATIC = 60,                  /* T_STATIC  */
  YYSYMBOL_T_STRUCT = 61,                  /* T_STRUCT  */
  YYSYMBOL_T_SWITCH = 62,                  /* T_SWITCH  */
  YYSYMBOL_T_TYPEDEF = 63,                 /* T_TYPEDEF  */
  YYSYMBOL_T_UNION = 64,                   /* T_UNION  */
  YYSYMBOL_T_UNSIGNED = 65,                /* T_UNSIGNED  */
  YYSYMBOL_T_VOID = 66,                    /* T_VOID  */
  YYSYMBOL_T_VOLATILE = 67,                /* T_VOLATILE  */
  YYSYMBOL_T_WHILE = 68,                   /* T_WHILE  */
  YYSYMBOL_T_PRINT = 69,                   /* T_PRINT  */
  YYSYMBOL_T_READ = 70,                    /* T_READ  */
  YYSYMBOL_LOWER_THAN_ELSE = 71,           /* LOWER_THAN_ELSE  */
  YYSYMBOL_YYACCEPT = 72,                  /* $accept  */
  YYSYMBOL_program = 73,                   /* program  */
  YYSYMBOL_external_var_list = 74,         /* external_var_list  */
  YYSYMBOL_external_declaration_list = 75, /* external_declaration_list  */
  YYSYMBOL_external_declaration = 76,      /* external_declaration  */
  YYSYMBOL_specifier = 77,                 /* specifier  */
  YYSYMBOL_function_declarator = 78,       /* function_declarator  */
  YYSYMBOL_parameter_list = 79,            /* parameter_list  */
  YYSYMBOL_parameter = 80,                 /* parameter  */
  YYSYMBOL_compound_statement = 81,        /* compound_statement  */
  YYSYMBOL_statement_list = 82,            /* statement_list  */
  YYSYMBOL_statement = 83,                 /* statement  */
  YYSYMBOL_declaration_list = 84,          /* declaration_list  */
  YYSYMBOL_declaration = 85,               /* declaration  */
  YYSYMBOL_Exp = 86,                       /* Exp  */
  YYSYMBOL_ID = 87,                        /* ID  */
  YYSYMBOL_Args = 88                       /* Args  */
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

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
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
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   298

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  72
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  17
/* YYNRULES -- Number of rules.  */
#define YYNRULES  56
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  111

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   326


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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    61,    61,    69,    73,    79,    80,    95,   112,   114,
     128,   132,   138,   142,   148,   156,   163,   167,   174,   178,
     182,   186,   190,   194,   198,   202,   206,   210,   217,   218,
     225,   250,   254,   258,   262,   266,   270,   274,   278,   282,
     286,   290,   294,   298,   302,   306,   310,   314,   318,   322,
     333,   337,   338,   340,   344,   349,   353
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
  "INTEGER_LITERAL", "FLOATING_LITERAL", "CHARACTER_LITERAL",
  "STRING_LITERAL", "AND", "OR", "LEQ", "GEQ", "EQ", "NE", "MOD", "PLUS",
  "MINUS", "STAR", "DIV", "ASSIGNOP", "LE", "GE", "DOT", "COMMA", "MAO",
  "SEMI", "WEN", "LP", "RP", "LB", "RB", "LC", "RC", "NOT", "INV",
  "T_AUTO", "T_BREAK", "T_CASE", "T_CHAR", "T_CONST", "T_CONTINUE",
  "T_DEFAULT", "T_DO", "T_DOUBLE", "T_ELSE", "T_ENUM", "T_EXTERN",
  "T_FLOAT", "T_FOR", "T_GOTO", "T_IF", "T_INLINE", "T_INT", "T_LONG",
  "T_REGISTER", "T_RESTRICT", "T_RETURN", "T_SHORT", "T_SIGNED",
  "T_SIZEOF", "T_STATIC", "T_STRUCT", "T_SWITCH", "T_TYPEDEF", "T_UNION",
  "T_UNSIGNED", "T_VOID", "T_VOLATILE", "T_WHILE", "T_PRINT", "T_READ",
  "LOWER_THAN_ELSE", "$accept", "program", "external_var_list",
  "external_declaration_list", "external_declaration", "specifier",
  "function_declarator", "parameter_list", "parameter",
  "compound_statement", "statement_list", "statement", "declaration_list",
  "declaration", "Exp", "ID", "Args", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326
};
#endif

#define YYPACT_NINF (-49)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-55)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -49,     5,   -48,   -49,   -49,   -49,   -48,     8,   -49,   -49,
      11,    -4,   -49,    -8,     0,   -49,   -49,   -49,     7,   -48,
     -49,    26,   -15,   -49,    49,   -49,   -49,   -48,   -49,     4,
     -49,   -49,    94,    94,   -49,    94,    25,    32,    31,    -1,
      41,    44,    45,   -49,   -49,   199,    50,   -49,    37,   126,
     -49,   -49,   -49,    94,   -49,   217,    94,    94,    56,    94,
      94,    94,    94,    94,    94,    94,    94,    94,    94,    94,
      94,    94,    94,   -49,    63,   -49,   157,   -49,   178,   235,
     -49,   277,   265,    46,    46,    46,    46,   -49,    37,    37,
     -49,   -49,   251,    46,    46,   -49,   251,    -6,    -8,    -8,
      94,    94,   -49,    42,   -49,    -3,   251,    -8,    62,   -49,
     -49
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       3,     0,     5,     1,     9,     8,     2,     0,     4,     6,
       0,     0,    54,     0,     0,    30,    28,     7,     0,    16,
      11,     0,     0,    13,     0,    29,    14,     0,    10,    51,
      52,    53,     0,     0,    15,     0,     0,     0,     0,     0,
       0,     0,     0,    19,    17,     0,     0,    12,    46,     0,
      47,    26,    27,     0,    21,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    18,     0,    45,     0,    22,     0,     0,
      50,    32,    33,    37,    36,    38,    39,    44,    40,    41,
      42,    43,    31,    35,    34,    49,    56,     0,     0,     0,
       0,     0,    48,    23,    25,     0,    55,     0,     0,    24,
      20
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -49,   -49,   -49,   -49,   -49,     1,   -49,   -49,    61,   -24,
     -49,   -49,   -49,    73,   -23,    83,    -5
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     1,     2,     6,     9,     7,    13,    22,    23,    17,
      24,    44,    19,     8,    96,    46,    97
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      43,    45,    29,    30,     4,     3,    31,    10,    27,    48,
      49,    11,    50,    28,    12,    32,    55,   101,     5,    21,
     101,    15,   102,    16,    54,   108,    33,    18,    21,    26,
      76,   -54,    35,    78,    79,    20,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      51,    65,    29,    30,    68,    69,    31,    52,    53,     4,
      65,    66,    67,    68,    69,    32,    29,    30,    56,    42,
      31,    57,    58,     5,   103,   104,    33,    74,   106,    32,
      16,    34,    35,   109,    80,    36,   107,   110,    47,    37,
      33,    95,    25,    14,     0,   105,    35,    29,    30,    38,
       0,    31,     0,     0,     0,    39,     0,     0,     0,     0,
      32,     0,     0,     0,     0,     0,     0,    40,    41,    42,
       0,    33,     0,     0,     0,     0,     0,    35,     0,     0,
       0,     0,     0,    42,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,     0,     0,
       0,     0,     0,     0,    75,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    42,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,     0,
       0,     0,     0,     0,     0,    98,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
       0,     0,     0,     0,     0,     0,    99,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,     0,     0,     0,    73,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,     0,
       0,     0,    77,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,     0,   100,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    59,     0,    61,    62,    63,    64,    65,
      66,    67,    68,    69,     0,    71,    72,    61,    62,    63,
      64,    65,    66,    67,    68,    69,     0,    71,    72
};

static const yytype_int8 yycheck[] =
{
      24,    24,     3,     4,    52,     0,     7,     6,    23,    32,
      33,     3,    35,    28,     3,    16,    39,    23,    66,    18,
      23,    25,    28,    31,    25,    28,    27,    27,    27,     3,
      53,    27,    33,    56,    57,    28,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      25,    14,     3,     4,    17,    18,     7,    25,    27,    52,
      14,    15,    16,    17,    18,    16,     3,     4,    27,    70,
       7,    27,    27,    66,    98,    99,    27,    27,   101,    16,
      31,    32,    33,   107,    28,    36,    44,    25,    27,    40,
      27,    28,    19,    10,    -1,   100,    33,     3,     4,    50,
      -1,     7,    -1,    -1,    -1,    56,    -1,    -1,    -1,    -1,
      16,    -1,    -1,    -1,    -1,    -1,    -1,    68,    69,    70,
      -1,    27,    -1,    -1,    -1,    -1,    -1,    33,    -1,    -1,
      -1,    -1,    -1,    70,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    -1,    -1,
      -1,    -1,    -1,    -1,    28,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    70,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    -1,
      -1,    -1,    -1,    -1,    -1,    28,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      -1,    -1,    -1,    -1,    -1,    -1,    28,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    -1,    -1,    -1,    25,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    -1,
      -1,    -1,    25,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    -1,    23,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,     8,    -1,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    -1,    20,    21,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    -1,    20,    21
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    73,    74,     0,    52,    66,    75,    77,    85,    76,
      77,     3,     3,    78,    87,    25,    31,    81,    27,    84,
      28,    77,    79,    80,    82,    85,     3,    23,    28,     3,
       4,     7,    16,    27,    32,    33,    36,    40,    50,    56,
      68,    69,    70,    81,    83,    86,    87,    80,    86,    86,
      86,    25,    25,    27,    25,    86,    27,    27,    27,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    25,    27,    28,    86,    25,    86,    86,
      28,    86,    86,    86,    86,    86,    86,    86,    86,    86,
      86,    86,    86,    86,    86,    28,    86,    88,    28,    28,
      23,    23,    28,    81,    81,    88,    86,    44,    28,    81,
      25
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    72,    73,    74,    74,    75,    75,    76,    77,    77,
      78,    78,    79,    79,    80,    81,    82,    82,    83,    83,
      83,    83,    83,    83,    83,    83,    83,    83,    84,    84,
      85,    86,    86,    86,    86,    86,    86,    86,    86,    86,
      86,    86,    86,    86,    86,    86,    86,    86,    86,    86,
      86,    86,    86,    86,    87,    88,    88
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     0,     2,     0,     2,     3,     1,     1,
       4,     3,     3,     1,     2,     4,     0,     2,     2,     1,
       7,     2,     3,     5,     7,     5,     2,     2,     0,     2,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     2,     2,     4,     3,
       3,     1,     1,     1,     1,     3,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


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
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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
# ifndef YY_LOCATION_PRINT
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yykind < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yykind], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
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
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */
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
    goto yyexhaustedlab;
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

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

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
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
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


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* program: external_var_list external_declaration_list  */
#line 61 "parser.y"
                                                       {
                root = new NodeBase();
                root->childrens.push_back((yyvsp[-1].expr));
                root->childrens.push_back((yyvsp[0].expr));
                setpos(root);
            }
#line 1278 "parser.tab.c"
    break;

  case 3: /* external_var_list: %empty  */
#line 69 "parser.y"
                   {
                (yyval.expr) = new GlobalVarList();
                setpos((yyval.expr));
            }
#line 1287 "parser.tab.c"
    break;

  case 4: /* external_var_list: external_var_list declaration  */
#line 73 "parser.y"
                                          {
            (yyvsp[-1].expr)->childrens.push_back((yyvsp[0].expr));
            (yyval.expr) = (yyvsp[-1].expr);
        }
#line 1296 "parser.tab.c"
    break;

  case 5: /* external_declaration_list: %empty  */
#line 79 "parser.y"
                   {(yyval.expr) = new GlobalDeclarationList(); setpos((yyval.expr)); }
#line 1302 "parser.tab.c"
    break;

  case 6: /* external_declaration_list: external_declaration_list external_declaration  */
#line 80 "parser.y"
                                                          {
            (yyvsp[-1].expr)->childrens.push_back((yyvsp[0].expr));
            (yyval.expr) = (yyvsp[-1].expr);
        }
#line 1311 "parser.tab.c"
    break;

  case 7: /* external_declaration: specifier function_declarator compound_statement  */
#line 95 "parser.y"
                                                             {
                (yyval.expr) = new GlobalFuncDecl((yyvsp[-2].expr), (yyvsp[-1].expr), (yyvsp[0].expr));
                setpos((yyval.expr));
            }
#line 1320 "parser.tab.c"
    break;

  case 8: /* specifier: T_VOID  */
#line 112 "parser.y"
                          {(yyval.expr) = new Type(Type::VARTYPE::VOID); setpos((yyval.expr));}
#line 1326 "parser.tab.c"
    break;

  case 9: /* specifier: T_INT  */
#line 114 "parser.y"
                          {(yyval.expr) = new Type(Type::VARTYPE::INT); setpos((yyval.expr));}
#line 1332 "parser.tab.c"
    break;

  case 10: /* function_declarator: ID LP parameter_list RP  */
#line 128 "parser.y"
                                    {
                (yyval.expr) = new FunctionDeclarator((yyvsp[-3].expr), (yyvsp[-1].expr));
                setpos((yyval.expr));
            }
#line 1341 "parser.tab.c"
    break;

  case 11: /* function_declarator: ID LP RP  */
#line 132 "parser.y"
                     {
                (yyval.expr) = new FunctionDeclarator((yyvsp[-2].expr));
                setpos((yyval.expr));
            }
#line 1350 "parser.tab.c"
    break;

  case 12: /* parameter_list: parameter_list COMMA parameter  */
#line 138 "parser.y"
                                            {
                (yyvsp[-2].expr)->childrens.push_back((yyvsp[0].expr));
                (yyval.expr) = (yyvsp[-2].expr);
            }
#line 1359 "parser.tab.c"
    break;

  case 13: /* parameter_list: parameter  */
#line 142 "parser.y"
                      {
                (yyval.expr) = new ParameterList((yyvsp[0].expr));
                setpos((yyval.expr));
            }
#line 1368 "parser.tab.c"
    break;

  case 14: /* parameter: specifier IDENTIFIER  */
#line 148 "parser.y"
                                 {
                (yyval.expr) = new Parameter((yyvsp[-1].expr), new DirectDeclarator((yyvsp[0].expr)));
                setpos((yyval.expr));
            }
#line 1377 "parser.tab.c"
    break;

  case 15: /* compound_statement: LC declaration_list statement_list RC  */
#line 156 "parser.y"
                                                  {
                (yyval.expr) = new CompStmt((yyvsp[-2].expr), (yyvsp[-1].expr));
                setpos((yyval.expr));
            }
#line 1386 "parser.tab.c"
    break;

  case 16: /* statement_list: %empty  */
#line 163 "parser.y"
                   {
                (yyval.expr) = new StmtList();
                setpos((yyval.expr));
            }
#line 1395 "parser.tab.c"
    break;

  case 17: /* statement_list: statement_list statement  */
#line 167 "parser.y"
                                     {
                (yyvsp[-1].expr)->childrens.push_back((yyvsp[0].expr));
                (yyval.expr) = (yyvsp[-1].expr);
            }
#line 1404 "parser.tab.c"
    break;

  case 18: /* statement: Exp SEMI  */
#line 174 "parser.y"
                     {
                (yyval.expr) = (yyvsp[-1].expr);
                setpos((yyval.expr));
            }
#line 1413 "parser.tab.c"
    break;

  case 19: /* statement: compound_statement  */
#line 178 "parser.y"
                               {
                (yyval.expr) = (yyvsp[0].expr);
                setpos((yyval.expr));
            }
#line 1422 "parser.tab.c"
    break;

  case 20: /* statement: T_PRINT LP Exp COMMA Args RP SEMI  */
#line 182 "parser.y"
                                              {
                (yyval.expr) = new PrintStmt((yyvsp[-4].expr), (yyvsp[-2].expr));
                setpos((yyval.expr));
            }
#line 1431 "parser.tab.c"
    break;

  case 21: /* statement: T_RETURN SEMI  */
#line 186 "parser.y"
                          {
                (yyval.expr) = new ReturnStmt();
                setpos((yyval.expr));
            }
#line 1440 "parser.tab.c"
    break;

  case 22: /* statement: T_RETURN Exp SEMI  */
#line 190 "parser.y"
                              {
                (yyval.expr) = new ReturnStmt((yyvsp[-1].expr));
                setpos((yyval.expr));
            }
#line 1449 "parser.tab.c"
    break;

  case 23: /* statement: T_IF LP Exp RP compound_statement  */
#line 194 "parser.y"
                                                                    {
                (yyval.expr) = new IfStmt((yyvsp[-2].expr), (yyvsp[0].expr));
                setpos((yyval.expr));
            }
#line 1458 "parser.tab.c"
    break;

  case 24: /* statement: T_IF LP Exp RP compound_statement T_ELSE compound_statement  */
#line 198 "parser.y"
                                                                        {
                (yyval.expr) = new IfStmt((yyvsp[-4].expr), (yyvsp[-2].expr), (yyvsp[0].expr));
                setpos((yyval.expr));
            }
#line 1467 "parser.tab.c"
    break;

  case 25: /* statement: T_WHILE LP Exp RP compound_statement  */
#line 202 "parser.y"
                                                 {
                (yyval.expr) = new WhileStmt((yyvsp[-2].expr), (yyvsp[0].expr));
                setpos((yyval.expr));
            }
#line 1476 "parser.tab.c"
    break;

  case 26: /* statement: T_BREAK SEMI  */
#line 206 "parser.y"
                         {
                (yyval.expr) = new BreakStmt();
                setpos((yyval.expr));
            }
#line 1485 "parser.tab.c"
    break;

  case 27: /* statement: T_CONTINUE SEMI  */
#line 210 "parser.y"
                            {
                (yyval.expr) = new ContinueStmt();
                setpos((yyval.expr));
            }
#line 1494 "parser.tab.c"
    break;

  case 28: /* declaration_list: %empty  */
#line 217 "parser.y"
                   { (yyval.expr) = new DeclarationList(); setpos((yyval.expr)); }
#line 1500 "parser.tab.c"
    break;

  case 29: /* declaration_list: declaration_list declaration  */
#line 218 "parser.y"
                                         {
                (yyvsp[-1].expr)->childrens.push_back((yyvsp[0].expr));
                (yyval.expr) = (yyvsp[-1].expr);
            }
#line 1509 "parser.tab.c"
    break;

  case 30: /* declaration: specifier IDENTIFIER SEMI  */
#line 225 "parser.y"
                                      {
                (yyval.expr) = new Declarations((yyvsp[-2].expr), new DirectDeclarator((yyvsp[-1].expr)));
                setpos((yyval.expr));
            }
#line 1518 "parser.tab.c"
    break;

  case 31: /* Exp: Exp ASSIGNOP Exp  */
#line 250 "parser.y"
                             {
                (yyval.expr) = new BinaryAssignments((yyvsp[-2].expr), BinaryAssignments::AssignOP::ASSIGNEQ, (yyvsp[0].expr));
                setpos((yyval.expr));
            }
#line 1527 "parser.tab.c"
    break;

  case 32: /* Exp: Exp AND Exp  */
#line 254 "parser.y"
                        {
                (yyval.expr) = new BinaryOperators((yyvsp[-2].expr), BinaryOperators::OP::LOGAND, (yyvsp[0].expr));
                setpos((yyval.expr));
            }
#line 1536 "parser.tab.c"
    break;

  case 33: /* Exp: Exp OR Exp  */
#line 258 "parser.y"
                       {
                (yyval.expr) = new BinaryOperators((yyvsp[-2].expr), BinaryOperators::OP::LOGOR, (yyvsp[0].expr));
                setpos((yyval.expr));
            }
#line 1545 "parser.tab.c"
    break;

  case 34: /* Exp: Exp GE Exp  */
#line 262 "parser.y"
                       {
                (yyval.expr) = new BinaryOperators((yyvsp[-2].expr), BinaryOperators::OP::GE, (yyvsp[0].expr));
                setpos((yyval.expr));
            }
#line 1554 "parser.tab.c"
    break;

  case 35: /* Exp: Exp LE Exp  */
#line 266 "parser.y"
                       {
                (yyval.expr) = new BinaryOperators((yyvsp[-2].expr), BinaryOperators::OP::LE, (yyvsp[0].expr));
                setpos((yyval.expr));
            }
#line 1563 "parser.tab.c"
    break;

  case 36: /* Exp: Exp GEQ Exp  */
#line 270 "parser.y"
                        {
                (yyval.expr) = new BinaryOperators((yyvsp[-2].expr), BinaryOperators::OP::GEQ, (yyvsp[0].expr));
                setpos((yyval.expr));
            }
#line 1572 "parser.tab.c"
    break;

  case 37: /* Exp: Exp LEQ Exp  */
#line 274 "parser.y"
                        {
                (yyval.expr) = new BinaryOperators((yyvsp[-2].expr), BinaryOperators::OP::LEQ, (yyvsp[0].expr));
                setpos((yyval.expr));
            }
#line 1581 "parser.tab.c"
    break;

  case 38: /* Exp: Exp EQ Exp  */
#line 278 "parser.y"
                       {
                (yyval.expr) = new BinaryOperators((yyvsp[-2].expr), BinaryOperators::OP::EQ, (yyvsp[0].expr));
                setpos((yyval.expr));
            }
#line 1590 "parser.tab.c"
    break;

  case 39: /* Exp: Exp NE Exp  */
#line 282 "parser.y"
                       {
                (yyval.expr) = new BinaryOperators((yyvsp[-2].expr), BinaryOperators::OP::NEQ, (yyvsp[0].expr));
                setpos((yyval.expr));
            }
#line 1599 "parser.tab.c"
    break;

  case 40: /* Exp: Exp PLUS Exp  */
#line 286 "parser.y"
                         {
                (yyval.expr) = new BinaryOperators((yyvsp[-2].expr), BinaryOperators::OP::ADD, (yyvsp[0].expr));
                setpos((yyval.expr));
            }
#line 1608 "parser.tab.c"
    break;

  case 41: /* Exp: Exp MINUS Exp  */
#line 290 "parser.y"
                          {
                (yyval.expr) = new BinaryOperators((yyvsp[-2].expr), BinaryOperators::OP::SUB, (yyvsp[0].expr));
                setpos((yyval.expr));
            }
#line 1617 "parser.tab.c"
    break;

  case 42: /* Exp: Exp STAR Exp  */
#line 294 "parser.y"
                         {
                (yyval.expr) = new BinaryOperators((yyvsp[-2].expr), BinaryOperators::OP::MUL, (yyvsp[0].expr));
                setpos((yyval.expr));
            }
#line 1626 "parser.tab.c"
    break;

  case 43: /* Exp: Exp DIV Exp  */
#line 298 "parser.y"
                        {
                (yyval.expr) = new BinaryOperators((yyvsp[-2].expr), BinaryOperators::OP::DIV, (yyvsp[0].expr));
                setpos((yyval.expr));
            }
#line 1635 "parser.tab.c"
    break;

  case 44: /* Exp: Exp MOD Exp  */
#line 302 "parser.y"
                        {
                (yyval.expr) = new BinaryOperators((yyvsp[-2].expr), BinaryOperators::OP::MOD, (yyvsp[0].expr));
                setpos((yyval.expr));
            }
#line 1644 "parser.tab.c"
    break;

  case 45: /* Exp: LP Exp RP  */
#line 306 "parser.y"
                      {
                (yyval.expr) = (yyvsp[-1].expr);
                setpos((yyval.expr));
            }
#line 1653 "parser.tab.c"
    break;

  case 46: /* Exp: MINUS Exp  */
#line 310 "parser.y"
                      {
                (yyval.expr) = new UnaryOperators(UnaryOperators::OP::SUB, (yyvsp[0].expr));
                setpos((yyval.expr));
            }
#line 1662 "parser.tab.c"
    break;

  case 47: /* Exp: NOT Exp  */
#line 314 "parser.y"
                    {
                (yyval.expr) = new UnaryOperators(UnaryOperators::OP::NOT, (yyvsp[0].expr));
                setpos((yyval.expr));
            }
#line 1671 "parser.tab.c"
    break;

  case 48: /* Exp: ID LP Args RP  */
#line 318 "parser.y"
                          {
                (yyval.expr) = new FunctionCall((yyvsp[-3].expr), (yyvsp[-1].expr));
                setpos((yyval.expr));
            }
#line 1680 "parser.tab.c"
    break;

  case 49: /* Exp: ID LP RP  */
#line 322 "parser.y"
                     {
                (yyval.expr) = new FunctionCall((yyvsp[-2].expr));
                setpos((yyval.expr));
            }
#line 1689 "parser.tab.c"
    break;

  case 50: /* Exp: T_READ LP RP  */
#line 333 "parser.y"
                        {
                (yyval.expr) = new ReadInt();
                setpos((yyval.expr));
            }
#line 1698 "parser.tab.c"
    break;

  case 51: /* Exp: IDENTIFIER  */
#line 337 "parser.y"
                            {(yyval.expr) = new ExpID(*yylval.string_val);setpos((yyval.expr));}
#line 1704 "parser.tab.c"
    break;

  case 52: /* Exp: INTEGER_LITERAL  */
#line 338 "parser.y"
                            {(yyval.expr) = new Constants(Type::VARTYPE::INT,*yylval.string_val);setpos((yyval.expr));}
#line 1710 "parser.tab.c"
    break;

  case 53: /* Exp: STRING_LITERAL  */
#line 340 "parser.y"
                             {(yyval.expr) = new Constants(Type::VARTYPE::STRING,*yylval.string_val);setpos((yyval.expr));}
#line 1716 "parser.tab.c"
    break;

  case 54: /* ID: IDENTIFIER  */
#line 344 "parser.y"
                      {
                (yyval.expr) = new Identifier(*yylval.string_val);
                setpos((yyval.expr));
            }
#line 1725 "parser.tab.c"
    break;

  case 55: /* Args: Args COMMA Exp  */
#line 349 "parser.y"
                           {
                (yyvsp[-2].expr)->childrens.push_back((yyvsp[0].expr));
                (yyval.expr) = (yyvsp[-2].expr);
            }
#line 1734 "parser.tab.c"
    break;

  case 56: /* Args: Exp  */
#line 353 "parser.y"
                {
            (yyval.expr) = new ExpressionList((yyvsp[0].expr));
            setpos((yyval.expr));
            }
#line 1743 "parser.tab.c"
    break;


#line 1747 "parser.tab.c"

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
      yyerror (YY_("syntax error"));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

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


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

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


#if !defined yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturn;
#endif


/*-------------------------------------------------------.
| yyreturn -- parsing is finished, clean up and return.  |
`-------------------------------------------------------*/
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 360 "parser.y"


NodeBasePtr root; // Definition of variable (to match declaration earlier)

NodeBasePtr parse()
{
  root = NULL;
  yyparse();
  return root;
}
