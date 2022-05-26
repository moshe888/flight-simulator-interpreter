#pragma once

#include <iostream>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

class ShuntingYard
{
    vector<string> str;

public:
    ShuntingYard(vector<string> str) : str(str)
    {
    }

    double compute()
    {
        queue<std::string> queue;
        stack<std::string> stack;

        int i = 0;
        while (i < str.size())
        {
            char c = str[i++];
            if (c == '(')
            {
                stack.push(string("("));
                continue;
            }
            if (c >= '0' && c <= '9')
            {
                std::string number;
                while (str[i] >= '0' && str[i] <= '9')
                {
                }
            }
        }
    }
};
