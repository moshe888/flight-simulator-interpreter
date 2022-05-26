#include "Equal.h"
#include "ShuntingYard.h"
#include "Exp.h"

int Equal ::doCommand(Line &line)
{

    Line templine = line;
    string var = (*names)[templine.parameters[0]];
    templine.parameters.erase(templine.parameters.begin());
    double val = unify(templine.parameters, symbolTable);

    string temp = string("set ") + var + " " + to_string(val)+"\r\n";
    Client::getInstance()->Send(temp);
    cout << "send : " << temp << endl ;
    //cout << "equals " << line.parameters[0] << " " << line.parameters[1] << endl;
    return 0;
}
