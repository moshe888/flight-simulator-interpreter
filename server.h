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

    // Private constructor to ensure singleton class
    Server() : new_socket(0)
    {}

public:
    // Singleton implementation, get the instance of the server
    static Server* getInstance() {
        if (!instance ) {
            instance = new Server();
        }
        return instance;
    }

    // Start listening to incoming connections on the given port
    void activate(int port) ;
 
    // Read data from the connected client
    string Read();
};
