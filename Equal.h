#pragma once
#include "Command.h"
#include "client.h"
#include "SymbolTable.h"

using namespace std;

// Client::Client(){}
class Equal : public Command
{

    SymbolTable  *symbolTable;
    map<string, string> *names;
    Client *client;
    ofstream file;
   
public:
    Equal(SymbolTable *symbolTable, map<string, string> *names)
        : Command(), symbolTable(symbolTable), names(names)
    {
    }

    int doCommand(const Line &line);
};
