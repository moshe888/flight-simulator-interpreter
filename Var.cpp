#include "Var.h"

 int Var :: doCommand(vector<string> parameters){
    if (parameters[2] == "bind") {
            (*names)[parameters[0]] = parameters[3].substr(1, parameters[3].size() - 2);    
        }
        else {
            //(*names)[parameters[0]] = "";//?
            (*symbolTable)[parameters[0]] = (*symbolTable)[parameters[2]];
        }

        return 0;  
}
