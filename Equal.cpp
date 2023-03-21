#include "Equal.h"
#include "ShuntingYard.h"
#include "Exp.h"

int Equal::doCommand(const Line &line)
{
    // Get the variable name from the SymbolTable
    string var = (symbol_table->get_names())[line.parameters[0]];
     
    vector<string> params = line.parameters;
    
    params.erase(params.begin());
    // Evaluate the expression and get its value
    double val = exp.expression_to_value(params, symbol_table);

    // Construct a message to set the variable with the given value
    string temp = string("set ") + var + " " + to_string(val) + "\r\n";
    // Send the message to the server using the Client singleton instance
    Client::getInstance()->Send(temp);

    return 0;
}

