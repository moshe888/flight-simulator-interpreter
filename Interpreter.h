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
	Parser parser; // Object to create lines from input

	std::map<string, Command*> commands; // Map of available commands

	SymbolTable* symbol_table; // Pointer to the symbol table singleton instance
	
	std::map<string, string> names; // Map of variable names and their corresponding paths in the simulator
	


public:
	Interpreter();

	~Interpreter();

		// Execute the command defined by the parsed line
	void perform(const Line &line);
 
	// Parse the file and execute the commands defined in it
	void parser_file(const string& file_path);
}; 
