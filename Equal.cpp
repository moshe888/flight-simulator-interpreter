#include "Equal.h"
#include "ShuntingYard.h"
#include "Exp.h"

int Equal::doCommand(const Line &line)
{
    // file.open("out2.txt", ios_base::app);

    string var = (*names)[line.parameters[0]];
    vector<string> params = line.parameters;
    
    params.erase(params.begin());
    double val = exp(params, symbolTable);

   // if (names->find(var) != names->end())
    // if((*names).find(line.parameters[0]) != names->end())
    // {
        string temp = string("set ") + var + " " + to_string(val) + "\r\n";
        Client::getInstance()->Send(temp);
       // file << "send : " << temp << endl;
//}
    // else
    // {
    //     symbolTable->set(line.parameters[0], val);
    // }

    // cout << "equals " << line.parameters[0] << " " << line.parameters[1] << endl;
    // file.close();

    return 0;
}
