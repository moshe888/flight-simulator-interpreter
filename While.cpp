#include "While.h"
#include "Interpreter.h"

int While::doCommand(const Line &line)
{
    while (condition(line.parameters))
    {
        for (const Line &it : line.list_command)
        {
            interpreter.perform(it);
        }
    }

    return 0;
}

bool While::condition(vector<string> parameters)
{
    double a;
    double b;

    a = symbol_table->get(parameters[0]);
    b = stod(parameters[2]);

    if (a < b)
        return true;
    else
        return false;
}

// bool While ::condition(vector<string> parameters)
// {

//     // if (parameters[0] == "1")
//     // {
//     //     return 1;
//     // }
//     // else
//     // {
//     //     return 0;
//     // }
//     double a;
//     // if (symbol_table->exists(parameters[0])) {
//     a = symbol_table->get(parameters[0]);
//     //}
//     // else {
//     //   //  cout << "stod " << parameters[0] << endl;
//     //     a = std::stod(parameters[0]);
//     // }

//     double b;
//     // if (symbol_table->exists(parameters[2])) {
//     //     b = symbol_table->get(parameters[2]);
//     // }
//     // else {
//     //     cout << "stod " << parameters[2] << endl;
//     b = std::stod(parameters[2]);
//     //}

//     if (a < b)
//     {

//         return true;
//     }
//     else
//     {
//         return false;
//     }
// }
