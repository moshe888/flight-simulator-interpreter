#pragma once

#include <iostream>
#include "ShuntingYard.h"

using namespace std;

double exp(vector<string> parameters, SymbolTable *symbolTable)
{
    // cout << "unify start" << endl;
    string str;
    for (string x : parameters)
    {

        str += x;
    }
    // cout << "unify " << str << endl;

    string result;
    // if (str[0] == '-')
    // {
    //     str = "0 " + str;
    // }

    for (int i = 0; i < str.size(); i++)
    {

        if (!((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z') || str[i] == '_'))
        {
            result += str[i];
            continue;
        }
        // string var = to_string(str[i]);
        string var;
        var.push_back(str[i]);
        i++;
        while ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= '0' && str[i] <= '9') || str[i] == '_')
        {

            // var += to_string(str[i]);
            var.push_back(str[i]);
            i++;
        }
        i--;
        var = to_string(symbolTable->get(var));
        result += var;
    }

    for (int i = 0; i < result.size() - 1; i++)
    {
        if (result[i] == '-' && result[i + 1] == '-')
        {
            result[i] = '+';

            result.erase(i + 1, 1);
            // string s =  result;
        }
    }

    if (result[0] == '-' || result[0] == '+' )
    {
        result = string("0") + result;
    }
    if (result[0] == '(' && (result[1] == '-' || result[1] == '+' ))
    {
        result[0] = '0';
        result = string("(") + result;
    }

    // cout << "unify shuntingyard " << result << endl;
    double num = Calculator().calculate(result);
    // cout << "unify end" << endl;
    return num;
}