#include "Var.h"

int Var::doCommand(const Line &line)
{
    // cout << "Var " << line.parameters[0] << endl;

    if (line.parameters[1] != "=")
    {
        throw std::runtime_error("var command - no = in the expected place");
    }

    if (line.parameters[2] == "bind")
    {
        symbol_table->set_name(line.parameters[0],
            line.parameters[3].substr(1, line.parameters[3].size() - 2));
        symbol_table->set(line.parameters[0], 0);
    }
    else
    {
        double d = symbol_table->get(line.parameters[2]);
        symbol_table->set(line.parameters[0], d);
    }

    return 0;
}
