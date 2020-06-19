%{

   #include <string.h>
   #include <stdio.h>
   #include <stdlib.h>

   int yylex();
   char temp[1000000];

   extern int line_count;

%}


%union{

	int iVal;
	double dVal;
	char sVal[100000];

}


/* Terminal type */
%token <sVal> VOID INT FLOAT CHAR DOUBLE CONST
%token <sVal> FOR DO WHILE BREAK CONTINUE IF ELSE RETURN SWITCH CASE DEFAULT

%token <sVal> INCRE DECRE LESS_EQ GREAT_EQ EQUAL NOT_EQ LOG_AND LOG_OR
%token <sVal> '+' '-' '*' '/' '%' '<' '>' '!' '&' '|' '(' ')' '[' ']' '{' '}' ':' ';' ',' '='

%token <sVal> ID

%token <iVal> NUM_INT
%token <dVal> NUM_FLOATING

%token <sVal> CHARACTER STRING


/* Non-terminal type */
%type <sVal> program var_decl scalar_decl const_decl var_type init_list init_unit
%type <sVal> expr id_arr_access access_list func_invoc argument_list literal
%type <sVal> array_decl init_list_arr init_unit_arr id_arr_decl arr_decl_list arr_content expr_list arr_content_list
%type <sVal> func_decl param_list param_unit
%type <sVal> statement statements compound_statement statement_var_decls statement_var_decl
%type <sVal> stmt_expression stmt_if stmt_switch switch_clauses switch_clause stmt_while stmt_for expr_empty
%type <sVal> stmt_return stmt_break stmt_continue
%type <sVal> func_def

/* Precedence (low to high) & Association */
%left ','
%right '='
%left LOG_OR
%left LOG_AND
%left '|'
%left '&'
%left EQUAL NOT_EQ
%left '<' '>' LESS_EQ GREAT_EQ
%left '+' '-'
%left '*' '/' '%'
%right UPLUS UMINUS INCRE DECRE '!'
%left '[' ']' '(' ')' SUFFIX_INCRE SUFFIX_DECRE 


%start program_plum


%%

/**********************************************/

program_plum: program {

		printf("%s", $1);

	};

program: program var_decl {

		sprintf(temp, "%s%s", $1, $2);
                strcpy($$, temp);

	}

	| program func_decl {

		sprintf(temp, "%s<func_decl>%s</func_decl>", $1, $2);
                strcpy($$, temp);

	}

	| program func_def {

		sprintf(temp, "%s<func_def>%s</func_def>", $1, $2);
                strcpy($$, temp);

	}

	|  {} ;


var_decl: scalar_decl {

		sprintf(temp, "<scalar_decl>%s</scalar_decl>", $1);
		strcpy($$, temp);

	}
	
	| array_decl {

		sprintf(temp, "<array_decl>%s</array_decl>", $1);
		strcpy($$, temp);

	}
	
	| const_decl {

		sprintf(temp, "<const_decl>%s</const_decl>", $1);
		strcpy($$, temp);

	};

/**********************************************/

scalar_decl: var_type init_list ';' {

		sprintf(temp, "%s%s;", $1, $2);
		strcpy($$, temp);

	};

var_type: INT | FLOAT | DOUBLE | CHAR ;

init_list: init_unit

	| init_list ',' init_unit {

		strcpy($$, $1);
		strcat($$, $2);
		strcat($$, $3);

	};

init_unit: ID

	| ID '=' expr {
		
		sprintf(temp, "%s=<expr>%s</expr>", $1, $3);
		strcpy($$, temp);

	};

/**********************************************/

