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

#line 2 "src/parser.y"

   #include <string.h>
   #include <stdio.h>
   #include <stdlib.h>

   #include <vector>
   #include <iostream>
   #include "symbol.h"

   #define DEBUG false

   extern "C" int yylex();
   char temp[1000000];

   extern int line_count;

   std::vector<symbol_entry> symbol_table;
   int cur_scope;
   int cur_arg;
   int cur_local;

#line 26 "src/parser.y"
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
#line 58 "src/y.tab.c"

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
#define UPLUS 282
#define UMINUS 283
#define ID 284
#define NUM_INT 285
#define NUM_FLOATING 286
#define CHARACTER 287
#define STRING 288
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
   13,   14,   15,   15,   16,   16,   17,   18,   18,   18,
   18,   18,   18,   19,   19,   20,   20,   21,   21,    4,
   22,   22,   22,   22,   23,   23,   24,   25,   25,   25,
   25,   25,   25,   25,   25,   25,   26,   26,   42,   27,
   43,   27,   28,   28,   29,   29,   30,   31,   31,   32,
   32,   33,   33,   34,   34,   34,   34,   34,   34,   34,
   34,   35,   35,   36,   37,   37,   38,   38,   39,   40,
   44,   41,   45,   41,   46,   41,   47,   41,
};
static const YYINT yylen[] = {                            2,
    1,    2,    2,    2,    0,    1,    1,    1,    3,    1,
    1,    1,    1,    1,    3,    1,    3,    3,    3,    3,
    3,    3,    3,    3,    3,    3,    3,    3,    3,    3,
    3,    3,    2,    3,    2,    2,    2,    2,    2,    2,
    2,    2,    2,    2,    3,    3,    1,    1,    1,    1,
    2,    4,    3,    4,    3,    3,    1,    1,    1,    1,
    1,    3,    1,    3,    1,    3,    2,    4,    3,    5,
    4,    5,    4,    3,    3,    1,    3,    1,    3,    4,
    6,    6,    5,    5,    3,    1,    2,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    2,    1,    0,    3,
    0,    4,    2,    1,    1,    1,    2,    5,    7,    7,
    6,    2,    1,    4,    3,    5,    4,    5,    4,    3,
    2,    5,    7,    9,    1,    0,    2,    3,    2,    2,
    0,    7,    0,    7,    0,    6,    0,    6,
};
static const YYINT yydefred[] = {                         5,
    0,    0,    0,   10,   11,   13,   12,    0,    2,    6,
    8,    0,    7,    3,    4,    0,    0,    0,    0,   14,
    0,   63,    0,    0,    0,    0,    0,    0,    0,    0,
    9,    0,   62,    0,    0,    0,    0,    0,   86,   80,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   58,   59,   60,   61,    0,    0,   47,   50,
    0,   15,    0,   64,    0,   66,   84,    0,   87,    0,
    0,   83,    0,    0,    0,    0,   69,    0,   38,    0,
   42,   35,   36,   33,    0,   39,   43,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   40,   44,    0,    0,
    0,    0,    0,   78,    0,    0,    0,  138,   82,    0,
   85,  136,   81,    0,   71,   73,   34,   55,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   20,   21,   22,    0,    0,    0,    0,    0,    0,
    0,   68,   74,    0,   75,    0,    0,    0,  134,  132,
   54,    0,   53,    0,   70,   72,    0,   79,  100,    0,
    0,    0,    0,    0,    0,    0,    0,  106,    0,    0,
  105,   96,    0,  104,   88,   89,   90,   91,   92,   93,
   94,   95,    0,   52,    0,    0,    0,  129,  130,    0,
  127,    0,    0,    0,  107,  102,  103,    0,    0,    0,
    0,    0,  128,    0,    0,    0,    0,    0,    0,    0,
    0,  122,    0,    0,    0,    0,    0,    0,    0,  111,
    0,  113,    0,  123,  109,    0,    0,    0,    0,  110,
  112,    0,    0,    0,    0,   98,    0,  124,    0,    0,
    0,   97,    0,    0,
};
static const YYINT yydgoto[] = {                          1,
    2,  178,   10,   11,   37,   19,   20,  180,   58,   91,
   59,  130,   60,   13,   21,   22,   23,   30,   66,  115,
  116,   14,   38,   39,  246,  247,  182,  183,  184,  185,
  186,  187,  231,  232,  188,  189,  209,  190,  191,  192,
   15,  157,  158,  124,  120,   73,   68,
};
static const YYINT yysindex[] = {                         0,
    0,  202, -282,    0,    0,    0,    0,  141,    0,    0,
    0, -237,    0,    0,    0,   11, -225,   -5,   -4,    0,
   17,    0,   10,   47,   24,   38,  126,  -42,  129,  -11,
    0, -225,    0, -197,   -9,   49, -178,   19,    0,    0,
   53,   95, -165, -163,   45, -134, -127,  129,  129,  129,
  129,    4,    0,    0,    0,    0,  727,    6,    0,    0,
  -39,    0,   79,    0,   92,    0,    0,   42,    0,  114,
  141,    0,   42,  116,   88,   97,    0,  100,    0,  100,
    0,    0,    0,    0,  500,    0,    0,  108,  129,  129,
  106,  129,  129,  129,  129,  129,  129,  129,  129,  129,
  129,  129,  129,  129,  129,  129,    0,    0,  129, -108,
 -106,  111,  727,    0,  -26,  -15,    0,    0,    0,   42,
    0,    0,    0,   42,    0,    0,    0,    0,  727,  103,
  526,  727,  129,  454,  454,  -28,  -28, 1025,  920,   54,
   54,    0,    0,    0,  454,  454, 1111, 1014,  727,  121,
  131,    0,    0,  129,    0,   -9,   94,   60,    0,    0,
    0,  129,    0,  537,    0,    0,  727,    0,    0,  196,
   86,  237,  211,  239,  261,  123,  262,    0,   25,  558,
    0,    0,   -2,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  727,    0,  129,   64,  129,    0,    0,  129,
    0,  569,  129,  -13,    0,    0,    0,  727,  251,  292,
  595,  606,    0,  658,  129,  129,   86,   42,  210,  277,
  695,    0,   69, -114,  129,  280,   42,  -18,  283,    0,
 -112,    0,  301,    0,    0,   58,   73,  304,   86,    0,
    0,   86,  307,  310,   86,    0,   86,    0,   86,   86,
   86,    0,   86,   86,
};
static const YYINT yyrindex[] = {                         0,
    0,  359,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   74,    0,    0,
    0,    0,   84,    0,   74,    0,    0,    0,    0,   22,
    0,    0,    0,    0,    0,  246,    0,    0,    0,    0,
  252,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  396,    0,    0,    0,    0,   96,  407,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  258,
    0,    0,    0,  265,    0,    0,    0,  433,    0,  468,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  151,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  -14,    0,    0,    0,   29,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  206,    0,
    0,    5,    0,  861,  888,  866,  982,  296,  -36,  818,
  853,    0,    0,    0,  955,  978,  990,   83,    9,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   -8,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  230,    0,  331,    0,    0,    0,    0,    0,
    0,    0,    0,   74,    0,    0,    0,  -17,    0,    0,
    0,    0,    0,    0,  331,    0,    0,    0,    0,    0,
    0,    0,  -33,    0,  350,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  -88,    0,
    0,    0,    0,    0,  -86,    0,  -73,    0,  -71,  -67,
  -55,    0,  -50,   39,
};
static const YYINT yygindex[] = {                         0,
    0,  403,    0,    0,   20,  389,  380, 1217,   99,    0,
    0,    0,    0,    0,    0,  384,    0,    0,  -49,    0,
    0,    0,  392,  349, -138,  -29,  -47,    0,  240,    0,
    0,    0,    0,  191,    0,    0, -131,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,
};
#define YYTABLESIZE 1442
static const YYINT yytable[] = {                        108,
   43,   16,   44,  110,   30,  111,  108,   30,  102,  108,
  230,  108,  240,  100,   98,  114,   99,  154,  101,  181,
  118,   12,   30,  125,  236,  122,  237,   17,  156,   76,
   50,  103,  196,  104,   27,   77,  121,   51,  115,   32,
   48,  125,   49,   88,  181,   45,   18,   29,   45,   46,
   24,  120,   46,  117,   31,   29,   30,  119,   25,   70,
   34,  101,   71,   45,   90,   67,  109,   46,  101,  114,
   35,  101,  159,  101,  116,   33,  160,   28,  222,   61,
   67,   32,   67,  220,   29,   28,   63,   36,   30,  108,
  102,  108,   50,  233,   89,  100,   40,   45,  153,   51,
  101,   46,   48,  248,   49,   69,  168,   67,  252,  155,
   76,   72,  252,   65,  252,  252,   77,   16,   50,   75,
  117,   76,  206,   32,   50,   51,   32,   65,   48,   45,
   49,   51,   16,   46,   48,   74,   49,   77,   71,   17,
   50,   32,   65,  161,   79,   81,  162,   51,  128,   78,
   48,  101,   49,   99,   17,   50,   80,  228,  229,  228,
  229,   50,   51,  118,  117,   48,   41,   49,   51,   28,
  223,   48,  119,   49,  123,   32,  150,  179,  151,  235,
  125,  201,  117,  121,  121,  115,  115,   51,   51,  126,
   89,   51,   51,   51,   51,   51,  133,   51,  120,  120,
  117,  117,  179,  152,  119,  119,   32,   32,  117,   51,
   51,   51,   51,  165,   65,  251,  114,  114,  169,  253,
  254,  116,  116,  166,  108,  108,  108,  108,  108,  108,
  108,  108,  108,  108,  108,  195,  108,  108,  108,  108,
  108,  108,   45,   51,   30,  112,   57,   92,   93,   57,
  108,  108,  108,  108,  108,    4,    5,    6,    7,    8,
  170,  171,  172,  173,  174,  175,  238,  176,  177,  198,
   56,   46,   47,   56,   51,   51,  197,   86,   87,  107,
  108,   52,   53,   54,   55,   56,  101,  101,  101,  101,
  101,  101,  101,  101,  101,  101,  101,  199,  101,  101,
  200,  203,  101,  101,    4,    5,    6,    7,  204,  215,
  118,  118,  101,  101,  101,  101,  101,    4,    5,    6,
    7,    8,  170,  171,  172,  173,  174,  175,  210,  176,
  177,  216,  224,   46,   47,  225,   29,  227,  234,   29,
  239,  242,  243,   52,   53,   54,   55,   56,  170,  171,
  172,  173,  174,  175,   29,  176,  177,  244,    1,   46,
   47,  245,   32,   32,  249,   46,   47,  250,  137,   52,
   53,   54,   55,   56,  135,   52,   53,   54,   55,   56,
  133,   46,   47,    4,    5,    6,    7,  131,   29,  126,
  126,   52,   53,   54,   55,   56,   46,   47,    4,    5,
    6,    7,   46,   47,    9,   26,   52,   53,   54,   55,
   56,   62,   52,   53,   54,   55,   56,   64,   42,  121,
   29,  241,  207,    0,   51,   51,   51,   51,   51,   51,
   51,   51,   48,   48,    0,    0,   48,   48,   48,   48,
   48,    0,   48,   49,   49,    0,    0,   49,   49,   49,
   49,   49,    0,   49,   48,   48,    0,   48,    3,    4,
    5,    6,    7,    8,    0,   49,   49,    0,   49,   37,
   37,    0,    0,   37,   37,   37,   37,   37,    0,   37,
    0,    0,    0,    0,    0,    0,    0,    0,   48,    0,
  102,   37,   37,    0,   37,  100,   98,    0,   99,   49,
  101,    0,    0,    0,   41,   41,    0,    0,   41,   41,
   41,   41,   41,    0,   41,    0,    0,    0,    0,   48,
   48,    0,    0,    0,    0,   37,   41,   41,    0,   41,
   49,   49,    0,    0,    0,    0,  102,  105,    0,    0,
  127,  100,   98,    0,   99,    0,  101,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   37,   37,    0,  103,
   41,  104,  102,  105,    0,    0,    0,  100,   98,    0,
   99,    0,  101,  102,  105,   29,   29,    0,  100,   98,
    0,   99,    0,  101,    0,  103,    0,  104,    0,    0,
    0,   41,   41,    0,  102,  105,  103,    0,  104,  100,
   98,    0,   99,    0,  101,  102,  105,    0,    0,    0,
  100,   98,    0,   99,    0,  101,  205,  103,  163,  104,
    0,    0,    0,  106,    0,    0,    0,  213,  103,  194,
  104,  102,  105,    0,    0,  217,  100,   98,    0,   99,
    0,  101,  102,  105,    0,    0,  218,  100,   98,  106,
   99,    0,  101,    0,  103,    0,  104,    0,    0,    0,
  106,    0,    0,    0,    0,  103,    0,  104,    0,    0,
    0,   48,   48,   48,   48,   48,   48,    0,    0,    0,
    0,  106,   49,   49,   49,   49,   49,   49,    0,    0,
    0,    0,  106,    0,  102,  105,    0,    0,  219,  100,
   98,    0,   99,    0,  101,    0,    0,    0,   37,   37,
   37,   37,   37,   37,    0,    0,    0,  103,  106,  104,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  106,
    0,  102,  105,    0,    0,  226,  100,   98,    0,   99,
    0,  101,    0,   41,   41,   41,   41,   41,   41,    0,
    0,    0,    0,    0,  103,    0,  104,    0,    0,    0,
    0,    0,    0,  102,  105,    0,    0,    0,  100,   98,
    0,   99,    0,  101,    0,   92,   93,   94,   95,   96,
   97,  106,    0,    0,    0,    0,  103,    0,  104,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   92,   93,   94,   95,   96,   97,    0,    0,    0,
    0,    0,   92,   93,   94,   95,   96,   97,  106,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   92,   93,   94,   95,   96,   97,    0,
    0,    0,    0,    0,   92,   93,   94,   95,   96,   97,
  106,    0,    0,    0,    0,   18,    0,    0,   18,    0,
   18,   18,   18,    0,    0,    0,    0,    0,    0,    0,
   92,   93,   94,   95,   96,   97,   18,   18,    0,   18,
    0,   92,   93,   94,   95,   96,   97,    0,    0,    0,
   19,    0,    0,   19,    0,   19,   19,   19,   24,    0,
    0,   24,    0,   27,   24,    0,   27,    0,    0,   27,
   18,   19,   19,    0,   19,    0,    0,    0,    0,   24,
   24,    0,   24,    0,   27,   26,    0,    0,   26,    0,
    0,   26,    0,   92,   93,   94,   95,   96,   97,    0,
    0,   18,   18,    0,    0,   19,   26,   26,    0,   26,
    0,    0,    0,   24,    0,    0,  102,  105,   27,    0,
    0,  100,   98,    0,   99,    0,  101,    0,    0,    0,
   92,   93,   94,   95,   96,   97,   19,   19,    0,  103,
   26,  104,    0,    0,   24,   24,    0,    0,    0,   27,
   27,    0,   23,    0,    0,   23,    0,    0,   23,    0,
    0,    0,   92,   93,   94,   95,   96,   97,    0,    0,
    0,   26,   26,   23,   23,   25,   23,    0,   25,   28,
    0,   25,   28,    0,    0,   28,    0,   31,    0,    0,
   31,    0,    0,   31,    0,    0,   25,   25,    0,   25,
   28,    0,    0,  106,    0,    0,    0,   23,   31,    0,
  102,  105,    0,    0,    0,  100,   98,    0,   99,    0,
  101,  102,  105,    0,    0,    0,  100,   98,    0,   99,
   25,  101,    0,  103,   28,  104,    0,    0,   23,   23,
    0,    0,   31,    0,  103,    0,  104,    0,    0,    0,
    0,    0,    0,   18,   18,   18,   18,   18,   18,    0,
    0,   25,   25,    0,    0,   28,   28,    0,    0,    0,
    0,    0,    0,   31,   31,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   19,   19,
   19,   19,   19,   19,    0,    0,   24,   24,   24,   24,
   24,   24,    0,   27,   27,   27,   27,  102,  106,    0,
    0,    0,  100,   98,    0,   99,    0,  101,    0,    0,
    0,    0,    0,   26,   26,   26,   26,   26,   26,    0,
  103,    0,  104,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   92,   93,   94,   95,   96,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   23,   23,   23,   23,   23,   23,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   57,    0,    0,    0,    0,
    0,    0,    0,   25,   25,   25,   25,   25,   25,   28,
   28,   28,   28,    0,   82,   83,   84,   85,    0,   31,
   31,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  113,    0,    0,    0,    0,    0,    0,    0,   92,
   93,   94,   95,    0,    0,    0,    0,    0,    0,    0,
   92,   93,   94,   95,  129,  131,  132,    0,  134,  135,
  136,  137,  138,  139,  140,  141,  142,  143,  144,  145,
  146,  147,  148,    0,    0,  149,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  164,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  167,    0,    0,    0,    0,    0,    0,    0,  193,    0,
    0,    0,    0,    0,    0,    0,   92,   93,   94,   95,
    0,    0,  202,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  208,    0,  211,    0,    0,  212,    0,    0,  214,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  208,  221,    0,    0,    0,    0,    0,    0,    0,
    0,  208,
};
static const YYINT yycheck[] = {                         33,
   43,  284,   45,   43,   41,   45,   40,   44,   37,   43,
  125,   45,  125,   42,   43,   65,   45,   44,   47,  158,
   68,    2,   59,   41,   43,   73,   45,    8,   44,   44,
   33,   60,  171,   62,   40,   44,  125,   40,  125,   44,
   43,   59,   45,   40,  183,   41,  284,   61,   44,   41,
   40,  125,   44,  125,   59,   61,   93,  125,  284,   41,
   44,   33,   44,   59,   61,   44,   61,   59,   40,  125,
   61,   43,  120,   45,  125,   59,  124,   91,  217,   91,
   59,   44,   61,  215,   61,   91,  284,   41,  125,  123,
   37,  125,   33,  225,   91,   42,   59,   93,  125,   40,
   47,   93,   43,  242,   45,  284,  156,   59,  247,  125,
  125,   59,  251,  123,  253,  254,  125,   44,   33,  285,
  123,  285,  125,   41,   33,   40,   44,   44,   43,  125,
   45,   40,   59,  125,   43,   41,   45,   93,   44,   44,
   33,   59,   59,   41,   46,   47,   44,   40,   41,  284,
   43,  123,   45,  125,   59,   33,  284,  272,  273,  272,
  273,   33,   40,  125,  123,   43,   41,   45,   40,   91,
  218,   43,   59,   45,   59,   93,  285,  158,  285,  227,
   93,   59,  123,  272,  273,  272,  273,   37,   38,   93,
   91,   41,   42,   43,   44,   45,   91,   47,  272,  273,
  272,  273,  183,   93,  272,  273,  124,  125,  123,   59,
   60,   61,   62,   93,  123,  245,  272,  273,  125,  249,
  250,  272,  273,   93,  258,  259,  260,  261,  262,  263,
  264,  265,  266,  267,  268,   40,  270,  271,  272,  273,
  274,  275,  285,   93,  281,  285,   41,  276,  277,   44,
  284,  285,  286,  287,  288,  258,  259,  260,  261,  262,
  263,  264,  265,  266,  267,  268,  285,  270,  271,   59,
   41,  274,  275,   44,  124,  125,   40,  274,  275,  274,
  275,  284,  285,  286,  287,  288,  258,  259,  260,  261,
  262,  263,  264,  265,  266,  267,  268,   59,  270,  271,
   40,   40,  274,  275,  258,  259,  260,  261,  284,   59,
  272,  273,  284,  285,  286,  287,  288,  258,  259,  260,
  261,  262,  263,  264,  265,  266,  267,  268,  265,  270,
  271,   40,  123,  274,  275,   59,   41,  269,   59,   44,
   58,   41,  285,  284,  285,  286,  287,  288,  263,  264,
  265,  266,  267,  268,   59,  270,  271,  285,    0,  274,
  275,   58,  280,  281,   58,  274,  275,   58,  123,  284,
  285,  286,  287,  288,  123,  284,  285,  286,  287,  288,
  123,  274,  275,  258,  259,  260,  261,  123,   93,   59,
   41,  284,  285,  286,  287,  288,  274,  275,  258,  259,
  260,  261,  274,  275,    2,   17,  284,  285,  286,  287,
  288,   32,  284,  285,  286,  287,  288,   34,   27,   71,
  125,  231,  183,   -1,  274,  275,  276,  277,  278,  279,
  280,  281,   37,   38,   -1,   -1,   41,   42,   43,   44,
   45,   -1,   47,   37,   38,   -1,   -1,   41,   42,   43,
   44,   45,   -1,   47,   59,   60,   -1,   62,  257,  258,
  259,  260,  261,  262,   -1,   59,   60,   -1,   62,   37,
   38,   -1,   -1,   41,   42,   43,   44,   45,   -1,   47,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   93,   -1,
   37,   59,   60,   -1,   62,   42,   43,   -1,   45,   93,
   47,   -1,   -1,   -1,   37,   38,   -1,   -1,   41,   42,
   43,   44,   45,   -1,   47,   -1,   -1,   -1,   -1,  124,
  125,   -1,   -1,   -1,   -1,   93,   59,   60,   -1,   62,
  124,  125,   -1,   -1,   -1,   -1,   37,   38,   -1,   -1,
   41,   42,   43,   -1,   45,   -1,   47,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  124,  125,   -1,   60,
   93,   62,   37,   38,   -1,   -1,   -1,   42,   43,   -1,
   45,   -1,   47,   37,   38,  280,  281,   -1,   42,   43,
   -1,   45,   -1,   47,   -1,   60,   -1,   62,   -1,   -1,
   -1,  124,  125,   -1,   37,   38,   60,   -1,   62,   42,
   43,   -1,   45,   -1,   47,   37,   38,   -1,   -1,   -1,
   42,   43,   -1,   45,   -1,   47,   59,   60,   93,   62,
   -1,   -1,   -1,  124,   -1,   -1,   -1,   59,   60,   93,
   62,   37,   38,   -1,   -1,   41,   42,   43,   -1,   45,
   -1,   47,   37,   38,   -1,   -1,   41,   42,   43,  124,
   45,   -1,   47,   -1,   60,   -1,   62,   -1,   -1,   -1,
  124,   -1,   -1,   -1,   -1,   60,   -1,   62,   -1,   -1,
   -1,  276,  277,  278,  279,  280,  281,   -1,   -1,   -1,
   -1,  124,  276,  277,  278,  279,  280,  281,   -1,   -1,
   -1,   -1,  124,   -1,   37,   38,   -1,   -1,   41,   42,
   43,   -1,   45,   -1,   47,   -1,   -1,   -1,  276,  277,
  278,  279,  280,  281,   -1,   -1,   -1,   60,  124,   62,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  124,
   -1,   37,   38,   -1,   -1,   41,   42,   43,   -1,   45,
   -1,   47,   -1,  276,  277,  278,  279,  280,  281,   -1,
   -1,   -1,   -1,   -1,   60,   -1,   62,   -1,   -1,   -1,
   -1,   -1,   -1,   37,   38,   -1,   -1,   -1,   42,   43,
   -1,   45,   -1,   47,   -1,  276,  277,  278,  279,  280,
  281,  124,   -1,   -1,   -1,   -1,   60,   -1,   62,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  276,  277,  278,  279,  280,  281,   -1,   -1,   -1,
   -1,   -1,  276,  277,  278,  279,  280,  281,  124,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  276,  277,  278,  279,  280,  281,   -1,
   -1,   -1,   -1,   -1,  276,  277,  278,  279,  280,  281,
  124,   -1,   -1,   -1,   -1,   38,   -1,   -1,   41,   -1,
   43,   44,   45,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  276,  277,  278,  279,  280,  281,   59,   60,   -1,   62,
   -1,  276,  277,  278,  279,  280,  281,   -1,   -1,   -1,
   38,   -1,   -1,   41,   -1,   43,   44,   45,   38,   -1,
   -1,   41,   -1,   38,   44,   -1,   41,   -1,   -1,   44,
   93,   59,   60,   -1,   62,   -1,   -1,   -1,   -1,   59,
   60,   -1,   62,   -1,   59,   38,   -1,   -1,   41,   -1,
   -1,   44,   -1,  276,  277,  278,  279,  280,  281,   -1,
   -1,  124,  125,   -1,   -1,   93,   59,   60,   -1,   62,
   -1,   -1,   -1,   93,   -1,   -1,   37,   38,   93,   -1,
   -1,   42,   43,   -1,   45,   -1,   47,   -1,   -1,   -1,
  276,  277,  278,  279,  280,  281,  124,  125,   -1,   60,
   93,   62,   -1,   -1,  124,  125,   -1,   -1,   -1,  124,
  125,   -1,   38,   -1,   -1,   41,   -1,   -1,   44,   -1,
   -1,   -1,  276,  277,  278,  279,  280,  281,   -1,   -1,
   -1,  124,  125,   59,   60,   38,   62,   -1,   41,   38,
   -1,   44,   41,   -1,   -1,   44,   -1,   38,   -1,   -1,
   41,   -1,   -1,   44,   -1,   -1,   59,   60,   -1,   62,
   59,   -1,   -1,  124,   -1,   -1,   -1,   93,   59,   -1,
   37,   38,   -1,   -1,   -1,   42,   43,   -1,   45,   -1,
   47,   37,   38,   -1,   -1,   -1,   42,   43,   -1,   45,
   93,   47,   -1,   60,   93,   62,   -1,   -1,  124,  125,
   -1,   -1,   93,   -1,   60,   -1,   62,   -1,   -1,   -1,
   -1,   -1,   -1,  276,  277,  278,  279,  280,  281,   -1,
   -1,  124,  125,   -1,   -1,  124,  125,   -1,   -1,   -1,
   -1,   -1,   -1,  124,  125,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  276,  277,
  278,  279,  280,  281,   -1,   -1,  276,  277,  278,  279,
  280,  281,   -1,  278,  279,  280,  281,   37,  124,   -1,
   -1,   -1,   42,   43,   -1,   45,   -1,   47,   -1,   -1,
   -1,   -1,   -1,  276,  277,  278,  279,  280,  281,   -1,
   60,   -1,   62,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  276,  277,  278,  279,  280,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  276,  277,  278,  279,  280,  281,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   29,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  276,  277,  278,  279,  280,  281,  278,
  279,  280,  281,   -1,   48,   49,   50,   51,   -1,  280,
  281,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   65,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  276,
  277,  278,  279,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  276,  277,  278,  279,   88,   89,   90,   -1,   92,   93,
   94,   95,   96,   97,   98,   99,  100,  101,  102,  103,
  104,  105,  106,   -1,   -1,  109,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  133,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  154,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  162,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  276,  277,  278,  279,
   -1,   -1,  176,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  195,   -1,  197,   -1,   -1,  200,   -1,   -1,  203,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  215,  216,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  225,
};
#define YYFINAL 1
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 290
#define YYUNDFTOKEN 340
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
"LOG_AND","LOG_OR","UPLUS","UMINUS","ID","NUM_INT","NUM_FLOATING","CHARACTER",
"STRING","SUFFIX_INCRE","SUFFIX_DECRE",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"illegal-symbol",
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
"arr_decl_list : arr_decl_list '[' '+' NUM_INT ']'",
"arr_decl_list : '[' '+' NUM_INT ']'",
"arr_decl_list : arr_decl_list '[' '-' NUM_INT ']'",
"arr_decl_list : '[' '-' NUM_INT ']'",
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
"$$1 :",
"compound_statement : '{' $$1 '}'",
"$$2 :",
"compound_statement : '{' $$2 statement_var_decls '}'",
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
"switch_clause : CASE '+' NUM_INT ':' statements",
"switch_clause : CASE '+' NUM_INT ':'",
"switch_clause : CASE '-' NUM_INT ':' statements",
"switch_clause : CASE '-' NUM_INT ':'",
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
"$$3 :",
"func_def : var_type ID '(' param_list ')' $$3 compound_statement",
"$$4 :",
"func_def : VOID ID '(' param_list ')' $$4 compound_statement",
"$$5 :",
"func_def : var_type ID '(' ')' $$5 compound_statement",
"$$6 :",
"func_def : VOID ID '(' ')' $$6 compound_statement",

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
#line 1218 "src/parser.y"


