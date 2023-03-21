#pragma once

#include <iostream>
#include <string>
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

using namespace std;

class Client
{
    static Client *instance;// pointer to the only instance of Client class

    Client(){}

public:
    int sock;
    struct sockaddr_in serv_addr;

    // Singleton pattern - gets the only instance of Client class
    static Client *getInstance()
    {
        if (!instance)
        {
            instance = new Client();
        }
        return instance;
    }

    // connects to a server with a given IP and port
    int connect(int port, std::string ip);

    // sends a message to the connected server
    void Send(std::string message);

    // receives a message from the connected server
    std::string recieve();
};
