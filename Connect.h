#pragma once

#include "client.h"
#include "Command.h"

class Connect : public Command {
	
 	// The connect command will use this object to communicate with the simulator.
	Client* client;

public:
	// Constructor to initialize the client pointer with the singleton instance of Client.
	Connect() {
		client = Client::getInstance();
	}

	// This method connects to the simulator using the IP and port given in the line parameters.
	int doCommand(const Line& line);

}; 
