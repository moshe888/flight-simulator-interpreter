#pragma once

#include <iostream>
#include <vector>
#include "Tools.cpp"
#include "Line.cpp"

using std::string;
using std::vector;
using std::ifstream;

class Parser
{
	vector<string> lexer(string line); // Split a line  

	vector<Line> create_inner_lines(ifstream &ins); // Parse a block of code enclosed in {} (for while)

public:
	// Parse a single line of code and return the parsed `Line` object
	Line create_line(const string& str, ifstream &ins);
};

