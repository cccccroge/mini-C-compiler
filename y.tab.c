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
   char temp[10000];

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
	char sVal[1000];

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
    0,    0,    1,    1,    2,    3,    3,    3,    3,    4,
    4,    5,    5,    6,    6,    6,    6,    6,    6,    6,
    6,    6,    6,    6,    6,    6,    6,    6,    6,    6,
    6,    6,    6,    6,    6,    6,    6,    6,    6,    6,
    6,    6,    6,    6,    6,    6,    7,    8,    8,    9,
   10,   10,   10,   11,   11,   11,   11,   12,   13,   13,
   14,   14,   15,   16,   16,   17,   17,   18,   18,   19,
   19,
};
static const YYINT yylen[] = {                            2,
    2,    0,    1,    1,    3,    1,    1,    1,    1,    1,
    3,    1,    3,    3,    3,    3,    3,    3,    3,    3,
    3,    3,    3,    3,    3,    3,    3,    3,    2,    3,
    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,
    3,    3,    1,    1,    1,    1,    2,    4,    3,    4,
    3,    1,    0,    1,    1,    1,    1,    3,    1,    3,
    1,    3,    2,    4,    3,    3,    3,    1,    3,    1,
    3,
};
static const YYINT yydefred[] = {                         2,
    0,    6,    7,    9,    8,    1,    3,    0,    4,    0,
    0,   10,    0,   59,    0,    0,    0,    0,    5,    0,
   58,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   54,   55,   56,   57,    0,    0,   43,   46,    0,
    0,   11,    0,   60,    0,   62,   65,    0,   34,    0,
   38,   31,   32,   29,    0,   35,   39,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   36,   40,    0,    0,
    0,   70,    0,    0,   30,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   16,   17,
   18,    0,    0,    0,    0,    0,   64,   66,    0,   67,
    0,   50,    0,   49,    0,    0,   71,    0,   48,
};
static const YYINT yydgoto[] = {                          1,
    6,    7,    8,   11,   12,   36,   37,   61,   38,   87,
   39,    9,   13,   14,   15,   18,   46,   83,   84,
};
static const YYINT yysindex[] = {                         0,
 -133,    0,    0,    0,    0,    0,    0, -273,    0,  -59,
  -24,    0,   -8,    0,  -46, -266,  -27,  -66,    0, -256,
    0, -244,  -79,  -18, -196, -195,  -27,  -27,  -27,  -27,
  -39,    0,    0,    0,    0,  155,  -56,    0,    0, -190,
   53,    0,    7,    0,  -33,    0,    0,   76,    0,   76,
    0,    0,    0,    0,  108,    0,    0,  -27,  -27,  -27,
   81,  -27,  -27,  -27,  -27,  -27,  -27,  -27,  -27,  -27,
  -27,  -27,  -27,  -27,  -27,  -27,    0,    0,  -27,   38,
  155,    0,  -36,   -5,    0,  155,  -30,   70,  155,  -27,
  166,  166,  514,  514,  456,  235,  129,  129,    0,    0,
    0,  166,  166,  463,  493,  155,    0,    0,  -27,    0,
  -79,    0,  -27,    0,  144,  155,    0,  155,    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  110,
    0,    0,    0,    0,  114,    0,    0,  -40,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   12,    0,    0,    0,    0,  118,   23,    0,    0,    0,
  110,    0,    0,    0,    0,    0,    0,   59,    0,   97,
    0,    0,    0,    0,    0,    0,    0,   -7,    0,    0,
  -14,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   -3,    0,    0,    0,    0,   32,    0,    0,   -1,    0,
  355,  367,   40,  359,  313,  414,  267,  320,    0,    0,
    0,  402,  409,   50,   36,  478,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   -2,    0,  179,    0,
};
static const YYINT yygindex[] = {                         0,
    0,    0,    0,    0,  158,  639,   37,    0,    0,    0,
    0,    0,    0,  157,    0,    0,  -42,    0,    0,
};
#define YYTABLESIZE 791
static const YYINT yytable[] = {                         29,
   58,   17,   82,   63,   79,   29,   30,  109,   10,   27,
  112,   28,   30,  113,   23,   27,   24,   28,   63,   20,
   63,   60,   47,   47,   40,   41,   47,   47,   47,   47,
   47,   16,   47,   53,   19,   22,   53,   43,  111,   41,
   68,   69,   41,   45,   47,   47,   47,   47,   44,   44,
   21,   59,   44,   44,   44,   44,   44,   41,   44,   45,
   45,   49,   51,   45,   45,   45,   45,   45,  117,   45,
   44,   44,   52,   44,   47,   52,   28,   23,   47,   28,
   23,   45,   45,   23,   45,   48,   50,   27,  108,   45,
   27,   41,   80,   27,   28,   33,   33,   16,   23,   33,
   33,   33,   33,   33,   44,   33,   72,   75,   27,   47,
   47,   70,   68,   17,   69,   45,   71,   33,   33,  110,
   33,   68,   69,   41,    2,    3,    4,    5,   28,   73,
  107,   74,   23,   37,   37,   44,   44,   37,   37,   37,
   37,   37,   27,   37,   72,   75,   45,   45,   85,   70,
   68,   33,   69,   12,   71,   37,   37,   61,   37,   28,
   28,   13,  114,   23,   23,   72,   59,   73,   12,   74,
   70,   90,   61,   27,   27,   71,   13,   42,   44,    0,
   72,   75,   33,   33,    0,   70,   68,    0,   69,   37,
   71,   72,   75,   76,    0,    0,   70,   68,    0,   69,
    0,   71,   72,   73,    0,   74,    0,   70,   68,    0,
   69,    0,   71,    0,   73,    0,   74,   77,   78,   51,
   37,   37,   51,    0,    0,    0,    0,    0,    0,    0,
    0,   76,    0,    0,   56,   57,  119,    0,    0,    0,
   25,   26,    0,    0,    0,    0,   25,   26,   31,   32,
   33,   34,   35,    0,   31,   32,   33,   34,   35,   47,
   47,   47,   47,   47,   47,   47,   47,   76,    0,    0,
    0,   72,   75,    0,    0,    0,   70,   68,   76,   69,
    0,   71,    0,    0,    0,    0,    0,   44,   44,   44,
   44,   44,   44,    0,   73,    0,   74,    0,   45,   45,
   45,   45,   45,   45,   14,    0,    0,   14,    0,   14,
   14,   14,    0,    0,    0,   28,   28,   23,   23,   23,
   23,    0,    0,    0,    0,   14,   14,    0,   14,   27,
   27,    0,    0,    0,   33,   33,   33,   33,   33,   33,
    0,    0,    0,    0,    0,   62,   63,   64,   65,   66,
   67,    0,    0,   25,    0,    0,   25,   15,   76,   14,
   15,    0,   15,   15,   15,    0,    0,    0,    0,    0,
    0,   25,   37,   37,   37,   37,   37,   37,   15,   15,
    0,   15,    0,   62,   63,   64,   65,   66,   67,    0,
   14,   14,   20,    0,    0,   20,   24,    0,   20,   24,
    0,    0,   24,    0,   22,   25,    0,   22,    0,    0,
   22,    0,   15,   20,   20,    0,   20,   24,    0,   62,
   63,   64,   65,   66,   67,   22,   22,    0,   22,    0,
   62,   63,   64,   65,   66,   67,    0,   25,    0,   19,
    0,    0,   19,   15,   15,   19,   21,   20,    0,   21,
    0,   24,   21,    0,   26,    0,    0,   26,    0,   22,
   19,   19,    0,   19,    0,    0,    0,   21,   21,    0,
   21,    0,   26,    0,    0,    0,    0,    0,   20,   20,
    0,    0,   24,   24,    0,    0,    0,    0,    0,    0,
   22,   22,   72,   75,   19,    0,    0,   70,   68,   72,
   69,   21,   71,    0,   70,   68,   26,   69,    0,   71,
   62,   63,   64,   65,   66,   73,    0,   74,   42,    0,
    0,   42,   73,    0,   74,   19,   19,    0,    0,   72,
   75,    0,   21,   21,   70,   68,   42,   69,   26,   71,
    0,    0,   14,   14,   14,   14,   14,   14,    0,    0,
   72,    0,   73,    0,   74,   70,   68,    0,   69,    0,
   71,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   42,    0,    0,   73,    0,   74,    0,    0,    0,   76,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   25,   25,    0,   15,   15,   15,   15,   15,
   15,    0,   42,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   20,   20,   20,   20,   20,   20,   24,   24,   24,   24,
    0,    0,   22,   22,   22,   22,   22,   22,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   52,   53,   54,   55,    0,
    0,    0,    0,    0,    0,    0,    0,   19,   19,   19,
   19,   19,   19,   81,   21,   21,   21,   21,   21,   21,
    0,    0,    0,    0,   26,    0,   86,   88,   89,    0,
   91,   92,   93,   94,   95,   96,   97,   98,   99,  100,
  101,  102,  103,  104,  105,    0,    0,  106,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  115,    0,
    0,   62,   63,   64,   65,    0,    0,    0,   62,   63,
   64,   65,    0,    0,    0,    0,    0,  116,    0,    0,
    0,  118,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   62,   63,
   64,   65,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   62,
   63,
};
static const YYINT yycheck[] = {                         33,
   40,   61,   45,   44,   61,   33,   40,   44,  282,   43,
   41,   45,   40,   44,   61,   43,  283,   45,   59,   44,
   61,   61,   37,   38,   91,  282,   41,   42,   43,   44,
   45,   91,   47,   41,   59,   44,   44,  282,   44,   41,
   44,   44,   44,  123,   59,   60,   61,   62,   37,   38,
   59,   91,   41,   42,   43,   44,   45,   59,   47,   37,
   38,   25,   26,   41,   42,   43,   44,   45,  111,   47,
   59,   60,   41,   62,   93,   44,   41,   38,   93,   44,
   41,   59,   60,   44,   62,  282,  282,   38,  125,  123,
   41,   93,  283,   44,   59,   37,   38,   91,   59,   41,
   42,   43,   44,   45,   93,   47,   37,   38,   59,  124,
  125,   42,   43,   61,   45,   93,   47,   59,   60,  125,
   62,  125,  125,  125,  258,  259,  260,  261,   93,   60,
   93,   62,   93,   37,   38,  124,  125,   41,   42,   43,
   44,   45,   93,   47,   37,   38,  124,  125,   41,   42,
   43,   93,   45,   44,   47,   59,   60,   44,   62,  124,
  125,   44,   93,  124,  125,   37,   91,   60,   59,   62,
   42,   91,   59,  124,  125,   47,   59,   20,   22,   -1,
   37,   38,  124,  125,   -1,   42,   43,   -1,   45,   93,
   47,   37,   38,  124,   -1,   -1,   42,   43,   -1,   45,
   -1,   47,   37,   60,   -1,   62,   -1,   42,   43,   -1,
   45,   -1,   47,   -1,   60,   -1,   62,  274,  275,   41,
  124,  125,   44,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  124,   -1,   -1,  274,  275,   93,   -1,   -1,   -1,
  274,  275,   -1,   -1,   -1,   -1,  274,  275,  282,  283,
  284,  285,  286,   -1,  282,  283,  284,  285,  286,  274,
  275,  276,  277,  278,  279,  280,  281,  124,   -1,   -1,
   -1,   37,   38,   -1,   -1,   -1,   42,   43,  124,   45,
   -1,   47,   -1,   -1,   -1,   -1,   -1,  276,  277,  278,
  279,  280,  281,   -1,   60,   -1,   62,   -1,  276,  277,
  278,  279,  280,  281,   38,   -1,   -1,   41,   -1,   43,
   44,   45,   -1,   -1,   -1,  280,  281,  278,  279,  280,
  281,   -1,   -1,   -1,   -1,   59,   60,   -1,   62,  280,
  281,   -1,   -1,   -1,  276,  277,  278,  279,  280,  281,
   -1,   -1,   -1,   -1,   -1,  276,  277,  278,  279,  280,
  281,   -1,   -1,   41,   -1,   -1,   44,   38,  124,   93,
   41,   -1,   43,   44,   45,   -1,   -1,   -1,   -1,   -1,
   -1,   59,  276,  277,  278,  279,  280,  281,   59,   60,
   -1,   62,   -1,  276,  277,  278,  279,  280,  281,   -1,
  124,  125,   38,   -1,   -1,   41,   38,   -1,   44,   41,
   -1,   -1,   44,   -1,   38,   93,   -1,   41,   -1,   -1,
   44,   -1,   93,   59,   60,   -1,   62,   59,   -1,  276,
  277,  278,  279,  280,  281,   59,   60,   -1,   62,   -1,
  276,  277,  278,  279,  280,  281,   -1,  125,   -1,   38,
   -1,   -1,   41,  124,  125,   44,   38,   93,   -1,   41,
   -1,   93,   44,   -1,   41,   -1,   -1,   44,   -1,   93,
   59,   60,   -1,   62,   -1,   -1,   -1,   59,   60,   -1,
   62,   -1,   59,   -1,   -1,   -1,   -1,   -1,  124,  125,
   -1,   -1,  124,  125,   -1,   -1,   -1,   -1,   -1,   -1,
  124,  125,   37,   38,   93,   -1,   -1,   42,   43,   37,
   45,   93,   47,   -1,   42,   43,   93,   45,   -1,   47,
  276,  277,  278,  279,  280,   60,   -1,   62,   41,   -1,
   -1,   44,   60,   -1,   62,  124,  125,   -1,   -1,   37,
   38,   -1,  124,  125,   42,   43,   59,   45,  125,   47,
   -1,   -1,  276,  277,  278,  279,  280,  281,   -1,   -1,
   37,   -1,   60,   -1,   62,   42,   43,   -1,   45,   -1,
   47,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   93,   -1,   -1,   60,   -1,   62,   -1,   -1,   -1,  124,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  280,  281,   -1,  276,  277,  278,  279,  280,
  281,   -1,  125,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  276,  277,  278,  279,  280,  281,  278,  279,  280,  281,
   -1,   -1,  276,  277,  278,  279,  280,  281,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   27,   28,   29,   30,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  276,  277,  278,
  279,  280,  281,   45,  276,  277,  278,  279,  280,  281,
   -1,   -1,   -1,   -1,  281,   -1,   58,   59,   60,   -1,
   62,   63,   64,   65,   66,   67,   68,   69,   70,   71,
   72,   73,   74,   75,   76,   -1,   -1,   79,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   90,   -1,
   -1,  276,  277,  278,  279,   -1,   -1,   -1,  276,  277,
  278,  279,   -1,   -1,   -1,   -1,   -1,  109,   -1,   -1,
   -1,  113,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  276,  277,
  278,  279,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  276,
  277,
};
#define YYFINAL 1
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 290
#define YYUNDFTOKEN 312
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
0,"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : program",
"program : program var_decl",
"program :",
"var_decl : scalar_decl",
"var_decl : array_decl",
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
"func_invoc : ID '(' param_list ')'",
"param_list : param_list ',' expr",
"param_list : expr",
"param_list :",
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
#line 487 "parser.y"


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
#line 502 "y.tab.c"

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
#line 67 "parser.y"
	{

	}
