%{
   #include <stdio.h>

   /* helper variable */
   int line_count = 0;
   char line_content[1000];

   int source_enable = 1;
   int token_enable = 1;

   /* function declaration */
   void printTokenType(const char t);
   void printLine();
   void append_line_content();
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

{KEYWORD} { printTokenType('k'); append_line_content(); }

(_|{CHAR})(_|{CHAR}|{DIGIT})* { printTokenType('i'); append_line_content(); }

{OPERATOR} { printTokenType('o'); append_line_content(); }

{PUNC} { printTokenType('p'); append_line_content(); }

[\+-]?{DIGIT}+ { printTokenType('n'); append_line_content(); }

[\+-]?({FLOAT_1}|{FLOAT_2}|{FLOAT_3}) { printTokenType('d'); append_line_content(); }

\" { BEGIN STRING_START; yymore(); }
<STRING_START>({PRINTABLE_EXCEPT_QUOT_D}|{ESC_QUOT_D}|{TAB})*(\") { printTokenType('s');
								    append_line_content();
			    			 	      	    BEGIN 0; }

\' { BEGIN CHAR_START; yymore(); }
<CHAR_START>({CHAR_1}|{CHAR_2}|{CHAR_3})(\') { printTokenType('c'); append_line_content();
				      	       BEGIN 0; }

\/\/(.)* { append_line_content(); }

\/\* { BEGIN LONG_COMMENT_START; yymore(); }
<LONG_COMMENT_START>({PRINTABLE_EXCEPT_STAR}|{TAB})* { append_line_content(); }
<LONG_COMMENT_START>{STAR_NOT_SLASH} { append_line_content(); }
<LONG_COMMENT_START>(\*\/) { append_line_content(); BEGIN 0; }
<LONG_COMMENT_START>{NEXT_LINE} { line_count += 1;
				  printLine();
				  line_content[0] = '\0'; }

#{SPACES}pragma{SPACES}source{SPACES}on { source_enable = 1; }
#{SPACES}pragma{SPACES}source{SPACES}off { source_enable = 0; }
#{SPACES}pragma{SPACES}token{SPACES}on { token_enable = 1; }
#{SPACES}pragma{SPACES}token{SPACES}off { token_enable = 0; }


({SPACE}|{TAB})* { append_line_content(); }
{NEXT_LINE} { line_count += 1; printLine(); line_content[0] = '\0'; }

%%


int main(int argc, char* argv[])
{
  line_content[0] = '\0';

  // read input from file or command line
  if (argc > 1) {
    yyin = fopen(argv[1], "r");
  } 
  else {
    yyin = stdin;
  }

  // parsing
  yylex();
  
  return 0;
}

void printTokenType(const char t)
{
  if (!token_enable)
    return;

  printf("#token ");

  switch(t)
  {
    case 'k':
      printf("key");
      break;
    case 'i':
      printf("id");
      break;
    case 'o':
      printf("op");
      break;
    case 'p':
      printf("punc");
      break;
    case 'n':
      printf("integer");
      break;
    case 'd':
      printf("double");
      break;
    case 'c':
      printf("char");
      break;
    case 's':
      printf("string");
      break;

    default:
      printf("{error}");
  };

  printf(":%s\n", yytext);
}

void printLine()
{
  if (!source_enable)
    return;

  printf("%d:%s\n", line_count, line_content);
}

void append_line_content()
{
  strcat(line_content, yytext);
}
