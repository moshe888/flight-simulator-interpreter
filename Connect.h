#pragma once

#include "client.h"

class Connect : public Command {
	
//  int port;
//  std::string ip;
	Client* client;
	//Client* nnn = new Client();

public:
	Connect() {
		client = Client::getInstance();
	}

	int doCommand(const Line& line) {
        cout << "The client ready? enter 1" << endl;
		int x;
		cin >> x;

		string ip = line.parameters[0];
		int port = std::stoi(line.parameters[1]);
 
 	 	client->connect(port, ip);

		return 0;
	}

    // void Send(std::string message) {
    //     client->Send(message);
 		 
 	// }

	// std::string recieve() {
	// 	return client->recieve();
	// }

    
};