#pragma once

#include <iostream>
#include "ShuntingYard.h"

using namespace std;

double unify(vector<string> parameters, map<string, double> *symbolTable)
{
    string str;
    for (string x : parameters)
    {
        str += x;
    }

    string result;
        if (str[0] == '-')
    {
        str = "0 " + str;
    }
    
    for (int i = 0; i < str.size(); i++)
    {

        if (!((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z') || str[i] == '_'))
        {
            result += str[i];
            continue;
        }
        string var = to_string(str[i]);
        i++;
        while ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= '0' && str[i] <= '9') || str[i] == '_')
        {
            var += str[i];
            i++;
        }
        i--;
        var = to_string((*symbolTable)[var]);
        result += var;
    }

    return Calculator().calculate(result);
}