/* original parser id follows */
/* yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93" */
/* (use YYMAJOR/YYMINOR for ifdefs dependent on parser version) */

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20140715

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)
#define YYENOMEM       (-2)
#define YYEOF          0
#define YYPREFIX "yy"

#define YYPURE 0

#line 2 "parser.y"

   #include <string.h>
   #include <stdio.h>
   #include <stdlib.h>

   int yylex();
   char temp[1000000];

   extern int line_count;

#line 15 "parser.y"
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union{

	int iVal;
	double dVal;
	char sVal[100000];

} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 47 "y.tab.c"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

#define VOID 257
#define INT 258
#define FLOAT 259
#define CHAR 260
#define DOUBLE 261
#define CONST 262
#define FOR 263
#define DO 264
#define WHILE 265
#define BREAK 266
#define CONTINUE 267
#define IF 268
#define ELSE 269
#define RETURN 270
#define SWITCH 271
#define CASE 272
#define DEFAULT 273
#define INCRE 274
#define DECRE 275
#define LESS_EQ 276
#define GREAT_EQ 277
#define EQUAL 278
#define NOT_EQ 279
#define LOG_AND 280
#define LOG_OR 281
#define ID 282
#define NUM_INT 283
#define NUM_FLOATING 284
#define CHARACTER 285
#define STRING 286
#define UPLUS 287
#define UMINUS 288
#define SUFFIX_INCRE 289
#define SUFFIX_DECRE 290
#define YYERRCODE 256
typedef short YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    1,    1,    1,    1,    2,    2,    2,    3,    5,
    5,    5,    5,    6,    6,    7,    7,    8,    8,    8,
    8,    8,    8,    8,    8,    8,    8,    8,    8,    8,
    8,    8,    8,    8,    8,    8,    8,    8,    8,    8,
    8,    8,    8,    8,    8,    8,    8,    8,    8,    8,
    9,   10,   10,   11,   11,   12,   12,   13,   13,   13,
   13,   14,   15,   15,   16,   16,   17,   18,   18,   19,
   19,   20,   20,   21,   21,    4,   22,   22,   22,   22,
   23,   23,   24,   25,   25,   25,   25,   25,   25,   25,
   25,   25,   26,   26,   27,   27,   28,   28,   29,   29,
   30,   31,   31,   32,   32,   33,   33,   34,   34,   34,
   34,   35,   35,   36,   37,   37,   38,   38,   39,   40,
   41,   41,   41,   41,
};
static const YYINT yylen[] = {                            2,
    1,    2,    2,    2,    0,    1,    1,    1,    3,    1,
    1,    1,    1,    1,    3,    1,    3,    3,    3,    3,
    3,    3,    3,    3,    3,    3,    3,    3,    3,    3,
    3,    3,    2,    3,    2,    2,    2,    2,    2,    2,
    2,    2,    2,    2,    3,    3,    1,    1,    1,    1,
    2,    4,    3,    4,    3,    3,    1,    1,    1,    1,
    1,    3,    1,    3,    1,    3,    2,    4,    3,    3,
    3,    1,    3,    1,    3,    4,    6,    6,    5,    5,
    3,    1,    2,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    2,    1,    2,    3,    2,    1,    1,    1,
    2,    5,    7,    7,    6,    2,    1,    4,    3,    3,
    2,    5,    7,    9,    1,    0,    2,    3,    2,    2,
    6,    6,    5,    5,
};
static const YYINT yydefred[] = {                         5,
    0,    0,    0,   10,   11,   13,   12,    0,    2,    6,
    8,    0,    7,    3,    4,    0,    0,    0,    0,   14,
    0,   63,    0,    0,    0,    0,    0,    0,    0,    0,
    9,    0,   62,    0,    0,    0,    0,    0,   82,   76,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   58,   59,   60,   61,    0,    0,   47,   50,    0,   15,
    0,   64,    0,   66,    0,   80,  124,   83,    0,    0,
   79,  123,    0,   69,    0,   38,    0,   42,   35,   36,
   33,    0,   39,   43,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   40,   44,    0,    0,    0,   74,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   95,
  100,    0,    0,   99,   92,    0,   98,   84,   85,   86,
   87,   88,   89,   90,   91,   78,  122,   81,   77,  121,
   34,   55,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   20,   21,   22,    0,    0,
    0,    0,    0,   68,   70,    0,   71,    0,    0,    0,
    0,  119,  120,    0,  117,    0,    0,    0,  101,   96,
   97,   54,    0,   53,    0,    0,   75,    0,    0,    0,
    0,    0,  118,    0,    0,   52,    0,    0,    0,    0,
    0,    0,    0,  112,    0,    0,    0,    0,    0,    0,
    0,  105,    0,  107,    0,  113,  103,    0,    0,  104,
  106,    0,    0,   94,    0,  114,    0,   93,
};
static const YYINT yydgoto[] = {                          1,
    2,  121,   10,   11,   37,   19,   20,  123,   56,   88,
   57,  144,   58,   13,   21,   22,   23,   30,   64,  110,
  111,   14,   38,   39,  124,  225,  125,  126,  127,  128,
  129,  130,  213,  214,  131,  132,  189,  133,  134,  135,
   15,
};
static const YYINT yysindex[] = {                         0,
    0,  270, -263,    0,    0,    0,    0, -114,    0,    0,
    0, -261,    0,    0,    0,  -14, -254,  -10,  -19,    0,
   16,    0,  -29,   44,   17,   29,   71, -222,   89,  -11,
    0, -254,    0, -220,  -23,  -46, -195,   38,    0,    0,
   10,  132,    8, -168, -157,   89,   89,   89,   89,    2,
    0,    0,    0,    0,  728,  -55,    0,    0, -142,    0,
   58,    0,   64,    0,   -4,    0,    0,    0,   12, -114,
    0,    0,   13,    0,   68,    0,   68,    0,    0,    0,
    0,  436,    0,    0,   70,   89,   89,   74,   89,   89,
   89,   89,   89,   89,   89,   89,   89,   89,   89,   89,
   89,   89,   89,    0,    0,   89,   84,  728,    0,  -42,
  -30,  148,   51,  154,  136,  144,  174,   83,  176,    0,
    0,  -64,  452,    0,    0,   25,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  728,  167,  463,  728,   89,  162,  162,  982,
  982,  933,  922,  159,  159,    0,    0,    0,  162,  162,
  954,  155,  728,    0,    0,   89,    0,  -23,   89,  -43,
   89,    0,    0,   89,    0,  479,   89,  -44,    0,    0,
    0,    0,   89,    0,  505,  728,    0,  728,  164,  184,
  537,  548,    0,  637,  728,    0,   89,   89,   51,  113,
  123,  188,  663,    0,  -21, -121,   89,  210,  113,   -8,
  214,    0, -105,    0,  253,    0,    0,  239,   51,    0,
    0,   51,   51,    0,   51,    0,   51,    0,
};
static const YYINT yyrindex[] = {                         0,
    0,  298,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   80,    0,    0,
    0,    0,   94,    0,   80,    0,    0,    0,    0,   15,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  342,
    0,    0,    0,    0,   99,  368,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  379,    0,  409,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  119,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  -17,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  169,    0,    0,  -26,    0,  803,  830,  513,
  863,   96,  -36,  760,  795,    0,    0,    0,  838,  888,
   -7,   61,    5,    0,    0,    0,    0,    0,  242,    0,
    0,    0,    0,    0,    0,    0,    0,   80,    0,    0,
    0,    0,    0,    0,    0,    6,    0,   -3,    0,    0,
    0,    0,    0,    0,  224,    0,  242,    0,    0,    0,
    0,    0,    0,    0,  -33,    0,  265,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0, -103,    0,
    0,    0, -101,    0,  -90,    0,  -82,    0,
};
static const YYINT yygindex[] = {                         0,
    0,  310,    0,    0,    1,  296,  288, 1175,    9,    0,
    0,    0,    0,    0,    0,  289,    0,    0,  -62,    0,
    0,    0,  297,  257,  336,  105,  -25,    0,  217,    0,
    0,    0,    0,  127,    0,    0, -152,    0,    0,    0,
    0,
};
#define YYTABLESIZE 1382
static const YYINT yytable[] = {                        102,
  109,  166,   12,  212,   30,  106,  102,   30,   17,  102,
   67,  102,   66,  168,   45,   72,   29,   45,   16,  220,
   18,  111,   30,  109,   32,   24,   72,   25,   48,   27,
   31,   35,   45,   31,  110,   49,   31,  115,   46,   31,
   47,   85,  108,  137,  202,   46,   28,  140,   46,   73,
   29,   31,   76,   78,  215,  115,   30,   48,   67,   34,
   43,   61,   87,   46,   49,  122,   45,   46,   71,   47,
  136,  139,   32,   67,   33,   67,   65,   29,   69,   59,
   28,   70,  165,   48,   36,   31,   68,   40,   30,  102,
   49,  102,   86,   46,  167,   47,   48,   46,   45,   63,
   74,   32,   48,   49,   32,  187,   46,   72,   47,   49,
  142,   41,   46,   75,   47,   48,   31,   31,   65,   32,
  120,   48,   49,   16,   77,   46,  122,   47,   49,   46,
   73,   46,   65,   47,   65,   65,   29,   65,   16,   29,
  107,  175,   17,    4,    5,    6,    7,   65,   28,  180,
  210,  211,   65,   32,   29,   51,   51,   17,   86,   51,
   51,   51,   51,   51,  147,   51,  210,  211,  111,  111,
  109,  109,   73,   65,  205,   70,  164,   51,   51,   51,
   51,  110,  110,  217,   32,   32,   63,  169,   29,  108,
  108,   99,  102,  171,  172,   99,   97,   95,   99,   96,
   97,   98,  173,   97,   95,   98,   96,  182,   98,   57,
  183,   51,   57,  174,  100,  177,  101,  178,  104,  105,
   29,  190,  197,  198,  102,  102,  102,  102,  102,  102,
  102,  102,  102,  102,  102,   65,  102,  102,  102,  102,
  102,  102,   51,   51,   30,  206,  207,  209,  102,  102,
  102,  102,  102,    4,    5,    6,    7,    8,  112,  113,
  114,  115,  116,  117,   56,  118,  119,   56,  216,   44,
   45,  219,   31,   31,  218,   83,   84,   50,   51,   52,
   53,   54,    4,    5,    6,    7,    8,  112,  113,  114,
  115,  116,  117,  222,  118,  119,  223,    1,   44,   45,
  116,    4,    5,    6,    7,  116,   50,   51,   52,   53,
   54,    9,   26,  112,  113,  114,  115,  116,  117,   60,
  118,  119,   62,   42,   44,   45,  138,  227,    4,    5,
    6,    7,   50,   51,   52,   53,   54,   44,   45,  221,
   32,   32,  181,   44,   45,   50,   51,   52,   53,   54,
    0,   50,   51,   52,   53,   54,   44,   45,    0,    0,
    0,    0,   44,   45,   50,   51,   52,   53,   54,    0,
   50,   51,   52,   53,   54,   29,   29,    0,   48,   48,
    0,    0,   48,   48,   48,   48,   48,    0,   48,    0,
    0,    0,   51,   51,   51,   51,   51,   51,   51,   51,
   48,   48,    0,   48,   49,   49,    0,    0,   49,   49,
   49,   49,   49,    0,   49,   37,   37,    0,    0,   37,
   37,   37,   37,   37,    0,   37,   49,   49,    0,   49,
   89,   90,   91,   92,   48,    0,    0,   37,   37,    0,
   37,    0,    0,    0,    0,   41,   41,    0,  170,   41,
   41,   41,   41,   41,    0,   41,    0,    0,    0,    0,
   49,    0,    0,    0,    0,   48,   48,   41,   41,    0,
   41,   37,   99,  102,    0,    0,  141,   97,   95,    0,
   96,    0,   98,    0,    0,    0,    0,    0,   99,  102,
    0,   49,   49,   97,   95,  100,   96,  101,   98,   99,
  102,   41,   37,   37,   97,   95,    0,   96,    0,   98,
  179,  100,    0,  101,    0,   99,  102,    0,    0,    0,
   97,   95,  100,   96,  101,   98,    3,    4,    5,    6,
    7,    8,   41,   41,  204,    0,    0,  193,  100,    0,
  101,   99,  102,    0,    0,    0,   97,   95,    0,   96,
   27,   98,    0,   27,  224,  184,   27,  226,  224,  103,
  228,    0,  228,    0,  100,    0,  101,    0,    0,    0,
    0,   27,    0,   99,  102,  103,    0,  199,   97,   95,
    0,   96,    0,   98,   99,  102,  103,    0,  200,   97,
   95,    0,   96,    0,   98,    0,  100,  196,  101,    0,
    0,    0,  103,    0,    0,   27,    0,  100,    0,  101,
    0,    0,    0,    0,    0,    0,    0,   48,   48,   48,
   48,   48,   48,    0,    0,    0,    0,    0,  103,    0,
    0,    0,    0,    0,    0,    0,   27,   27,    0,    0,
    0,    0,    0,   49,   49,   49,   49,   49,   49,    0,
    0,    0,    0,    0,   37,   37,   37,   37,   37,   37,
  103,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  103,    0,   99,  102,    0,    0,  201,   97,   95,
    0,   96,    0,   98,   41,   41,   41,   41,   41,   41,
    0,    0,    0,    0,    0,    0,  100,    0,  101,   99,
  102,    0,    0,  208,   97,   95,    0,   96,    0,   98,
    0,   89,   90,   91,   92,   93,   94,    0,    0,    0,
    0,    0,  100,    0,  101,    0,    0,   89,   90,   91,
   92,   93,   94,    0,    0,    0,    0,    0,   89,   90,
   91,   92,   93,   94,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   89,   90,   91,   92,   93,   94,
  103,    0,    0,    0,   99,  102,    0,    0,    0,   97,
   95,    0,   96,    0,   98,    0,    0,    0,    0,    0,
   89,   90,   91,   92,   93,   94,  103,  100,    0,  101,
   27,   27,   27,   27,    0,    0,    0,   18,    0,    0,
   18,    0,   18,   18,   18,    0,    0,    0,    0,    0,
    0,    0,   89,   90,   91,   92,   93,   94,   18,   18,
    0,   18,    0,   89,   90,   91,   92,   93,   94,    0,
    0,    0,   19,    0,    0,   19,    0,   19,   19,   19,
   24,    0,    0,   24,    0,    0,   24,    0,    0,    0,
    0,  103,   18,   19,   19,    0,   19,    0,    0,    0,
    0,   24,   24,    0,   24,    0,    0,   26,    0,    0,
   26,    0,    0,   26,    0,   23,    0,    0,   23,    0,
    0,   23,    0,   18,   18,    0,    0,   19,   26,   26,
    0,   26,    0,    0,    0,   24,   23,   23,    0,   23,
   28,    0,    0,   28,    0,    0,   28,    0,    0,    0,
    0,    0,   89,   90,   91,   92,   93,   94,   19,   19,
    0,   28,   26,    0,    0,   25,   24,   24,   25,    0,
   23,   25,    0,    0,    0,    0,    0,    0,   89,   90,
   91,   92,   93,   94,    0,    0,   25,   25,    0,   25,
    0,    0,    0,   26,   26,   28,    0,    0,   99,  102,
    0,   23,   23,   97,   95,    0,   96,    0,   98,   99,
  102,    0,    0,    0,   97,   95,    0,   96,    0,   98,
   25,  100,    0,  101,    0,    0,   28,   28,    0,    0,
   99,    0,  100,    0,  101,   97,   95,    0,   96,    0,
   98,    0,    0,   89,   90,   91,   92,   93,   94,    0,
    0,   25,   25,  100,    0,  101,    0,    0,   99,    0,
    0,    0,    0,   97,   95,    0,   96,    0,   98,    0,
    0,    0,    0,    0,    0,   18,   18,   18,   18,   18,
   18,  100,    0,  101,    0,  103,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  103,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   19,   19,   19,   19,   19,   19,    0,    0,   24,   24,
   24,   24,   24,   24,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   26,   26,   26,   26,   26,
   26,    0,    0,   23,   23,   23,   23,   23,   23,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   28,   28,   28,   28,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   25,   25,   25,   25,   25,   25,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   89,   90,   91,
   92,   93,    0,   55,    0,    0,    0,    0,   89,   90,
   91,   92,    0,    0,    0,    0,    0,    0,    0,    0,
   79,   80,   81,   82,    0,    0,    0,    0,    0,   89,
   90,   91,   92,    0,    0,    0,    0,  108,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   89,   90,  143,
  145,  146,    0,  148,  149,  150,  151,  152,  153,  154,
  155,  156,  157,  158,  159,  160,  161,  162,    0,    0,
  163,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  176,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  185,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  186,    0,    0,  188,    0,  191,    0,    0,  192,    0,
    0,  194,    0,    0,    0,    0,    0,  195,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  188,  203,    0,    0,    0,    0,    0,    0,    0,
    0,  188,
};
static const YYINT yycheck[] = {                         33,
   63,   44,    2,  125,   41,   61,   40,   44,    8,   43,
   36,   45,   59,   44,   41,   41,   61,   44,  282,  125,
  282,  125,   59,  125,   44,   40,   44,  282,   33,   40,
   38,   61,   59,   41,  125,   40,   44,   41,   43,   59,
   45,   40,  125,   69,  197,   41,   91,   73,   44,   44,
   61,   59,   44,   45,  207,   59,   93,   33,   44,   44,
  283,  282,   61,   59,   40,   65,   93,   43,   59,   45,
   59,   59,   44,   59,   59,   61,  123,   61,   41,   91,
   91,   44,  125,   33,   41,   93,  282,   59,  125,  123,
   40,  125,   91,   43,  125,   45,   33,   93,  125,  123,
   93,   41,   33,   40,   44,  168,   43,  125,   45,   40,
   41,   41,   43,  282,   45,   33,  124,  125,  123,   59,
  125,   33,   40,   44,  282,   43,  126,   45,   40,  125,
  125,   43,  123,   45,  123,  123,   41,   44,   59,   44,
  283,   59,   44,  258,  259,  260,  261,  123,   91,  125,
  272,  273,   59,   93,   59,   37,   38,   59,   91,   41,
   42,   43,   44,   45,   91,   47,  272,  273,  272,  273,
  272,  273,   41,  123,  200,   44,   93,   59,   60,   61,
   62,  272,  273,  209,  124,  125,  123,   40,   93,  272,
  273,   37,   38,   40,   59,   37,   42,   43,   37,   45,
   42,   47,   59,   42,   43,   47,   45,   41,   47,   41,
   44,   93,   44,   40,   60,   40,   62,  282,  274,  275,
  125,  265,   59,   40,  258,  259,  260,  261,  262,  263,
  264,  265,  266,  267,  268,  123,  270,  271,  272,  273,
  274,  275,  124,  125,  281,  123,   59,  269,  282,  283,
  284,  285,  286,  258,  259,  260,  261,  262,  263,  264,
  265,  266,  267,  268,   41,  270,  271,   44,   59,  274,
  275,   58,  280,  281,  283,  274,  275,  282,  283,  284,
  285,  286,  258,  259,  260,  261,  262,  263,  264,  265,
  266,  267,  268,   41,  270,  271,   58,    0,  274,  275,
   59,  258,  259,  260,  261,   41,  282,  283,  284,  285,
  286,    2,   17,  263,  264,  265,  266,  267,  268,   32,
  270,  271,   34,   27,  274,  275,   70,  223,  258,  259,
  260,  261,  282,  283,  284,  285,  286,  274,  275,  213,
  280,  281,  126,  274,  275,  282,  283,  284,  285,  286,
   -1,  282,  283,  284,  285,  286,  274,  275,   -1,   -1,
   -1,   -1,  274,  275,  282,  283,  284,  285,  286,   -1,
  282,  283,  284,  285,  286,  280,  281,   -1,   37,   38,
   -1,   -1,   41,   42,   43,   44,   45,   -1,   47,   -1,
   -1,   -1,  274,  275,  276,  277,  278,  279,  280,  281,
   59,   60,   -1,   62,   37,   38,   -1,   -1,   41,   42,
   43,   44,   45,   -1,   47,   37,   38,   -1,   -1,   41,
   42,   43,   44,   45,   -1,   47,   59,   60,   -1,   62,
  276,  277,  278,  279,   93,   -1,   -1,   59,   60,   -1,
   62,   -1,   -1,   -1,   -1,   37,   38,   -1,  113,   41,
   42,   43,   44,   45,   -1,   47,   -1,   -1,   -1,   -1,
   93,   -1,   -1,   -1,   -1,  124,  125,   59,   60,   -1,
   62,   93,   37,   38,   -1,   -1,   41,   42,   43,   -1,
   45,   -1,   47,   -1,   -1,   -1,   -1,   -1,   37,   38,
   -1,  124,  125,   42,   43,   60,   45,   62,   47,   37,
   38,   93,  124,  125,   42,   43,   -1,   45,   -1,   47,
   59,   60,   -1,   62,   -1,   37,   38,   -1,   -1,   -1,
   42,   43,   60,   45,   62,   47,  257,  258,  259,  260,
  261,  262,  124,  125,  199,   -1,   -1,   59,   60,   -1,
   62,   37,   38,   -1,   -1,   -1,   42,   43,   -1,   45,
   38,   47,   -1,   41,  219,   93,   44,  222,  223,  124,
  225,   -1,  227,   -1,   60,   -1,   62,   -1,   -1,   -1,
   -1,   59,   -1,   37,   38,  124,   -1,   41,   42,   43,
   -1,   45,   -1,   47,   37,   38,  124,   -1,   41,   42,
   43,   -1,   45,   -1,   47,   -1,   60,   93,   62,   -1,
   -1,   -1,  124,   -1,   -1,   93,   -1,   60,   -1,   62,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  276,  277,  278,
  279,  280,  281,   -1,   -1,   -1,   -1,   -1,  124,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  124,  125,   -1,   -1,
   -1,   -1,   -1,  276,  277,  278,  279,  280,  281,   -1,
   -1,   -1,   -1,   -1,  276,  277,  278,  279,  280,  281,
  124,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  124,   -1,   37,   38,   -1,   -1,   41,   42,   43,
   -1,   45,   -1,   47,  276,  277,  278,  279,  280,  281,
   -1,   -1,   -1,   -1,   -1,   -1,   60,   -1,   62,   37,
   38,   -1,   -1,   41,   42,   43,   -1,   45,   -1,   47,
   -1,  276,  277,  278,  279,  280,  281,   -1,   -1,   -1,
   -1,   -1,   60,   -1,   62,   -1,   -1,  276,  277,  278,
  279,  280,  281,   -1,   -1,   -1,   -1,   -1,  276,  277,
  278,  279,  280,  281,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  276,  277,  278,  279,  280,  281,
  124,   -1,   -1,   -1,   37,   38,   -1,   -1,   -1,   42,
   43,   -1,   45,   -1,   47,   -1,   -1,   -1,   -1,   -1,
  276,  277,  278,  279,  280,  281,  124,   60,   -1,   62,
  278,  279,  280,  281,   -1,   -1,   -1,   38,   -1,   -1,
   41,   -1,   43,   44,   45,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  276,  277,  278,  279,  280,  281,   59,   60,
   -1,   62,   -1,  276,  277,  278,  279,  280,  281,   -1,
   -1,   -1,   38,   -1,   -1,   41,   -1,   43,   44,   45,
   38,   -1,   -1,   41,   -1,   -1,   44,   -1,   -1,   -1,
   -1,  124,   93,   59,   60,   -1,   62,   -1,   -1,   -1,
   -1,   59,   60,   -1,   62,   -1,   -1,   38,   -1,   -1,
   41,   -1,   -1,   44,   -1,   38,   -1,   -1,   41,   -1,
   -1,   44,   -1,  124,  125,   -1,   -1,   93,   59,   60,
   -1,   62,   -1,   -1,   -1,   93,   59,   60,   -1,   62,
   38,   -1,   -1,   41,   -1,   -1,   44,   -1,   -1,   -1,
   -1,   -1,  276,  277,  278,  279,  280,  281,  124,  125,
   -1,   59,   93,   -1,   -1,   38,  124,  125,   41,   -1,
   93,   44,   -1,   -1,   -1,   -1,   -1,   -1,  276,  277,
  278,  279,  280,  281,   -1,   -1,   59,   60,   -1,   62,
   -1,   -1,   -1,  124,  125,   93,   -1,   -1,   37,   38,
   -1,  124,  125,   42,   43,   -1,   45,   -1,   47,   37,
   38,   -1,   -1,   -1,   42,   43,   -1,   45,   -1,   47,
   93,   60,   -1,   62,   -1,   -1,  124,  125,   -1,   -1,
   37,   -1,   60,   -1,   62,   42,   43,   -1,   45,   -1,
   47,   -1,   -1,  276,  277,  278,  279,  280,  281,   -1,
   -1,  124,  125,   60,   -1,   62,   -1,   -1,   37,   -1,
   -1,   -1,   -1,   42,   43,   -1,   45,   -1,   47,   -1,
   -1,   -1,   -1,   -1,   -1,  276,  277,  278,  279,  280,
  281,   60,   -1,   62,   -1,  124,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  124,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  276,  277,  278,  279,  280,  281,   -1,   -1,  276,  277,
  278,  279,  280,  281,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  276,  277,  278,  279,  280,
  281,   -1,   -1,  276,  277,  278,  279,  280,  281,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  278,  279,  280,  281,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  276,  277,  278,  279,  280,  281,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  276,  277,  278,
  279,  280,   -1,   29,   -1,   -1,   -1,   -1,  276,  277,
  278,  279,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   46,   47,   48,   49,   -1,   -1,   -1,   -1,   -1,  276,
  277,  278,  279,   -1,   -1,   -1,   -1,   63,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  276,  277,   85,
   86,   87,   -1,   89,   90,   91,   92,   93,   94,   95,
   96,   97,   98,   99,  100,  101,  102,  103,   -1,   -1,
  106,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  118,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  147,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  166,   -1,   -1,  169,   -1,  171,   -1,   -1,  174,   -1,
   -1,  177,   -1,   -1,   -1,   -1,   -1,  183,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  197,  198,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  207,
};
#define YYFINAL 1
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 290
#define YYUNDFTOKEN 334
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
"'!'",0,0,0,"'%'","'&'",0,"'('","')'","'*'","'+'","','","'-'",0,"'/'",0,0,0,0,0,
0,0,0,0,0,"':'","';'","'<'","'='","'>'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,"'['",0,"']'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,"'{'","'|'","'}'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"VOID","INT","FLOAT","CHAR",
"DOUBLE","CONST","FOR","DO","WHILE","BREAK","CONTINUE","IF","ELSE","RETURN",
"SWITCH","CASE","DEFAULT","INCRE","DECRE","LESS_EQ","GREAT_EQ","EQUAL","NOT_EQ",
"LOG_AND","LOG_OR","ID","NUM_INT","NUM_FLOATING","CHARACTER","STRING","UPLUS",
"UMINUS","SUFFIX_INCRE","SUFFIX_DECRE",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : program_plum",
"program_plum : program",
"program : program var_decl",
"program : program func_decl",
"program : program func_def",
"program :",
"var_decl : scalar_decl",
"var_decl : array_decl",
"var_decl : const_decl",
"scalar_decl : var_type init_list ';'",
"var_type : INT",
"var_type : FLOAT",
"var_type : DOUBLE",
"var_type : CHAR",
"init_list : init_unit",
"init_list : init_list ',' init_unit",
"init_unit : ID",
"init_unit : ID '=' expr",
"expr : expr '+' expr",
"expr : expr '-' expr",
"expr : expr '*' expr",
"expr : expr '/' expr",
"expr : expr '%' expr",
"expr : expr '<' expr",
"expr : expr LESS_EQ expr",
"expr : expr '>' expr",
"expr : expr GREAT_EQ expr",
"expr : expr EQUAL expr",
"expr : expr NOT_EQ expr",
"expr : expr LOG_AND expr",
"expr : expr LOG_OR expr",
"expr : expr '&' expr",
"expr : expr '|' expr",
"expr : '!' expr",
"expr : '(' expr ')'",
"expr : '+' expr",
"expr : '-' expr",
"expr : INCRE ID",
"expr : INCRE id_arr_access",
"expr : ID INCRE",
"expr : id_arr_access INCRE",
"expr : DECRE ID",
"expr : DECRE id_arr_access",
"expr : ID DECRE",
"expr : id_arr_access DECRE",
"expr : ID '=' expr",
"expr : id_arr_access '=' expr",
"expr : func_invoc",
"expr : ID",
"expr : id_arr_access",
"expr : literal",
"id_arr_access : ID access_list",
"access_list : access_list '[' expr ']'",
"access_list : '[' expr ']'",
"func_invoc : ID '(' argument_list ')'",
"func_invoc : ID '(' ')'",
"argument_list : argument_list ',' expr",
"argument_list : expr",
"literal : NUM_INT",
"literal : NUM_FLOATING",
"literal : CHARACTER",
"literal : STRING",
"array_decl : var_type init_list_arr ';'",
"init_list_arr : init_unit_arr",
"init_list_arr : init_list_arr ',' init_unit_arr",
"init_unit_arr : id_arr_decl",
"init_unit_arr : id_arr_decl '=' arr_content",
"id_arr_decl : ID arr_decl_list",
"arr_decl_list : arr_decl_list '[' NUM_INT ']'",
"arr_decl_list : '[' NUM_INT ']'",
"arr_content : '{' expr_list '}'",
"arr_content : '{' arr_content_list '}'",
"expr_list : expr",
"expr_list : expr_list ',' expr",
"arr_content_list : arr_content",
"arr_content_list : arr_content_list ',' arr_content",
"const_decl : CONST var_type init_list ';'",
"func_decl : var_type ID '(' param_list ')' ';'",
"func_decl : VOID ID '(' param_list ')' ';'",
"func_decl : var_type ID '(' ')' ';'",
"func_decl : VOID ID '(' ')' ';'",
"param_list : param_list ',' param_unit",
"param_list : param_unit",
"param_unit : var_type ID",
"statement : stmt_expression",
"statement : stmt_if",
"statement : stmt_switch",
"statement : stmt_while",
"statement : stmt_for",
"statement : stmt_return",
"statement : stmt_break",
"statement : stmt_continue",
"statement : compound_statement",
"statements : statements statement",
"statements : statement",
"compound_statement : '{' '}'",
"compound_statement : '{' statement_var_decls '}'",
"statement_var_decls : statement_var_decls statement_var_decl",
"statement_var_decls : statement_var_decl",
"statement_var_decl : statement",
"statement_var_decl : var_decl",
"stmt_expression : expr ';'",
"stmt_if : IF '(' expr ')' compound_statement",
"stmt_if : IF '(' expr ')' compound_statement ELSE compound_statement",
"stmt_switch : SWITCH '(' expr ')' '{' switch_clauses '}'",
"stmt_switch : SWITCH '(' expr ')' '{' '}'",
"switch_clauses : switch_clauses switch_clause",
"switch_clauses : switch_clause",
"switch_clause : CASE NUM_INT ':' statements",
"switch_clause : CASE NUM_INT ':'",
"switch_clause : DEFAULT ':' statements",
"switch_clause : DEFAULT ':'",
"stmt_while : WHILE '(' expr ')' statement",
"stmt_while : DO statement WHILE '(' expr ')' ';'",
"stmt_for : FOR '(' expr_empty ';' expr_empty ';' expr_empty ')' statement",
"expr_empty : expr",
"expr_empty :",
"stmt_return : RETURN ';'",
"stmt_return : RETURN expr ';'",
"stmt_break : BREAK ';'",
"stmt_continue : CONTINUE ';'",
"func_def : var_type ID '(' param_list ')' compound_statement",
"func_def : VOID ID '(' param_list ')' compound_statement",
"func_def : var_type ID '(' ')' compound_statement",
"func_def : VOID ID '(' ')' compound_statement",

};
#endif

