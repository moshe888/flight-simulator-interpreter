#pragma once

#include "Command.h"

class Print : public Command
{

   SymbolTable *symbolTable;

public:
    Print(SymbolTable *symbolTable) : Command(), symbolTable(symbolTable) {}
    
    int doCommand(const Line &line)
    {
        if (line.parameters[0][0] == '\"')
        {
            string str;
            for (string x : line.parameters)
            {
                str += (x + " ");
            }
            if (str[str.size() - 2] != '\"')     {
                throw runtime_error("print command -wrong gershaim");
            }

            str = str.substr(1, str.size() - 3);
            cout << str << endl;
        }
        else
        {
            string s = to_string(symbolTable->get(line.parameters[0]));
            cout << line.parameters[0] << " = " << s << endl;
        }
        
        return 0;
    }
};
