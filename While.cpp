#include "While.h"
#include "Interpreter.h"

int While::doCommand(const Line &line)
{

    // while (condition(line.parameters))
    double val_condition = stod(line.parameters[2]);
    while (expression(symbol_table->get(line.parameters[0]), line.parameters[1],val_condition))
    {
        // Execute each command in the loop body
        for (const Line &it : line.list_command)
        {
            interpreter.perform(it);
        }
    }

    return 0;

}


bool While::expression(double x, const string &operat, double y)
{
     // Evaluate the expression based on the operator
    if ((operat == "<") && (x < y))
        return true;
    else if ((operat == ">") && (x > y))
        return true;
    else if ((operat == ">=") && (x >= y))
        return true;
    else if ((operat == "<=") && (x <= y))
        return true;
    else if ((operat == "==") && (x == y))
        return true;
    else if ((operat == "!=") && (x != y))
        return true;

    return false;
}

// bool While ::condition(vector<string> parameters)
// {

//     double a;
//     double b;

//     a = symbol_table->get(parameters[0]);
//     b = stod(parameters[2]);

//     if (a < b)
//         return true;
//     else
//         return false;
// }