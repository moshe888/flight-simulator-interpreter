#include <iostream>
#include <queue>
#include <stack>
#include <vector>

 using std::string;
 using std::vector;


class ShuntingYard {
  vector<string> str;

public:
    ShuntingYard(vector<string> str) : str(str)
    {}

    double compute() {
        std::queue<std::string> queue;
        std::stack<std::string> stack;

         
        int i = 0;
        while (i < str.size()) {
            char c = str[i];
            i++;
            if (c == '(') {
                stack.push(std::string("("));
                continue;
            }
            if (c >= '0' && c <= '9') {
                std::string number;
                while (str[i] >= '0' && str[i] <= '9') {

                }
            }
        }
    }
};
