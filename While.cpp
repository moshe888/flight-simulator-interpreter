#include "While.h"
#include "Interpreter.h"

int While::doCommand(Line &line)
{

    while (condition(line.parameters))
    {

        for (Line &it : line.list_command)
        {
            interpreter->perform(it);
        }
    }

    return 0;

    //  לרווץ בלולאה ממספר השורה ולהכניס לקובץ
    //  ןאחר כך נפעילר פרסר בלולאה כל עוד התנא מתקיים
    //  ןלמחוק את הקובץ
}

bool While ::condition(vector<string> parameters)
{

    // if (parameters[0] == "1")
    // {
    //     return 1;
    // }
    // else
    // {
    //     return 0;
    // }
        double a;
        if ((*symbolTable).find(parameters[0]) != (*symbolTable).end()) {
            a = (*symbolTable)[parameters[0]];
        }
        else {
          //  cout << "stod " << parameters[0] << endl;
            a = std::stod(parameters[0]);
        }

        double b;
        if ((*symbolTable).find(parameters[2]) != (*symbolTable).end()) {
            b = (*symbolTable)[parameters[2]];
        }
        else {
       //     cout << "stod " << parameters[2] << endl;
            b = std::stod(parameters[2]);
        }

    if (a < b)
    {

        return true;
    }
    else
    {
        return false;
    }
}
