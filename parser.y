%{

   #include <string.h>
   #include <stdio.h>
   #include <stdlib.h>

   int yylex();
   char temp[10000];

   extern int line_count;

%}


%union{

	int iVal;
	double dVal;
	char sVal[1000];

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
%type <sVal> program var_decl scalar_decl var_type init_list init_unit
%type <sVal> expr id_arr_access access_list func_invoc param_list literal
%type <sVal> array_decl init_list_arr init_unit_arr id_arr_decl arr_decl_list arr_content expr_list arr_content_list


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


%start program


%%

/**********************************************/

program: program var_decl {

	}

/*	| program func_decl {

	}

	| program func_def {

	}
*/
	|  {} ;


var_decl: scalar_decl
	| array_decl ;

/**********************************************/

scalar_decl: var_type init_list ';' {

		printf("<scalar_decl>%s%s;</scalar_decl>", $1, $2);

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

func_invoc: ID '(' param_list ')' {

                strcpy($$, $1);
                strcat($$, $2);
                strcat($$, $3);
		strcat($$, $4);

	};

param_list: param_list ',' expr {

		sprintf(temp, "%s,<expr>%s</expr>", $1, $3);
		strcpy($$, temp);

	}

	| expr {

		sprintf(temp, "<expr>%s</expr>", $1);
		strcpy($$, temp);

	}

	| {} ;

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

		printf("<array_decl>%s%s;</array_decl>", $1, $2);

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
