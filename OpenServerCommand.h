#pragma once

#include "Command.h"
#include <string>
#include <thread>
#include <map>
#include <iostream>
#include "SymbolTable.h"
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include "server.h"

class OpenServerCommand : public Command
{
	std::thread thread;
	Server *server;
	int seconds;
	SymbolTable *symbolTable;
	std::map<string, string> *names;
	bool end;

public:
	OpenServerCommand(SymbolTable *symbolTable, std::map<string, string> *names)
	 : Command(), symbolTable(symbolTable), names(names), end(false)
	{

		server = Server::getInstance();
	}

	static vector<string> initXmlTable();
 

	int doCommand(const Line &line);
 

	static vector<string> split(string str, string delimiter);
 

	static void readwhile(int seconds, int port, SymbolTable *symbolTable,std::map<string, string> *names, Server *server);
	
	~OpenServerCommand()
	{
	
		thread.join();
	}
};
