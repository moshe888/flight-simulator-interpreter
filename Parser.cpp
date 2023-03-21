#include "Parser.h"



#include "Parser.h"

 
vector<string> Parser::lexer(string line)
{
    vector<string> parameters = Tools::split(line, " ");
    return parameters;
}

// Parse a block of code inside curly braces into a vector of Line objects(for while)
vector<Line> Parser::create_inner_lines(ifstream& ins)  
{
    string str;
    vector<Line> inner_commands;
    std::getline(ins, str);
    while (lexer(str)[0] != "}")  
    {
        Line line = create_line(str, ins); // parse each line inside the block
        inner_commands.push_back(line);

        std::getline(ins, str);
    }

    return inner_commands;
}

// Parse a single line of code into a Line object
Line Parser::create_line(const string& str, ifstream& ins)
{
    //create a new Line object represent the parsed line
    Line line;
    //Split the string into parameters by lexer
    line.parameters = lexer(str);
    line.name_command = line.parameters[0];

    if (line.parameters[1] == "=") 
    {
        line.name_command = "equal"; 
        line.parameters.erase(line.parameters.begin() + 1);  
    }
    else
    {
        line.parameters.erase(line.parameters.begin()); // remove the command name from parameters
    }

    if (line.name_command == "while")  
    {
        line.parameters.erase(line.parameters.end() - 1);  
        line.list_command = create_inner_lines(ins); // parse the inner block of code
    }

    return line;
}
