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

// Connect(int port, std::string ip):Command() , port(port),ip(ip){}


	int doCommand(vector<string> parameters) {
		string ip = parameters[0];
		int port = std::stoi(parameters[1]);
 
 	 	client->connect(port, ip);

		return 0;
	}

     void Send(std::string message) {
        client->Send(message);
 		 
 	}

	std::string recieve() {
		return client->recieve();
	}

    
};