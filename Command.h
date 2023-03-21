#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "Line.cpp"

using namespace std;

// Command is an abstract base class for all commands in the interpreter
class Command
{
public:
	// doCommand is a pure virtual function that takes a Line object and returns an int
	virtual int doCommand(const Line& line) = 0;  

	// Virtual destructor to ensure proper cleanup of derived objects
	virtual ~Command() {}
};
