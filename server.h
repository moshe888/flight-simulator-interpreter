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

	void activate(int port) ;
	 
    
    string Read();
 
 };

 