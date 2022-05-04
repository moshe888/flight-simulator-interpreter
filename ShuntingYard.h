#include <iostream>
#include <queue>
#include <stack>
 using std::string;

class ShuntingYard {
    string str;

public:
    ShuntingYard(string str) : str(str)
    {}

    double compute() {
        std::queue<std::string> queue;
        std::stack<std::string> stack;

        std::vector<char> chars(str.begin(), str.end());
        int i = 0;
        while (i < chars.size()) {
            char c = chars[i];
            i++;
            if (c == '(') {
                stack.push(std::string("("));
                continue;
            }
            if (c >= '0' && c <= '9') {
                std::string number;
                while (chars[i] >= '0' && chars[i] <= '9') {

                }
            }
        }
    }
};
