#pragma once

#include "client.h"
#include "Command.h"

class Connect : public Command {
	
//  int port;
//  std::string ip;
	Client* client;
	//Client* nnn = new Client();

public:
	Connect() {
		client = Client::getInstance();
	}

	int doCommand(const Line& line) ;

    // void Send(std::string message) {
    //     client->Send(message);
 		 
 	// }

	// std::string recieve() {
	// 	return client->recieve();
	// }

    
};