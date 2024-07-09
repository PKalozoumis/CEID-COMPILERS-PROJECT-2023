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
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

    #include <stdio.h>
    #include <stdlib.h>
    #include <inttypes.h>
    #include <math.h>

    #include <string.h>
    
    #include "hashing.h"
    #include "error.h"

    void yyerror(const char*);
    int check_for_required_attributes(const char* elem, uint16_t attr, uint16_t req);

    extern FILE* yyin;
    extern FILE* yyout;
    extern char* yytext;

    extern int yylex();

    extern uint32_t line_number;
    extern int eof_comment;
    extern int bad_comment;
    
    enum error err_type = ERR_SYNTAX;

    enum attr
    {
        ATTR_WIDTH = 1,
        ATTR_HEIGHT = 1 << 1,
        ATTR_ID = 1 << 2,
        ATTR_ORIENT = 1 << 3,
        ATTR_TEXT = 1 << 4,
        ATTR_TEXTCOLOR = 1 << 5,
        ATTR_SRC = 1 << 6,
        ATTR_PADDING = 1 << 7,
        ATTR_CHECKED = 1 << 8,
        ATTR_MAX = 1 << 9,
        ATTR_PROGRESS = 1 << 10,
        ATTR_COUNT = 1 << 11
    };

    char* decode_attr[12] =
    {
        "layout_width", "layout_height", "id", "orientation", "text", "textColor", "src",
        "padding", "checkedButton", "max", "progress", "count"
    };

    uint32_t duplicate_attr_mask = 0;
    int attr_val_max = -1;
    int attr_val_progress = -1;
    int attr_val_count = -1;

    //The value of attribute "checkedButton" inside the current RadioGroup body
    //Used along with found_id to check if one the embedded radio buttons has an id that's equal to this value
    //A value of NULL indicates a nonexistent checkedButton attribute, so no checks need to be performed
    //Needs to be reset after the final check (for the value of found_id) is performed
    char* attr_val_checked = NULL;
    int found_id = 0;

    int button_count = 0;

    List* hashTable = NULL;