int main(void)
{
	line_count = 1;
	cur_scope = 0;
	cur_arg = 0;
	cur_local = 1;
	symbol_init();

	yyparse();

	return 0;
}

int yyerror(char *s)
{
	fprintf(stderr, "Error at line %d:\n%s\n", line_count, s);
	return 1;
}
#line 774 "src/y.tab.c"

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
#line 84 "src/parser.y"
	{

		if (DEBUG)
			std::cout << "->program_plum" << std::endl;

	}
break;
case 2:
#line 91 "src/parser.y"
	{

		sprintf(temp, "%s%s", yystack.l_mark[-1].sVal, yystack.l_mark[0].sVal);
                strcpy(yyval.sVal, temp);

	}
break;
case 3:
#line 98 "src/parser.y"
	{

		sprintf(temp, "%s<func_decl>%s</func_decl>", yystack.l_mark[-1].sVal, yystack.l_mark[0].sVal);
                strcpy(yyval.sVal, temp);

		if (DEBUG)
                        std::cout << "->program" << std::endl;

	}
break;
case 4:
#line 108 "src/parser.y"
	{

		sprintf(temp, "%s<func_def>%s</func_def>", yystack.l_mark[-1].sVal, yystack.l_mark[0].sVal);
                strcpy(yyval.sVal, temp);

		if (DEBUG)
                        std::cout << "->program" << std::endl;

	}