break;
case 2:
#line 79 "parser.y"
	{}
break;
case 5:
#line 87 "parser.y"
	{

		printf("<scalar_decl>%s%s;</scalar_decl>", yystack.l_mark[-2].sVal, yystack.l_mark[-1].sVal);

	}
break;
case 11:
#line 97 "parser.y"
	{

		strcpy(yyval.sVal, yystack.l_mark[-2].sVal);
		strcat(yyval.sVal, yystack.l_mark[-1].sVal);
		strcat(yyval.sVal, yystack.l_mark[0].sVal);

	}
break;
case 13:
#line 107 "parser.y"
	{
		
		sprintf(temp, "%s=<expr>%s</expr>", yystack.l_mark[-2].sVal, yystack.l_mark[0].sVal);
		strcpy(yyval.sVal, temp);

	}
break;
case 14:
#line 116 "parser.y"
	{

		sprintf(temp, "<expr>%s</expr>+<expr>%s</expr>", yystack.l_mark[-2].sVal, yystack.l_mark[0].sVal);
		strcpy(yyval.sVal, temp);

	}
break;
case 15:
#line 123 "parser.y"
	{

                sprintf(temp, "<expr>%s</expr>-<expr>%s</expr>", yystack.l_mark[-2].sVal, yystack.l_mark[0].sVal);
		strcpy(yyval.sVal, temp);

	}
