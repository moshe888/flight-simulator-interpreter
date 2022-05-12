#pragma once
#include "Command.h"
#include "client.h"

// Client::Client(){}
class Equal : public Command
{

    map<string, double>* symbolTable;
    map<string, string>* names;
    Client* client;


 public : 

    Equal( map<string, double>* symbolTable,map<string, string>* names) 
        :  Command(), symbolTable(symbolTable),names(names)
    {}

    int doCommand(vector<string> parameters){
        Client::getInstance()->Send(string("set ") + (*names)[parameters[0]] + " " + parameters[1]);
        cout << "equals " << parameters[0] << " " << parameters[1] << endl;
        return 0;
    }


};