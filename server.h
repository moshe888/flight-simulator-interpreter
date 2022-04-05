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
    Server(){}

 public:
     static Server* getInstance() {
        if (instance == 0)
        {
            instance = new Server();
        }
        return instance;
    }


	void activate(int port){
		int server_fd;
		struct sockaddr_in address;
		int opt = 1;
		int addrlen = sizeof(address);
		
		// char *hello = "Hello from server";

		// Creating socket file descriptor
		if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
		{
			perror("socket failed");
			exit(EXIT_FAILURE);
		}
		
		// Forcefully attaching socket to the port 8080
		if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,
													&opt, sizeof(opt)))
		{
			perror("setsockopt");
			exit(EXIT_FAILURE);
		}
		address.sin_family = AF_INET;
		address.sin_addr.s_addr = INADDR_ANY;
		address.sin_port = htons( port );
	
		// Forcefully attaching socket to the port 8080
		if (bind(server_fd, (struct sockaddr *)&address,
									sizeof(address))<0)
		{
			perror("bind failed");
			exit(EXIT_FAILURE);
		}
		if (listen(server_fd, 3) < 0)
		{
			perror("listen");
			exit(EXIT_FAILURE);
		}
		if ((new_socket = accept(server_fd, (struct sockaddr *)&address,
						(socklen_t*)&addrlen))<0)
		{
			perror("accept");
			exit(EXIT_FAILURE);
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
		char buffer[1024] = {0};
		int valread = read(new_socket, buffer, 1024);
		//printf("%s\n",buffer );
		return buffer;
    }
};

Server* Server::instance = NULL;