break;
case 16:
#line 130 "parser.y"
	{

		sprintf(temp, "<expr>%s</expr>*<expr>%s</expr>", yystack.l_mark[-2].sVal, yystack.l_mark[0].sVal);
		strcpy(yyval.sVal, temp);

	}
break;
case 17:
#line 137 "parser.y"
	{

                sprintf(temp, "<expr>%s</expr>/<expr>%s</expr>", yystack.l_mark[-2].sVal, yystack.l_mark[0].sVal);
		strcpy(yyval.sVal, temp);

        }
break;
case 18:
#line 144 "parser.y"
	{

                sprintf(temp, "<expr>%s</expr>%%<expr>%s</expr>", yystack.l_mark[-2].sVal, yystack.l_mark[0].sVal);
		strcpy(yyval.sVal, temp);

        }
break;
case 19:
#line 151 "parser.y"
	{

                sprintf(temp, "<expr>%s</expr><<expr>%s</expr>", yystack.l_mark[-2].sVal, yystack.l_mark[0].sVal);
		strcpy(yyval.sVal, temp);

        }
break;
case 20:
#line 158 "parser.y"
	{

		sprintf(temp, "<expr>%s</expr><=<expr>%s</expr>", yystack.l_mark[-2].sVal, yystack.l_mark[0].sVal);
		strcpy(yyval.sVal, temp);

        }
