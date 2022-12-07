#pragma once
#include "Command.h"
#include "client.h"
#include "SymbolTable.h"
#include "Exp.h"

using namespace std;

class Equal : public Command
{

    SymbolTable  *symbol_table ;
    Client *client;
    ofstream file;
    Expressions exp;
   
public:
    Equal() : Command(), symbol_table(SymbolTable::get_instance())
    {}

    int doCommand(const Line &line);
};