int      yydebug;
int      yynerrs;

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  10000
#endif
#endif

#define YYINITSTACKSIZE 200

typedef struct {
    unsigned stacksize;
    YYINT    *s_base;
    YYINT    *s_mark;
    YYINT    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;
#line 809 "parser.y"


int main(void)
{
	line_count = 1;

	yyparse();

	return 0;
}

int yyerror(char *s)
{
	fprintf(stderr, "Error at line %d:\n%s\n", line_count, s);
	return 1;
}
#line 722 "y.tab.c"

#if YYDEBUG
#include <stdio.h>		/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    YYINT *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return YYENOMEM;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (YYINT *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return YYENOMEM;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return YYENOMEM;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
        {
            goto yyoverflow;
        }
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;

    YYERROR_CALL("syntax error");

    goto yyerrlab;

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yystack.s_mark]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
                {
                    goto yyoverflow;
                }
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == YYEOF) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
case 1:
#line 71 "parser.y"
	{

		printf("%s", yystack.l_mark[0].sVal);

	}
break;
case 2:
#line 77 "parser.y"
	{

		sprintf(temp, "%s%s", yystack.l_mark[-1].sVal, yystack.l_mark[0].sVal);
                strcpy(yyval.sVal, temp);

	}
break;
case 3:
#line 84 "parser.y"
	{

		sprintf(temp, "%s<func_decl>%s</func_decl>", yystack.l_mark[-1].sVal, yystack.l_mark[0].sVal);
                strcpy(yyval.sVal, temp);

	}