break;
case 21:
#line 165 "parser.y"
	{

                sprintf(temp, "<expr>%s</expr>><expr>%s</expr>", yystack.l_mark[-2].sVal, yystack.l_mark[0].sVal);
		strcpy(yyval.sVal, temp);

        }
break;
case 22:
#line 172 "parser.y"
	{

                sprintf(temp, "<expr>%s</expr>>=<expr>%s</expr>", yystack.l_mark[-2].sVal, yystack.l_mark[0].sVal);
		strcpy(yyval.sVal, temp);

        }
break;
case 23:
#line 179 "parser.y"
	{

                sprintf(temp, "<expr>%s</expr>==<expr>%s</expr>", yystack.l_mark[-2].sVal, yystack.l_mark[0].sVal);
		strcpy(yyval.sVal, temp);

        }
break;
case 24:
#line 186 "parser.y"
	{

                sprintf(temp, "<expr>%s</expr>!=<expr>%s</expr>", yystack.l_mark[-2].sVal, yystack.l_mark[0].sVal);
		strcpy(yyval.sVal, temp);

        }
break;
case 25:
#line 193 "parser.y"
	{

                sprintf(temp, "<expr>%s</expr>&&<expr>%s</expr>", yystack.l_mark[-2].sVal, yystack.l_mark[0].sVal);
		strcpy(yyval.sVal, temp);
        }
