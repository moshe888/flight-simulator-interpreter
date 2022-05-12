#include "Command.h"
#include "lexer.h"


class While : public Command 
{
    int* numline;
	string* file_path;
    Command** comands;
public: 
    While(int* numline,string* file_path , Command** comands) 
        : Command() , numline(numline) , file_path(file_path) , comands(comands) {}

     int doCommand(vector<string> parameters){
         Lexer lexer;
        //  לרווץ בלולאה ממספר השורה ולהכניס לקובץ 
        //  ןאחר כך נפעילר פרסר בלולאה כל עוד התנא מתקיים
        //  ןלמחוק את הקובץ

        

     }

    
    
};
