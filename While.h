#pragma once

#include "Command.h"
#include "SymbolTable.h"

class Interpreter;


class While : public Command
{
    SymbolTable* symbolTable;
    Interpreter* interpreter;//למה לא רפרנסס?
    

public:
    While(SymbolTable *symbolTable,Interpreter* interpreter) 
    : Command(), symbolTable(symbolTable) ,interpreter(interpreter){}

    int doCommand(const Line &line);
  
    bool condition(vector<string> parameters);
 
};
