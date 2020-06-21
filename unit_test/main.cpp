#include "symbol.h"


std::vector<symbol_entry> symbol_table;
int cur_scope;


int main()
{
	cur_scope++;
	
	symbol_add(std::string("a"), VAR);
	{
		cur_scope++;

		symbol_add(std::string("a"), VAR);
		symbol_add(std::string("a"), VAR);

		int ret = symbol_find("a", VAR);

		symbol_remove(cur_scope);
	}
	cur_scope--;

	return 0;
}

