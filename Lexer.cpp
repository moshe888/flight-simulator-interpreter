#include "Lexer.h"




	vector<string> Lexer :: split(string str, string delimiter)
	{
		vector<string> result;

		size_t pos = 0;
		string token;
		while ((pos = str.find(delimiter)) != string::npos)//?
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

	vector<string> Lexer ::  lexer(string line)
	{
		while (line[0] == ' ' || line[0] == '\t' || line[0] == '\r' || line[0] == '\n') {
			line.erase(0, 1);
		}
		vector<string> parameters = split(line, " ");
		return parameters;
	}


	vector<Line> Lexer :: recursive(ifstream& ins)  
	{
		string str;
		vector<Line> innerCommands;
		std::getline(ins, str);
		while (lexer(str)[0] != "}")
		{
			//	interpreter.numline ++;
			//std::cout << str<< "(while)" << std::endl;

			Line line = parser(str, ins);
			innerCommands.push_back(line);

			std::getline(ins, str);
		}

		return innerCommands;
	}

	Line Lexer :: parser(string str, ifstream& ins)
	{
		Line line;

		line.parameters = lexer(str);
		line.name_command = line.parameters[0];
		//line.str_line = str;

		//	string command = parameters[0];

		if (line.parameters[1] == "=")
		{
			line.name_command = "equal";
			line.parameters.erase(line.parameters.begin() + 1);  
		}
		else
		{
			line.parameters.erase(line.parameters.begin());
		}

		if (line.name_command == "while")
		{

 			line.parameters.erase(line.parameters.end() - 1);
			//	line.interpreter = &interpreter;
			line.list_command = recursive(ins);
		}

		return line;

	 
	}

	// void Lexer :: parser_file(string file_path)
	// {
		 
	// 	ifstream ins(file_path);
	// 	string str;
	// 	while (std::getline(ins, str))
	// 	{
			 
	// 		std::cout << str << std::endl;

	// 		Line line = parser(str, ins);
	// 		// interpreter.perform(line);

	// 	}
	// }