break;
case 4:
#line 91 "parser.y"
	{

		sprintf(temp, "%s<func_def>%s</func_def>", yystack.l_mark[-1].sVal, yystack.l_mark[0].sVal);
                strcpy(yyval.sVal, temp);

	}
break;
case 5:
#line 98 "parser.y"
	{}
break;
case 6:
#line 101 "parser.y"
	{

		sprintf(temp, "<scalar_decl>%s</scalar_decl>", yystack.l_mark[0].sVal);
		strcpy(yyval.sVal, temp);

	}
break;
case 7:
#line 108 "parser.y"
	{

		sprintf(temp, "<array_decl>%s</array_decl>", yystack.l_mark[0].sVal);
		strcpy(yyval.sVal, temp);

	}
break;
case 8:
#line 115 "parser.y"
	{

		sprintf(temp, "<const_decl>%s</const_decl>", yystack.l_mark[0].sVal);
		strcpy(yyval.sVal, temp);

	}
break;
case 9:
#line 124 "parser.y"
	{

		sprintf(temp, "%s%s;", yystack.l_mark[-2].sVal, yystack.l_mark[-1].sVal);
		strcpy(yyval.sVal, temp);

	}
break;
case 15:
#line 135 "parser.y"
	{

		strcpy(yyval.sVal, yystack.l_mark[-2].sVal);
		strcat(yyval.sVal, yystack.l_mark[-1].sVal);
		strcat(yyval.sVal, yystack.l_mark[0].sVal);

	}
