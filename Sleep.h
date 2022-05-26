#pragma once

#include "Command.h"
 
#include <time.h>
#include <unistd.h>

 

class Sleep : public Command
{
    map<string, double> *symbolTable;

public:
Sleep(map<string, double> *symbolTable) : Command() , symbolTable(symbolTable) {}
    int doCommand(Line &line)
    {
         
        // double ms = unify(line.parameters,symbolTable);
        // auto M = (useconds_t)ms;
        // usleep(1000 * M);
        double ms = stod(line.parameters[0])/1000;
        sleep(ms);
        cout << "sleep " << ms << endl;
        return 0;
    }
};