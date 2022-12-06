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
#include "Tools.h"

class OpenServerCommand : public Command
{
	std::thread thread;
	Server* server;
	Tools tools;
	
	SymbolTable* symbol_table;
	bool end;

	static vector<string> initXmlTable();

public:
	OpenServerCommand() : 
		Command(), server(Server::getInstance()), symbol_table(SymbolTable::get_instance()), end(false)
	{}
 
	int doCommand(const Line &line);
 
	// static vector<string> split(string str, string delimiter);
 
	static void read_from_server(int seconds, int port, SymbolTable *symbol_table, Server *server);
	
	~OpenServerCommand()
	{
		thread.join();
	}
};