break;
case 17:
#line 145 "parser.y"
	{
		
		sprintf(temp, "%s=<expr>%s</expr>", yystack.l_mark[-2].sVal, yystack.l_mark[0].sVal);
		strcpy(yyval.sVal, temp);

	}
break;
case 18:
#line 154 "parser.y"
	{

		sprintf(temp, "<expr>%s</expr>+<expr>%s</expr>", yystack.l_mark[-2].sVal, yystack.l_mark[0].sVal);
		strcpy(yyval.sVal, temp);

	}
break;
case 19:
#line 161 "parser.y"
	{

                sprintf(temp, "<expr>%s</expr>-<expr>%s</expr>", yystack.l_mark[-2].sVal, yystack.l_mark[0].sVal);
		strcpy(yyval.sVal, temp);

	}
break;
case 20:
#line 168 "parser.y"
	{

		sprintf(temp, "<expr>%s</expr>*<expr>%s</expr>", yystack.l_mark[-2].sVal, yystack.l_mark[0].sVal);
		strcpy(yyval.sVal, temp);

	}
break;
case 21:
#line 175 "parser.y"
	{

                sprintf(temp, "<expr>%s</expr>/<expr>%s</expr>", yystack.l_mark[-2].sVal, yystack.l_mark[0].sVal);
		strcpy(yyval.sVal, temp);

        }
