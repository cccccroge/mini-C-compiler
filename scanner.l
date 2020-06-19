%{
   #include "y.tab.h"
   #include <string.h>
   #include <stdlib.h>

   int line_count;
%}


KEYWORD (void|const|NULL|for|do|while|break|continue|if|else|return|struct|switch|case|default|int|double|float|char|fclose|clearerr|feof|ferror|fflush|fgetpos|fopen|fread|freopen|fseek|fsetpos|ftell|fwrite|remove|rename|rewind|setbuf|setvbuf|tmpfile|tmpnam|fprintf|printf|sprintf|vfprintf|vprintf|vsprintf|fscanf|scanf|sscanf|fgetc|fgets|fputc|fputs|getc|getchar|gets|putc|putchar|puts|ungetc|perror)

OPERATOR (\+|-|\*|\/|%|\+\+|--|<|<=|>|>=|==|!=|=|&&|\|\||!|&|\|) 

PUNC [:;,\.\[\]\(\)\{\}]

CHAR	 [a-zA-Z]
ESC_QUOT_D (\\\")
ESC_QUOT_S (\\')
PRINTABLE_EXCEPT_QUOT_D [\40-\41\43-\176]
PRINTABLE_EXCEPT_QUOT_S [\40-\46\50-\176]
PRINTABLE_EXCEPT_STAR [\40-\51\53-\176]
PRINTABLE [\40-\176]
STAR_NOT_SLASH (\*([^\/])?)

TAB (\t)
NEXT_LINE (\n)
SPACE ([ ])
SPACES ({TAB}|{SPACE})*

DIGIT	 [0-9]

FLOAT_1	 ({DIGIT}+)\.({DIGIT}+)
FLOAT_2	 ({DIGIT}+)\.
FLOAT_3	 \.({DIGIT}+)

CHAR_1 (\\)?{PRINTABLE_EXCEPT_QUOT_S}
CHAR_2 {ESC_QUOT_S}
CHAR_3 {TAB}

%x STRING_START
%x CHAR_START
%x LONG_COMMENT_START


%%

void {

	strcpy(yylval.sVal, yytext);
	return VOID;	

}

const {

	strcpy(yylval.sVal, yytext);
	return CONST;

}

for {

	strcpy(yylval.sVal, yytext);
        return FOR;

}

do {

	strcpy(yylval.sVal, yytext);
        return DO;

}

while {

	strcpy(yylval.sVal, yytext);
        return WHILE;

}

break {

	strcpy(yylval.sVal, yytext);
        return BREAK;

}

continue {

	strcpy(yylval.sVal, yytext);
        return CONTINUE;

}

if {

	strcpy(yylval.sVal, yytext);
        return IF;

}

else {

	strcpy(yylval.sVal, yytext);
        return ELSE;

}

return {

	strcpy(yylval.sVal, yytext);
        return RETURN;

}

switch {

	strcpy(yylval.sVal, yytext);
        return SWITCH;

}

case {

	strcpy(yylval.sVal, yytext);
        return CASE;

}

default {

	strcpy(yylval.sVal, yytext);
        return DEFAULT;

}

int {

	strcpy(yylval.sVal, yytext);
        return INT;

}

float {

	strcpy(yylval.sVal, yytext);
        return FLOAT;

}

char {

	strcpy(yylval.sVal, yytext);
        return CHAR;

}

double {

	strcpy(yylval.sVal, yytext);
        return DOUBLE;

}

(\+|-|\*|\/|%|<|>|=|!|&|\||\(|\)|\[|\]|\{|\}|:|;|,) {

	strcpy(yylval.sVal, yytext);
	return yylval.sVal[0];

}

"++" {

	strcpy(yylval.sVal, yytext);
	return INCRE;

}

"--" {

	strcpy(yylval.sVal, yytext);
        return DECRE;

}

"<=" {

	strcpy(yylval.sVal, yytext);
        return LESS_EQ;

}

">=" {

	strcpy(yylval.sVal, yytext);
        return GREAT_EQ;

}

"==" {

        strcpy(yylval.sVal, yytext);
        return EQUAL;

}

"!=" {

	strcpy(yylval.sVal, yytext);
        return NOT_EQ;

}

"&&" {

	strcpy(yylval.sVal, yytext);
        return LOG_AND;

}

"||" {

	strcpy(yylval.sVal, yytext);
        return LOG_OR;

}

(_|{CHAR})(_|{CHAR}|{DIGIT})* {


        strcpy(yylval.sVal, yytext);	
	return ID;

}

{DIGIT}+ {

	yylval.iVal = atoi(yytext);
	return NUM_INT;

}

({FLOAT_1}|{FLOAT_2}|{FLOAT_3}) {

	yylval.dVal = (double) atof(yytext);
	return NUM_FLOATING;

}

\" { BEGIN STRING_START; yymore(); }
<STRING_START>({PRINTABLE_EXCEPT_QUOT_D}|{ESC_QUOT_D}|{TAB})*(\") {

	BEGIN 0;

	strcpy(yylval.sVal, yytext);
	return STRING;

}

\' { BEGIN CHAR_START; yymore(); }
<CHAR_START>({CHAR_1}|{CHAR_2}|{CHAR_3})(\') {

	BEGIN 0;

	strcpy(yylval.sVal, yytext);
	return CHARACTER;	

}


\/\/(.)* {

	// ignore: single line comment

}


\/\* { BEGIN LONG_COMMENT_START;  }
<LONG_COMMENT_START>({PRINTABLE_EXCEPT_STAR}|{TAB})* {  }
<LONG_COMMENT_START>{STAR_NOT_SLASH} {  }
<LONG_COMMENT_START>(\*\/) {  

	// ingore: multiple line comment
	BEGIN 0;

}
<LONG_COMMENT_START>{NEXT_LINE} { }


({SPACE}|{TAB})* {

	// ignore: space, tab (not inside literals)
}


{NEXT_LINE} {

	line_count += 1;

}

%%

