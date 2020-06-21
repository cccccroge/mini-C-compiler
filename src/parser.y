%{

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
   int cur_temp;

%}


%union{

	int iVal;
	double dVal;
	char sVal[100000];

}


/* Terminal type */
%token <sVal> VOID INT FLOAT CHAR DOUBLE CONST
%token <sVal> FOR DO WHILE BREAK CONTINUE IF ELSE RETURN SWITCH CASE DEFAULT

%token <sVal> INCRE DECRE LESS_EQ GREAT_EQ EQUAL NOT_EQ LOG_AND LOG_OR UPLUS UMINUS
%token <sVal> '+' '-' '*' '/' '%' '<' '>' '!' '&' '|' '(' ')' '[' ']' '{' '}' ':' ';' ',' '='

%token <sVal> ID

%token <iVal> NUM_INT
%token <dVal> NUM_FLOATING

%token <sVal> CHARACTER STRING


/* Non-terminal type */
%type <sVal> program_plum
%type <sVal> program var_decl scalar_decl const_decl var_type init_list init_unit
%type <sVal> expr id_arr_access access_list func_invoc argument_list literal
%type <sVal> array_decl init_list_arr init_unit_arr id_arr_decl arr_decl_list arr_content expr_list arr_content_list
%type <sVal> func_decl
%type <sVal> param_list param_unit
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

		if (DEBUG)
			std::cout << "->program_plum" << std::endl;

	};

