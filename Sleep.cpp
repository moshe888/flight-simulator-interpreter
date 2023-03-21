#include "Sleep.h"


int Sleep::doCommand(const Line& line) 
{
        double ms = stod(line.parameters[0]) / 1000;
        sleep(ms);
        // cout << "sleep " << ms << endl;

        return 0;
    }