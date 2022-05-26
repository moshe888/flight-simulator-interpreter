#pragma once

#include "Command.h"

class Print : public Command
{

    map<string, double> *symbolTable;

public:
    Print(map<string, double> *symbolTable) : Command(), symbolTable(symbolTable) {}

    int doCommand(Line &line)
    {
        if (line.parameters[0][0] == '\"')
        {
            cout << line.parameters[0] << endl;
        }
        else
        {
            string s = to_string((*symbolTable)[line.parameters[0]]);
            cout << s << endl;
        }
        return 0;
    }
};