break;
case 5:
#line 118 "src/parser.y"
	{}
break;
case 6:
#line 121 "src/parser.y"
	{

		sprintf(temp, "<scalar_decl>%s</scalar_decl>", yystack.l_mark[0].sVal);
		strcpy(yyval.sVal, temp);

	}
break;
case 7:
#line 128 "src/parser.y"
	{

		sprintf(temp, "<array_decl>%s</array_decl>", yystack.l_mark[0].sVal);
		strcpy(yyval.sVal, temp);

	}
break;
case 8:
#line 135 "src/parser.y"
	{

		sprintf(temp, "<const_decl>%s</const_decl>", yystack.l_mark[0].sVal);
		strcpy(yyval.sVal, temp);

	}
break;
case 9:
#line 144 "src/parser.y"
	{

		sprintf(temp, "%s%s;", yystack.l_mark[-2].sVal, yystack.l_mark[-1].sVal);
		strcpy(yyval.sVal, temp);

	}
break;
case 15:
#line 155 "src/parser.y"
	{

		strcpy(yyval.sVal, yystack.l_mark[-2].sVal);
		strcat(yyval.sVal, yystack.l_mark[-1].sVal);
		strcat(yyval.sVal, yystack.l_mark[0].sVal);

	}
break;
case 16:
#line 163 "src/parser.y"
	{

		/* install local variable*/
		int i = symbol_add(std::string(yystack.l_mark[0].sVal), SYMBOL_TYPE::VAR);
		int offset = -4 * (symbol_table[i].args_num + cur_local + 1);
		symbol_table[i].offset = offset;
		
		/* save to register*/
		std::string reg = "s" + std::to_string(cur_local);
		cur_local += 1;
		std::cout << "addi " + reg + ", zero, 0" << std::endl;	/* initialize to default value 0*/

		/* modify pre-saved value on stack*/
		std::cout << "sw " + reg + ", " + std::to_string(offset) + "(s0)" << std::endl;

	}
