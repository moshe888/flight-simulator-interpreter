#include "client.h"


Client* Client::instance = NULL;

    
    int Client :: connect(int port, std::string ip){
        sock = socket(AF_INET, SOCK_STREAM, 0);

        serv_addr.sin_family = AF_INET;  // tell the connect use IP
        serv_addr.sin_port = htons(port);  // put the port in the connect

        // Convert IPv4 and IPv6 addresses from text to binary form
		if (inet_pton(AF_INET, ip.c_str(), &serv_addr.sin_addr) <= 0) {
			printf("\nInvalid address/ Address not supported \n");
			return -1;
		}

		if (::connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
			printf("\nConnection Failed \n");
			return -1;
		}

        return 0;
    }

    void Client :: Send(std::string message) {
 		send(sock, message.c_str(), message.length(), 0);
 	}

string	Client:: recieve() {
		char buffer[1024] = {0};
	    int valread = read( sock , buffer, 1024);
		std::cout << buffer << std::endl;
		return std::string(buffer);
	}

   