break;
case 22:
#line 182 "parser.y"
	{

                sprintf(temp, "<expr>%s</expr>%%<expr>%s</expr>", yystack.l_mark[-2].sVal, yystack.l_mark[0].sVal);
		strcpy(yyval.sVal, temp);

        }
break;
case 23:
#line 189 "parser.y"
	{

                sprintf(temp, "<expr>%s</expr><<expr>%s</expr>", yystack.l_mark[-2].sVal, yystack.l_mark[0].sVal);
		strcpy(yyval.sVal, temp);

        }
break;
case 24:
#line 196 "parser.y"
	{

		sprintf(temp, "<expr>%s</expr><=<expr>%s</expr>", yystack.l_mark[-2].sVal, yystack.l_mark[0].sVal);
		strcpy(yyval.sVal, temp);

        }
break;
case 25:
#line 203 "parser.y"
	{

                sprintf(temp, "<expr>%s</expr>><expr>%s</expr>", yystack.l_mark[-2].sVal, yystack.l_mark[0].sVal);
		strcpy(yyval.sVal, temp);

        }
break;
case 26:
#line 210 "parser.y"
	{

                sprintf(temp, "<expr>%s</expr>>=<expr>%s</expr>", yystack.l_mark[-2].sVal, yystack.l_mark[0].sVal);
		strcpy(yyval.sVal, temp);

        }
