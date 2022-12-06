#pragma once

#include <map>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "Command.h"
#include "Connect.h"
#include "OpenServerCommand.h"
#include "Var.h"
#include "Equal.h"
#include "SymbolTable.h"
#include "While.h"
#include "Print.h"
#include "Sleep.h"
#include "Parser.h"

class Interpreter
{
	Parser create_line;
	std::map<string, Command*> commands;
	SymbolTable* symbol_table;
	std::map<string, string> names;

public:
	Interpreter();

	~Interpreter();

	void perform(const Line &line);

	void parser_file(const string& file_path);
}; 
