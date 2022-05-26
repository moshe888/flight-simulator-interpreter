#include "Var.h"
 

 int Var :: doCommand(Line& line){
    cout << "Var " << line.parameters[0] << endl;
    if (line.parameters[2] == "bind") {
        (*names)[line.parameters[0]] = line.parameters[3].substr(1, line.parameters[3].size() - 2);
        (*symbolTable)[line.parameters[0]] = 0;
    }
    else {
        //(*names)[line.parameters[0]] = "";//?
        (*symbolTable)[line.parameters[0]] = (*symbolTable)[line.parameters[2]];
    }
    

    return 0;  
}
