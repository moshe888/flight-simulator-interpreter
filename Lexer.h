#pragma once

#include <iostream>
#include <vector>
// #include "Interpreter.h"
#include "Line.h"

using namespace std;

class Lexer
{
	// Interpreter interpreter;

	vector<string> split(string str, string delimiter);

	vector<string> lexer(string line);

	vector<Line> recursive(ifstream &ins);//for while

public:
	Line parser(string str, ifstream &ins);
	// void parser_file(string file_path);
};
