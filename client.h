#pragma once

#include <iostream>
#include <string>
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
// #include "Command.h"
 
 

using namespace std;

class Client
{
    static Client *instance;// 

    Client()
    {
    }

public:
    int sock;
    struct sockaddr_in serv_addr;
    // int port;
    // std::string ip;

    static Client *getInstance()
    {
        if (!instance)
        {
            instance = new Client();
        }
        return instance;
    }

    int connect(int port, std::string ip);

    void Send(std::string message);

    std::string recieve();
};
