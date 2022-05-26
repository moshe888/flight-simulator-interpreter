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
 //class While;
 #include "While.h"
#include "Print.h"
#include "Sleep.h"

// class While;

class Interpreter
{
public:
	std::map<string, Command *> map;
	std::map<string, double> symbolTable;
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
	}

	void perform(Line &line)
	{
		if (map.find(line.name_command) == map.end())
		{
			std::cout << "Invalid command" << std::endl;
			return;
		}
		map[line.name_command]->doCommand(line);
	}
};

 