expr: expr '+' expr {

		sprintf(temp, "<expr>%s</expr>+<expr>%s</expr>", $1, $3);
		strcpy($$, temp);

	}

	| expr '-' expr {

                sprintf(temp, "<expr>%s</expr>-<expr>%s</expr>", $1, $3);
		strcpy($$, temp);

	}

	| expr '*' expr {

		sprintf(temp, "<expr>%s</expr>*<expr>%s</expr>", $1, $3);
		strcpy($$, temp);

	}

	| expr '/' expr {

                sprintf(temp, "<expr>%s</expr>/<expr>%s</expr>", $1, $3);
		strcpy($$, temp);

        }

        | expr '%' expr {

                sprintf(temp, "<expr>%s</expr>%%<expr>%s</expr>", $1, $3);
		strcpy($$, temp);

        }

        | expr '<' expr {

                sprintf(temp, "<expr>%s</expr><<expr>%s</expr>", $1, $3);
		strcpy($$, temp);

        }

        | expr LESS_EQ expr {

		sprintf(temp, "<expr>%s</expr><=<expr>%s</expr>", $1, $3);
		strcpy($$, temp);

        }

        | expr '>' expr {

                sprintf(temp, "<expr>%s</expr>><expr>%s</expr>", $1, $3);
		strcpy($$, temp);

        }

        | expr GREAT_EQ expr {

                sprintf(temp, "<expr>%s</expr>>=<expr>%s</expr>", $1, $3);
		strcpy($$, temp);

        }

        | expr EQUAL expr {

                sprintf(temp, "<expr>%s</expr>==<expr>%s</expr>", $1, $3);
		strcpy($$, temp);

        }

        | expr NOT_EQ expr {

                sprintf(temp, "<expr>%s</expr>!=<expr>%s</expr>", $1, $3);
		strcpy($$, temp);

        }

        | expr LOG_AND expr {

                sprintf(temp, "<expr>%s</expr>&&<expr>%s</expr>", $1, $3);
		strcpy($$, temp);
        }

        | expr LOG_OR expr {

                sprintf(temp, "<expr>%s</expr>||<expr>%s</expr>", $1, $3);
		strcpy($$, temp);		

        }

        | expr '&' expr {

                sprintf(temp, "<expr>%s</expr>&<expr>%s</expr>", $1, $3);
                strcpy($$, temp);

        }

        | expr '|' expr {

                sprintf(temp, "<expr>%s</expr>|<expr>%s</expr>", $1, $3);
		strcpy($$, temp);

        }

        | '!' expr {

		sprintf(temp, "!<expr>%s</expr>", $2);
                strcpy($$, temp);

        }

	| '(' expr ')' {
                
                sprintf(temp, "(<expr>%s</expr>)", $2);
		strcpy($$, temp);

	}

        | '+' expr %prec UPLUS {

                sprintf(temp, "+<expr>%s</expr>", $2);
		strcpy($$, temp);

        }

        | '-' expr %prec UMINUS {

                sprintf(temp, "-<expr>%s</expr>", $2);
		strcpy($$, temp);

        }

	| INCRE ID {

		strcpy($$, $1);
		strcat($$, $2);

	}

	| INCRE id_arr_access {

                strcpy($$, $1);
                strcat($$, $2);

	}

	| ID INCRE %prec SUFFIX_INCRE {

                strcpy($$, $1);
                strcat($$, $2);

	}

	| id_arr_access INCRE %prec SUFFIX_INCRE {

                strcpy($$, $1);
                strcat($$, $2);

	}

	| DECRE ID {

                strcpy($$, $1);
                strcat($$, $2);

        }

        | DECRE id_arr_access {

                strcpy($$, $1);
                strcat($$, $2);

        }

        | ID DECRE %prec SUFFIX_DECRE {

                strcpy($$, $1);
                strcat($$, $2);

        }

        | id_arr_access DECRE %prec SUFFIX_DECRE {

                strcpy($$, $1);
                strcat($$, $2);

        }
	
	| ID '=' expr {

                sprintf(temp, "%s=<expr>%s</expr>", $1, $3);
		strcpy($$, temp);

	}

	| id_arr_access '=' expr {

                sprintf(temp, "%s=<expr>%s</expr>", $1, $3);
		strcpy($$, temp);

	}

	| func_invoc

	| ID 

	| id_arr_access 

	| literal ;

id_arr_access: ID access_list {

                strcpy($$, $1);
                strcat($$, $2);

	};

access_list: access_list '[' expr ']' {

		sprintf(temp, "%s[<expr>%s</expr>]", $1, $3);
		strcpy($$, temp);

	}

	| '[' expr ']' {

		sprintf(temp, "[<expr>%s</expr>]", $2);
		strcpy($$, temp);

	};

func_invoc: ID '(' argument_list ')' {

                strcpy($$, $1);
                strcat($$, $2);
                strcat($$, $3);
		strcat($$, $4);

	}

	| ID '(' ')';

