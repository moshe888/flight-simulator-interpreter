
#include "server.h"

Server* Server::instance = nullptr;
 
	void Server :: activate(int port) {
		std::cout<< " active"<<std::endl;
		int server_fd;
		struct sockaddr_in address;
		int opt = 1;
		int addrlen = sizeof(address);
		
		// char *hello = "Hello from server";

		// Creating socket file descriptor
		if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
			throw runtime_error("socket failed");
			// std::cout << "socket failed" << std::endl;
			// exit(1);
		}		
		
		// Forcefully attaching socket to the port 
		if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
			std::cout << "setsockopt failed " << setsockopt << std::endl;
			exit(1);
		}
		address.sin_family = AF_INET;
		address.sin_addr.s_addr = INADDR_ANY;
		address.sin_port = htons( port );
	 
	
		// Forcefully attaching socket to the port 
		if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0) {
			std::cout << "bind failed" << std::endl;
			exit(1);
		}
	 

		if (listen(server_fd, 3) < 0) {
			std::cout << "listen" << std::endl;
			exit(1);
			
		}
	 
		if ((new_socket = accept(server_fd, (struct sockaddr * )&address, (socklen_t*)&addrlen)) < 0) {
			std::cout << "accept" << std::endl;
			exit(1);
		}
	 
 
    }

  string  Server:: Read(){
		char buffer[1024] = {0};
		int valread = read(new_socket, buffer, 1024);

		return buffer;
    }


 