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
extern YYSTYPE yylval;
