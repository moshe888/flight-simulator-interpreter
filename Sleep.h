#pragma once

#include "Command.h"

#include <time.h>
#include <unistd.h>
#include "SymbolTable.h"

class Sleep : public Command
{
    SymbolTable *symbol_table;

public:
    Sleep() : Command(), symbol_table(SymbolTable::get_instance())
    {}

    int doCommand(const Line &line);
    
};
