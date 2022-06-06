#pragma once

#include "Command.h"

#include <time.h>
#include <unistd.h>
#include "SymbolTable.h"

class Sleep : public Command
{
    SymbolTable *symbolTable;

public:
    Sleep(SymbolTable *symbolTable) : Command(), symbolTable(symbolTable) {}
    int doCommand(const Line &line)
    {

        double ms = stod(line.parameters[0]) / 1000;
        sleep(ms);
        cout << "sleep " << ms << endl;

        return 0;
    }
};