program: program var_decl {

		sprintf(temp, "%s%s", $1, $2);
                strcpy($$, temp);

	}

	| program func_decl {

		sprintf(temp, "%s<func_decl>%s</func_decl>", $1, $2);
                strcpy($$, temp);

		if (DEBUG)
                        std::cout << "->program" << std::endl;

	}

	| program func_def {

		sprintf(temp, "%s<func_def>%s</func_def>", $1, $2);
                strcpy($$, temp);

		if (DEBUG)
                        std::cout << "->program" << std::endl;

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

init_unit: ID {

		// install local variable
		int i = symbol_add(std::string($1), SYMBOL_TYPE::VAR);
		int offset = -4 * (symbol_table[i].args_num + cur_local + 1);
		symbol_table[i].offset = offset;
		
		// save to register
		std::string reg = "s" + std::to_string(cur_local);
		cur_local += 1;
		std::cout << "addi " + reg + ", zero, 0" << std::endl;	// initialize to default value 0

		// modify pre-saved value on stack
		std::cout << "sw " + reg + ", " + std::to_string(offset) + "(s0)" << std::endl;

	}
		
	| ID '=' expr {
		
		// install local variable
		int i = symbol_add(std::string($1), SYMBOL_TYPE::VAR);
		int offset = -4 * (symbol_table[i].args_num + cur_local + 1);
                symbol_table[i].offset = offset;

                // save to register
                std::string reg = "s" + std::to_string(cur_local);
                cur_local += 1;

		std::cout << "lw t0, 0(sp)" << std::endl;
                std::cout << "addi sp, sp, 4" << std::endl;
                std::cout << "addi " + reg + ", t0, 0" << std::endl;

                // modify pre-saved value on stack
                std::cout << "sw " + reg + ", " + std::to_string(offset) + "(s0)" << std::endl;

	};

/**********************************************/

expr: expr '+' expr {

		// get temp values from stack
		std::cout << "lw t1, 0(sp)" << std::endl;
		std::cout << "addi sp, sp, 4" << std::endl;
		std::cout << "lw t0, 0(sp)" << std::endl;
		std::cout << "addi sp, sp, 4" << std::endl;

		// add
		std::cout << "add t0, t0, t1" << std::endl;

		// push stack as temp value
		std::cout << "addi sp, sp, -4" << std::endl;
		std::cout << "sw t0, 0(sp)" << std::endl;

	}

	| expr '-' expr {

		// get temp values from stack
                std::cout << "lw t1, 0(sp)" << std::endl;
                std::cout << "addi sp, sp, 4" << std::endl;
                std::cout << "lw t0, 0(sp)" << std::endl;
                std::cout << "addi sp, sp, 4" << std::endl;

                // subtract
                std::cout << "sub t0, t0, t1" << std::endl;

                // push stack as temp value
                std::cout << "addi sp, sp, -4" << std::endl;
                std::cout << "sw t0, 0(sp)" << std::endl;

	}

	| expr '*' expr {

		// get temp values from stack
                std::cout << "lw t1, 0(sp)" << std::endl;
                std::cout << "addi sp, sp, 4" << std::endl;
                std::cout << "lw t0, 0(sp)" << std::endl;
                std::cout << "addi sp, sp, 4" << std::endl;

                // multiply
                std::cout << "mul t0, t0, t1" << std::endl;

                // push stack as temp value
                std::cout << "addi sp, sp, -4" << std::endl;
                std::cout << "sw t0, 0(sp)" << std::endl;

	}

	| expr '/' expr {

		// get temp values from stack
                std::cout << "lw t1, 0(sp)" << std::endl;
                std::cout << "addi sp, sp, 4" << std::endl;
                std::cout << "lw t0, 0(sp)" << std::endl;
                std::cout << "addi sp, sp, 4" << std::endl;

                // divide
                std::cout << "div t0, t0, t1" << std::endl;

                // push stack as temp value
                std::cout << "addi sp, sp, -4" << std::endl;
                std::cout << "sw t0, 0(sp)" << std::endl;

        }

        | expr '%' expr {

		// get temp values from stack
                std::cout << "lw t1, 0(sp)" << std::endl;
                std::cout << "addi sp, sp, 4" << std::endl;
                std::cout << "lw t0, 0(sp)" << std::endl;
                std::cout << "addi sp, sp, 4" << std::endl;

                // remainder
                std::cout << "rem t0, t0, t1" << std::endl;

                // push stack as temp value
                std::cout << "addi sp, sp, -4" << std::endl;
                std::cout << "sw t0, 0(sp)" << std::endl;

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

		// find entry on stack
		int i = symbol_find(std::string($1), SYMBOL_TYPE::VAR);
                int offset = symbol_table[i].offset;

		// get temp value from stack
		std::cout << "lw t0, 0(sp)" << std::endl;
                std::cout << "addi sp, sp, 4" << std::endl;

		// assignment
		std::cout << "sw t0, " + std::to_string(offset) + "(s0)" << std::endl;

		// push stack as temp value
		std::cout << "addi sp, sp, -4" << std::endl;
		std::cout << "sw t0, 0(sp)" << std::endl;

	}

	| id_arr_access '=' expr {

                sprintf(temp, "%s=<expr>%s</expr>", $1, $3);
		strcpy($$, temp);

	}

	| func_invoc {

		// get value from return register
		std::cout << "addi t0, a0, 0" << std::endl;

		// push stack as temp value
		std::cout << "addi sp, sp, -4" << std::endl;
                std::cout << "sw t0, 0(sp)" << std::endl;

	}

	| ID {

		// find entry on stack
		int i = symbol_find(std::string($1), SYMBOL_TYPE::VAR);
		int offset = symbol_table[i].offset;
		std::cout << "lw t0, " + std::to_string(offset) + "(s0)" << std::endl;

		// push stack as temp value
                std::cout << "addi sp, sp, -4" << std::endl;
                std::cout << "sw t0, 0(sp)" << std::endl;

	}

	| id_arr_access 

	| literal {

		// put number to temp register
		std::cout << "li t0, " + std::string($1) << std::endl;

		// push stack as temp value
                std::cout << "addi sp, sp, -4" << std::endl;
                std::cout << "sw t0, 0(sp)" << std::endl;

	};

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

		int i = symbol_find(std::string($1), SYMBOL_TYPE::FUNC);
		// ignore function undeclaration


		// Do C-A-B if function is special
		// in A just save 'ra' since there won't be recursive call within these functions
		// don't need to do D since they return nothing
		if (std::string($1) == "digitalWrite" || std::string($1) == "delay") {

			// C has been done half here (arguments are passed)
			std::cout << "addi sp, sp, -4" << std::endl;
			std::cout << "sw ra, 0(sp)" << std::endl;

			std::cout << "jal ra, " + std::string($1) << std::endl;

			std::cout << "lw ra, 0(sp)" << std::endl;
			std::cout << "addi sp, sp, 4" << std::endl;

		}
		// Do C otherwise, A-B will be done in 'func_def', D will be done in stmt_return
		else {

			// C has been done half here (arguments are passed)
                        std::cout << "jal ra, " + std::string($1) << std::endl;
		
		}

		// reset argument index counter, next invocation will starts from 0
		cur_arg = 0;

                //strcpy($$, $1);
                //strcat($$, $2);
                //strcat($$, $3);
		//strcat($$, $4);

	}

	| ID '(' ')' {

		int i = symbol_find(std::string($1), SYMBOL_TYPE::FUNC);
                // ignore function undeclaration


                // Do C otherwise, A-B will be done in 'func_def', D will be done in expr
                std::cout << "jal ra, " + std::string($1) << std::endl;
                
		//sprintf(temp, "%s()", $1);
		//strcpy($$, temp);

	};

