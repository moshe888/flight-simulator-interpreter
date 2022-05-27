#pragma once

#include "Command.h"
#include <string>
#include <thread>
#include <map>
#include <iostream>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include "server.h"

class OpenServerCommand : public Command
{
	std::thread thread;
	Server *server;
	int seconds;
	std::map<string, double> *symbolTable;
	std::map<string, string> *names;

public:
	OpenServerCommand(std::map<string, double> *symbolTable, std::map<string, string> *names) : Command(), symbolTable(symbolTable), names(names)
	{

		server = Server::getInstance();
	}

	static vector<string> initXmlTable()
	{
		vector<string> xmlVal;

		xmlVal.push_back("/instrumentation/airspeed-indicator/indicated-speed-kt");
		xmlVal.push_back("/sim/time/warp");
		xmlVal.push_back("/controls/switches/magnetos");
		xmlVal.push_back("/instrumentation/heading-indicator/offset-deg");
		xmlVal.push_back("/instrumentation/altimeter/indicated-altitude-ft");
		xmlVal.push_back("/instrumentation/altimeter/pressure-alt-ft");
		xmlVal.push_back("/instrumentation/attitude-indicator/indicated-pitch-deg");
		xmlVal.push_back("/instrumentation/attitude-indicator/indicated-roll-deg");
		xmlVal.push_back("/instrumentation/attitude-indicator/internal-pitch-deg");
		xmlVal.push_back("/instrumentation/attitude-indicator/internal-roll-deg");
		xmlVal.push_back("/instrumentation/encoder/indicated-altitude-ft");
		xmlVal.push_back("/instrumentation/encoder/pressure-alt-ft");
		xmlVal.push_back("/instrumentation/gps/indicated-altitude-ft");
		xmlVal.push_back("/instrumentation/gps/indicated-ground-speed-kt");
		xmlVal.push_back("/instrumentation/gps/indicated-vertical-speed");
		xmlVal.push_back("/instrumentation/heading-indicator/indicated-heading-deg");
		xmlVal.push_back("/instrumentation/magnetic-compass/indicated-heading-deg");
		xmlVal.push_back("/instrumentation/slip-skid-ball/indicated-slip-skid");
		xmlVal.push_back("/instrumentation/turn-indicator/indicated-turn-rate");
		xmlVal.push_back("/instrumentation/vertical-speed-indicator/indicated-speed-fpm");
		xmlVal.push_back("/controls/flight/aileron");
		xmlVal.push_back("/controls/flight/elevator");
		xmlVal.push_back("/controls/flight/rudder");
		xmlVal.push_back("/controls/flight/flaps");
		xmlVal.push_back("/controls/engines/engine/throttle");
		xmlVal.push_back("/controls/engines/current-engine/throttle");
		xmlVal.push_back("/controls/switches/master-avionics");
		xmlVal.push_back("/controls/switches/starter");
		xmlVal.push_back("/engines/active-engine/auto-start");
		xmlVal.push_back("/controls/flight/speedbrake");
		xmlVal.push_back("/sim/model/c172p/brake-parking");
		xmlVal.push_back("/controls/engines/engine/primer");
		xmlVal.push_back("/controls/engines/current-engine/mixture");
		xmlVal.push_back("/controls/switches/master-bat");
		xmlVal.push_back("/controls/switches/master-alt");
		xmlVal.push_back("/engines/engine/rpm");
		return xmlVal;
	}

	int doCommand(Line &line)
	{
		int port = std::stoi(line.parameters[0]);
		seconds = std::stoi(line.parameters[1]);

		server->activate(port);
		std::cout << "open server" << std::endl;

		// readwhile(seconds, port, symbolTable, names, server);
		thread = std::thread(readwhile, seconds, port, symbolTable, names, server);

		// sleep(60);
		return 0;
	}

	static vector<string> split(string str, string delimiter)
	{
		vector<string> result;

		size_t pos = 0;
		string token;
		while ((pos = str.find(delimiter)) != string::npos)
		{
			token = str.substr(0, pos);
			result.push_back(token);
			str.erase(0, pos + delimiter.length());
		}
		result.push_back(str);

		return result;
	}

	static void readwhile(int seconds, int port, std::map<string, double> *symbolTable,
						  std::map<string, string> *names, Server *server)
	{

		vector<string> xml = initXmlTable(); //למה בפונקציה?

		ofstream file;
		file.open("out.txt");
			ofstream file1;
		file1.open("out1.txt");

		while (1)
		{
			file << "--------------\n";

			std::string response = server->Read();
			file << response << "\n";
			vector<string> spl = split(response, ",");
			file << spl.size() << endl;
			for (int i = 0; i < xml.size(); i++)
			{
				if (spl[i] == "" || spl[i] == " ")
				{
					continue;
				}
				//	cout << "stod " << spl[i] << endl;
				double number = stod(spl[i]);
				// std::cout << "a3" << std::endl;
				for (const std::pair<string, string> &p : *names)
				{
					if (p.second == xml[i])
					{
						//	cout << p.first  << " updating to :" << number << endl;
						(*symbolTable)[p.first] = number;
						file1 << p.first << "  updating to : " << (*symbolTable)[p.first] << endl;
						break;
					}
				}
				// std::cout << "@ " << number << std::endl;
			}


			sleep(1 / seconds);
		}
		
		file.close();
	}

	~OpenServerCommand()
	{
		thread.join();
	}
};