break;
case 17:
#line 180 "src/parser.y"
	{
		
		/* install local variable*/
		int i = symbol_add(std::string(yystack.l_mark[-2].sVal), SYMBOL_TYPE::VAR);
		int offset = -4 * (symbol_table[i].args_num + cur_local + 1);
                symbol_table[i].offset = offset;

                /* save to register*/
                std::string reg = "s" + std::to_string(cur_local);
                cur_local += 1;
                std::cout << "addi " + reg + ", t0, 0" << std::endl;  /* use expr value, stored on t0*/

                /* modify pre-saved value on stack*/
                std::cout << "sw " + reg + ", " + std::to_string(offset) + "(s0)" << std::endl;

	}
break;
case 18:
#line 199 "src/parser.y"
	{

		sprintf(temp, "<expr>%s</expr>+<expr>%s</expr>", yystack.l_mark[-2].sVal, yystack.l_mark[0].sVal);
		strcpy(yyval.sVal, temp);

	}
break;
case 19:
#line 206 "src/parser.y"
	{

                sprintf(temp, "<expr>%s</expr>-<expr>%s</expr>", yystack.l_mark[-2].sVal, yystack.l_mark[0].sVal);
		strcpy(yyval.sVal, temp);

	}
break;
case 20:
#line 213 "src/parser.y"
	{

		sprintf(temp, "<expr>%s</expr>*<expr>%s</expr>", yystack.l_mark[-2].sVal, yystack.l_mark[0].sVal);
		strcpy(yyval.sVal, temp);

	}
