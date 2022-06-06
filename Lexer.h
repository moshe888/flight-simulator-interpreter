#pragma once

#include <iostream>
#include <vector>
#include "Interpreter.h"
#include "Line.h"

using namespace std;

class Lexer
{
	Interpreter interpreter;

	vector<string> split(string str, string delimiter);

	vector<string> lexer(string line);

	vector<Line> recursive(ifstream &ins);

	Line parser(string str, ifstream &ins);

public:
	void parser_file(string file_path);
};