argument_list: argument_list ',' expr {

		// C: get value from stack and store to corresponding argument register
		std::cout << "lw t0, 0(sp)" << std::endl;
                std::cout << "addi sp, sp, 4" << std::endl;
		std::cout << "addi a" + std::to_string(cur_arg) + ", t0, 0" << std::endl;

		cur_arg += 1;

	}

	| expr {

		std::cout << "lw t0, 0(sp)" << std::endl;
                std::cout << "addi sp, sp, 4" << std::endl;
		std::cout << "addi a" + std::to_string(cur_arg) + ", t0, 0" << std::endl;
		
		cur_arg += 1;

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

		if (strcmp($1, "'\\\\'") == 0) {
		
			sprintf(temp, "%s", "\\");
			strcpy($$, temp);
		}

		else if (strcmp($1, "'\\''") == 0) {

			sprintf(temp, "%s", "'");
			strcpy($$, temp);
		}

		else if (strcmp($1, "'\\n'") == 0)
			strcpy($$, "\n");

		else if (strcmp($1, "'\\t'") == 0)
			strcpy($$, "\t");

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

	}

	| arr_decl_list '[' '+' NUM_INT ']' %prec UPLUS {

                sprintf(temp, "%s[%d]", $1, $4);
                strcpy($$, temp);

        }

        | '[' '+' NUM_INT ']' %prec UPLUS {

                sprintf(temp, "[%d]", $3);
                strcpy($$, temp);

        }

	| arr_decl_list '[' '-' NUM_INT ']' %prec UMINUS {

                sprintf(temp, "%s[-%d]", $1, $4);
                strcpy($$, temp);

        }

        | '[' '-' NUM_INT ']' %prec UMINUS {

                sprintf(temp, "[-%d]", $3);
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

		symbol_add(std::string($2), SYMBOL_TYPE::FUNC);

		std::cout << ".global " << std::string($2) << std::endl;		

		//sprintf(temp, "%s%s(%s);", $1, $2, $4);
		//strcpy($$, temp);

	}

	| VOID ID '(' param_list ')' ';'{

		symbol_add(std::string($2), SYMBOL_TYPE::FUNC);

		std::cout << ".global " << std::string($2) << std::endl;

		//sprintf(temp, "%s%s(%s);", $1, $2, $4);
		//strcpy($$, temp);

	}
	
	| var_type ID '(' ')' ';' {

		symbol_add(std::string($2), SYMBOL_TYPE::FUNC);
		
		std::cout << ".global " << std::string($2) << std::endl;

		//sprintf(temp, "%s%s();", $1, $2);
		//strcpy($$, temp);

	}

	| VOID ID '(' ')' ';' {

		symbol_add(std::string($2), SYMBOL_TYPE::FUNC);

		std::cout << ".global " << std::string($2) << std::endl;

		//sprintf(temp, "%s%s();", $1, $2);
		//strcpy($$, temp);

	};

param_list: param_list ',' param_unit {

		sprintf(temp, "%s %s", $1, $3);
                strcpy($$, temp);

	}
	  
	| param_unit;

