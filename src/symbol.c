#include "symbol.h"


extern std::vector<symbol_entry> symbol_table;
extern int cur_scope;


void symbol_init()
{
	// add some special functions

	// digitalWrite(pin, value);
	symbol_entry entry;
        entry.name = "digitalWrite";
        entry.type = SYMBOL_TYPE::FUNC;
        entry.scope = cur_scope;
        entry.args_num = 2;
        entry.offset = 0;

        symbol_table.push_back(entry);

	// digitalWrite(pin, value);
        entry.name = "delay";
        entry.type = SYMBOL_TYPE::FUNC;
        entry.scope = cur_scope;
        entry.args_num = 1;
        entry.offset = 0;

        symbol_table.push_back(entry);		
}

int symbol_add(const std::string name, const SYMBOL_TYPE type)
{
        // add entry directly: ignore redeclaration
        symbol_entry entry;
        entry.name = name;
        entry.type = type;
        entry.scope = cur_scope;
        entry.args_num = 0;
	entry.offset = 0;

        symbol_table.push_back(entry);

	return symbol_table.size() - 1;
}

int symbol_find(const std::string name, const SYMBOL_TYPE type)
{
        // find entry in backward (closest scope first)
        for (auto it = symbol_table.end() - 1; it >= symbol_table.begin(); --it) {

                if (it->name != name || it->type != type)
                        continue;

                return std::distance(symbol_table.begin(), it);

        }

        return -1;
}

bool symbol_remove(const int scope)
{
        if (scope == 0)
                return false;
 
        if (symbol_table.size() == 0)
                return false;


	bool has_removed = false;

        // remove all entries greater/equal to [scope], from the back,
	// and only remove variable, since we assuming all functions are global
        for (auto it = symbol_table.end() - 1; it >= symbol_table.begin(); ) {

		if (it->type == SYMBOL_TYPE::FUNC) {

			it -= 1;
			continue;

		}

                if (it->scope >= scope) {

                        it = symbol_table.erase(it) - 1;
			has_removed = true;

		} else
                        break;

        }

	return has_removed;
}

