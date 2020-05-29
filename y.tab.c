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
    0,    0,    1,    2,    3,    3,    3,    3,    4,    4,
    5,    5,    6,    6,    6,    6,    6,    6,    6,    6,
    6,    6,    6,    6,    6,    6,    6,    6,    6,    6,
    6,    6,    6,    6,    6,    6,    6,    6,    6,    6,
    6,    6,    6,    6,    6,    7,    8,    8,    9,   10,
   10,   10,   11,   11,   11,   11,
};
static const YYINT yylen[] = {                            2,
    2,    0,    1,    3,    1,    1,    1,    1,    1,    3,
    1,    3,    3,    3,    3,    3,    3,    3,    3,    3,
    3,    3,    3,    3,    3,    3,    3,    2,    3,    2,
    2,    2,    2,    2,    2,    2,    2,    2,    2,    3,
    3,    1,    1,    1,    1,    2,    4,    3,    4,    3,
    1,    0,    1,    1,    1,    1,
};
static const YYINT yydefred[] = {                         2,
    0,    5,    6,    8,    7,    1,    3,    0,    0,    0,
    9,    0,    4,    0,    0,    0,    0,    0,    0,    0,
    0,   53,   54,   55,   56,    0,    0,   42,   45,   10,
    0,   33,    0,   37,   30,   31,   28,    0,   34,   38,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   35,
   39,    0,   29,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   15,   16,   17,    0,
    0,    0,    0,    0,   49,    0,   48,    0,    0,   47,
};
static const YYINT yydgoto[] = {                          1,
    6,    7,    8,   10,   11,   26,   27,   44,   28,   65,
   29,
};
static const YYINT yysindex[] = {                         0,
 -192,    0,    0,    0,    0,    0,    0, -280,  -53,  -40,
    0,  -33,    0, -280, -273, -268,  -33,  -33,  -33,  -33,
  -35,    0,    0,    0,    0,  140,  -58,    0,    0,    0,
  -71,    0,  -71,    0,    0,    0,    0,   86,    0,    0,
  -33,  -33,  -33,  -42,  -33,  -33,  -33,  -33,  -33,  -33,
  -33,  -33,  -33,  -33,  -33,  -33,  -33,  -33,  -33,    0,
    0,  -33,    0,  140,    2,  102,  140,  -33,   38,   38,
  504,  504,  441,  185,  -36,  -36,    0,    0,    0,   38,
   38,  468,  452,  140,    0,  -33,    0,  114,  140,    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,  -29,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   -9,    0,    0,    0,    0,   -7,   17,    0,    0,    0,
   49,    0,   75,    0,    0,    0,    0,    0,    0,    0,
    3,    0,    0,  -20,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   30,    0,    0,  -28,    0,  276,  363,
   62,  264,  280,  125,  153,  244,    0,    0,    0,  407,
  414,  367,  317,    4,    0,    0,    0,    0,   54,    0,
};
static const YYINT yygindex[] = {                         0,
    0,    0,    0,    0,   43,  559,   73,    0,    0,    0,
    0,
};
#define YYTABLESIZE 781
static const YYINT yytable[] = {                         19,
   55,    9,   62,   14,   41,   53,   20,   12,   31,   17,
   54,   18,   40,   33,   11,   40,   46,   46,   13,   42,
   46,   46,   46,   46,   46,   43,   46,   43,   43,   11,
   40,   43,   43,   43,   43,   43,   12,   43,   46,   46,
   46,   46,   85,   52,   41,   86,   52,   41,   68,   43,
   43,   12,   43,   44,   44,   42,   30,   44,   44,   44,
   44,   44,   41,   44,   40,    2,    3,    4,    5,    0,
   51,    0,   46,   51,   55,   44,   44,    0,   44,   53,
   51,    0,   52,   43,   54,   32,   32,   32,   34,   32,
   32,   32,   32,   32,   50,   32,   41,   50,    0,   22,
    0,    0,   22,   46,    0,   22,    0,   32,   32,   44,
   32,   36,   36,    0,   43,   36,   36,   36,   36,   36,
   22,   36,   55,   58,    0,    0,   63,   53,   51,    0,
   52,    0,   54,   36,   36,    0,   36,    0,   55,   58,
   44,   32,    0,   53,   51,   56,   52,   57,   54,    0,
   55,   58,    0,    0,   22,   53,   51,    0,   52,    0,
   54,   56,    0,   57,    0,   25,    0,   36,   25,    0,
    0,    0,   32,   56,    0,   57,   55,   58,    0,    0,
    0,   53,   51,   25,   52,   22,   54,    0,    0,    0,
   13,    0,    0,   13,   87,   13,   13,   13,   36,   56,
    0,   57,    0,    0,    0,    0,   90,    0,    0,   59,
    0,   13,   13,    0,   13,   60,   61,   25,    0,    0,
    0,   55,   58,    0,    0,   59,   53,   51,    0,   52,
    0,   54,    0,    0,    0,    0,    0,   59,   39,   40,
   15,   16,    0,    0,   56,   13,   57,    0,   21,   22,
   23,   24,   25,   46,   46,   46,   46,   46,   46,   46,
   46,    0,    0,   59,    0,    0,   43,   43,   43,   43,
   43,   43,    0,    0,    0,    0,   13,    0,    0,    0,
    0,   14,    0,    0,   14,    0,   14,   14,   14,    0,
    0,    0,   44,   44,   44,   44,   44,   44,    0,    0,
    0,   23,   14,   14,   23,   14,    0,   23,   59,    0,
    0,    0,    0,   19,    0,    0,   19,    0,    0,   19,
   24,    0,   23,   24,   32,   32,   32,   32,   32,   32,
    0,    0,    0,    0,   19,   19,   14,   19,   24,   22,
   22,   22,   22,    0,    0,    0,    0,    0,    0,    0,
   36,   36,   36,   36,   36,   36,   23,   27,    0,    0,
   27,   45,   46,   47,   48,   49,   50,   14,   19,    0,
    0,    0,   24,    0,    0,   27,    0,   45,   46,   47,
   48,   49,   50,    0,    0,    0,    0,   23,    0,   45,
   46,   47,   48,   49,   50,    0,    0,    0,    0,   19,
   21,    0,    0,   21,   26,   25,   21,   26,    0,   27,
   26,    0,    0,    0,    0,   45,   46,   47,   48,   49,
   50,   21,   21,    0,   21,   26,    0,    0,   13,   13,
   13,   13,   13,   13,    0,    0,    0,    0,    0,    0,
   27,    0,    0,    0,   18,    0,    0,   18,    0,    0,
   18,   20,    0,    0,   20,   21,    0,   20,    0,   26,
   45,   46,   47,   48,   49,   18,   18,    0,   18,    0,
    0,    0,   20,   20,    0,   20,    0,   55,   58,    0,
    0,    0,   53,   51,    0,   52,   21,   54,   55,   58,
   26,    0,    0,   53,   51,    0,   52,    0,   54,   18,
   56,    0,   57,    0,   55,    0,   20,    0,    0,   53,
   51,   56,   52,   57,   54,    0,    0,    0,    0,   14,
   14,   14,   14,   14,   14,    0,    0,   56,    0,   57,
   18,    0,    0,    0,    0,    0,    0,   20,    0,    0,
   55,   23,   23,   23,   23,   53,   51,    0,   52,    0,
   54,   19,   19,   19,   19,   19,   19,    0,    0,   24,
   24,    0,    0,   56,   59,   57,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   35,   36,   37,   38,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   27,   27,    0,   64,
   66,   67,    0,   69,   70,   71,   72,   73,   74,   75,
   76,   77,   78,   79,   80,   81,   82,   83,    0,    0,
   84,    0,    0,    0,    0,    0,   88,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   21,   21,
   21,   21,   21,   21,   89,    0,   26,   26,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   18,   18,   18,   18,   18,   18,    0,   20,
   20,   20,   20,   20,   20,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   45,   46,   47,   48,
    0,    0,    0,    0,    0,    0,    0,   45,   46,   47,
   48,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   45,   46,   47,   48,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   45,
   46,
};
static const YYINT yycheck[] = {                         33,
   37,  282,   61,   44,   40,   42,   40,   61,  282,   43,
   47,   45,   41,  282,   44,   44,   37,   38,   59,   91,
   41,   42,   43,   44,   45,   61,   47,   37,   38,   59,
   59,   41,   42,   43,   44,   45,   44,   47,   59,   60,
   61,   62,   41,   41,   41,   44,   44,   44,   91,   59,
   60,   59,   62,   37,   38,   91,   14,   41,   42,   43,
   44,   45,   59,   47,   93,  258,  259,  260,  261,   -1,
   41,   -1,   93,   44,   37,   59,   60,   -1,   62,   42,
   43,   -1,   45,   93,   47,   37,   38,   15,   16,   41,
   42,   43,   44,   45,   41,   47,   93,   44,   -1,   38,
   -1,   -1,   41,  124,   -1,   44,   -1,   59,   60,   93,
   62,   37,   38,   -1,  124,   41,   42,   43,   44,   45,
   59,   47,   37,   38,   -1,   -1,   41,   42,   43,   -1,
   45,   -1,   47,   59,   60,   -1,   62,   -1,   37,   38,
  124,   93,   -1,   42,   43,   60,   45,   62,   47,   -1,
   37,   38,   -1,   -1,   93,   42,   43,   -1,   45,   -1,
   47,   60,   -1,   62,   -1,   41,   -1,   93,   44,   -1,
   -1,   -1,  124,   60,   -1,   62,   37,   38,   -1,   -1,
   -1,   42,   43,   59,   45,  124,   47,   -1,   -1,   -1,
   38,   -1,   -1,   41,   93,   43,   44,   45,  124,   60,
   -1,   62,   -1,   -1,   -1,   -1,   93,   -1,   -1,  124,
   -1,   59,   60,   -1,   62,  274,  275,   93,   -1,   -1,
   -1,   37,   38,   -1,   -1,  124,   42,   43,   -1,   45,
   -1,   47,   -1,   -1,   -1,   -1,   -1,  124,  274,  275,
  274,  275,   -1,   -1,   60,   93,   62,   -1,  282,  283,
  284,  285,  286,  274,  275,  276,  277,  278,  279,  280,
  281,   -1,   -1,  124,   -1,   -1,  276,  277,  278,  279,
  280,  281,   -1,   -1,   -1,   -1,  124,   -1,   -1,   -1,
   -1,   38,   -1,   -1,   41,   -1,   43,   44,   45,   -1,
   -1,   -1,  276,  277,  278,  279,  280,  281,   -1,   -1,
   -1,   38,   59,   60,   41,   62,   -1,   44,  124,   -1,
   -1,   -1,   -1,   38,   -1,   -1,   41,   -1,   -1,   44,
   41,   -1,   59,   44,  276,  277,  278,  279,  280,  281,
   -1,   -1,   -1,   -1,   59,   60,   93,   62,   59,  278,
  279,  280,  281,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  276,  277,  278,  279,  280,  281,   93,   41,   -1,   -1,
   44,  276,  277,  278,  279,  280,  281,  124,   93,   -1,
   -1,   -1,   93,   -1,   -1,   59,   -1,  276,  277,  278,
  279,  280,  281,   -1,   -1,   -1,   -1,  124,   -1,  276,
  277,  278,  279,  280,  281,   -1,   -1,   -1,   -1,  124,
   38,   -1,   -1,   41,   38,  281,   44,   41,   -1,   93,
   44,   -1,   -1,   -1,   -1,  276,  277,  278,  279,  280,
  281,   59,   60,   -1,   62,   59,   -1,   -1,  276,  277,
  278,  279,  280,  281,   -1,   -1,   -1,   -1,   -1,   -1,
  124,   -1,   -1,   -1,   38,   -1,   -1,   41,   -1,   -1,
   44,   38,   -1,   -1,   41,   93,   -1,   44,   -1,   93,
  276,  277,  278,  279,  280,   59,   60,   -1,   62,   -1,
   -1,   -1,   59,   60,   -1,   62,   -1,   37,   38,   -1,
   -1,   -1,   42,   43,   -1,   45,  124,   47,   37,   38,
  124,   -1,   -1,   42,   43,   -1,   45,   -1,   47,   93,
   60,   -1,   62,   -1,   37,   -1,   93,   -1,   -1,   42,
   43,   60,   45,   62,   47,   -1,   -1,   -1,   -1,  276,
  277,  278,  279,  280,  281,   -1,   -1,   60,   -1,   62,
  124,   -1,   -1,   -1,   -1,   -1,   -1,  124,   -1,   -1,
   37,  278,  279,  280,  281,   42,   43,   -1,   45,   -1,
   47,  276,  277,  278,  279,  280,  281,   -1,   -1,  280,
  281,   -1,   -1,   60,  124,   62,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   17,   18,   19,   20,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  280,  281,   -1,   41,
   42,   43,   -1,   45,   46,   47,   48,   49,   50,   51,
   52,   53,   54,   55,   56,   57,   58,   59,   -1,   -1,
   62,   -1,   -1,   -1,   -1,   -1,   68,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  276,  277,
  278,  279,  280,  281,   86,   -1,  280,  281,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  276,  277,  278,  279,  280,  281,   -1,  276,
  277,  278,  279,  280,  281,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  276,  277,  278,  279,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  276,  277,  278,
  279,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  276,  277,  278,  279,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  276,
  277,
};
#define YYFINAL 1
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 290
#define YYUNDFTOKEN 304
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
"UMINUS","SUFFIX_INCRE","SUFFIX_DECRE",0,0,0,0,0,0,0,0,0,0,0,0,0,
"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : program",
"program : program var_decl",
"program :",
"var_decl : scalar_decl",
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
#line 404 "parser.y"


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
#line 472 "y.tab.c"

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
#line 66 "parser.y"
	{

	}
