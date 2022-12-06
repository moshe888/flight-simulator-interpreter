#pragma once

#include <iostream>
#include <vector>
#include "Tools.h"
#include "Line.h"

using std::string;
using std::vector;
using std::ifstream;

class Parser
{
	// vector<string> split(string str, const string& delimiter);
	Tools tools;

	vector<string> lexer(string line);

	vector<Line> create_inner_lines(ifstream &ins);

public:
	Line create_line(const string& str, ifstream &ins);
};
