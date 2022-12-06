#pragma once

#include "Command.h"
#include "SymbolTable.h"

class Interpreter;


class While : public Command
{
    SymbolTable* symbol_table;
    Interpreter& interpreter;
    
public:
    While(Interpreter& interpreter) : 
        Command(), symbol_table(SymbolTable::get_instance()), interpreter(interpreter)
    {}

    int doCommand(const Line &line);
  
    bool condition(vector<string> parameters);
};
