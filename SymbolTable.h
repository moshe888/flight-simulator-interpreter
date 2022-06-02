#pragma once

#include <iostream>
#include <mutex>

using namespace std;

class SymbolTable
{
private:
    map<string, double> symbolTable;
    mutex mtx;

public:
    void set(string key, double d)
    {
        lock_guard<mutex> lock(mtx);
        symbolTable[key] = d;
    }

    double get(string key)
    {
        lock_guard<mutex> lock(mtx);
        return symbolTable[key];
    }

    bool exists(string key)
    {
        lock_guard<mutex> lock(mtx);
        return symbolTable.find(key) != symbolTable.end();
    }

    map<string, double> getTable()
    {
        return symbolTable;
    }
};