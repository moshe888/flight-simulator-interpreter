#include <iostream>
#include <vector>
#include "Interpreter.h"
// #include "shaintrin.h"

using std::vector;
using std::string;
using std::cout;
using std::ifstream;

class Lexer {
    vector<string> split(string str, string delimiter) {
		vector<string> result;

		size_t pos = 0;
		string token;
		while ((pos = str.find(delimiter)) != string::npos) {
			token = str.substr(0, pos);
			result.push_back(token);
			str.erase(0, pos + delimiter.length());
		}
		result.push_back(str);

		return result;
	}

    vector<string> lexer(string line) {
		vector<string> parameters = split(line, " ");
		return parameters;
	}

public:
	Interpreter interpreter;

	Line* recursive() {
		string condition;
		vector<Line*> innerCommands;

		for (x : file) {
			innerCommands.push_back(parser_line(x));
		}

		return Line(condition, innerCommands);
	}

    void parser_line(string line) {
		vector<string> parameters = lexer(line);
		string command = parameters[0];

		if (parameters[1] == "=")
		{
			command = "equal";
			parameters.erase(parameters.begin()+1);//בעיה עצובית
		}
		else
		{
			parameters.erase(parameters.begin());
		}

		CommandDetails* details = new CommandDetails(command, parameters);
		
		interpreter.perform(details);  // map[command]->doCommand(parameters);
	}

	void parser_file(string File_path) {
		//interpreter.file_path = File_path;
		ifstream ins(File_path);
		string line;
		while (std::getline(ins, line)) {
		//	interpreter.numline ++;
			std::cout << line << std::endl;
			parser_line(line);
		}
	}
};