break;
case 2:
#line 78 "parser.y"
	{}
break;
case 3:
#line 81 "parser.y"
	{

	}
break;
case 4:
#line 87 "parser.y"
	{

		printf("<scalar_decl>%s%s;</scalar_decl>", yystack.l_mark[-2].sVal, yystack.l_mark[-1].sVal);

	}
break;
case 10:
#line 97 "parser.y"
	{

		strcpy(yyval.sVal, yystack.l_mark[-2].sVal);
		strcat(yyval.sVal, yystack.l_mark[-1].sVal);
		strcat(yyval.sVal, yystack.l_mark[0].sVal);

	}
break;
case 12:
#line 107 "parser.y"
	{
		
		sprintf(temp, "%s=<expr>%s</expr>", yystack.l_mark[-2].sVal, yystack.l_mark[0].sVal);
		strcpy(yyval.sVal, temp);

	}
break;
case 13:
#line 116 "parser.y"
	{

		sprintf(temp, "<expr>%s</expr>+<expr>%s</expr>", yystack.l_mark[-2].sVal, yystack.l_mark[0].sVal);
		strcpy(yyval.sVal, temp);

	}
break;
case 14:
#line 123 "parser.y"
	{

                sprintf(temp, "<expr>%s</expr>-<expr>%s</expr>", yystack.l_mark[-2].sVal, yystack.l_mark[0].sVal);
		strcpy(yyval.sVal, temp);

	}