param_unit: var_type ID {
	 
		strcpy($$, $2);

	};

/**********************************************/

statement: stmt_expression {

		if (DEBUG)
                        std::cout << "->statement" << std::endl;

	}

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

compound_statement:
		  
	'{' {

		cur_scope += 1;

	} '}' {

		symbol_remove(cur_scope);
		cur_scope -= 1;

		sprintf(temp, "{}");
                strcpy($$, temp);

	}

	| '{' {

		cur_scope += 1;

	} statement_var_decls '}' {

		if (DEBUG) {
			std::cout << "YOOOOOOOOOOOOOOOO" << std::endl;
			std::cout << "cur_scope = " << cur_scope << std::endl;

		}
		symbol_remove(cur_scope);
		cur_scope -= 1;

		sprintf(temp, "{%s}", $2);
                strcpy($$, temp);

		if (DEBUG)
                        std::cout << "->compound_statement" << std::endl;


	};

statement_var_decls: statement_var_decls statement_var_decl {

		sprintf(temp, "%s%s", $1, $2);
                strcpy($$, temp);

		if (DEBUG)
                        std::cout << "->statement_var_decls" << std::endl;

	}

	| statement_var_decl;

statement_var_decl: statement {

		sprintf(temp, "<stmt>%s</stmt>", $1);
                strcpy($$, temp);

		if (DEBUG)
                        std::cout << "->statement_var_decl" << std::endl;

	}

	| var_decl;

/**********************************************/

