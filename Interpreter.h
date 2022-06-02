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
 //class While;
 #include "While.h"
#include "Print.h"
#include "Sleep.h"

// class While;

class Interpreter
{
public:
	std::map<string, Command *> map;
	 SymbolTable symbolTable;
	std::map<string, string> names;

public:
	Interpreter()
	{
		map["openDataServer"] = new OpenServerCommand(&symbolTable, &names);
		map["connect"] = new Connect();
		map["var"] = new Var(&symbolTable, &names);
		map["equal"] = new Equal(&symbolTable, &names);
		map["while"] = new While(&symbolTable, this);
		map["print"] = new Print(&symbolTable);
		map["sleep"] = new Sleep(&symbolTable);
	}

	~Interpreter()
	{
		delete map["openDataServer"];
		delete map["connect"];
		delete map["var"];
		delete map["equal"];
		delete map["while"];
		delete map["print"];
		delete map["sleep"];

		ofstream output;
		output.open("output.txt");

		output << "Symboltable:" << endl;
		for (pair<string, float> symbol : symbolTable.getTable()) {
			output << symbol.first << " = " << symbol.second << endl;
		}

		output << endl;

		output << "Names:" << endl;
		for (pair<string, string> name : names) {
			output << name.first << " = " << name.second << endl;
		}

		output.close();
	}

	void perform(const Line &line)
	{
		try {
			if (map.find(line.name_command) == map.end())
			{
				std::cout << "Invalid command" << std::endl;
				return;
			}
			map[line.name_command]->doCommand(line);
		}
		catch (const std::exception& e) {
			std::cout << "EXCEPTION " << e.what() << std::endl;
			exit(1);
		}
	}
};

 