break;
case 21:
#line 220 "src/parser.y"
	{

                sprintf(temp, "<expr>%s</expr>/<expr>%s</expr>", yystack.l_mark[-2].sVal, yystack.l_mark[0].sVal);
		strcpy(yyval.sVal, temp);

        }
break;
case 22:
#line 227 "src/parser.y"
	{

                sprintf(temp, "<expr>%s</expr>%%<expr>%s</expr>", yystack.l_mark[-2].sVal, yystack.l_mark[0].sVal);
		strcpy(yyval.sVal, temp);

        }
break;
case 23:
#line 234 "src/parser.y"
	{

                sprintf(temp, "<expr>%s</expr><<expr>%s</expr>", yystack.l_mark[-2].sVal, yystack.l_mark[0].sVal);
		strcpy(yyval.sVal, temp);

        }
break;
case 24:
#line 241 "src/parser.y"
	{

		sprintf(temp, "<expr>%s</expr><=<expr>%s</expr>", yystack.l_mark[-2].sVal, yystack.l_mark[0].sVal);
		strcpy(yyval.sVal, temp);

        }
break;
case 25:
#line 248 "src/parser.y"
	{

                sprintf(temp, "<expr>%s</expr>><expr>%s</expr>", yystack.l_mark[-2].sVal, yystack.l_mark[0].sVal);
		strcpy(yyval.sVal, temp);

        }
break;
case 26:
#line 255 "src/parser.y"
	{

                sprintf(temp, "<expr>%s</expr>>=<expr>%s</expr>", yystack.l_mark[-2].sVal, yystack.l_mark[0].sVal);
		strcpy(yyval.sVal, temp);

        }
break;
case 27:
#line 262 "src/parser.y"
	{

                sprintf(temp, "<expr>%s</expr>==<expr>%s</expr>", yystack.l_mark[-2].sVal, yystack.l_mark[0].sVal);
		strcpy(yyval.sVal, temp);

        }
break;
case 28:
#line 269 "src/parser.y"
	{

                sprintf(temp, "<expr>%s</expr>!=<expr>%s</expr>", yystack.l_mark[-2].sVal, yystack.l_mark[0].sVal);
		strcpy(yyval.sVal, temp);

        }
break;
case 29:
#line 276 "src/parser.y"
	{

                sprintf(temp, "<expr>%s</expr>&&<expr>%s</expr>", yystack.l_mark[-2].sVal, yystack.l_mark[0].sVal);
		strcpy(yyval.sVal, temp);
        }
break;
case 30:
#line 282 "src/parser.y"
	{

                sprintf(temp, "<expr>%s</expr>||<expr>%s</expr>", yystack.l_mark[-2].sVal, yystack.l_mark[0].sVal);
		strcpy(yyval.sVal, temp);		

        }
break;
case 31:
#line 289 "src/parser.y"
	{

                sprintf(temp, "<expr>%s</expr>&<expr>%s</expr>", yystack.l_mark[-2].sVal, yystack.l_mark[0].sVal);
                strcpy(yyval.sVal, temp);

        }
break;
case 32:
#line 296 "src/parser.y"
	{

                sprintf(temp, "<expr>%s</expr>|<expr>%s</expr>", yystack.l_mark[-2].sVal, yystack.l_mark[0].sVal);
		strcpy(yyval.sVal, temp);

        }
break;
case 33:
#line 303 "src/parser.y"
	{

		sprintf(temp, "!<expr>%s</expr>", yystack.l_mark[0].sVal);
                strcpy(yyval.sVal, temp);

        }
break;
case 34:
#line 310 "src/parser.y"
	{
                
                sprintf(temp, "(<expr>%s</expr>)", yystack.l_mark[-1].sVal);
		strcpy(yyval.sVal, temp);

	}
break;
case 35:
#line 317 "src/parser.y"
	{

                sprintf(temp, "+<expr>%s</expr>", yystack.l_mark[0].sVal);
		strcpy(yyval.sVal, temp);

        }
break;
case 36:
#line 324 "src/parser.y"
	{

                sprintf(temp, "-<expr>%s</expr>", yystack.l_mark[0].sVal);
		strcpy(yyval.sVal, temp);

        }
break;
case 37:
#line 331 "src/parser.y"
	{

		strcpy(yyval.sVal, yystack.l_mark[-1].sVal);
		strcat(yyval.sVal, yystack.l_mark[0].sVal);

	}
break;
case 38:
#line 338 "src/parser.y"
	{

                strcpy(yyval.sVal, yystack.l_mark[-1].sVal);
                strcat(yyval.sVal, yystack.l_mark[0].sVal);

	}
break;
case 39:
#line 345 "src/parser.y"
	{

                strcpy(yyval.sVal, yystack.l_mark[-1].sVal);
                strcat(yyval.sVal, yystack.l_mark[0].sVal);

	}
break;
case 40:
#line 352 "src/parser.y"
	{

                strcpy(yyval.sVal, yystack.l_mark[-1].sVal);
                strcat(yyval.sVal, yystack.l_mark[0].sVal);

	}
break;
case 41:
#line 359 "src/parser.y"
	{

                strcpy(yyval.sVal, yystack.l_mark[-1].sVal);
                strcat(yyval.sVal, yystack.l_mark[0].sVal);

        }
break;
case 42:
#line 366 "src/parser.y"
	{

                strcpy(yyval.sVal, yystack.l_mark[-1].sVal);
                strcat(yyval.sVal, yystack.l_mark[0].sVal);

        }
break;
case 43:
#line 373 "src/parser.y"
	{

                strcpy(yyval.sVal, yystack.l_mark[-1].sVal);
                strcat(yyval.sVal, yystack.l_mark[0].sVal);

        }
break;
case 44:
#line 380 "src/parser.y"
	{

                strcpy(yyval.sVal, yystack.l_mark[-1].sVal);
                strcat(yyval.sVal, yystack.l_mark[0].sVal);

        }
break;
case 45:
#line 387 "src/parser.y"
	{

                sprintf(temp, "%s=<expr>%s</expr>", yystack.l_mark[-2].sVal, yystack.l_mark[0].sVal);
		strcpy(yyval.sVal, temp);

	}
break;
case 46:
#line 394 "src/parser.y"
	{

                sprintf(temp, "%s=<expr>%s</expr>", yystack.l_mark[-2].sVal, yystack.l_mark[0].sVal);
		strcpy(yyval.sVal, temp);

	}
break;
case 50:
#line 407 "src/parser.y"
	{

		std::cout << "li t0, " + std::string(yystack.l_mark[0].sVal) << std::endl;

	}
break;
case 51:
#line 413 "src/parser.y"
	{

                strcpy(yyval.sVal, yystack.l_mark[-1].sVal);
                strcat(yyval.sVal, yystack.l_mark[0].sVal);

	}
break;
case 52:
#line 420 "src/parser.y"
	{

		sprintf(temp, "%s[<expr>%s</expr>]", yystack.l_mark[-3].sVal, yystack.l_mark[-1].sVal);
		strcpy(yyval.sVal, temp);

	}
break;
case 53:
#line 427 "src/parser.y"
	{

		sprintf(temp, "[<expr>%s</expr>]", yystack.l_mark[-1].sVal);
		strcpy(yyval.sVal, temp);

	}
