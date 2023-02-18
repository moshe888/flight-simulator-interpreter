#include "Connect.h"


 
 
	

	int Connect::doCommand(const Line& line) {
        cout << "The client ready? enter 1" << endl;
		int x;
		cin >> x;

		string ip = line.parameters[0];
		int port = std::stoi(line.parameters[1]);
 
 	 	client->connect(port, ip);

		return 0;
	}
 