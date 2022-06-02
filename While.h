#pragma once

#include "Command.h"
#include "SymbolTable.h"

class Interpreter;


class While : public Command
{
    SymbolTable *symbolTable;
    Interpreter* interpreter;

public:
    While(SymbolTable *symbolTable,Interpreter* interpreter) 
    : Command(), symbolTable(symbolTable) ,interpreter(interpreter){}

    int doCommand(const Line &line);
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
