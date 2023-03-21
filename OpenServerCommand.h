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
#include "Tools.cpp"

// class OpenServerCommand : public Command
// {
//     std::thread thread; // represents the thread that the server is running on
//     Server* server; // the server instance
//     Tools tools;  

//     SymbolTable* symbol_table;  
//     bool end;  

//     static vector<string> initXmlTable(); // a static function for parsing the XML table

// public:
//     OpenServerCommand() : Command(), server(Server::getInstance()), 
//         symbol_table(SymbolTable::get_instance()), end(false)
//     {}

//     int doCommand(const Line &line);  
//     static void read_from_server(int seconds, int port, SymbolTable *symbol_table, Server *server);
//     // a static function for reading data from the server

//     ~OpenServerCommand() // destructor for stopping the server
//     {
//         thread.join();
//     }
// };
class OpenServerCommand : public Command {
private:
    std::thread thread;
    Server* server;
    Tools tools;
    SymbolTable* symbol_table;
    bool end;

    static vector<string> initXmlTable();
    static void updateSymbolTable(SymbolTable* symbol_table,const vector<string>& data, const vector<string>& xml, ofstream& file);

public:
    OpenServerCommand() :
        Command(), server(Server::getInstance()), symbol_table(SymbolTable::get_instance()), end(false)
    {}
 
    int doCommand(const Line &line);
    static void read_from_server(int seconds, int port, SymbolTable *symbol_table, Server *server);

    ~OpenServerCommand() {
        thread.join();
    }
};
