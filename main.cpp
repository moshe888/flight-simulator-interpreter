#include "Interpreter.h"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "Enter the path of instruction file" << std::endl;
        return 0;
    }
    Interpreter interpreter;
 
    
  interpreter.parser_file(argv[1]);

  

   
     return 0;
  }

