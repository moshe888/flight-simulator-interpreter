// Server side C/C++ program to demonstrate Socket programming
#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
//#define PORT 8080


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
		cout<< " active0"<<std::endl;
		int server_fd;
		struct sockaddr_in address;
		int opt = 1;
		int addrlen = sizeof(address);
		
		// char *hello = "Hello from server";

		// Creating socket file descriptor
		if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
			std::cout << "socket failed" << std::endl;
			exit(1);
		}
		cout<< " active1"<<std::endl;
		
		// Forcefully attaching socket to the port 8080
		if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
			std::cout << "setsockopt failed " << setsockopt << std::endl;
			exit(1);
		}
		address.sin_family = AF_INET;
		address.sin_addr.s_addr = INADDR_ANY;
		address.sin_port = htons( port );
		cout<< " active2"<<std::endl;
	
		// Forcefully attaching socket to the port 8080
		if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0) {
			std::cout << "bind failed" << std::endl;
			exit(1);
		}
		cout<< " active3"<<std::endl;

		if (listen(server_fd, 3) < 0) {
			std::cout << "listen" << std::endl;
			exit(1);
		}
		cout<< " active4"<<std::endl;
		if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
			std::cout << "accept" << std::endl;
			exit(1);
		}
		cout<< " active"<<std::endl;

		// send(new_socket , hello , strlen(hello) , 0 );
		// printf("Hello message sent\n");
		// while (true)
		// {
		// 	int alread = read( new_socket , buffer, 1024);
		// 	printf("%s\n", buffer);
		// 	sleep(Second);
		// }
		cout<< " active5"<<std::endl;
    }

    std::string Read(){
		char buffer[1024] = {0};
		std::cout<<"**read **";
		int valread = read(new_socket, buffer, 1024);
		// printf("server read %d bytes\n", valread);
		return buffer;
    }
};

Server* Server::instance = NULL;