break;
case 27:
#line 217 "parser.y"
	{

                sprintf(temp, "<expr>%s</expr>==<expr>%s</expr>", yystack.l_mark[-2].sVal, yystack.l_mark[0].sVal);
		strcpy(yyval.sVal, temp);

        }
break;
case 28:
#line 224 "parser.y"
	{

                sprintf(temp, "<expr>%s</expr>!=<expr>%s</expr>", yystack.l_mark[-2].sVal, yystack.l_mark[0].sVal);
		strcpy(yyval.sVal, temp);

        }
break;
case 29:
#line 231 "parser.y"
	{

                sprintf(temp, "<expr>%s</expr>&&<expr>%s</expr>", yystack.l_mark[-2].sVal, yystack.l_mark[0].sVal);
		strcpy(yyval.sVal, temp);
        }
break;
case 30:
#line 237 "parser.y"
	{

                sprintf(temp, "<expr>%s</expr>||<expr>%s</expr>", yystack.l_mark[-2].sVal, yystack.l_mark[0].sVal);
		strcpy(yyval.sVal, temp);		

        }
break;
case 31:
#line 244 "parser.y"
	{

                sprintf(temp, "<expr>%s</expr>&<expr>%s</expr>", yystack.l_mark[-2].sVal, yystack.l_mark[0].sVal);
                strcpy(yyval.sVal, temp);

        }
break;
case 32:
#line 251 "parser.y"
	{

                sprintf(temp, "<expr>%s</expr>|<expr>%s</expr>", yystack.l_mark[-2].sVal, yystack.l_mark[0].sVal);
		strcpy(yyval.sVal, temp);

        }
break;
case 33:
#line 258 "parser.y"
	{

		sprintf(temp, "!<expr>%s</expr>", yystack.l_mark[0].sVal);
                strcpy(yyval.sVal, temp);

        }
break;
case 34:
#line 265 "parser.y"
	{
                
                sprintf(temp, "(<expr>%s</expr>)", yystack.l_mark[-1].sVal);
		strcpy(yyval.sVal, temp);

	}
break;
case 35:
#line 272 "parser.y"
	{

                sprintf(temp, "+<expr>%s</expr>", yystack.l_mark[0].sVal);
		strcpy(yyval.sVal, temp);

        }
break;
case 36:
#line 279 "parser.y"
	{

                sprintf(temp, "-<expr>%s</expr>", yystack.l_mark[0].sVal);
		strcpy(yyval.sVal, temp);

        }
break;
case 37:
#line 286 "parser.y"
	{

		strcpy(yyval.sVal, yystack.l_mark[-1].sVal);
		strcat(yyval.sVal, yystack.l_mark[0].sVal);

	}
break;
case 38:
#line 293 "parser.y"
	{

                strcpy(yyval.sVal, yystack.l_mark[-1].sVal);
                strcat(yyval.sVal, yystack.l_mark[0].sVal);

	}
break;
case 39:
#line 300 "parser.y"
	{

                strcpy(yyval.sVal, yystack.l_mark[-1].sVal);
                strcat(yyval.sVal, yystack.l_mark[0].sVal);

	}
break;
case 40:
#line 307 "parser.y"
	{

                strcpy(yyval.sVal, yystack.l_mark[-1].sVal);
                strcat(yyval.sVal, yystack.l_mark[0].sVal);

	}
break;
case 41:
#line 314 "parser.y"
	{

                strcpy(yyval.sVal, yystack.l_mark[-1].sVal);
                strcat(yyval.sVal, yystack.l_mark[0].sVal);

        }
break;
case 42:
#line 321 "parser.y"
	{

                strcpy(yyval.sVal, yystack.l_mark[-1].sVal);
                strcat(yyval.sVal, yystack.l_mark[0].sVal);

        }
break;
case 43:
#line 328 "parser.y"
	{

                strcpy(yyval.sVal, yystack.l_mark[-1].sVal);
                strcat(yyval.sVal, yystack.l_mark[0].sVal);

        }
break;
case 44:
#line 335 "parser.y"
	{

                strcpy(yyval.sVal, yystack.l_mark[-1].sVal);
                strcat(yyval.sVal, yystack.l_mark[0].sVal);

        }
break;
case 45:
#line 342 "parser.y"
	{

                sprintf(temp, "%s=<expr>%s</expr>", yystack.l_mark[-2].sVal, yystack.l_mark[0].sVal);
		strcpy(yyval.sVal, temp);

	}