break;
case 15:
#line 130 "parser.y"
	{

		sprintf(temp, "<expr>%s</expr>*<expr>%s</expr>", yystack.l_mark[-2].sVal, yystack.l_mark[0].sVal);
		strcpy(yyval.sVal, temp);

	}
break;
case 16:
#line 137 "parser.y"
	{

                sprintf(temp, "<expr>%s</expr>/<expr>%s</expr>", yystack.l_mark[-2].sVal, yystack.l_mark[0].sVal);
		strcpy(yyval.sVal, temp);

        }
break;
case 17:
#line 144 "parser.y"
	{

                sprintf(temp, "<expr>%s</expr>%%<expr>%s</expr>", yystack.l_mark[-2].sVal, yystack.l_mark[0].sVal);
		strcpy(yyval.sVal, temp);

        }
break;
case 18:
#line 151 "parser.y"
	{

                sprintf(temp, "<expr>%s</expr><<expr>%s</expr>", yystack.l_mark[-2].sVal, yystack.l_mark[0].sVal);
		strcpy(yyval.sVal, temp);

        }
break;
case 19:
#line 158 "parser.y"
	{

		sprintf(temp, "<expr>%s</expr><=<expr>%s</expr>", yystack.l_mark[-2].sVal, yystack.l_mark[0].sVal);
		strcpy(yyval.sVal, temp);

        }
