#pragma once

#include <map>
#include "Command.h"
#include "SymbolTable.h"

class Var : public Command {
    SymbolTable* symbol_table;

public:
    Var() : Command(), symbol_table(SymbolTable::get_instance())
    {}

    int doCommand(const Line& line); 
};
