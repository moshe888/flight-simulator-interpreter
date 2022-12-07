#pragma once

#include <vector>
#include <string>

using std::string;
using std::vector;

class Tools
{
 public:
 static vector<string>  split(string str, const string& delimiter)
{
	vector<string> result;

	size_t pos = 0;
	string token;
	while ((pos = str.find(delimiter)) != string::npos)
	{
		token = str.substr(0, pos);
		while (token[0] == ' ' || token[0] == '\t' || token[0] == '\r' || token[0] == '\n') {
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

};
