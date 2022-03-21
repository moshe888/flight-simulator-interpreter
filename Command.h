#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

class Command {
public:
	// השווה 0 אומר שהפונקציה היא וירטואלית-טהורהaa
	// כלומר אי אפשר ליצור משתנים מהמחלקה, אלא רק מהמחלקות היורשות שיממשו את פונקציה הזאת
	// הוירטואל עצמו גורם לפולימורפיזם, כלומר שיהיה שימוש בפונקציה של מחלקת הבן ולא של האב
	virtual int doCommand(vector<string> parameters) = 0;
	virtual ~Command() {}
};