#line 136 "parser.tab.c"

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
  YYSYMBOL_STR_LINEAR_LAYOUT = 3,          /* "LinearLayout"  */
  YYSYMBOL_STR_RELATIVE_LAYOUT = 4,        /* "RelativeLayout"  */
  YYSYMBOL_STR_TEXT_VIEW = 5,              /* "TextView"  */
  YYSYMBOL_STR_IMAGE_VIEW = 6,             /* "ImageView"  */
  YYSYMBOL_STR_BUTTON = 7,                 /* "Button"  */
  YYSYMBOL_STR_RADIO_BUTTON = 8,           /* "RadioButton"  */
  YYSYMBOL_STR_RADIO_GROUP = 9,            /* "RadioGroup"  */
  YYSYMBOL_STR_PROGRESS_BAR = 10,          /* "ProgressBar"  */
  YYSYMBOL_STR_ANDROID = 11,               /* "android"  */
  YYSYMBOL_STR_ATTR_WIDTH = 12,            /* "layout_width"  */
  YYSYMBOL_STR_ATTR_HEIGHT = 13,           /* "layout_height"  */
  YYSYMBOL_STR_ATTR_ID = 14,               /* "id"  */
  YYSYMBOL_STR_ATTR_ORIENT = 15,           /* "orientation"  */
  YYSYMBOL_STR_ATTR_TEXT = 16,             /* "text"  */
  YYSYMBOL_STR_ATTR_TEXTCOLOR = 17,        /* "textColor"  */
  YYSYMBOL_STR_ATTR_SRC = 18,              /* "src"  */
  YYSYMBOL_STR_ATTR_PADDING = 19,          /* "padding"  */
  YYSYMBOL_STR_ATTR_CHECKED = 20,          /* "checkedButton"  */
  YYSYMBOL_STR_ATTR_MAX = 21,              /* "max"  */
  YYSYMBOL_STR_ATTR_PROGRESS = 22,         /* "progress"  */
  YYSYMBOL_STR_ATTR_COUNT = 23,            /* "count"  */
  YYSYMBOL_STRING = 24,                    /* STRING  */
  YYSYMBOL_INTEGER = 25,                   /* INTEGER  */
  YYSYMBOL_26_ = 26,                       /* '/'  */
  YYSYMBOL_27_ = 27,                       /* '>'  */
  YYSYMBOL_28_ = 28,                       /* '='  */
  YYSYMBOL_29_ = 29,                       /* '"'  */
  YYSYMBOL_30_ = 30,                       /* '<'  */
  YYSYMBOL_31_ = 31,                       /* ':'  */
  YYSYMBOL_YYACCEPT = 32,                  /* $accept  */
  YYSYMBOL_start = 33,                     /* start  */
  YYSYMBOL_self_close = 34,                /* self_close  */
  YYSYMBOL_attr_orient = 35,               /* attr_orient  */
  YYSYMBOL_attr_id = 36,                   /* attr_id  */
  YYSYMBOL_attr_text = 37,                 /* attr_text  */
  YYSYMBOL_attr_textcolor = 38,            /* attr_textcolor  */
  YYSYMBOL_attr_src = 39,                  /* attr_src  */
  YYSYMBOL_attr_padding = 40,              /* attr_padding  */
  YYSYMBOL_attr_checked = 41,              /* attr_checked  */
  YYSYMBOL_attr_max = 42,                  /* attr_max  */
  YYSYMBOL_attr_progress = 43,             /* attr_progress  */
  YYSYMBOL_attr_count = 44,                /* attr_count  */
  YYSYMBOL_req_attr = 45,                  /* req_attr  */
  YYSYMBOL_attr_width = 46,                /* attr_width  */
  YYSYMBOL_attr_width_val = 47,            /* attr_width_val  */
  YYSYMBOL_attr_height = 48,               /* attr_height  */
  YYSYMBOL_attr_height_val = 49,           /* attr_height_val  */
  YYSYMBOL_linear_layout = 50,             /* linear_layout  */
  YYSYMBOL_linear_attr_top = 51,           /* linear_attr_top  */
  YYSYMBOL_linear_attr_list = 52,          /* linear_attr_list  */
  YYSYMBOL_linear_attr = 53,               /* linear_attr  */
  YYSYMBOL_linear_body = 54,               /* linear_body  */
  YYSYMBOL_linear_body_options = 55,       /* linear_body_options  */
  YYSYMBOL_relative_layout = 56,           /* relative_layout  */
  YYSYMBOL_relative_close = 57,            /* relative_close  */
  YYSYMBOL_relative_attr_top = 58,         /* relative_attr_top  */
  YYSYMBOL_relative_attr_list = 59,        /* relative_attr_list  */
  YYSYMBOL_relative_attr = 60,             /* relative_attr  */
  YYSYMBOL_relative_body = 61,             /* relative_body  */
  YYSYMBOL_relative_body_options = 62,     /* relative_body_options  */
  YYSYMBOL_text_view = 63,                 /* text_view  */
  YYSYMBOL_text_view_close = 64,           /* text_view_close  */
  YYSYMBOL_text_view_attr_top = 65,        /* text_view_attr_top  */
  YYSYMBOL_text_view_attr_list = 66,       /* text_view_attr_list  */
  YYSYMBOL_text_view_attr = 67,            /* text_view_attr  */
  YYSYMBOL_image_view = 68,                /* image_view  */
  YYSYMBOL_image_view_close = 69,          /* image_view_close  */
  YYSYMBOL_image_view_attr_top = 70,       /* image_view_attr_top  */
  YYSYMBOL_image_view_attr_list = 71,      /* image_view_attr_list  */
  YYSYMBOL_image_view_attr = 72,           /* image_view_attr  */
  YYSYMBOL_button = 73,                    /* button  */
  YYSYMBOL_button_close = 74,              /* button_close  */
  YYSYMBOL_button_attr_top = 75,           /* button_attr_top  */
  YYSYMBOL_button_attr_list = 76,          /* button_attr_list  */
  YYSYMBOL_button_attr = 77,               /* button_attr  */
  YYSYMBOL_radio_button = 78,              /* radio_button  */
  YYSYMBOL_radio_button_close = 79,        /* radio_button_close  */
  YYSYMBOL_radio_button_attr_top = 80,     /* radio_button_attr_top  */
  YYSYMBOL_radio_button_attr_list = 81,    /* radio_button_attr_list  */
  YYSYMBOL_radio_button_attr = 82,         /* radio_button_attr  */
  YYSYMBOL_radio_group = 83,               /* radio_group  */
  YYSYMBOL_radio_group_attr_top = 84,      /* radio_group_attr_top  */
  YYSYMBOL_radio_group_attr_list = 85,     /* radio_group_attr_list  */
  YYSYMBOL_radio_group_attr = 86,          /* radio_group_attr  */
  YYSYMBOL_radio_group_body = 87,          /* radio_group_body  */
  YYSYMBOL_radio_group_body_options = 88,  /* radio_group_body_options  */
  YYSYMBOL_progress_bar = 89,              /* progress_bar  */
  YYSYMBOL_progress_bar_close = 90,        /* progress_bar_close  */
  YYSYMBOL_progress_bar_attr_top = 91,     /* progress_bar_attr_top  */
  YYSYMBOL_progress_bar_attr_list = 92,    /* progress_bar_attr_list  */
  YYSYMBOL_progress_bar_attr = 93          /* progress_bar_attr  */
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
typedef yytype_uint8 yy_state_t;

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
#define YYFINAL  7
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   218

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  32
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  62
/* YYNRULES -- Number of rules.  */
#define YYNRULES  115
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  227

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   280


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
       2,     2,     2,     2,    29,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    26,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    31,     2,
      30,    28,    27,     2,     2,     2,     2,     2,     2,     2,
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
      25
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   133,   133,   133,   135,   140,   142,   159,   161,   163,
     165,   175,   177,   189,   201,   214,   215,   217,   218,   230,
     244,   245,   257,   274,   276,   282,   294,   297,   298,   299,
     301,   301,   303,   303,   303,   303,   303,   303,   303,   307,
     309,   309,   311,   317,   329,   332,   333,   335,   335,   337,
     337,   337,   337,   337,   337,   337,   341,   343,   343,   345,
     351,   363,   366,   367,   368,   369,   373,   375,   375,   377,
     383,   395,   398,   399,   400,   401,   405,   407,   407,   409,
     415,   427,   430,   431,   432,   433,   437,   439,   439,   441,
     447,   459,   462,   463,   475,   479,   511,   517,   529,   532,
     533,   534,   535,   537,   537,   539,   543,   545,   545,   547,
     571,   583,   586,   587,   588,   589
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
  "\"end of file\"", "error", "\"invalid token\"", "\"LinearLayout\"",
  "\"RelativeLayout\"", "\"TextView\"", "\"ImageView\"", "\"Button\"",
  "\"RadioButton\"", "\"RadioGroup\"", "\"ProgressBar\"", "\"android\"",
  "\"layout_width\"", "\"layout_height\"", "\"id\"", "\"orientation\"",
  "\"text\"", "\"textColor\"", "\"src\"", "\"padding\"",
  "\"checkedButton\"", "\"max\"", "\"progress\"", "\"count\"", "STRING",
  "INTEGER", "'/'", "'>'", "'='", "'\"'", "'<'", "':'", "$accept", "start",
  "self_close", "attr_orient", "attr_id", "attr_text", "attr_textcolor",
  "attr_src", "attr_padding", "attr_checked", "attr_max", "attr_progress",
  "attr_count", "req_attr", "attr_width", "attr_width_val", "attr_height",
  "attr_height_val", "linear_layout", "linear_attr_top",
  "linear_attr_list", "linear_attr", "linear_body", "linear_body_options",
  "relative_layout", "relative_close", "relative_attr_top",
  "relative_attr_list", "relative_attr", "relative_body",
  "relative_body_options", "text_view", "text_view_close",
  "text_view_attr_top", "text_view_attr_list", "text_view_attr",
  "image_view", "image_view_close", "image_view_attr_top",
  "image_view_attr_list", "image_view_attr", "button", "button_close",
  "button_attr_top", "button_attr_list", "button_attr", "radio_button",
  "radio_button_close", "radio_button_attr_top", "radio_button_attr_list",
  "radio_button_attr", "radio_group", "radio_group_attr_top",
  "radio_group_attr_list", "radio_group_attr", "radio_group_body",
  "radio_group_body_options", "progress_bar", "progress_bar_close",
  "progress_bar_attr_top", "progress_bar_attr_list", "progress_bar_attr", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-105)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -22,    29,    24,  -105,  -105,  -105,  -105,  -105,   -11,    28,
      52,    30,    -2,     4,    22,  -105,  -105,  -105,    39,    51,
    -105,    47,  -105,  -105,  -105,  -105,  -105,  -105,  -105,    85,
    -105,    57,    53,  -105,  -105,  -105,  -105,  -105,     8,  -105,
      67,    73,    87,    92,  -105,  -105,  -105,  -105,  -105,  -105,
      16,  -105,  -105,  -105,  -105,  -105,  -105,  -105,  -105,  -105,
    -105,  -105,    63,    48,    77,    98,    79,   103,    94,   108,
      81,   111,   120,    95,    96,    97,    99,   123,   100,  -105,
    -105,   101,   104,  -105,  -105,   102,   105,  -105,  -105,   106,
     109,   107,   110,  -105,  -105,   112,   114,    86,    88,   118,
     121,   117,   122,    34,   124,    50,   125,    72,   128,  -105,
     116,  -105,    17,   126,    31,  -105,  -105,  -105,   127,  -105,
    -105,   129,   130,   131,  -105,   142,   133,   134,  -105,  -105,
    -105,  -105,  -105,   143,   135,   136,  -105,  -105,  -105,  -105,
    -105,   146,  -105,  -105,  -105,  -105,  -105,  -105,     1,  -105,
     137,   138,  -105,  -105,  -105,  -105,  -105,   119,   139,   140,
    -105,  -105,  -105,  -105,  -105,  -105,  -105,  -105,  -105,   144,
     141,   147,   145,   148,   149,   152,    91,   158,   164,   151,
     153,   154,   155,   156,  -105,   159,   162,  -105,   163,   132,
    -105,   160,  -105,  -105,   157,   165,   167,   168,  -105,   169,
     170,   171,   172,   173,   174,   178,    80,  -105,   176,   177,
     179,   180,  -105,  -105,  -105,  -105,   181,  -105,  -105,  -105,
    -105,  -105,  -105,  -105,  -105,   183,  -105
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     2,     3,    26,    44,     1,     0,    24,
       0,    42,     0,     0,     0,    48,    40,    39,     0,     0,
      32,     0,    31,    33,    34,    35,    36,    37,    38,     0,
       4,     0,     0,    61,    71,    81,    98,   111,     0,    30,
       0,     0,     0,     0,    29,    28,    27,    15,    16,    25,
       0,    49,    50,    47,    51,    52,    53,    54,    55,    46,
      45,    43,     0,    59,     0,    69,     0,    79,     0,    96,
       0,   109,     0,     0,     0,     0,     0,     0,     0,    57,
      56,     0,     0,    67,    66,     0,     0,    77,    76,     0,
       0,     0,     0,   107,   106,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   105,
       0,   104,     0,     0,     0,    23,    19,    18,     0,    22,
      21,     0,     0,     0,    41,     0,     0,     0,    63,    64,
      65,    62,    60,     0,     0,     0,    73,    75,    74,    72,
      70,     0,    83,    85,    84,    82,    80,    91,     0,   103,
       0,     0,   100,   101,   102,    99,    97,     0,     0,     0,
     113,   114,   115,   112,   110,    17,    20,     6,     5,     0,
       0,     0,     0,     0,     0,     0,     0,    89,     0,     0,
       0,     0,     0,     0,    58,     0,     0,    68,     0,     0,
      78,     0,    87,    86,     0,     0,     0,     0,   108,     0,
       0,     0,     0,     0,     0,     0,     0,    95,     0,     0,
       0,     0,     7,     8,     9,    10,     0,    93,    94,    92,
      90,    11,    14,    12,    13,     0,    88
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -105,  -105,   -60,  -105,   -32,  -104,  -105,  -105,    89,  -105,
    -105,  -105,  -105,   -31,  -105,  -105,  -105,  -105,     5,  -105,
    -105,  -105,  -105,   186,     7,  -105,  -105,  -105,  -105,  -105,
    -105,   166,  -105,  -105,  -105,  -105,   182,  -105,  -105,  -105,
    -105,   184,  -105,  -105,  -105,  -105,  -105,  -105,  -105,  -105,
    -105,   185,  -105,  -105,  -105,  -105,    21,   187,  -105,  -105,
    -105,  -105
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,    16,    44,    45,   129,   130,   137,   138,   153,
     161,   162,   154,    46,    47,   118,    48,   121,    20,     8,
       9,    49,    21,    22,    23,    17,    10,    11,    61,    31,
      53,    24,    80,    62,    63,   132,    25,    84,    64,    65,
     140,    26,    88,    66,    67,   146,   109,   193,   176,   177,
     220,    27,    68,    69,   156,   110,   111,    28,    94,    70,
      71,   164
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      59,    60,    79,   143,    83,     3,    87,     4,     1,   147,
      93,     5,     6,    33,    34,    35,    12,    36,    37,     5,
       6,    33,    34,    35,     7,    36,    37,   178,    19,    40,
      41,    42,     5,     6,    72,    29,    51,   150,    52,    13,
     151,    18,    77,    40,    41,    42,    40,    41,    42,    30,
     126,   127,   158,   159,     5,     6,    33,    34,    35,    81,
      36,    37,    40,    41,    42,    40,    41,    42,   134,   135,
      32,   128,   131,   136,   139,   142,   145,    38,    14,    15,
     152,   155,   160,   163,    40,    41,    42,    50,   126,    14,
      78,   135,    40,    41,    42,    73,   126,    40,    41,    42,
      43,    74,   218,    14,    82,    14,    86,    14,    92,    85,
     116,   117,   119,   120,    89,    75,   192,    14,   191,    91,
      76,    90,    95,    96,    97,    98,    99,   101,   100,   181,
     102,   149,   103,   105,   104,   106,   147,   107,   112,   108,
     113,   115,   122,   114,   124,   123,   148,   169,   125,   172,
     133,   141,   157,   175,     0,     0,   165,   204,   166,   167,
     168,   170,   171,   173,   174,   179,   180,   182,   183,   194,
     185,   184,   187,   195,   217,   219,   186,   188,   189,   190,
     196,   198,   197,   201,   199,   200,   202,   203,   206,   225,
     205,   208,   207,   209,   210,   211,   144,    54,     0,     0,
     212,   213,   214,   215,   216,   221,   222,    39,   223,   224,
     226,     0,     0,    55,     0,    56,    57,     0,    58
};

