#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "Line.cpp"

using namespace std;

 

class Command
{
public:
	virtual int doCommand(const Line& line) = 0;  
 
	virtual ~Command() {}
};
