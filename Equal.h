#pragma once
#include "Command.h"
#include "client.h"


using namespace std;

// Client::Client(){}
class Equal : public Command
{

    map<string, double> *symbolTable;
    map<string, string> *names;
    Client *client;

    

public:
    Equal(map<string, double> *symbolTable, map<string, string> *names)
        : Command(), symbolTable(symbolTable), names(names)
    {
    }

    int doCommand(Line &line);

};
     