break;
case 54:
#line 434 "src/parser.y"
	{

		int i = symbol_find(std::string(yystack.l_mark[-3].sVal), SYMBOL_TYPE::FUNC);
		/* ignore function undeclaration*/


		/* Do C-A-B if function is special*/
		/* in A just save 'ra' since there won't be recursive call within these functions*/
		/* don't need to do D since they return nothing*/
		if (std::string(yystack.l_mark[-3].sVal) == "digitalWrite" || std::string(yystack.l_mark[-3].sVal) == "delay") {

			/* C has been done half here (arguments are passed)*/
			std::cout << "addi sp, sp, -4" << std::endl;
			std::cout << "sw ra, 0(sp)" << std::endl;

			std::cout << "jal ra, " + std::string(yystack.l_mark[-3].sVal) << std::endl;

			std::cout << "lw ra, 0(sp)" << std::endl;
			std::cout << "addi sp, sp, 4" << std::endl;

		}
		/* Do C otherwise, A-B will be done in 'func_def', D will be done in expr*/
		else {

			/* C has been done half here (arguments are passed)*/
                        std::cout << "jal ra, " + std::string(yystack.l_mark[-3].sVal) << std::endl;
		
		}

		/* reset argument index counter, next invocation will starts from 0*/
		cur_arg = 0;

                /*strcpy($$, $1);*/
                /*strcat($$, $2);*/
                /*strcat($$, $3);*/
		/*strcat($$, $4);*/

	}
break;
case 55:
#line 473 "src/parser.y"
	{

		int i = symbol_find(std::string(yystack.l_mark[-2].sVal), SYMBOL_TYPE::FUNC);
                /* ignore function undeclaration*/


                /* Do C otherwise, A-B will be done in 'func_def', D will be done in expr*/
                std::cout << "jal ra, " + std::string(yystack.l_mark[-2].sVal) << std::endl;
                
		/*sprintf(temp, "%s()", $1);*/
		/*strcpy($$, temp);*/

	}
break;
case 56:
#line 487 "src/parser.y"
	{

		/* C: get value from t0, since all expr will be evaluated to t0*/
                /* store to corresponding argument register*/
		std::cout << "addi a" + std::to_string(cur_arg) + ", t0, 0" << std::endl;
                cur_arg += 1;

	}
break;
case 57:
#line 496 "src/parser.y"
	{

		std::cout << "addi a" + std::to_string(cur_arg) + ", t0, 0" << std::endl;
		cur_arg += 1;

	}
break;
case 58:
#line 503 "src/parser.y"
	{

		sprintf(temp, "%d", yystack.l_mark[0].iVal);
		strcpy(yyval.sVal, temp);

	}
break;
case 59:
#line 510 "src/parser.y"
	{

		sprintf(temp, "%f", yystack.l_mark[0].dVal);
		strcpy(yyval.sVal, temp);

	}
break;
case 60:
#line 517 "src/parser.y"
	{

		if (strcmp(yystack.l_mark[0].sVal, "'\\\\'") == 0) {
		
			sprintf(temp, "%s", "\\");
			strcpy(yyval.sVal, temp);
		}

		else if (strcmp(yystack.l_mark[0].sVal, "'\\''") == 0) {

			sprintf(temp, "%s", "'");
			strcpy(yyval.sVal, temp);
		}

		else if (strcmp(yystack.l_mark[0].sVal, "'\\n'") == 0)
			strcpy(yyval.sVal, "\n");

		else if (strcmp(yystack.l_mark[0].sVal, "'\\t'") == 0)
			strcpy(yyval.sVal, "\t");

	}
break;
case 62:
#line 543 "src/parser.y"
	{

		sprintf(temp, "%s%s;", yystack.l_mark[-2].sVal, yystack.l_mark[-1].sVal);
		strcpy(yyval.sVal, temp);	

	}
break;
case 64:
#line 552 "src/parser.y"
	{

		sprintf(temp, "%s,%s", yystack.l_mark[-2].sVal, yystack.l_mark[0].sVal);
		strcpy(yyval.sVal, temp);

	}
break;
case 66:
#line 561 "src/parser.y"
	{

		sprintf(temp, "%s=%s", yystack.l_mark[-2].sVal, yystack.l_mark[0].sVal);
                strcpy(yyval.sVal, temp);

	}
break;
case 67:
#line 568 "src/parser.y"
	{

		strcpy(yyval.sVal, yystack.l_mark[-1].sVal);
		strcat(yyval.sVal, yystack.l_mark[0].sVal);

	}
break;
case 68:
#line 575 "src/parser.y"
	{

		sprintf(temp, "%s[%d]", yystack.l_mark[-3].sVal, yystack.l_mark[-1].iVal);
		strcpy(yyval.sVal, temp);

	}
break;
case 69:
#line 582 "src/parser.y"
	{

                sprintf(temp, "[%d]", yystack.l_mark[-1].iVal);
                strcpy(yyval.sVal, temp);

	}
break;
case 70:
#line 589 "src/parser.y"
	{

                sprintf(temp, "%s[%d]", yystack.l_mark[-4].sVal, yystack.l_mark[-1].iVal);
                strcpy(yyval.sVal, temp);

        }
break;
case 71:
#line 596 "src/parser.y"
	{

                sprintf(temp, "[%d]", yystack.l_mark[-1].iVal);
                strcpy(yyval.sVal, temp);

        }
break;
case 72:
#line 603 "src/parser.y"
	{

                sprintf(temp, "%s[-%d]", yystack.l_mark[-4].sVal, yystack.l_mark[-1].iVal);
                strcpy(yyval.sVal, temp);

        }
break;
case 73:
#line 610 "src/parser.y"
	{

                sprintf(temp, "[-%d]", yystack.l_mark[-1].iVal);
                strcpy(yyval.sVal, temp);

        }
break;
case 74:
#line 617 "src/parser.y"
	{

                sprintf(temp, "{%s}", yystack.l_mark[-1].sVal);
                strcpy(yyval.sVal, temp);

	}
break;
case 75:
#line 624 "src/parser.y"
	{

                sprintf(temp, "{%s}", yystack.l_mark[-1].sVal);
                strcpy(yyval.sVal, temp);

	}
break;
case 76:
#line 631 "src/parser.y"
	{

		sprintf(temp, "<expr>%s</expr>", yystack.l_mark[0].sVal);
		strcpy(yyval.sVal, temp);

	}
break;
case 77:
#line 638 "src/parser.y"
	{

		sprintf(temp, "%s,<expr>%s</expr>", yystack.l_mark[-2].sVal, yystack.l_mark[0].sVal);
		strcpy(yyval.sVal, temp);

	}
break;
case 79:
#line 647 "src/parser.y"
	{

		sprintf(temp, "%s,%s", yystack.l_mark[-2].sVal, yystack.l_mark[0].sVal);
		strcpy(yyval.sVal, temp);

	}
break;
case 80:
#line 657 "src/parser.y"
	{

		sprintf(temp, "%s%s%s;", yystack.l_mark[-3].sVal, yystack.l_mark[-2].sVal, yystack.l_mark[-1].sVal);
                strcpy(yyval.sVal, temp);

	}
break;
case 81:
#line 665 "src/parser.y"
	{

		symbol_add(std::string(yystack.l_mark[-4].sVal), SYMBOL_TYPE::FUNC);

		std::cout << ".global " << std::string(yystack.l_mark[-4].sVal) << std::endl;		

		/*sprintf(temp, "%s%s(%s);", $1, $2, $4);*/
		/*strcpy($$, temp);*/

	}
break;
case 82:
#line 676 "src/parser.y"
	{

		symbol_add(std::string(yystack.l_mark[-4].sVal), SYMBOL_TYPE::FUNC);

		std::cout << ".global " << std::string(yystack.l_mark[-4].sVal) << std::endl;

		/*sprintf(temp, "%s%s(%s);", $1, $2, $4);*/
		/*strcpy($$, temp);*/

	}
break;
case 83:
#line 687 "src/parser.y"
	{

		symbol_add(std::string(yystack.l_mark[-3].sVal), SYMBOL_TYPE::FUNC);
		
		std::cout << ".global " << std::string(yystack.l_mark[-3].sVal) << std::endl;

		/*sprintf(temp, "%s%s();", $1, $2);*/
		/*strcpy($$, temp);*/

	}