argument_list: argument_list ',' expr {

		sprintf(temp, "%s,<expr>%s</expr>", $1, $3);
		strcpy($$, temp);

	}

	| expr {

		sprintf(temp, "<expr>%s</expr>", $1);
		strcpy($$, temp);

	};

literal: NUM_INT {

		sprintf(temp, "%d", $1);
		strcpy($$, temp);

	}

	| NUM_FLOATING {

		sprintf(temp, "%f", $1);
		strcpy($$, temp);

	}

	| CHARACTER {

		if (strcmp($1, "\\\\") == 0)
			sprintf(temp, "%s", "\\");
		else if (strcmp($1, "\\'") == 0)
			sprintf(temp, "%s", "'");

		strcpy($$, temp);

	}

	| STRING ;

/**********************************************/

array_decl: var_type init_list_arr ';' {

		sprintf(temp, "%s%s;", $1, $2);
		strcpy($$, temp);	

	};

init_list_arr: init_unit_arr

	| init_list_arr ',' init_unit_arr {

		sprintf(temp, "%s,%s", $1, $3);
		strcpy($$, temp);

	};

init_unit_arr: id_arr_decl

	| id_arr_decl '=' arr_content {

		sprintf(temp, "%s=%s", $1, $3);
                strcpy($$, temp);

	};

id_arr_decl: ID arr_decl_list {

		strcpy($$, $1);
		strcat($$, $2);

	};

arr_decl_list: arr_decl_list '[' NUM_INT ']' {

		sprintf(temp, "%s[%d]", $1, $3);
		strcpy($$, temp);

	}

	| '[' NUM_INT ']' {

                sprintf(temp, "[%d]", $2);
                strcpy($$, temp);

	};

arr_content: '{' expr_list '}' {

                sprintf(temp, "{%s}", $2);
                strcpy($$, temp);

	}

	| '{' arr_content_list '}' {

                sprintf(temp, "{%s}", $2);
                strcpy($$, temp);

	};

expr_list: expr {

		sprintf(temp, "<expr>%s</expr>", $1);
		strcpy($$, temp);

	}

	| expr_list ',' expr {

		sprintf(temp, "%s,<expr>%s</expr>", $1, $3);
		strcpy($$, temp);

	};

arr_content_list: arr_content

	| arr_content_list ',' arr_content {

		sprintf(temp, "%s,%s", $1, $3);
		strcpy($$, temp);

	};


/**********************************************/

const_decl: CONST var_type init_list ';' {

		sprintf(temp, "%s%s%s;", $1, $2, $3);
                strcpy($$, temp);

	};


func_decl: var_type ID '(' param_list ')' ';' {

		sprintf(temp, "%s%s(%s);", $1, $2, $4);
		strcpy($$, temp);

	}

	| VOID ID '(' param_list ')' ';' {

		sprintf(temp, "%s%s(%s);", $1, $2, $4);
		strcpy($$, temp);

	}
	
	| var_type ID '(' ')' ';' {

		sprintf(temp, "%s%s();", $1, $2);
		strcpy($$, temp);

	}

	| VOID ID '(' ')' ';' {

		sprintf(temp, "%s%s();", $1, $2);
		strcpy($$, temp);

	};

param_list: param_list ',' param_unit {

		sprintf(temp, "%s,%s", $1, $3);
                strcpy($$, temp);

	}
	  
	| param_unit;

param_unit: var_type ID {
	 
		sprintf(temp, "%s%s", $1, $2);
                strcpy($$, temp);

	};

/**********************************************/

statement: stmt_expression

	| stmt_if

	| stmt_switch

	| stmt_while

	| stmt_for

	| stmt_return

	| stmt_break

	| stmt_continue

	| compound_statement;

statements: statements statement {

		sprintf(temp, "%s<stmt>%s</stmt>", $1, $2);
                strcpy($$, temp);

	}

	| statement {

		sprintf(temp, "<stmt>%s</stmt>", $1);
                strcpy($$, temp);
	
	};

compound_statement: '{' '}' {

		sprintf(temp, "{}");
                strcpy($$, temp);

	}

	| '{' statement_var_decls '}' {

		sprintf(temp, "{%s}", $2);
                strcpy($$, temp);

	};

