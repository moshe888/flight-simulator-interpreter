#pragma once

#include <iostream>
#include <vector>
#include "Interpreter.h"
#include "Line.h"
 

 using namespace std;

class Lexer
{
	vector<string> split(string str, string delimiter)
	{
		vector<string> result;

		size_t pos = 0;
		string token;
		while ((pos = str.find(delimiter)) != string::npos)
		{
			token = str.substr(0, pos);
			while (token[0] == ' ' || token[0] == '\t') {
				token.erase(token.begin());
			}
			if (token != "") {
				result.push_back(token);
			}
			str.erase(0, pos + delimiter.length());
		}
			result.push_back(str);

		return result;
	}

	vector<string> lexer(string line)
	{
		vector<string> parameters = split(line, " ");
		return parameters;
	}

public:
	Interpreter interpreter;

	vector<Line> recursive(ifstream& ins) //למה מצביע?
	{
		string str;
		vector<Line> innerCommands;
		std::getline(ins, str);
		while (lexer(str)[0] != "}")
		{
			//	interpreter.numline ++;
			std::cout << str<< "(while)" << std::endl;

			Line line = parser(str, ins);
			innerCommands.push_back(line);

			std::getline(ins, str);
		}

		return innerCommands;
	}

	Line parser(string str, ifstream& ins)
	{
		Line line;

		line.parameters = lexer(str);
		line.name_command = line.parameters[0];
		line.str_line = str;

		//	string command = parameters[0];

		if (line.parameters[1] == "=")
		{
			line.name_command = "equal";
			line.parameters.erase(line.parameters.begin() + 1); //בעיה עצובית
			 
			
		}

		else
		{
			line.parameters.erase(line.parameters.begin());
		}

		if (line.name_command == "while")
		{

			// while(כל עוד התנאי מתקיים
			line.parameters.erase(line.parameters.end() - 1);
			//	line.interpreter = &interpreter;
			line.list_command = recursive(ins);
		}

		return line;

		// CommandDetails* details = new CommandDetails(command, parameters);

		//	interpreter.perform(details);  // map[command]->doCommand(parameters);
	}

	void parser_file(string File_path)
	{
		// interpreter.file_path = File_path;

		ifstream ins(File_path);
		string str;
		while (std::getline(ins, str))
		{
			//	interpreter.numline ++;
			std::cout << str << std::endl;

			Line line = parser(str, ins);
			interpreter.perform(line);

		}
	}
};