break;
case 20:
#line 165 "parser.y"
	{

                sprintf(temp, "<expr>%s</expr>><expr>%s</expr>", yystack.l_mark[-2].sVal, yystack.l_mark[0].sVal);
		strcpy(yyval.sVal, temp);

        }
break;
case 21:
#line 172 "parser.y"
	{

                sprintf(temp, "<expr>%s</expr>>=<expr>%s</expr>", yystack.l_mark[-2].sVal, yystack.l_mark[0].sVal);
		strcpy(yyval.sVal, temp);

        }
break;
case 22:
#line 179 "parser.y"
	{

                sprintf(temp, "<expr>%s</expr>==<expr>%s</expr>", yystack.l_mark[-2].sVal, yystack.l_mark[0].sVal);
		strcpy(yyval.sVal, temp);

        }
break;
case 23:
#line 186 "parser.y"
	{

                sprintf(temp, "<expr>%s</expr>!=<expr>%s</expr>", yystack.l_mark[-2].sVal, yystack.l_mark[0].sVal);
		strcpy(yyval.sVal, temp);

        }
break;
case 24:
#line 193 "parser.y"
	{

                sprintf(temp, "<expr>%s</expr>&&<expr>%s</expr>", yystack.l_mark[-2].sVal, yystack.l_mark[0].sVal);
		strcpy(yyval.sVal, temp);
        }
