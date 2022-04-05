#pragma once

#include <map>
#include "Command.h"

class Var : public Command {
    std::map<string, double>* symbolTable;
    std::map<string, string>* names;

public:
    Var(std::map<string, double>* symbolTable) : Command(), symbolTable(symbolTable)
    {}

    int doCommand(vector<string> parameters) {
        if (parameters[2] == "bind") {
            (*names)[parameters[0]] = parameters[3];
        }
        else {
            (*names)[parameters[0]] = "";
            (*symbolTable)[parameters[0]] = (*symbolTable)[parameters[2]];
        }

        return 0;
    }
};
