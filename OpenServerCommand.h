#include "Command.h"
#include <string>
#include <thread> 
#include <iostream>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include "server.h"


class OpenServerCommand : public Command{

	std::thread thread;
	Server* server;
	int seconds;

public:

 	OpenServerCommand(){
		server = Server::getInstance(); 
	}

	static vector<string> initXmlTable() {
		vector<string> xmlVal;
		xmlVal.push_back("/instrumentation/airspeed-indicator/indicated-speed-kt");
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
		xmlVal.push_back("/controls/engines/current-engine/throttle");
		xmlVal.push_back("/engines/engine/rpm");
		return xmlVal;
	}
    
    int doCommand(vector<string> parameters){
        int port = std::stoi(parameters[0]);
        seconds = std::stoi(parameters[1]);

		thread = std::thread(readwhile, seconds, port, server);

		// server->activate(port);
		// readwhile(seconds, server);

		return 0;
	}

	static vector<string> split(string str, string delimiter) {
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

	static void readwhile(int seconds, int port, Server* server){
		server->activate(port);

		while(1) {
			std::string response = server->Read();
			vector<string> splitted = split(response, ",");
			vector<string> xml = initXmlTable();
			std::map<string, double> values;
			for (int i = 0; i < xml.size(); i++) {
				double number = std::stod(splitted[i].c_str());
				values[xml[i]] = number;
				std::cout << "@ " << number << std::endl;
			}

			sleep(1 / seconds);
		}
	}
	 

    ~OpenServerCommand() {
		thread.join();
    }

};

 