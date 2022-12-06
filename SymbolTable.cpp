#include "SymbolTable.h"
#include <map>

using std::lock_guard;
using std::mutex;

SymbolTable* SymbolTable::instance = nullptr;

SymbolTable *SymbolTable::get_instance()//?
{
    if (!instance) {
        instance = new SymbolTable();
    }
    return instance;
}
    
void SymbolTable::set(const string& key, double d)
{
    lock_guard<mutex> lock(mtx);
    symbol_table[key] = d;
}

double SymbolTable::get(const string& key)
{
    lock_guard<mutex> lock(mtx);
    return symbol_table[key];
}

bool SymbolTable::exists(string key)
{
    lock_guard<mutex> lock(mtx);
    return symbol_table.find(key) != symbol_table.end();
}

map<string, double> SymbolTable::get_table() const
{
    return symbol_table;
}

map<string, string> SymbolTable::get_names() const
{
    return names;
}

void SymbolTable::set_name(string key, string value) {
    names[key] = value;
}