break;
case 26:
#line 199 "parser.y"
	{

                sprintf(temp, "<expr>%s</expr>||<expr>%s</expr>", yystack.l_mark[-2].sVal, yystack.l_mark[0].sVal);
		strcpy(yyval.sVal, temp);		

        }
break;
case 27:
#line 206 "parser.y"
	{

                sprintf(temp, "<expr>%s</expr>&<expr>%s</expr>", yystack.l_mark[-2].sVal, yystack.l_mark[0].sVal);
                strcpy(yyval.sVal, temp);

        }
break;
case 28:
#line 213 "parser.y"
	{

                sprintf(temp, "<expr>%s</expr>|<expr>%s</expr>", yystack.l_mark[-2].sVal, yystack.l_mark[0].sVal);
		strcpy(yyval.sVal, temp);

        }
break;
case 29:
#line 220 "parser.y"
	{

		sprintf(temp, "!<expr>%s</expr>", yystack.l_mark[0].sVal);
                strcpy(yyval.sVal, temp);

        }
break;
case 30:
#line 227 "parser.y"
	{
                
                sprintf(temp, "(<expr>%s</expr>)", yystack.l_mark[-1].sVal);
		strcpy(yyval.sVal, temp);

	}
break;
case 31:
#line 234 "parser.y"
	{

                sprintf(temp, "+<expr>%s</expr>", yystack.l_mark[0].sVal);
		strcpy(yyval.sVal, temp);

        }
