#pragma once

#include <iostream>
#include <mutex>
#include <map>

using std::map;
using std::string;
using std::mutex;

class SymbolTable
{
private:
    std::map<string, string> names;
    map<string, double> symbol_table;
    mutex mtx;

    SymbolTable() {}

    static SymbolTable* instance;

public:
    static SymbolTable* get_instance();
    
    void set(const string& key, double d);
 
    double get(const string& key);
   
    bool exists(string key);

    map<string, double> get_table() const;

    map<string, string> get_names() const;

    void set_name(string key, string value);
};
