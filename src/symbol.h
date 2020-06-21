#pragma once

#include <string>
#include <vector>


/* Symbol table related structure */

enum SYMBOL_TYPE {

	VAR,
	FUNC,

};

struct symbol_entry {
       
	std::string name;	// string of id
	SYMBOL_TYPE type;	// VAR or FUNC
	int scope;		// stack-like integer scope
	int args_num;		// for function
	int offset;		// for variable, offset from frame pointer (s0) in bytes
};


/* Function declaration */

void symbol_init();

int symbol_add(const std::string name, const SYMBOL_TYPE type);

int symbol_find(const std::string name, const SYMBOL_TYPE type);

bool symbol_remove(const int scope);