break;
case 32:
#line 241 "parser.y"
	{

                sprintf(temp, "-<expr>%s</expr>", yystack.l_mark[0].sVal);
		strcpy(yyval.sVal, temp);

        }
break;
case 33:
#line 248 "parser.y"
	{

		strcpy(yyval.sVal, yystack.l_mark[-1].sVal);
		strcat(yyval.sVal, yystack.l_mark[0].sVal);

	}
break;
case 34:
#line 255 "parser.y"
	{

                strcpy(yyval.sVal, yystack.l_mark[-1].sVal);
                strcat(yyval.sVal, yystack.l_mark[0].sVal);

	}
break;
case 35:
#line 262 "parser.y"
	{

                strcpy(yyval.sVal, yystack.l_mark[-1].sVal);
                strcat(yyval.sVal, yystack.l_mark[0].sVal);

	}
break;
case 36:
#line 269 "parser.y"
	{

                strcpy(yyval.sVal, yystack.l_mark[-1].sVal);
                strcat(yyval.sVal, yystack.l_mark[0].sVal);

	}
break;
case 37:
#line 276 "parser.y"
	{

                strcpy(yyval.sVal, yystack.l_mark[-1].sVal);
                strcat(yyval.sVal, yystack.l_mark[0].sVal);

        }
break;
case 38:
#line 283 "parser.y"
	{

                strcpy(yyval.sVal, yystack.l_mark[-1].sVal);
                strcat(yyval.sVal, yystack.l_mark[0].sVal);

        }
break;
case 39:
#line 290 "parser.y"
	{

                strcpy(yyval.sVal, yystack.l_mark[-1].sVal);
                strcat(yyval.sVal, yystack.l_mark[0].sVal);

        }
break;
case 40:
#line 297 "parser.y"
	{

                strcpy(yyval.sVal, yystack.l_mark[-1].sVal);
                strcat(yyval.sVal, yystack.l_mark[0].sVal);

        }
break;
case 41:
#line 304 "parser.y"
	{

                sprintf(temp, "%s=<expr>%s</expr>", yystack.l_mark[-2].sVal, yystack.l_mark[0].sVal);
		strcpy(yyval.sVal, temp);

	}
break;
case 42:
#line 311 "parser.y"
	{

                sprintf(temp, "%s=<expr>%s</expr>", yystack.l_mark[-2].sVal, yystack.l_mark[0].sVal);
		strcpy(yyval.sVal, temp);

	}
break;
case 47:
#line 326 "parser.y"
	{

                strcpy(yyval.sVal, yystack.l_mark[-1].sVal);
                strcat(yyval.sVal, yystack.l_mark[0].sVal);

	}
break;
case 48:
#line 333 "parser.y"
	{

		sprintf(temp, "%s[<expr>%s</expr>]", yystack.l_mark[-3].sVal, yystack.l_mark[-1].sVal);
		strcpy(yyval.sVal, temp);

	}
break;
case 49:
#line 340 "parser.y"
	{

		sprintf(temp, "[<expr>%s</expr>]", yystack.l_mark[-1].sVal);
		strcpy(yyval.sVal, temp);

	}