break;
case 46:
#line 349 "parser.y"
	{

                sprintf(temp, "%s=<expr>%s</expr>", yystack.l_mark[-2].sVal, yystack.l_mark[0].sVal);
		strcpy(yyval.sVal, temp);

	}
break;
case 51:
#line 364 "parser.y"
	{

                strcpy(yyval.sVal, yystack.l_mark[-1].sVal);
                strcat(yyval.sVal, yystack.l_mark[0].sVal);

	}
break;
case 52:
#line 371 "parser.y"
	{

		sprintf(temp, "%s[<expr>%s</expr>]", yystack.l_mark[-3].sVal, yystack.l_mark[-1].sVal);
		strcpy(yyval.sVal, temp);

	}
break;
case 53:
#line 378 "parser.y"
	{

		sprintf(temp, "[<expr>%s</expr>]", yystack.l_mark[-1].sVal);
		strcpy(yyval.sVal, temp);

	}
break;
case 54:
#line 385 "parser.y"
	{

                strcpy(yyval.sVal, yystack.l_mark[-3].sVal);
                strcat(yyval.sVal, yystack.l_mark[-2].sVal);
                strcat(yyval.sVal, yystack.l_mark[-1].sVal);
		strcat(yyval.sVal, yystack.l_mark[0].sVal);

	}
break;
case 56:
#line 396 "parser.y"
	{

		sprintf(temp, "%s,<expr>%s</expr>", yystack.l_mark[-2].sVal, yystack.l_mark[0].sVal);
		strcpy(yyval.sVal, temp);

	}
break;
case 57:
#line 403 "parser.y"
	{

		sprintf(temp, "<expr>%s</expr>", yystack.l_mark[0].sVal);
		strcpy(yyval.sVal, temp);

	}
break;
case 58:
#line 410 "parser.y"
	{

		sprintf(temp, "%d", yystack.l_mark[0].iVal);
		strcpy(yyval.sVal, temp);

	}
break;
case 59:
#line 417 "parser.y"
	{

		sprintf(temp, "%f", yystack.l_mark[0].dVal);
		strcpy(yyval.sVal, temp);

	}
break;
case 60:
#line 424 "parser.y"
	{

		if (strcmp(yystack.l_mark[0].sVal, "\\\\") == 0)
			sprintf(temp, "%s", "\\");
		else if (strcmp(yystack.l_mark[0].sVal, "\\'") == 0)
			sprintf(temp, "%s", "'");

		strcpy(yyval.sVal, temp);

	}
break;
case 62:
#line 439 "parser.y"
	{

		sprintf(temp, "%s%s;", yystack.l_mark[-2].sVal, yystack.l_mark[-1].sVal);
		strcpy(yyval.sVal, temp);	

	}
break;
case 64:
#line 448 "parser.y"
	{

		sprintf(temp, "%s,%s", yystack.l_mark[-2].sVal, yystack.l_mark[0].sVal);
		strcpy(yyval.sVal, temp);

	}
break;
case 66:
#line 457 "parser.y"
	{

		sprintf(temp, "%s=%s", yystack.l_mark[-2].sVal, yystack.l_mark[0].sVal);
                strcpy(yyval.sVal, temp);

	}
break;
case 67:
#line 464 "parser.y"
	{

		strcpy(yyval.sVal, yystack.l_mark[-1].sVal);
		strcat(yyval.sVal, yystack.l_mark[0].sVal);

	}
break;
case 68:
#line 471 "parser.y"
	{

		sprintf(temp, "%s[%d]", yystack.l_mark[-3].sVal, yystack.l_mark[-1].iVal);
		strcpy(yyval.sVal, temp);

	}
break;
case 69:
#line 478 "parser.y"
	{

                sprintf(temp, "[%d]", yystack.l_mark[-1].iVal);
                strcpy(yyval.sVal, temp);

	}
break;
case 70:
#line 485 "parser.y"
	{

                sprintf(temp, "{%s}", yystack.l_mark[-1].sVal);
                strcpy(yyval.sVal, temp);

	}
break;
case 71:
#line 492 "parser.y"
	{

                sprintf(temp, "{%s}", yystack.l_mark[-1].sVal);
                strcpy(yyval.sVal, temp);

	}
break;
case 72:
#line 499 "parser.y"
	{

		sprintf(temp, "<expr>%s</expr>", yystack.l_mark[0].sVal);
		strcpy(yyval.sVal, temp);

	}
break;
case 73:
#line 506 "parser.y"
	{

		sprintf(temp, "%s,<expr>%s</expr>", yystack.l_mark[-2].sVal, yystack.l_mark[0].sVal);
		strcpy(yyval.sVal, temp);

	}
break;
case 75:
#line 515 "parser.y"
	{

		sprintf(temp, "%s,%s", yystack.l_mark[-2].sVal, yystack.l_mark[0].sVal);
		strcpy(yyval.sVal, temp);

	}
break;
case 76:
#line 525 "parser.y"
	{

		sprintf(temp, "%s%s%s;", yystack.l_mark[-3].sVal, yystack.l_mark[-2].sVal, yystack.l_mark[-1].sVal);
                strcpy(yyval.sVal, temp);

	}
break;
case 77:
#line 533 "parser.y"
	{

		sprintf(temp, "%s%s(%s);", yystack.l_mark[-5].sVal, yystack.l_mark[-4].sVal, yystack.l_mark[-2].sVal);
		strcpy(yyval.sVal, temp);

	}
break;
case 78:
#line 540 "parser.y"
	{

		sprintf(temp, "%s%s(%s);", yystack.l_mark[-5].sVal, yystack.l_mark[-4].sVal, yystack.l_mark[-2].sVal);
		strcpy(yyval.sVal, temp);

	}
break;
case 79:
#line 547 "parser.y"
	{

		sprintf(temp, "%s%s();", yystack.l_mark[-4].sVal, yystack.l_mark[-3].sVal);
		strcpy(yyval.sVal, temp);

	}
break;
case 80:
#line 554 "parser.y"
	{

		sprintf(temp, "%s%s();", yystack.l_mark[-4].sVal, yystack.l_mark[-3].sVal);
		strcpy(yyval.sVal, temp);

	}
break;
case 81:
#line 561 "parser.y"
	{

		sprintf(temp, "%s,%s", yystack.l_mark[-2].sVal, yystack.l_mark[0].sVal);
                strcpy(yyval.sVal, temp);

	}
break;
case 83:
#line 570 "parser.y"
	{
	 
		sprintf(temp, "%s%s", yystack.l_mark[-1].sVal, yystack.l_mark[0].sVal);
                strcpy(yyval.sVal, temp);

	}
break;
case 93:
#line 597 "parser.y"
	{

		sprintf(temp, "%s<stmt>%s</stmt>", yystack.l_mark[-1].sVal, yystack.l_mark[0].sVal);
                strcpy(yyval.sVal, temp);

	}
break;
case 94:
#line 604 "parser.y"
	{

		sprintf(temp, "<stmt>%s</stmt>", yystack.l_mark[0].sVal);
                strcpy(yyval.sVal, temp);
	
	}
