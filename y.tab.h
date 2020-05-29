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
extern YYSTYPE yylval;
