#pragma once

#include "Command.h"

class Interpreter;


class While : public Command
{
    map<string, double> *symbolTable;
    Interpreter* interpreter;

public:
    While(map<string, double> *symbolTable,Interpreter* interpreter) 
    : Command(), symbolTable(symbolTable) ,interpreter(interpreter){}

    int doCommand(Line &line);
    /*{

        while (condition(line.parameters))
        {

            for (Line &it : line.list_command)
            {
                interpreter->perform(it);
            }
        }

        //  לרווץ בלולאה ממספר השורה ולהכניס לקובץ
        //  ןאחר כך נפעילר פרסר בלולאה כל עוד התנא מתקיים
        //  ןלמחוק את הקובץ
    }*/
    bool condition(vector<string> parameters);
 
};
