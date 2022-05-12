#pragma once

#include <map>
#include "Command.h"

class Var : public Command {
    map<string, double>* symbolTable;
    map<string, string>* names;

public:
    Var(map<string, double>* symbolTable, map<string, string>* names) :
        Command(), symbolTable(symbolTable), names(names)
    {}

    int doCommand(vector<string> parameters); 
//         if (parameters[2] == "bind") {
//             (*names)[parameters[0]] = parameters[3];
//         }
//         else {
//             //(*names)[parameters[0]] = "";//?
//             (*symbolTable)[parameters[0]] = (*symbolTable)[parameters[2]];
//         }

//         return 0;
        
//     }
};
