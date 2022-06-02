#pragma once

#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <iostream>

using namespace std;

class Server{
	int new_socket;
    static Server* instance;
	
    Server() : new_socket(0)
	{}

public:
     static Server* getInstance() {
        if (instance == 0) {
            instance = new Server();
        }
        return instance;
    }

	void activate(int port) {
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
		
		// Forcefully attaching socket to the port 8080
		if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
			std::cout << "setsockopt failed " << setsockopt << std::endl;
			exit(1);
		}
		address.sin_family = AF_INET;
		address.sin_addr.s_addr = INADDR_ANY;
		address.sin_port = htons( port );
	 
	
		// Forcefully attaching socket to the port 8080
		if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0) {
			std::cout << "bind failed" << std::endl;
			exit(1);
		}
	 

		if (listen(server_fd, 3) < 0) {
			std::cout << "listen" << std::endl;
			exit(1);
		}
	 
		if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
			std::cout << "accept" << std::endl;
			exit(1);
		}
	 

		// send(new_socket , hello , strlen(hello) , 0 );
		// printf("Hello message sent\n");
		// while (true)
		// {
		// 	int alread = read( new_socket , buffer, 1024);
		// 	printf("%s\n", buffer);
		// 	sleep(Second);
		// }
 
    }

    std::string Read(){
		char buffer[10024] = {0};
	//	std::cout<<"**read **";
		int valread = read(new_socket, buffer, 10024);
		// printf("server read %d bytes\n", valread);
		return buffer;
    }
};

// Server* Server::instance = NULL;