static const yytype_int16 yycheck[] =
{
      32,    32,    62,   107,    64,     0,    66,     0,    30,     8,
      70,     3,     4,     5,     6,     7,    27,     9,    10,     3,
       4,     5,     6,     7,     0,     9,    10,    26,    30,    12,
      13,    14,     3,     4,    26,    31,    31,    20,    31,    11,
      23,    11,    26,    12,    13,    14,    12,    13,    14,    27,
      16,    17,    21,    22,     3,     4,     5,     6,     7,    11,
       9,    10,    12,    13,    14,    12,    13,    14,    18,    19,
      31,   103,   103,   105,   105,   107,   107,    30,    26,    27,
     112,   112,   114,   114,    12,    13,    14,    30,    16,    26,
      27,    19,    12,    13,    14,    28,    16,    12,    13,    14,
      15,    28,   206,    26,    27,    26,    27,    26,    27,    11,
      24,    25,    24,    25,    11,    28,   176,    26,    27,    11,
      28,    27,    11,     3,    29,    29,    29,     4,    29,    10,
      30,   110,    31,    31,    30,    30,     8,    31,    31,    30,
      30,    27,    24,    31,    27,    24,    30,     5,    26,     6,
      26,    26,    26,     7,    -1,    -1,    29,    25,    29,    29,
      29,    28,    28,    28,    28,    28,    28,    28,    28,    11,
      29,    27,    27,     9,   206,   206,    29,    29,    29,    27,
      29,    27,    29,    24,    29,    29,    24,    24,    31,     8,
      30,    24,    27,    25,    25,    25,   107,    31,    -1,    -1,
      29,    29,    29,    29,    26,    29,    29,    21,    29,    29,
      27,    -1,    -1,    31,    -1,    31,    31,    -1,    31
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    30,    33,    50,    56,     3,     4,     0,    51,    52,
      58,    59,    27,    11,    26,    27,    34,    57,    11,    30,
      50,    54,    55,    56,    63,    68,    73,    83,    89,    31,
      27,    61,    31,     5,     6,     7,     9,    10,    30,    55,
      12,    13,    14,    15,    35,    36,    45,    46,    48,    53,
      30,    50,    56,    62,    63,    68,    73,    83,    89,    36,
      45,    60,    65,    66,    70,    71,    75,    76,    84,    85,
      91,    92,    26,    28,    28,    28,    28,    26,    27,    34,
      64,    11,    27,    34,    69,    11,    27,    34,    74,    11,
      27,    11,    27,    34,    90,    11,     3,    29,    29,    29,
      29,     4,    30,    31,    30,    31,    30,    31,    30,    78,
      87,    88,    31,    30,    31,    27,    24,    25,    47,    24,
      25,    49,    24,    24,    27,    26,    16,    17,    36,    37,
      38,    45,    67,    26,    18,    19,    36,    39,    40,    45,
      72,    26,    36,    37,    40,    45,    77,     8,    30,    88,
      20,    23,    36,    41,    44,    45,    86,    26,    21,    22,
      36,    42,    43,    45,    93,    29,    29,    29,    29,     5,
      28,    28,     6,    28,    28,     7,    80,    81,    26,    28,
      28,    10,    28,    28,    27,    29,    29,    27,    29,    29,
      27,    27,    34,    79,    11,     9,    29,    29,    27,    29,
      29,    24,    24,    24,    25,    30,    31,    27,    24,    25,
      25,    25,    29,    29,    29,    29,    26,    36,    37,    45,
      82,    29,    29,    29,    29,     8,    27
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    32,    33,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    45,    46,    47,    47,
      48,    49,    49,    50,    51,    52,    52,    53,    53,    53,
      54,    54,    55,    55,    55,    55,    55,    55,    55,    56,
      57,    57,    58,    59,    59,    60,    60,    61,    61,    62,
      62,    62,    62,    62,    62,    62,    63,    64,    64,    65,
      66,    66,    67,    67,    67,    67,    68,    69,    69,    70,
      71,    71,    72,    72,    72,    72,    73,    74,    74,    75,
      76,    76,    77,    77,    77,    77,    78,    79,    79,    80,
      81,    81,    82,    82,    82,    83,    84,    85,    85,    86,
      86,    86,    86,    87,    87,    88,    89,    90,    90,    91,
      92,    92,    93,    93,    93,    93
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     5,     5,     5,     5,     5,
       5,     5,     5,     5,     5,     1,     1,     5,     1,     1,
       5,     1,     1,     9,     1,     4,     0,     1,     1,     1,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     4,
       1,     6,     1,     4,     0,     1,     1,     2,     0,     1,
       1,     1,     1,     1,     1,     1,     4,     1,     5,     1,
       4,     0,     1,     1,     1,     1,     4,     1,     5,     1,
       4,     0,     1,     1,     1,     1,     4,     1,     5,     1,
       4,     0,     1,     1,     1,     1,     4,     1,     5,     1,
       4,     0,     1,     1,     1,     9,     1,     4,     0,     1,
       1,     1,     1,     2,     1,     1,     4,     1,     5,     1,
       4,     0,     1,     1,     1,     1
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
  case 5: /* attr_orient: "orientation" '=' '"' STRING '"'  */
#line 140 "parser.y"
                                              { free((yyvsp[-1].str_val)); /*for now*/ }
#line 1380 "parser.tab.c"
    break;

  case 6: /* attr_id: "id" '=' '"' STRING '"'  */
#line 143 "parser.y"
{
    if (insert(hashTable, (yyvsp[-1].str_val)))
    {
        char str[256];
        sprintf(str, "Value \"%s\" already exists for ID", (yyvsp[-1].str_val));
        err_type = ERR_OTHER;
        yyerror(str);
        YYABORT;
    }

    //BE CAREFUL NOT TO FREE THIS
    //OWNERSHIP IS NOT TRANSFERRED TO HASH TABLE
    //BUT THE HASH TABLE IS STILL RESPONSIBLE FOR FREEING IT AFTER EVERYTHING IS OVER
    (yyval.str_val) = (yyvsp[-1].str_val);
}
#line 1400 "parser.tab.c"
    break;

  case 7: /* attr_text: "text" '=' '"' STRING '"'  */
#line 159 "parser.y"
                                     { free((yyvsp[-1].str_val)); /*for now*/ }
#line 1406 "parser.tab.c"
    break;

  case 8: /* attr_textcolor: "textColor" '=' '"' STRING '"'  */
#line 161 "parser.y"
                                               { free((yyvsp[-1].str_val)); /*for now*/ }
#line 1412 "parser.tab.c"
    break;

  case 9: /* attr_src: "src" '=' '"' STRING '"'  */
#line 163 "parser.y"
                                   { free((yyvsp[-1].str_val)); /*for now*/ }
#line 1418 "parser.tab.c"
    break;

  case 10: /* attr_padding: "padding" '=' '"' INTEGER '"'  */
#line 166 "parser.y"
{
    if ((yyvsp[-1].int_val) <= 0)
    {
        err_type = ERR_OTHER;
        yyerror("Attribute \"padding\" must have a positive value");
        YYABORT;
    }
}
#line 1431 "parser.tab.c"
    break;

  case 11: /* attr_checked: "checkedButton" '=' '"' STRING '"'  */
#line 175 "parser.y"
                                                 { (yyval.str_val) = (yyvsp[-1].str_val); }
#line 1437 "parser.tab.c"
    break;

  case 12: /* attr_max: "max" '=' '"' INTEGER '"'  */
#line 178 "parser.y"
{
    if ((yyvsp[-1].int_val) <= 0)
    {
        err_type = ERR_OTHER;
        yyerror("Attribute \"max\" must have a positive value");
        YYABORT;
    }

    (yyval.int_val) = (yyvsp[-1].int_val);
}
#line 1452 "parser.tab.c"
    break;

  case 13: /* attr_progress: "progress" '=' '"' INTEGER '"'  */
#line 190 "parser.y"
{
    if ((yyvsp[-1].int_val) < 0)
    {
        err_type = ERR_OTHER;
        yyerror("Attribute \"progress\" cannot have a negative value");
        YYABORT;
    }

    (yyval.int_val) = (yyvsp[-1].int_val);
}
#line 1467 "parser.tab.c"
    break;

  case 14: /* attr_count: "count" '=' '"' INTEGER '"'  */
#line 202 "parser.y"
{
    if ((yyvsp[-1].int_val) <= 0)
    {
        err_type = ERR_OTHER;
        char* str = "Attribute \"count\" must have a positive value";
        yyerror(str);
        YYABORT;
    }

    (yyval.int_val) = (yyvsp[-1].int_val);
}
#line 1483 "parser.tab.c"
    break;

  case 15: /* req_attr: attr_width  */
#line 214 "parser.y"
                     { (yyval.uint_val) = ATTR_WIDTH; }
#line 1489 "parser.tab.c"
    break;

  case 16: /* req_attr: attr_height  */
#line 215 "parser.y"
                      { (yyval.uint_val) = ATTR_HEIGHT; }
#line 1495 "parser.tab.c"
    break;

  case 18: /* attr_width_val: INTEGER  */
#line 219 "parser.y"
{
    if ((yyvsp[0].int_val) <= 0)
    {
        err_type = ERR_OTHER;
        char str[512];
        sprintf(str, "Attribute layout_width must have a positive value (got %d)", (yyvsp[0].int_val));
        yyerror(str);

        YYABORT;
    }
}
#line 1511 "parser.tab.c"
    break;

  case 19: /* attr_width_val: STRING  */
#line 231 "parser.y"
{
    if ((strcmp((yyvsp[0].str_val), "match_parent") != 0)&&(strcmp((yyvsp[0].str_val), "wrap_content") != 0))
    {
        err_type = ERR_OTHER;
        char str[512];
        sprintf(str, "Incorrect value \"%s\" for attribute layout_width, should be \"wrap_content\", \"match_parent\" or a positive integer", (yyvsp[0].str_val));
        free((yyvsp[0].str_val));
        yyerror(str);

        YYABORT;
    }
}
#line 1528 "parser.tab.c"
    break;

  case 21: /* attr_height_val: INTEGER  */
#line 246 "parser.y"
{
    if ((yyvsp[0].int_val) <= 0)
    {
        err_type = ERR_OTHER;
        char str[512];
        sprintf(str, "Attribute layout_height must have a positive value (got %d)", (yyvsp[0].int_val));
        yyerror(str);

        YYABORT;
    }
}
#line 1544 "parser.tab.c"
    break;

  case 22: /* attr_height_val: STRING  */
#line 258 "parser.y"
{
    if ((strcmp((yyvsp[0].str_val), "match_parent") != 0)&&(strcmp((yyvsp[0].str_val), "wrap_content") != 0))
    {
        err_type = ERR_OTHER;
        char str[512];
        sprintf(str, "Incorrect value \"%s\" for attribute layout_height, should be \"wrap_content\", \"match_parent\" or a positive integer", (yyvsp[0].str_val));
        free((yyvsp[0].str_val));
        yyerror(str);

        YYABORT;
    }
}
#line 1561 "parser.tab.c"
    break;

  case 24: /* linear_attr_top: linear_attr_list  */
#line 277 "parser.y"
{
    if (!check_for_required_attributes("LinearLayout", (yyvsp[0].uint_val), ATTR_WIDTH | ATTR_HEIGHT))
        YYABORT;
}
#line 1570 "parser.tab.c"
    break;

  case 25: /* linear_attr_list: linear_attr_list "android" ':' linear_attr  */
#line 283 "parser.y"
{
    duplicate_attr_mask = (yyvsp[-3].uint_val) & (yyvsp[0].uint_val);

    if (duplicate_attr_mask)
    {
        err_type = ERR_DUPLICATE_ATTR;
        yyerror("Duplicate attributes");
        YYABORT;
    }
    else (yyval.uint_val) = (yyvsp[-3].uint_val) | (yyvsp[0].uint_val);
}
#line 1586 "parser.tab.c"
    break;

  case 26: /* linear_attr_list: %empty  */
#line 294 "parser.y"
         { (yyval.uint_val) = 0; }
#line 1592 "parser.tab.c"
    break;

  case 27: /* linear_attr: req_attr  */
#line 297 "parser.y"
         { (yyval.uint_val) = (yyvsp[0].uint_val); }
#line 1598 "parser.tab.c"
    break;

  case 28: /* linear_attr: attr_id  */
#line 298 "parser.y"
        { (yyval.uint_val) = ATTR_ID; }
#line 1604 "parser.tab.c"
    break;

  case 29: /* linear_attr: attr_orient  */
#line 299 "parser.y"
            { (yyval.uint_val) = ATTR_ORIENT; }
#line 1610 "parser.tab.c"
    break;

  case 42: /* relative_attr_top: relative_attr_list  */
#line 312 "parser.y"
{
    if (!check_for_required_attributes("RelativeLayout", (yyvsp[0].uint_val), ATTR_WIDTH | ATTR_HEIGHT))
        YYABORT;
}
#line 1619 "parser.tab.c"
    break;

  case 43: /* relative_attr_list: relative_attr_list "android" ':' relative_attr  */
#line 318 "parser.y"
{
    duplicate_attr_mask = (yyvsp[-3].uint_val) & (yyvsp[0].uint_val);

    if (duplicate_attr_mask)
    {
        err_type = ERR_DUPLICATE_ATTR;
        yyerror("Duplicate attributes");
        YYABORT;
    }
    else (yyval.uint_val) = (yyvsp[-3].uint_val) | (yyvsp[0].uint_val);
}
#line 1635 "parser.tab.c"
    break;

  case 44: /* relative_attr_list: %empty  */
#line 329 "parser.y"
         { (yyval.uint_val) = 0; }
#line 1641 "parser.tab.c"
    break;

  case 45: /* relative_attr: req_attr  */
#line 332 "parser.y"
         { (yyval.uint_val) = (yyvsp[0].uint_val); }
#line 1647 "parser.tab.c"
    break;

  case 46: /* relative_attr: attr_id  */
#line 333 "parser.y"
        { (yyval.uint_val) = ATTR_ID; }
#line 1653 "parser.tab.c"
    break;

  case 59: /* text_view_attr_top: text_view_attr_list  */
#line 346 "parser.y"
{
    if (!check_for_required_attributes("TextView", (yyvsp[0].uint_val), ATTR_WIDTH | ATTR_HEIGHT | ATTR_TEXT))
        YYABORT;
}
#line 1662 "parser.tab.c"
    break;

  case 60: /* text_view_attr_list: text_view_attr_list "android" ':' text_view_attr  */
#line 352 "parser.y"
{
    duplicate_attr_mask = (yyvsp[-3].uint_val) & (yyvsp[0].uint_val);

    if (duplicate_attr_mask)
    {
        err_type = ERR_DUPLICATE_ATTR;
        yyerror("Duplicate attributes");
        YYABORT;
    }
    else (yyval.uint_val) = (yyvsp[-3].uint_val) | (yyvsp[0].uint_val);
}
#line 1678 "parser.tab.c"
    break;

  case 61: /* text_view_attr_list: %empty  */
#line 363 "parser.y"
         { (yyval.uint_val) = 0; }
#line 1684 "parser.tab.c"
    break;

  case 62: /* text_view_attr: req_attr  */
#line 366 "parser.y"
         { (yyval.uint_val) = (yyvsp[0].uint_val); }
#line 1690 "parser.tab.c"
    break;

  case 63: /* text_view_attr: attr_id  */
#line 367 "parser.y"
        { (yyval.uint_val) = ATTR_ID; }
#line 1696 "parser.tab.c"
    break;

  case 64: /* text_view_attr: attr_text  */
#line 368 "parser.y"
          { (yyval.uint_val) = ATTR_TEXT; }
#line 1702 "parser.tab.c"
    break;

  case 65: /* text_view_attr: attr_textcolor  */
#line 369 "parser.y"
               { (yyval.uint_val) = ATTR_TEXTCOLOR; }
#line 1708 "parser.tab.c"
    break;

  case 69: /* image_view_attr_top: image_view_attr_list  */
#line 378 "parser.y"
{
    if (!check_for_required_attributes("ImageView", (yyvsp[0].uint_val), ATTR_WIDTH | ATTR_HEIGHT | ATTR_SRC))
        YYABORT;
}
#line 1717 "parser.tab.c"
    break;

  case 70: /* image_view_attr_list: image_view_attr_list "android" ':' image_view_attr  */
#line 384 "parser.y"
{
    duplicate_attr_mask = (yyvsp[-3].uint_val) & (yyvsp[0].uint_val);

    if (duplicate_attr_mask)
    {
        err_type = ERR_DUPLICATE_ATTR;
        yyerror("Duplicate attributes");
        YYABORT;
    }
    else (yyval.uint_val) = (yyvsp[-3].uint_val) | (yyvsp[0].uint_val);
}
#line 1733 "parser.tab.c"
    break;

  case 71: /* image_view_attr_list: %empty  */
#line 395 "parser.y"
         { (yyval.uint_val) = 0; }
#line 1739 "parser.tab.c"
    break;

  case 72: /* image_view_attr: req_attr  */
#line 398 "parser.y"
         { (yyval.uint_val) = (yyvsp[0].uint_val); }
#line 1745 "parser.tab.c"
    break;

  case 73: /* image_view_attr: attr_id  */
#line 399 "parser.y"
        { (yyval.uint_val) = ATTR_ID; }
#line 1751 "parser.tab.c"
    break;

  case 74: /* image_view_attr: attr_padding  */
#line 400 "parser.y"
             { (yyval.uint_val) = ATTR_PADDING; }
#line 1757 "parser.tab.c"
    break;

  case 75: /* image_view_attr: attr_src  */
#line 401 "parser.y"
         { (yyval.uint_val) = ATTR_SRC; }
#line 1763 "parser.tab.c"
    break;

  case 79: /* button_attr_top: button_attr_list  */
#line 410 "parser.y"
{
    if (!check_for_required_attributes("Button", (yyvsp[0].uint_val), ATTR_WIDTH | ATTR_HEIGHT | ATTR_TEXT))
        YYABORT;
}
#line 1772 "parser.tab.c"
    break;

  case 80: /* button_attr_list: button_attr_list "android" ':' button_attr  */
#line 416 "parser.y"
{
    duplicate_attr_mask = (yyvsp[-3].uint_val) & (yyvsp[0].uint_val);

    if (duplicate_attr_mask)
    {
        err_type = ERR_DUPLICATE_ATTR;
        yyerror("Duplicate attributes");
        YYABORT;
    }
    else (yyval.uint_val) = (yyvsp[-3].uint_val) | (yyvsp[0].uint_val);
}
#line 1788 "parser.tab.c"
    break;

  case 81: /* button_attr_list: %empty  */
#line 427 "parser.y"
         { (yyval.uint_val) = 0; }
#line 1794 "parser.tab.c"
    break;

  case 82: /* button_attr: req_attr  */
#line 430 "parser.y"
         { (yyval.uint_val) = (yyvsp[0].uint_val); }
#line 1800 "parser.tab.c"
    break;

  case 83: /* button_attr: attr_id  */
#line 431 "parser.y"
        { (yyval.uint_val) = ATTR_ID; }
#line 1806 "parser.tab.c"
    break;

  case 84: /* button_attr: attr_padding  */
#line 432 "parser.y"
             { (yyval.uint_val) = ATTR_PADDING; }
#line 1812 "parser.tab.c"
    break;

  case 85: /* button_attr: attr_text  */
#line 433 "parser.y"
          { (yyval.uint_val) = ATTR_TEXT; }
#line 1818 "parser.tab.c"
    break;

  case 86: /* radio_button: '<' "RadioButton" radio_button_attr_top radio_button_close  */
#line 437 "parser.y"
                                                                         { button_count++; }
#line 1824 "parser.tab.c"
    break;

  case 89: /* radio_button_attr_top: radio_button_attr_list  */
#line 442 "parser.y"
{
    if (!check_for_required_attributes("RadioButton", (yyvsp[0].uint_val), ATTR_WIDTH | ATTR_HEIGHT | ATTR_TEXT))
        YYABORT;
}
#line 1833 "parser.tab.c"
    break;

  case 90: /* radio_button_attr_list: radio_button_attr_list "android" ':' radio_button_attr  */
#line 448 "parser.y"
{
    duplicate_attr_mask = (yyvsp[-3].uint_val) & (yyvsp[0].uint_val);

    if (duplicate_attr_mask)
    {
        err_type = ERR_DUPLICATE_ATTR;
        yyerror("Duplicate attributes");
        YYABORT;
    }
    else (yyval.uint_val) = (yyvsp[-3].uint_val) | (yyvsp[0].uint_val);
}
#line 1849 "parser.tab.c"
    break;

  case 91: /* radio_button_attr_list: %empty  */
#line 459 "parser.y"
         { (yyval.uint_val) = 0; }
#line 1855 "parser.tab.c"
    break;

  case 92: /* radio_button_attr: req_attr  */
#line 462 "parser.y"
         { (yyval.uint_val) = (yyvsp[0].uint_val); }
#line 1861 "parser.tab.c"
    break;

  case 93: /* radio_button_attr: attr_id  */
#line 464 "parser.y"
{
    (yyval.uint_val) = ATTR_ID;

    if (attr_val_checked)
    {
        if (strcmp((yyvsp[0].str_val), attr_val_checked) == 0)
        {
            found_id = 1;
        }
    }
}
#line 1877 "parser.tab.c"
    break;

  case 94: /* radio_button_attr: attr_text  */
#line 475 "parser.y"
          { (yyval.uint_val) = ATTR_TEXT; }
#line 1883 "parser.tab.c"
    break;

  case 95: /* radio_group: '<' "RadioGroup" radio_group_attr_top '>' radio_group_body '<' '/' "RadioGroup" '>'  */
#line 480 "parser.y"
{
    //This is where we check if one of the radio buttons had the requested id

    if (attr_val_checked && !found_id)
    {
        err_type = ERR_OTHER;
        char str[256];
        snprintf(str, 256, "Value \"%s\" of checkedButton does not point to any of the contained RadioButton IDs", attr_val_checked);
        yyerror(str);
        YYABORT;
    }

    free(attr_val_checked);
    attr_val_checked = NULL;
    found_id = 0;

    //This is where we check for the number of buttons

    if (attr_val_count != button_count)
    {
        err_type = ERR_OTHER;
        char str[256];
        snprintf(str, 256, "Attribute \"count\" requests %d radio buttons, but there were %d", attr_val_count, button_count);
        yyerror(str);
        YYABORT;
    }

    button_count = 0;
    attr_val_count = -1; //Not necessary
}
#line 1918 "parser.tab.c"
    break;

  case 96: /* radio_group_attr_top: radio_group_attr_list  */
#line 512 "parser.y"
{
    if (!check_for_required_attributes("RadioGroup", (yyvsp[0].uint_val), ATTR_WIDTH | ATTR_HEIGHT | ATTR_COUNT))
        YYABORT;
}
#line 1927 "parser.tab.c"
    break;

  case 97: /* radio_group_attr_list: radio_group_attr_list "android" ':' radio_group_attr  */
#line 518 "parser.y"
{
    duplicate_attr_mask = (yyvsp[-3].uint_val) & (yyvsp[0].uint_val);

    if (duplicate_attr_mask)
    {
        err_type = ERR_DUPLICATE_ATTR;
        yyerror("Duplicate attributes");
        YYABORT;
    }
    else (yyval.uint_val) = (yyvsp[-3].uint_val) | (yyvsp[0].uint_val);
}
#line 1943 "parser.tab.c"
    break;

  case 98: /* radio_group_attr_list: %empty  */
#line 529 "parser.y"
         { (yyval.uint_val) = 0; }
#line 1949 "parser.tab.c"
    break;

  case 99: /* radio_group_attr: req_attr  */
#line 532 "parser.y"
         { (yyval.uint_val) = (yyvsp[0].uint_val); }
#line 1955 "parser.tab.c"
    break;

  case 100: /* radio_group_attr: attr_id  */
#line 533 "parser.y"
        { (yyval.uint_val) = ATTR_ID; }
#line 1961 "parser.tab.c"
    break;

  case 101: /* radio_group_attr: attr_checked  */
#line 534 "parser.y"
             { (yyval.uint_val) = ATTR_CHECKED; attr_val_checked = (yyvsp[0].str_val); /*freed at radio_group*/ }
#line 1967 "parser.tab.c"
    break;

  case 102: /* radio_group_attr: attr_count  */
#line 535 "parser.y"
           { (yyval.uint_val) = ATTR_COUNT; attr_val_count = (yyvsp[0].int_val); }
#line 1973 "parser.tab.c"
    break;

  case 109: /* progress_bar_attr_top: progress_bar_attr_list  */
#line 548 "parser.y"
{
    if (!check_for_required_attributes("ProgressBar", (yyvsp[0].uint_val), ATTR_WIDTH | ATTR_HEIGHT))
        YYABORT;

    if (((yyvsp[0].uint_val) & ATTR_PROGRESS) != 0)
    {
        if (((yyvsp[0].uint_val) & ATTR_MAX) == 0 )
        {
            err_type = ERR_OTHER;
            yyerror("Cannot have attrbute \"progress\" without attribute \"max\"");
            YYABORT;
        }
        else if (attr_val_progress >  attr_val_max)
        {
            err_type = ERR_OTHER;
            char str[256];
            snprintf(str, 256, "Value of progress (%d) must be between 0 and max (%d)", attr_val_progress, attr_val_max);
            yyerror(str);
            YYABORT;
        }
    }   
}
#line 2000 "parser.tab.c"
    break;

  case 110: /* progress_bar_attr_list: progress_bar_attr_list "android" ':' progress_bar_attr  */
#line 572 "parser.y"
{
    duplicate_attr_mask = (yyvsp[-3].uint_val) & (yyvsp[0].uint_val);

    if (duplicate_attr_mask)
    {
        err_type = ERR_DUPLICATE_ATTR;
        yyerror("Duplicate attributes");
        YYABORT;
    }
    else (yyval.uint_val) = (yyvsp[-3].uint_val) | (yyvsp[0].uint_val);
}
#line 2016 "parser.tab.c"
    break;

  case 111: /* progress_bar_attr_list: %empty  */
#line 583 "parser.y"
         { (yyval.uint_val) = 0; }
#line 2022 "parser.tab.c"
    break;

  case 112: /* progress_bar_attr: req_attr  */
#line 586 "parser.y"
         { (yyval.uint_val) = (yyvsp[0].uint_val); }
#line 2028 "parser.tab.c"
    break;

  case 113: /* progress_bar_attr: attr_id  */
#line 587 "parser.y"
        { (yyval.uint_val) = ATTR_ID; }
#line 2034 "parser.tab.c"
    break;

  case 114: /* progress_bar_attr: attr_max  */
#line 588 "parser.y"
         { (yyval.uint_val) = ATTR_MAX; attr_val_max = (yyvsp[0].int_val); }
#line 2040 "parser.tab.c"
    break;

  case 115: /* progress_bar_attr: attr_progress  */
#line 589 "parser.y"
              { (yyval.uint_val) = ATTR_PROGRESS; attr_val_progress = (yyvsp[0].int_val); }
#line 2046 "parser.tab.c"
    break;


#line 2050 "parser.tab.c"

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
  yyerror (YY_("memory exhausted"));
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

#line 591 "parser.y"


int main(int argc, char** argv)
{
    hashTable = createHashTable();
    FILE *fi = NULL, *fo = NULL;

    if (argc == 1)
    {
        printf("Please insert an input file\n");
        exit(EXIT_FAILURE);
    }
    else if (argc == 2)
    {
        //printf("Please insert an output file\n");
        //exit(EXIT_FAILURE);

        fo = stdout;
    }
    
    else if (argc > 3)
    {
        printf("Too many arguments\n");
        exit(EXIT_FAILURE);
    }

    if ((fi = fopen(argv[1], "r")) == NULL)
    {
        perror("INPUT ERROR");
        exit(EXIT_FAILURE);
    }

    if (argc == 3)
    {
        if ((fo = fopen(argv[2], "w")) == NULL)
        {
            perror("OUTPUT ERROR");
            exit(EXIT_FAILURE);
        }
    }

    yyin = fi;
    yyout = fo;

    printf("\nParsing %s...\n=============================================================================================================================\n\n", argv[1]);
    
    if (yyparse() == 0)
    {
        printf("\n\n=============================================================================================================================\n");
        printf("\nNo errors were encountered during the parsing process.\n");
    }

    printf("\n");

    //printHashTable(hashTable);

    fclose(fi);
    fclose(fo);
    freeHashTable(&hashTable);

    exit(EXIT_SUCCESS);
}

void yyerror(const char* str)
{
    printf("\n\n");
    printf("=============================================================================================================================\n\n");
    printf("ERROR at Line %d: ", line_number);

    switch(err_type)
    {
        case ERR_SYNTAX:
        {
            printf("Unexpected token \"%s\"\n", yytext);
        }
        break;

        case ERR_OTHER:
        {
            printf("%s\n", str);
        }
        break;

        case ERR_EOF_COMMENT:
        {
            printf("Comment reached end of file!\n");
        }
        break;

        case ERR_BAD_COMMENT:
        {
            printf("The string \"--\" is not allowed inside a comment!\n");
        }
        break;

        case ERR_DUPLICATE_ATTR:
        {
            //printf("log: %f\n", log2(duplicate_attr_mask));

            //We only check for one duplicate attribute at a time, even though there can be multiple.
            //The attribute with the biggest value in the enum has priority
            //Any other attributes have 1s in less significant bits, so the mask is a decimal number between the prioritized attribute's value and the next power of two
            //log2 is not an integer, but gets floored into one and gives us the prioritized attribute
            printf("Duplicate attribute %s\n", decode_attr[(int)(log2(duplicate_attr_mask))]);
        }
        break;
    }
}

int check_for_required_attributes(const char* elem, uint16_t attr, uint16_t req)
{
    int missing_count = 0;
    char missing_attr_str[256] = "\n\n * "; 

    for (int i = 0; req != 0; i++)
    {    
        //Only if we require a certain atrribute and that doesn't exist in the list, we throw error
        if ( ((req & 1) == 1) && ((attr & 1) == 0) )
        {
            if (missing_count == 0)
            {
                strcat(missing_attr_str, decode_attr[i]);
            }
            else
            {
                strcat(missing_attr_str, "\n\n * ");
                strcat(missing_attr_str, decode_attr[i]);
            }

            missing_count++;
        }

        attr = attr >> 1;
        req = req >> 1;
    }

    if (missing_count > 0)
    {
        char str[300] = "";

        snprintf(str, 300, "Missing %d required attribute%s for element %s: %s", missing_count, (missing_count > 1)?("s"):(""), elem, missing_attr_str);

        err_type = ERR_OTHER;
        yyerror(str);
        return 0;
    }
    
    return 1;
}
