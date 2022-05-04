#include <iostream>
#include <vector>
#include "Interpreter.h"

using std::vector;
using std::string;

class Lexer {
public:
    Interpreter interpreter;

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
		vector<string> words = split(line, " ");
		return words;
	}

public:
    void parser_line(string line) {
 		vector<string> words = lexer(line);
		string command = words[0];
		words.erase(words.begin());
		interpreter.perform(command, words);  // map[command]->doCommand(words);
	}

	void parser_file(string File_path) {
		std::ifstream ins(File_path);
		std::string line;
		while (std::getline(ins, line)) {
			std::cout << line << std::endl;
			parser_line(line);
		}
	}
};
