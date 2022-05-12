#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <map>
 
 using namespace std;


// using std::string;
// using std::vector;

class Command {
public:

	virtual int doCommand(vector<string> parameters) = 0;
	virtual ~Command() {}
};