stmt_expression: expr ';' {

		sprintf(temp, "<expr>%s</expr>;", $1);
                strcpy($$, temp);

		if (DEBUG)
                        std::cout << "->stmt_expression" << std::endl;

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

	| CASE '+' NUM_INT ':' statements %prec UPLUS {

                sprintf(temp, "%s%d:%s", $1, $3, $5);
                strcpy($$, temp);

        }

        | CASE '+' NUM_INT ':' %prec UPLUS {

                sprintf(temp, "%s%d:", $1, $3);
                strcpy($$, temp);

        }

	| CASE '-' NUM_INT ':' statements %prec UPLUS {

                sprintf(temp, "%s-%d:%s", $1, $3, $5);
                strcpy($$, temp);

        }

        | CASE '-' NUM_INT ':' %prec UPLUS {

                sprintf(temp, "%s-%d:", $1, $3);
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

		// get temp value on stack and store to return register
		std::cout << "lw t0, 0(sp)" << std::endl;
		std::cout << "addi sp, sp, 4" << std::endl;
		std::cout << "addi a0, t0, 0" << std::endl;

		//sprintf(temp, "%s<expr>%s</expr>;", $1, $2);
                //strcpy($$, temp);

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

func_def: var_type ID '(' param_list ')' {
	
		// add symbol for function if it hasn't (no declaration before)
		int i = symbol_find(std::string($2), SYMBOL_TYPE::FUNC);

                if (i == -1) {

                        symbol_add(std::string($2), SYMBOL_TYPE::FUNC);

                }

		// param_list's scope should be the same as the ones after '{'
		cur_scope += 1;

		int param_count = 0;
		char *param = strtok($4, " ");
		
		while (param) {

			param_count += 1;
			int i = symbol_add(std::string(param), SYMBOL_TYPE::VAR);
			symbol_table[i].offset = -4 * param_count - 4;

			param = strtok(NULL, " ");

		}

		symbol_table[i].args_num = param_count;

		cur_scope -= 1;

		// do A before '{'
		std::cout << std::string($2) << ":" << std::endl;

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


	} compound_statement {

		// do B after '}'
		std::cout << "addi sp, s0, -4" << std::endl;
		
		std::cout << "lw ra, 0(sp)" << std::endl;
		std::cout << "addi sp, sp, 4" << std::endl;
		
		std::cout << "lw s0, 0(sp)" << std::endl;
		std::cout << "addi sp, sp, 4" << std::endl;

		cur_local = 0;
		
	}

	| VOID ID '(' param_list ')' {
	
		// add symbol for function if it hasn't (no declaration before)
                int i = symbol_find(std::string($2), SYMBOL_TYPE::FUNC);

                if (i == -1) {

                        symbol_add(std::string($2), SYMBOL_TYPE::FUNC);

                }

                // param_list's scope should be the same as the ones after '{'
                cur_scope += 1;

                int param_count = 0;
                char *param = strtok($4, " ");

                while (param) {

                        param_count += 1;
                        int i = symbol_add(std::string(param), SYMBOL_TYPE::VAR);
                        symbol_table[i].offset = -4 * param_count - 4;
                        
                        param = strtok(NULL, " ");

                }

                symbol_table[i].args_num = param_count;

                cur_scope -= 1;		

		// do A before '{'
		std::cout << std::string($2) << ":" << std::endl;

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

	} compound_statement {

		// do B after '}'
                std::cout << "addi sp, s0, -4" << std::endl;

                std::cout << "lw ra, 0(sp)" << std::endl;
                std::cout << "addi sp, sp, 4" << std::endl;

                std::cout << "lw s0, 0(sp)" << std::endl;
                std::cout << "addi sp, sp, 4" << std::endl;

		cur_local = 0;
		
	}

	| var_type ID '(' ')' {

		int i = symbol_find(std::string($2), SYMBOL_TYPE::FUNC);

                if (i == -1) {

                        symbol_add(std::string($2), SYMBOL_TYPE::FUNC);

                }

		// do A before '{'
		std::cout << std::string($2) << ":" << std::endl;

                std::cout << "addi sp, sp, -4" << std::endl;
                std::cout << "sw s0, 0(sp)" << std::endl;

                std::cout << "addi s0, sp, 0" << std::endl;

                std::cout << "addi sp, sp, -4" << std::endl;
                std::cout << "sw ra, 0(sp)" << std::endl;

                for (int i = 1; i <= 11; ++i) {

                        std::cout << "addi sp, sp, -4" << std::endl;
                        std::cout << "sw s" + std::to_string(i) + ", 0(sp)" << std::endl;

                }

	} compound_statement {

		// do B after '}'
                std::cout << "addi sp, s0, -4" << std::endl;

                std::cout << "lw ra, 0(sp)" << std::endl;
                std::cout << "addi sp, sp, 4" << std::endl;

                std::cout << "lw s0, 0(sp)" << std::endl;
                std::cout << "addi sp, sp, 4" << std::endl;

		cur_local = 0;
		
	}

	| VOID ID '(' ')' {

		int i = symbol_find(std::string($2), SYMBOL_TYPE::FUNC);

                if (i == -1) {

                        symbol_add(std::string($2), SYMBOL_TYPE::FUNC);

                }

		// do A before '{'
		std::cout << std::string($2) << ":" << std::endl;

                std::cout << "addi sp, sp, -4" << std::endl;
                std::cout << "sw s0, 0(sp)" << std::endl;

                std::cout << "addi s0, sp, 0" << std::endl;

                std::cout << "addi sp, sp, -4" << std::endl;
                std::cout << "sw ra, 0(sp)" << std::endl;

                for (int i = 1; i <= 11; ++i) {

                        std::cout << "addi sp, sp, -4" << std::endl;
                        std::cout << "sw s" + std::to_string(i) + ", 0(sp)" << std::endl;

                }

	} compound_statement {

		// do B after '}'
                std::cout << "addi sp, s0, -4" << std::endl;

                std::cout << "lw ra, 0(sp)" << std::endl;
                std::cout << "addi sp, sp, 4" << std::endl;

                std::cout << "lw s0, 0(sp)" << std::endl;
                std::cout << "addi sp, sp, 4" << std::endl;

		cur_local = 0;
		
		if (DEBUG)
			std::cout << "->func_def" << std::endl;
	};

/**********************************************/


%%


int main(void)
{
	line_count = 1;
	cur_scope = 0;
	cur_arg = 0;
	cur_local = 1;
	cur_temp = 0;
	symbol_init();

	yyparse();

	return 0;
}

int yyerror(char *s)
{
	fprintf(stderr, "Error at line %d:\n%s\n", line_count, s);
	return 1;
}
