#include "Command.h"
#include <map>

class Interpreter {
	std::map<string, Command> map;

	vector<string> split(string str, string delimiter) {
		vector<string> result;

		size_t pos = 0;
		string token;
		while ((pos = str.find(delimiter)) != string::npos) {
			token = str.substr(0, pos);
			result.push_back(token);
			str.erase(0, pos + delimiter.length());
		}

		return result;
	}

public:
	Interpreter() {
		// map["a"] = A();
	}

	int perform(string command, vector<string> parameters) {
		return map[command].doCommand(parameters);
	}

	vector<string> lexer(string line) {
		vector<string> words = split(line, " ");
		return words;
	}

	void parser(string line) {
		vector<string> words = lexer(line);
		string command = words[0];
		words.erase(words.begin());  // delete first
		perform(command, words);
	}
};