break;
case 84:
#line 698 "src/parser.y"
	{

		symbol_add(std::string(yystack.l_mark[-3].sVal), SYMBOL_TYPE::FUNC);

		std::cout << ".global " << std::string(yystack.l_mark[-3].sVal) << std::endl;

		/*sprintf(temp, "%s%s();", $1, $2);*/
		/*strcpy($$, temp);*/

	}
break;
case 85:
#line 709 "src/parser.y"
	{

		sprintf(temp, "%s %s", yystack.l_mark[-2].sVal, yystack.l_mark[0].sVal);
                strcpy(yyval.sVal, temp);

	}
break;
case 87:
#line 718 "src/parser.y"
	{
	 
		strcpy(yyval.sVal, yystack.l_mark[0].sVal);

	}
break;
case 88:
#line 726 "src/parser.y"
	{

		if (DEBUG)
                        std::cout << "->statement" << std::endl;

	}
break;
case 97:
#line 749 "src/parser.y"
	{

		sprintf(temp, "%s<stmt>%s</stmt>", yystack.l_mark[-1].sVal, yystack.l_mark[0].sVal);
                strcpy(yyval.sVal, temp);

	}
break;
case 98:
#line 756 "src/parser.y"
	{

		sprintf(temp, "<stmt>%s</stmt>", yystack.l_mark[0].sVal);
                strcpy(yyval.sVal, temp);
	
	}
break;
case 99:
#line 765 "src/parser.y"
	{

		cur_scope += 1;

	}
break;
case 100:
#line 769 "src/parser.y"
	{

		symbol_remove(cur_scope);
		cur_scope -= 1;

		sprintf(temp, "{}");
                strcpy(yyval.sVal, temp);

	}
break;
case 101:
#line 779 "src/parser.y"
	{

		cur_scope += 1;

	}
break;
case 102:
#line 783 "src/parser.y"
	{

		if (DEBUG) {
			std::cout << "YOOOOOOOOOOOOOOOO" << std::endl;
			std::cout << "cur_scope = " << cur_scope << std::endl;

		}
		symbol_remove(cur_scope);
		cur_scope -= 1;

		sprintf(temp, "{%s}", yystack.l_mark[-2].sVal);
                strcpy(yyval.sVal, temp);

		if (DEBUG)
                        std::cout << "->compound_statement" << std::endl;


	}
break;
case 103:
#line 802 "src/parser.y"
	{

		sprintf(temp, "%s%s", yystack.l_mark[-1].sVal, yystack.l_mark[0].sVal);
                strcpy(yyval.sVal, temp);

		if (DEBUG)
                        std::cout << "->statement_var_decls" << std::endl;

	}
break;
case 105:
#line 814 "src/parser.y"
	{

		sprintf(temp, "<stmt>%s</stmt>", yystack.l_mark[0].sVal);
                strcpy(yyval.sVal, temp);

		if (DEBUG)
                        std::cout << "->statement_var_decl" << std::endl;

	}
break;
case 107:
#line 828 "src/parser.y"
	{

		sprintf(temp, "<expr>%s</expr>;", yystack.l_mark[-1].sVal);
                strcpy(yyval.sVal, temp);

		if (DEBUG)
                        std::cout << "->stmt_expression" << std::endl;

	}
break;
case 108:
#line 838 "src/parser.y"
	{

		sprintf(temp, "%s(<expr>%s</expr>)%s", yystack.l_mark[-4].sVal, yystack.l_mark[-2].sVal, yystack.l_mark[0].sVal);
                strcpy(yyval.sVal, temp);

	}
break;
case 109:
#line 845 "src/parser.y"
	{

		sprintf(temp, "%s(<expr>%s</expr>)%s%s%s", yystack.l_mark[-6].sVal, yystack.l_mark[-4].sVal, yystack.l_mark[-2].sVal, yystack.l_mark[-1].sVal, yystack.l_mark[0].sVal);
                strcpy(yyval.sVal, temp);

	}
break;
case 110:
#line 852 "src/parser.y"
	{

		sprintf(temp, "%s(<expr>%s</expr>){%s}", yystack.l_mark[-6].sVal, yystack.l_mark[-4].sVal, yystack.l_mark[-1].sVal);
                strcpy(yyval.sVal, temp);

	}
break;
case 111:
#line 859 "src/parser.y"
	{

		sprintf(temp, "%s(<expr>%s</expr>){}", yystack.l_mark[-5].sVal, yystack.l_mark[-3].sVal);
                strcpy(yyval.sVal, temp);

	}
break;
case 112:
#line 866 "src/parser.y"
	{

		sprintf(temp, "%s%s", yystack.l_mark[-1].sVal, yystack.l_mark[0].sVal);
                strcpy(yyval.sVal, temp);

	}
break;
case 114:
#line 875 "src/parser.y"
	{

		sprintf(temp, "%s%d:%s", yystack.l_mark[-3].sVal, yystack.l_mark[-2].iVal, yystack.l_mark[0].sVal);
                strcpy(yyval.sVal, temp);

	}
break;
case 115:
#line 882 "src/parser.y"
	{

		sprintf(temp, "%s%d:", yystack.l_mark[-2].sVal, yystack.l_mark[-1].iVal);
                strcpy(yyval.sVal, temp);

	}
break;
case 116:
#line 889 "src/parser.y"
	{

                sprintf(temp, "%s%d:%s", yystack.l_mark[-4].sVal, yystack.l_mark[-2].iVal, yystack.l_mark[0].sVal);
                strcpy(yyval.sVal, temp);

        }
break;
case 117:
#line 896 "src/parser.y"
	{

                sprintf(temp, "%s%d:", yystack.l_mark[-3].sVal, yystack.l_mark[-1].iVal);
                strcpy(yyval.sVal, temp);

        }
break;
case 118:
#line 903 "src/parser.y"
	{

                sprintf(temp, "%s-%d:%s", yystack.l_mark[-4].sVal, yystack.l_mark[-2].iVal, yystack.l_mark[0].sVal);
                strcpy(yyval.sVal, temp);

        }
break;
case 119:
#line 910 "src/parser.y"
	{

                sprintf(temp, "%s-%d:", yystack.l_mark[-3].sVal, yystack.l_mark[-1].iVal);
                strcpy(yyval.sVal, temp);

        }
break;
case 120:
#line 917 "src/parser.y"
	{

		sprintf(temp, "%s:%s", yystack.l_mark[-2].sVal, yystack.l_mark[0].sVal);
                strcpy(yyval.sVal, temp);

	}
break;
case 121:
#line 924 "src/parser.y"
	{

		sprintf(temp, "%s:", yystack.l_mark[-1].sVal);
                strcpy(yyval.sVal, temp);

	}
break;
case 122:
#line 931 "src/parser.y"
	{

		sprintf(temp, "%s(<expr>%s</expr>)<stmt>%s</stmt>", yystack.l_mark[-4].sVal, yystack.l_mark[-2].sVal, yystack.l_mark[0].sVal);
                strcpy(yyval.sVal, temp);

	}
break;
case 123:
#line 938 "src/parser.y"
	{

		sprintf(temp, "%s<stmt>%s</stmt>%s(<expr>%s</expr>);", yystack.l_mark[-6].sVal, yystack.l_mark[-5].sVal, yystack.l_mark[-4].sVal, yystack.l_mark[-2].sVal);
                strcpy(yyval.sVal, temp);

	}
break;
case 124:
#line 945 "src/parser.y"
	{

		sprintf(temp, "%s(%s;%s;%s)<stmt>%s</stmt>", yystack.l_mark[-8].sVal, yystack.l_mark[-6].sVal, yystack.l_mark[-4].sVal, yystack.l_mark[-2].sVal, yystack.l_mark[0].sVal);
                strcpy(yyval.sVal, temp);

	}
break;
case 125:
#line 952 "src/parser.y"
	{

		sprintf(temp, "<expr>%s</expr>", yystack.l_mark[0].sVal);
                strcpy(yyval.sVal, temp);

	}
break;
case 126:
#line 959 "src/parser.y"
	{}
