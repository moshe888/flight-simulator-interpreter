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

    int doCommand( Line& line); 
//         if (line.parameters[2] == "bind") {
//             (*names)[line.parameters[0]] = line.parameters[3];
//         }
//         else {
//             //(*names)[line.parameters[0]] = "";//?
//             (*symbolTable)[line.parameters[0]] = (*symbolTable)[line.parameters[2]];
//         }

//         return 0;
        
//     }
};
