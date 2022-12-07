#include "Parser.h"



vector<string> Parser::lexer(string line)
{
	 
	vector<string> parameters = Tools::split(line, " ");
	return parameters;
}


vector<Line> Parser::create_inner_lines(ifstream& ins)  
{
	string str;
	vector<Line> inner_commands;
	std::getline(ins, str);
	while (lexer(str)[0] != "}")
	{
		Line line = create_line(str, ins);
		inner_commands.push_back(line);

		std::getline(ins, str);
	}

	return inner_commands;
}

Line Parser::create_line(const string& str, ifstream& ins)
{
	Line line;

	line.parameters = lexer(str);
	line.name_command = line.parameters[0];

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
		line.list_command = create_inner_lines(ins);
	}

	return line;
}

// void Parser :: parser_file(string file_path)
// {
		
// 	ifstream ins(file_path);
// 	string str;
// 	while (std::getline(ins, str))
// 	{
			
// 		std::cout << str << std::endl;

// 		Line line = create_line(str, ins);
// 		// interpreter.perform(line);

// 	}
// }