break;
case 127:
#line 961 "src/parser.y"
	{

		sprintf(temp, "%s;", yystack.l_mark[-1].sVal);
                strcpy(yyval.sVal, temp);

	}
break;
case 128:
#line 968 "src/parser.y"
	{

		sprintf(temp, "%s<expr>%s</expr>;", yystack.l_mark[-2].sVal, yystack.l_mark[-1].sVal);
                strcpy(yyval.sVal, temp);

	}
break;
case 129:
#line 975 "src/parser.y"
	{

		sprintf(temp, "%s;", yystack.l_mark[-1].sVal);
                strcpy(yyval.sVal, temp);

	}
break;
case 130:
#line 982 "src/parser.y"
	{

		sprintf(temp, "%s;", yystack.l_mark[-1].sVal);
                strcpy(yyval.sVal, temp);

	}
break;
case 131:
#line 991 "src/parser.y"
	{
	
		/* add symbol for function if it hasn't (no declaration before)*/
		int i = symbol_find(std::string(yystack.l_mark[-3].sVal), SYMBOL_TYPE::FUNC);

                if (i == -1) {

                        symbol_add(std::string(yystack.l_mark[-3].sVal), SYMBOL_TYPE::FUNC);

                }

		/* param_list's scope should be the same as the ones after '{'*/
		cur_scope += 1;

		int param_count = 0;
		char *param = strtok(yystack.l_mark[-1].sVal, " ");
		
		while (param) {

			param_count += 1;
			int i = symbol_add(std::string(param), SYMBOL_TYPE::VAR);
			symbol_table[i].offset = -4 * param_count - 4;

			param = strtok(NULL, " ");

		}

		symbol_table[i].args_num = param_count;

		cur_scope -= 1;

		/* do A before '{'*/
		std::cout << std::string(yystack.l_mark[-3].sVal) << ":" << std::endl;

		std::cout << "addi sp, sp, -4" << std::endl;
		std::cout << "sw s0, 0(sp)" << std::endl;

		std::cout << "addi s0, sp, 0" << std::endl;

		std::cout << "addi sp, sp, -4" << std::endl;
		std::cout << "sw ra, 0(sp)" << std::endl;

		for (int j = 0; j < symbol_table[i].args_num; ++j) {

			std::cout << "addi sp, sp, -4" << std::endl;
			std::cout << "sw a" + std::to_string(j) + ", 0(sp)" << std::endl;

		}

		for (int i = 1; i <= 11; ++i) {

			std::cout << "addi sp, sp, -4" << std::endl;
                        std::cout << "sw s" + std::to_string(i) + ", 0(sp)" << std::endl;

		}


	}
break;
case 132:
#line 1048 "src/parser.y"
	{

		/* do B after '}'*/
		std::cout << "addi sp, s0, -4" << std::endl;
		
		std::cout << "lw ra, 0(sp)" << std::endl;
		std::cout << "addi sp, sp, 4" << std::endl;
		
		std::cout << "lw s0, 0(sp)" << std::endl;
		std::cout << "addi sp, sp, 4" << std::endl;

	}
break;
case 133:
#line 1061 "src/parser.y"
	{
	
		/* add symbol for function if it hasn't (no declaration before)*/
                int i = symbol_find(std::string(yystack.l_mark[-3].sVal), SYMBOL_TYPE::FUNC);

                if (i == -1) {

                        symbol_add(std::string(yystack.l_mark[-3].sVal), SYMBOL_TYPE::FUNC);

                }

                /* param_list's scope should be the same as the ones after '{'*/
                cur_scope += 1;

                int param_count = 0;
                char *param = strtok(yystack.l_mark[-1].sVal, " ");

                while (param) {

                        param_count += 1;
                        int i = symbol_add(std::string(param), SYMBOL_TYPE::VAR);
                        symbol_table[i].offset = -4 * param_count - 4;
                        
                        param = strtok(NULL, " ");

                }

                symbol_table[i].args_num = param_count;

                cur_scope -= 1;		

		/* do A before '{'*/
		std::cout << std::string(yystack.l_mark[-3].sVal) << ":" << std::endl;

                std::cout << "addi sp, sp, -4" << std::endl;
                std::cout << "sw s0, 0(sp)" << std::endl;

                std::cout << "addi s0, sp, 0" << std::endl;

                std::cout << "addi sp, sp, -4" << std::endl;
                std::cout << "sw ra, 0(sp)" << std::endl;

                for (int j = 0; j < symbol_table[i].args_num; ++j) {

                        std::cout << "addi sp, sp, -4" << std::endl;
                        std::cout << "sw a" + std::to_string(j) + ", 0(sp)" << std::endl;

                }

                for (int i = 1; i <= 11; ++i) {

                        std::cout << "addi sp, sp, -4" << std::endl;
                        std::cout << "sw s" + std::to_string(i) + ", 0(sp)" << std::endl;

                }

	}
break;
case 134:
#line 1117 "src/parser.y"
	{

		/* do B after '}'*/
                std::cout << "addi sp, s0, -4" << std::endl;

                std::cout << "lw ra, 0(sp)" << std::endl;
                std::cout << "addi sp, sp, 4" << std::endl;

                std::cout << "lw s0, 0(sp)" << std::endl;
                std::cout << "addi sp, sp, 4" << std::endl;

	}
break;
case 135:
#line 1130 "src/parser.y"
	{

		int i = symbol_find(std::string(yystack.l_mark[-2].sVal), SYMBOL_TYPE::FUNC);

                if (i == -1) {

                        symbol_add(std::string(yystack.l_mark[-2].sVal), SYMBOL_TYPE::FUNC);

                }

		/* do A before '{'*/
		std::cout << std::string(yystack.l_mark[-2].sVal) << ":" << std::endl;

                std::cout << "addi sp, sp, -4" << std::endl;
                std::cout << "sw s0, 0(sp)" << std::endl;

                std::cout << "addi s0, sp, 0" << std::endl;

                std::cout << "addi sp, sp, -4" << std::endl;
                std::cout << "sw ra, 0(sp)" << std::endl;

                for (int i = 1; i <= 11; ++i) {

                        std::cout << "addi sp, sp, -4" << std::endl;
                        std::cout << "sw s" + std::to_string(i) + ", 0(sp)" << std::endl;

                }

	}
break;
case 136:
#line 1158 "src/parser.y"
	{

		/* do B after '}'*/
                std::cout << "addi sp, s0, -4" << std::endl;

                std::cout << "lw ra, 0(sp)" << std::endl;
                std::cout << "addi sp, sp, 4" << std::endl;

                std::cout << "lw s0, 0(sp)" << std::endl;
                std::cout << "addi sp, sp, 4" << std::endl;

	}
break;
case 137:
#line 1171 "src/parser.y"
	{

		int i = symbol_find(std::string(yystack.l_mark[-2].sVal), SYMBOL_TYPE::FUNC);

                if (i == -1) {

                        symbol_add(std::string(yystack.l_mark[-2].sVal), SYMBOL_TYPE::FUNC);

                }

		/* do A before '{'*/
		std::cout << std::string(yystack.l_mark[-2].sVal) << ":" << std::endl;

                std::cout << "addi sp, sp, -4" << std::endl;
                std::cout << "sw s0, 0(sp)" << std::endl;

                std::cout << "addi s0, sp, 0" << std::endl;

                std::cout << "addi sp, sp, -4" << std::endl;
                std::cout << "sw ra, 0(sp)" << std::endl;

                for (int i = 1; i <= 11; ++i) {

                        std::cout << "addi sp, sp, -4" << std::endl;
                        std::cout << "sw s" + std::to_string(i) + ", 0(sp)" << std::endl;

                }

	}
break;
case 138:
#line 1199 "src/parser.y"
	{

		/* do B after '}'*/
                std::cout << "addi sp, s0, -4" << std::endl;

                std::cout << "lw ra, 0(sp)" << std::endl;
                std::cout << "addi sp, sp, 4" << std::endl;

                std::cout << "lw s0, 0(sp)" << std::endl;
                std::cout << "addi sp, sp, 4" << std::endl;

		if (DEBUG)
			std::cout << "->func_def" << std::endl;
	}
break;
#line 2285 "src/y.tab.c"
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
