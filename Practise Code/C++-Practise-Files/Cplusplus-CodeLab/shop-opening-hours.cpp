#include <iostream>
#include <string>
using namespace std;

void print(string msg) { cout << msg << endl; }

int main() {
	enum class OpenDays {//enum class for the days of the week.
		MONDAY = 1,//monday is the first day, which is why it is set to one, otherwise it would start at 0.
		TUESDAY,
		WEDNESDAY,
		THURSDAY,
		FRIDAY,
		SATURDAY,
		SUNDAY
	};

	print("Select a day for the opening hours \n1. Monday \n2. Tuesday \n3. Wednesday \n4. Thursday \n5. Friday \n6. Saturday \n7. Sunday");
	/*the text inside this function will be printed to the console. \n divides them into their own lines.*/

	int userInput;
	cin >> userInput;//the integer above is initialised by the user.
	while (cin.fail() || (userInput < 1 || userInput > 7)) {
		cin.clear();
		cin.ignore(1000, '\n');
		print("You need to enter something within the parameter.");
		cin >> userInput;
	}
	/*this while loop will check to see if the user has entered a number within the set of numbers they were told above.*/

	switch (static_cast<OpenDays>(userInput)) {
		/*static cast calls for the number that is inside the enum and compares it to the number from the integer variable from the user.*/
	case OpenDays::MONDAY://the switch statement is written the same as the previous task, using the name of the enum as well as the name of the variables inside it.
		print("We are not open today.");//this is printed to the console if the user enters 1.
		break;
	case OpenDays::TUESDAY:
	case OpenDays::WEDNESDAY:
	case OpenDays::THURSDAY:
		print("We are open from 11am to 10pm.");//this is printed to the console if the user enters 2, 3 or 4.
		break;
	case OpenDays::FRIDAY:
	case OpenDays::SATURDAY:
	case OpenDays::SUNDAY:
		print("We are open from 11am to 11.30pm");//this is printed to the console if the user enters 5, 6 or 7.
		break;
	}

	return 0;
}
