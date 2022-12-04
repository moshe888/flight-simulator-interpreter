#include "Interpreter.h"

int main() {
    Interpreter interpreter;
    // /*string line;
    // std::cout << "  insert line: ";
    // std::getline(std::cin , line);  
    // std::cout << "  is: " << line << std::endl;
 
    // lexer.parser_line(line);
     
  //  lexer.parser_line("connect 127.0.0.1 5402");
    
  interpreter.parser_file("file6.txt");

  //   ((Connect*) lexer.interpreter.map["connect"])->Send("ls\r\n");
  //   sleep(1);
  //   ((Connect*) lexer.interpreter.map["connect"])->recieve();
  //   sleep(1);


  //   ((Connect*)(lexer.interpreter.map["connect"]))->Send("set controls/flight/rudder 1\r\n");
  //   sleep(1);
  //   ((Connect*)(lexer.interpreter.map["connect"]))->Send("set controls/flight/rudder -1\r\n");
  //   sleep(1);
  //   ((Connect*)(lexer.interpreter.map["connect"]))->Send("set controls/flight/rudder 1\r\n");
  //   sleep(1);
  //   ((Connect*)(lexer.interpreter.map["connect"]))->Send("set controls/flight/rudder -1\r\n");
  //   sleep(1);
  //   ((Connect*)(lexer.interpreter.map["connect"]))->Send("set controls/flight/rudder 1\r\n");
  //   sleep(1);
  //   ((Connect*)(lexer.interpreter.map["connect"]))->Send("set controls/flight/rudder -1\r\n");
  //   sleep(1);
  //   ((Connect*)(lexer.interpreter.map["connect"]))->Send("set controls/flight/rudder 1\r\n");
     return 0;
  }

