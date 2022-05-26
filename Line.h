#pragma once

#include <map>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
//#include "Interpreter.h"
 

using std::string;
using std::vector;

//class Interpreter;

class Line
{
public:
  // Interpreter* interpreter;
    string str_line;
    string name_command;
    vector<string> parameters;
    
    vector<Line> list_command;


 

    
};