break;
case 25:
#line 199 "parser.y"
	{

                sprintf(temp, "<expr>%s</expr>||<expr>%s</expr>", yystack.l_mark[-2].sVal, yystack.l_mark[0].sVal);
		strcpy(yyval.sVal, temp);		

        }
break;
case 26:
#line 206 "parser.y"
	{

                sprintf(temp, "<expr>%s</expr>&<expr>%s</expr>", yystack.l_mark[-2].sVal, yystack.l_mark[0].sVal);
                strcpy(yyval.sVal, temp);

        }
break;
case 27:
#line 213 "parser.y"
	{

                sprintf(temp, "<expr>%s</expr>|<expr>%s</expr>", yystack.l_mark[-2].sVal, yystack.l_mark[0].sVal);
		strcpy(yyval.sVal, temp);

        }
break;
case 28:
#line 220 "parser.y"
	{

		sprintf(temp, "!<expr>%s</expr>", yystack.l_mark[0].sVal);
                strcpy(yyval.sVal, temp);

        }
break;
case 29:
#line 227 "parser.y"
	{
                
                sprintf(temp, "(<expr>%s</expr>)", yystack.l_mark[-1].sVal);
		strcpy(yyval.sVal, temp);

	}
break;
case 30:
#line 234 "parser.y"
	{

                sprintf(temp, "+<expr>%s</expr>", yystack.l_mark[0].sVal);
		strcpy(yyval.sVal, temp);

        }
break;
case 31:
#line 241 "parser.y"
	{

                sprintf(temp, "-<expr>%s</expr>", yystack.l_mark[0].sVal);
		strcpy(yyval.sVal, temp);

        }
break;
case 32:
#line 248 "parser.y"
	{

		strcpy(yyval.sVal, yystack.l_mark[-1].sVal);
		strcat(yyval.sVal, yystack.l_mark[0].sVal);

	}
break;
case 33:
#line 255 "parser.y"
	{

                strcpy(yyval.sVal, yystack.l_mark[-1].sVal);
                strcat(yyval.sVal, yystack.l_mark[0].sVal);

	}