break;
case 95:
#line 611 "parser.y"
	{

		sprintf(temp, "{}");
                strcpy(yyval.sVal, temp);

	}
break;
case 96:
#line 618 "parser.y"
	{

		sprintf(temp, "{%s}", yystack.l_mark[-1].sVal);
                strcpy(yyval.sVal, temp);

	}
break;
case 97:
#line 625 "parser.y"
	{

		sprintf(temp, "%s%s", yystack.l_mark[-1].sVal, yystack.l_mark[0].sVal);
                strcpy(yyval.sVal, temp);

	}
break;
case 99:
#line 634 "parser.y"
	{

		sprintf(temp, "<stmt>%s</stmt>", yystack.l_mark[0].sVal);
                strcpy(yyval.sVal, temp);

	}
break;
case 101:
#line 645 "parser.y"
	{

		sprintf(temp, "<expr>%s</expr>;", yystack.l_mark[-1].sVal);
                strcpy(yyval.sVal, temp);

	}
break;
case 102:
#line 652 "parser.y"
	{

		sprintf(temp, "%s(<expr>%s</expr>)%s", yystack.l_mark[-4].sVal, yystack.l_mark[-2].sVal, yystack.l_mark[0].sVal);
                strcpy(yyval.sVal, temp);

	}
break;
case 103:
#line 659 "parser.y"
	{

		sprintf(temp, "%s(<expr>%s</expr>)%s%s%s", yystack.l_mark[-6].sVal, yystack.l_mark[-4].sVal, yystack.l_mark[-2].sVal, yystack.l_mark[-1].sVal, yystack.l_mark[0].sVal);
                strcpy(yyval.sVal, temp);

	}
break;
case 104:
#line 666 "parser.y"
	{

		sprintf(temp, "%s(<expr>%s</expr>){%s}", yystack.l_mark[-6].sVal, yystack.l_mark[-4].sVal, yystack.l_mark[-1].sVal);
                strcpy(yyval.sVal, temp);

	}
break;
case 105:
#line 673 "parser.y"
	{

		sprintf(temp, "%s(<expr>%s</expr>){}", yystack.l_mark[-5].sVal, yystack.l_mark[-3].sVal);
                strcpy(yyval.sVal, temp);

	}
break;
case 106:
#line 680 "parser.y"
	{

		sprintf(temp, "%s%s", yystack.l_mark[-1].sVal, yystack.l_mark[0].sVal);
                strcpy(yyval.sVal, temp);

	}
break;
case 108:
#line 689 "parser.y"
	{

		sprintf(temp, "%s%d:%s", yystack.l_mark[-3].sVal, yystack.l_mark[-2].iVal, yystack.l_mark[0].sVal);
                strcpy(yyval.sVal, temp);

	}
break;
case 109:
#line 696 "parser.y"
	{

		sprintf(temp, "%s%d:", yystack.l_mark[-2].sVal, yystack.l_mark[-1].iVal);
                strcpy(yyval.sVal, temp);

	}
break;
case 110:
#line 703 "parser.y"
	{

		sprintf(temp, "%s:%s", yystack.l_mark[-2].sVal, yystack.l_mark[0].sVal);
                strcpy(yyval.sVal, temp);

	}
break;
case 111:
#line 710 "parser.y"
	{

		sprintf(temp, "%s:", yystack.l_mark[-1].sVal);
                strcpy(yyval.sVal, temp);

	}
break;
case 112:
#line 717 "parser.y"
	{

		sprintf(temp, "%s(<expr>%s</expr>)<stmt>%s</stmt>", yystack.l_mark[-4].sVal, yystack.l_mark[-2].sVal, yystack.l_mark[0].sVal);
                strcpy(yyval.sVal, temp);

	}
break;
case 113:
#line 724 "parser.y"
	{

		sprintf(temp, "%s<stmt>%s</stmt>%s(<expr>%s</expr>);", yystack.l_mark[-6].sVal, yystack.l_mark[-5].sVal, yystack.l_mark[-4].sVal, yystack.l_mark[-2].sVal);
                strcpy(yyval.sVal, temp);

	}
break;
case 114:
#line 731 "parser.y"
	{

		sprintf(temp, "%s(%s;%s;%s)<stmt>%s</stmt>", yystack.l_mark[-8].sVal, yystack.l_mark[-6].sVal, yystack.l_mark[-4].sVal, yystack.l_mark[-2].sVal, yystack.l_mark[0].sVal);
                strcpy(yyval.sVal, temp);

	}
break;
case 115:
#line 738 "parser.y"
	{

		sprintf(temp, "<expr>%s</expr>", yystack.l_mark[0].sVal);
                strcpy(yyval.sVal, temp);

	}
break;
case 116:
#line 745 "parser.y"
	{}
break;
case 117:
#line 747 "parser.y"
	{

		sprintf(temp, "%s;", yystack.l_mark[-1].sVal);
                strcpy(yyval.sVal, temp);

	}
break;
case 118:
#line 754 "parser.y"
	{

		sprintf(temp, "%s<expr>%s</expr>;", yystack.l_mark[-2].sVal, yystack.l_mark[-1].sVal);
                strcpy(yyval.sVal, temp);

	}
break;
case 119:
#line 761 "parser.y"
	{

		sprintf(temp, "%s;", yystack.l_mark[-1].sVal);
                strcpy(yyval.sVal, temp);

	}
break;
case 120:
#line 768 "parser.y"
	{

		sprintf(temp, "%s;", yystack.l_mark[-1].sVal);
                strcpy(yyval.sVal, temp);

	}
break;
case 121:
#line 777 "parser.y"
	{

		sprintf(temp, "%s%s(%s)%s", yystack.l_mark[-5].sVal, yystack.l_mark[-4].sVal, yystack.l_mark[-2].sVal, yystack.l_mark[0].sVal);
		strcpy(yyval.sVal, temp);

	}
break;
case 122:
#line 784 "parser.y"
	{
	
		sprintf(temp, "%s%s(%s)%s", yystack.l_mark[-5].sVal, yystack.l_mark[-4].sVal, yystack.l_mark[-2].sVal, yystack.l_mark[0].sVal);
		strcpy(yyval.sVal, temp);

	}
break;
case 123:
#line 791 "parser.y"
	{

		sprintf(temp, "%s%s()%s", yystack.l_mark[-4].sVal, yystack.l_mark[-3].sVal, yystack.l_mark[0].sVal);
		strcpy(yyval.sVal, temp);

	}
break;
case 124:
#line 798 "parser.y"
	{

		sprintf(temp, "%s%s()%s", yystack.l_mark[-4].sVal, yystack.l_mark[-3].sVal, yystack.l_mark[0].sVal);
		strcpy(yyval.sVal, temp);

	}
break;
#line 1783 "y.tab.c"
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
            if (yydebug)
            {
                yys = yyname[YYTRANSLATE(yychar)];
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == YYEOF) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
    {
        goto yyoverflow;
    }
    *++yystack.s_mark = (YYINT) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    YYERROR_CALL("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
