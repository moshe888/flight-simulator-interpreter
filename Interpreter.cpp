#include "Interpreter.h"

Interpreter::Interpreter() : symbol_table(SymbolTable::get_instance())
{
    commands["openDataServer"] = new OpenServerCommand();
    commands["connect"] = new Connect();
    commands["var"] = new Var();
    commands["equal"] = new Equal();
    commands["while"] = new While(*this);
    commands["print"] = new Print();
    commands["sleep"] = new Sleep();
}

Interpreter::~Interpreter()
{
    delete commands["openDataServer"];
    delete commands["connect"];
    delete commands["var"];
    delete commands["equal"];
    delete commands["while"];
    delete commands["print"];
    delete commands["sleep"];

    ofstream output;
    output.open("output.txt");

    output << "Symboltable:" << endl;
    for (const pair<string, float>& symbol : symbol_table->get_table()) {
        output << symbol.first << " = " << symbol.second << endl;
    }

    output << endl;

    output << "Names:" << endl;
    for (const pair<string, string>& name : names) {
        output << name.first << " = " << name.second << endl;
    }

    output.close();
}

void Interpreter::perform(const Line &line)
{
    try {
        if (commands.find(line.name_command) == commands.end())
        {
            std::cout << "Invalid command" << std::endl;
            return;
        }
        
        commands[line.name_command]->doCommand(line);
    }
    catch (const std::exception& e) {
        std::cout << "EXCEPTION " << e.what() << std::endl;//?
        exit(1);
    }
}

void Interpreter::parser_file(const string& file_path)
{
    ifstream ins(file_path);
    if (ins.fail()){
        cout << "File does not exist"<<endl;
         
    }
    string str;
    while (std::getline(ins, str))
    {
        std::cout << str << std::endl;

        Line line = create_line.create_line(str, ins);
        perform(line);
    }
     
}