break;
case 50:
#line 347 "parser.y"
	{

                strcpy(yyval.sVal, yystack.l_mark[-3].sVal);
                strcat(yyval.sVal, yystack.l_mark[-2].sVal);
                strcat(yyval.sVal, yystack.l_mark[-1].sVal);
		strcat(yyval.sVal, yystack.l_mark[0].sVal);

	}
break;
case 51:
#line 356 "parser.y"
	{

		sprintf(temp, "%s,<expr>%s</expr>", yystack.l_mark[-2].sVal, yystack.l_mark[0].sVal);
		strcpy(yyval.sVal, temp);

	}
break;
case 52:
#line 363 "parser.y"
	{

		sprintf(temp, "<expr>%s</expr>", yystack.l_mark[0].sVal);
		strcpy(yyval.sVal, temp);

	}
break;
case 53:
#line 370 "parser.y"
	{}
break;
case 54:
#line 372 "parser.y"
	{

		sprintf(temp, "%d", yystack.l_mark[0].iVal);
		strcpy(yyval.sVal, temp);

	}
break;
case 55:
#line 379 "parser.y"
	{

		sprintf(temp, "%f", yystack.l_mark[0].dVal);
		strcpy(yyval.sVal, temp);

	}
break;
case 56:
#line 386 "parser.y"
	{

		if (strcmp(yystack.l_mark[0].sVal, "\\\\") == 0)
			sprintf(temp, "%s", "\\");
		else if (strcmp(yystack.l_mark[0].sVal, "\\'") == 0)
			sprintf(temp, "%s", "'");

		strcpy(yyval.sVal, temp);

	}
break;
case 58:
#line 401 "parser.y"
	{

		printf("<array_decl>%s%s;</array_decl>", yystack.l_mark[-2].sVal, yystack.l_mark[-1].sVal);

	}
break;
case 60:
#line 409 "parser.y"
	{

		sprintf(temp, "%s,%s", yystack.l_mark[-2].sVal, yystack.l_mark[0].sVal);
		strcpy(yyval.sVal, temp);

	}
break;
case 62:
#line 418 "parser.y"
	{

		sprintf(temp, "%s=%s", yystack.l_mark[-2].sVal, yystack.l_mark[0].sVal);
                strcpy(yyval.sVal, temp);

	}
break;
case 63:
#line 425 "parser.y"
	{

		strcpy(yyval.sVal, yystack.l_mark[-1].sVal);
		strcat(yyval.sVal, yystack.l_mark[0].sVal);

	}
break;
case 64:
#line 432 "parser.y"
	{

		sprintf(temp, "%s[%d]", yystack.l_mark[-3].sVal, yystack.l_mark[-1].iVal);
		strcpy(yyval.sVal, temp);

	}
break;
case 65:
#line 439 "parser.y"
	{

                sprintf(temp, "[%d]", yystack.l_mark[-1].iVal);
                strcpy(yyval.sVal, temp);

	}
break;
case 66:
#line 446 "parser.y"
	{

                sprintf(temp, "{%s}", yystack.l_mark[-1].sVal);
                strcpy(yyval.sVal, temp);

	}
break;
case 67:
#line 453 "parser.y"
	{

                sprintf(temp, "{%s}", yystack.l_mark[-1].sVal);
                strcpy(yyval.sVal, temp);

	}
break;
case 68:
#line 460 "parser.y"
	{

		sprintf(temp, "<expr>%s</expr>", yystack.l_mark[0].sVal);
		strcpy(yyval.sVal, temp);

	}
break;
case 69:
#line 467 "parser.y"
	{

		sprintf(temp, "%s,<expr>%s</expr>", yystack.l_mark[-2].sVal, yystack.l_mark[0].sVal);
		strcpy(yyval.sVal, temp);

	}
break;
case 71:
#line 476 "parser.y"
	{

		sprintf(temp, "%s,%s", yystack.l_mark[-2].sVal, yystack.l_mark[0].sVal);
		strcpy(yyval.sVal, temp);

	}
break;
#line 1190 "y.tab.c"
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
