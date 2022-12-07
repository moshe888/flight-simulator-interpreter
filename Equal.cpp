#include "Equal.h"
#include "ShuntingYard.h"
#include "Exp.h"

int Equal::doCommand(const Line &line)
{
    string var = (symbol_table->get_names())[line.parameters[0]];
    vector<string> params = line.parameters;
    
    params.erase(params.begin());
    double val = exp.expression_to_value(params, symbol_table);

   
        string temp = string("set ") + var + " " + to_string(val) + "\r\n";
        Client::getInstance()->Send(temp);
 

    return 0;
}
