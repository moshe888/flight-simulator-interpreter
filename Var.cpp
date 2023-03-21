#include "Var.h"

int Var::doCommand(const Line &line)
{
     

    if (line.parameters[1] != "=")
    {
        throw std::runtime_error("var command - no = in the expected place");
    }
    // If the third parameter is "bind", add a new variable to the symbol table with the given name
    if (line.parameters[2] == "bind")
    {
        symbol_table->set_name(line.parameters[0],
            line.parameters[3].substr(1, line.parameters[3].size() - 2));
        symbol_table->set(line.parameters[0], 0);
    }
    // If the third parameter is not "bind", set the value of the first parameter to the value of the third parameter
    else
    {
        double d = symbol_table->get(line.parameters[2]);
        symbol_table->set(line.parameters[0], d);
    }

    return 0;
}
