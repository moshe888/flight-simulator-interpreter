#pragma once

#include <map>
#include "Command.h"
#include "SymbolTable.h"

class Var : public Command {
    SymbolTable* symbolTable;
    map<string, string>* names;

public:
    Var( SymbolTable* symbolTable, map<string, string>* names) :
        Command(), symbolTable(symbolTable), names(names)
    {}

    int doCommand(const Line& line); 
};
