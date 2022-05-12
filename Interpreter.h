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
//#include "While.h"

class Interpreter {
public:
	std::map<string, Command*> map;
	std::map<string, double> symbolTable;
	std::map<string, string> names;
	int numline;
	//string file_path;
	//Command* comands;


public:
	Interpreter() {
		map["openDataServer"] = new OpenServerCommand(&symbolTable, &names);
		map["connect"] = new Connect();
		map["var"] = new Var(&symbolTable, &names);
		map["equal"] = new Equal(&symbolTable,&names);
		//map["while"] = new While(&numline, &file_path ,&comands);

	}

	~Interpreter() {
		delete map["openDataServer"];
		delete map["connect"];
		delete map["var"];
	}

	void perform(string command, vector<string> parameters) {
		// if (map.find(command) == map.end()) {
		// 	std::cout << "Invalid command" << std::endl;
		// 	return;
		// }
		map[command]->doCommand(parameters);
	}
 
};