statement_var_decls: statement_var_decls statement_var_decl {

		sprintf(temp, "%s%s", $1, $2);
                strcpy($$, temp);

	}

	| statement_var_decl;

statement_var_decl: statement {

		sprintf(temp, "<stmt>%s</stmt>", $1);
                strcpy($$, temp);

	}

	| var_decl;

/**********************************************/

stmt_expression: expr ';' {

		sprintf(temp, "<expr>%s</expr>;", $1);
                strcpy($$, temp);

	};

stmt_if: IF '(' expr ')' compound_statement {

		sprintf(temp, "%s(<expr>%s</expr>)%s", $1, $3, $5);
                strcpy($$, temp);

	}

	| IF '(' expr ')' compound_statement ELSE compound_statement {

		sprintf(temp, "%s(<expr>%s</expr>)%s%s%s", $1, $3, $5, $6, $7);
                strcpy($$, temp);

	};

stmt_switch: SWITCH '(' expr ')' '{' switch_clauses '}' {

		sprintf(temp, "%s(<expr>%s</expr>){%s}", $1, $3, $6);
                strcpy($$, temp);

	}

	| SWITCH '(' expr ')' '{' '}' {

		sprintf(temp, "%s(<expr>%s</expr>){}", $1, $3);
                strcpy($$, temp);

	};

switch_clauses: switch_clauses switch_clause {

		sprintf(temp, "%s%s", $1, $2);
                strcpy($$, temp);

	}

	| switch_clause;

switch_clause: CASE NUM_INT ':' statements {

		sprintf(temp, "%s%d:%s", $1, $2, $4);
                strcpy($$, temp);

	}

	| CASE NUM_INT ':' {

		sprintf(temp, "%s%d:", $1, $2);
                strcpy($$, temp);

	}

	| DEFAULT ':' statements {

		sprintf(temp, "%s:%s", $1, $3);
                strcpy($$, temp);

	}

	| DEFAULT ':' {

		sprintf(temp, "%s:", $1);
                strcpy($$, temp);

	};

stmt_while: WHILE '(' expr ')' statement {

		sprintf(temp, "%s(<expr>%s</expr>)<stmt>%s</stmt>", $1, $3, $5);
                strcpy($$, temp);

	}

	| DO statement WHILE '(' expr ')' ';' {

		sprintf(temp, "%s<stmt>%s</stmt>%s(<expr>%s</expr>);", $1, $2, $3, $5);
                strcpy($$, temp);

	};

stmt_for: FOR '(' expr_empty ';' expr_empty ';' expr_empty ')' statement {

		sprintf(temp, "%s(%s;%s;%s)<stmt>%s</stmt>", $1, $3, $5, $7, $9);
                strcpy($$, temp);

	};

expr_empty: expr {

		sprintf(temp, "<expr>%s</expr>", $1);
                strcpy($$, temp);

	}

	| {} ;

stmt_return: RETURN ';' {

		sprintf(temp, "%s;", $1);
                strcpy($$, temp);

	}

	| RETURN expr ';' {

		sprintf(temp, "%s<expr>%s</expr>;", $1, $2);
                strcpy($$, temp);

	};

stmt_break: BREAK ';' {

		sprintf(temp, "%s;", $1);
                strcpy($$, temp);

	};

stmt_continue: CONTINUE ';' {

		sprintf(temp, "%s;", $1);
                strcpy($$, temp);

	};

/**********************************************/

func_def: var_type ID '(' param_list ')' compound_statement {

		sprintf(temp, "%s%s(%s)%s", $1, $2, $4, $6);
		strcpy($$, temp);

	}

	| VOID ID '(' param_list ')' compound_statement {
	
		sprintf(temp, "%s%s(%s)%s", $1, $2, $4, $6);
		strcpy($$, temp);

	}

	| var_type ID '(' ')' compound_statement {

		sprintf(temp, "%s%s()%s", $1, $2, $5);
		strcpy($$, temp);

	}

	| VOID ID '(' ')' compound_statement {

		sprintf(temp, "%s%s()%s", $1, $2, $5);
		strcpy($$, temp);

	};

/**********************************************/


%%


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
