#include<iostream>
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include "Command.h"




class Client
{
           static Client* instance  ;

    
         Client (){}
    public:
        int sock;
    	struct sockaddr_in serv_addr;
        int port;
        std::string ip;

        static Client* getInstance()
         {
        
        if (instance == 0)
        {
            instance = new Client();
        }
          return instance;
        }

     
	
 public:
    
    int connect(int port, std::string ip){
        sock = socket(AF_INET, SOCK_STREAM, 0);
        serv_addr.sin_family = AF_INET;
        serv_addr.sin_port = htons(port);

        // Convert IPv4 and IPv6 addresses from text to binary form
		if (inet_pton(AF_INET, ip.c_str(), &serv_addr.sin_addr) <= 0) {
			printf("\nInvalid address/ Address not supported \n");
			return -1;
		}

		if (::connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
		{
			printf("\nConnection Failed \n");
			return -1;
		}

        return 0;
    }

    void Send(std::string message) {
 		send(sock, message.c_str(), message.length(), 0);
 	}

	std::string recieve() {
		char buffer[1024] = {0};
	    int valread = read( sock , buffer, 1024);
		std::cout << buffer << std::endl;
		return std::string(buffer);
	}

   

};

Client* Client::instance = NULL;

    
 

 