break;
case 34:
#line 262 "parser.y"
	{

                strcpy(yyval.sVal, yystack.l_mark[-1].sVal);
                strcat(yyval.sVal, yystack.l_mark[0].sVal);

	}
break;
case 35:
#line 269 "parser.y"
	{

                strcpy(yyval.sVal, yystack.l_mark[-1].sVal);
                strcat(yyval.sVal, yystack.l_mark[0].sVal);

	}
break;
case 36:
#line 276 "parser.y"
	{

                strcpy(yyval.sVal, yystack.l_mark[-1].sVal);
                strcat(yyval.sVal, yystack.l_mark[0].sVal);

        }
break;
case 37:
#line 283 "parser.y"
	{

                strcpy(yyval.sVal, yystack.l_mark[-1].sVal);
                strcat(yyval.sVal, yystack.l_mark[0].sVal);

        }
break;
case 38:
#line 290 "parser.y"
	{

                strcpy(yyval.sVal, yystack.l_mark[-1].sVal);
                strcat(yyval.sVal, yystack.l_mark[0].sVal);

        }
break;
case 39:
#line 297 "parser.y"
	{

                strcpy(yyval.sVal, yystack.l_mark[-1].sVal);
                strcat(yyval.sVal, yystack.l_mark[0].sVal);

        }
break;
case 40:
#line 304 "parser.y"
	{

                sprintf(temp, "%s=<expr>%s</expr>", yystack.l_mark[-2].sVal, yystack.l_mark[0].sVal);
		strcpy(yyval.sVal, temp);

	}
break;
case 41:
#line 311 "parser.y"
	{

                sprintf(temp, "%s=<expr>%s</expr>", yystack.l_mark[-2].sVal, yystack.l_mark[0].sVal);
		strcpy(yyval.sVal, temp);

	}
break;
case 46:
#line 326 "parser.y"
	{

                strcpy(yyval.sVal, yystack.l_mark[-1].sVal);
                strcat(yyval.sVal, yystack.l_mark[0].sVal);

	}
break;
case 47:
#line 333 "parser.y"
	{

		sprintf(temp, "%s[<expr>%s</expr>]", yystack.l_mark[-3].sVal, yystack.l_mark[-1].sVal);
		strcpy(yyval.sVal, temp);

	}
break;
case 48:
#line 340 "parser.y"
	{

		sprintf(temp, "[<expr>%s</expr>]", yystack.l_mark[-1].sVal);
		strcpy(yyval.sVal, temp);

	}
break;
case 49:
#line 347 "parser.y"
	{

                strcpy(yyval.sVal, yystack.l_mark[-3].sVal);
                strcat(yyval.sVal, yystack.l_mark[-2].sVal);
                strcat(yyval.sVal, yystack.l_mark[-1].sVal);
		strcat(yyval.sVal, yystack.l_mark[0].sVal);

	}
break;
case 50:
#line 356 "parser.y"
	{

		sprintf(temp, "%s,<expr>%s</expr>", yystack.l_mark[-2].sVal, yystack.l_mark[0].sVal);
		strcpy(yyval.sVal, temp);

	}
break;
case 51:
#line 363 "parser.y"
	{

		sprintf(temp, "<expr>%s</expr>", yystack.l_mark[0].sVal);
		strcpy(yyval.sVal, temp);

	}
break;
case 52:
#line 370 "parser.y"
	{}
break;
case 53:
#line 372 "parser.y"
	{

		sprintf(temp, "%d", yystack.l_mark[0].iVal);
		strcpy(yyval.sVal, temp);

	}
break;
case 54:
#line 379 "parser.y"
	{

		sprintf(temp, "%f", yystack.l_mark[0].dVal);
		strcpy(yyval.sVal, temp);

	}
break;
case 55:
#line 386 "parser.y"
	{

		if (strcmp(yystack.l_mark[0].sVal, "\\\\") == 0)
			sprintf(temp, "%s", "\\");
		else if (strcmp(yystack.l_mark[0].sVal, "\\'") == 0)
			sprintf(temp, "%s", "'");

		strcpy(yyval.sVal, temp);

	}
break;
#line 1068 "y.tab.c"
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
