#include <iostream>
#include <string>
using namespace std;

void print(string msg) {

	cout << msg << endl;
}//this function is used for printing text to the console.

int main() {

	enum class Direction {
		NOWHERE,
		UP,
		DOWN,
		LEFT,
		RIGHT
	};//an enum is declared and initialised with 4 elements.

	Direction movement = Direction::NOWHERE;//a variable made using the enum.

	char userMovement;//a variable for the direction keys.
	print("Where would you like to go?\n W: Up\n S: Down\n A: Left\n D: Right\n");//this text is outputted to the console.
	cin >> userMovement;//user input for the movement they want to do.
	userMovement = toupper(userMovement);//this will make the entered letter a capital letter.

	switch (userMovement) {//the switch is used for when the user inputs the certain letters.
	case 'W'://W is up
		movement = Direction::UP;
		break;
	case 'S'://S is down.
		movement = Direction::DOWN;
		break;
	case 'A'://A is left
		movement = Direction::LEFT;
		break;
	case 'D'://D is right.
		movement = Direction::RIGHT;
		break;
	default:
		movement = Direction::NOWHERE;
	}

	switch (movement) {//another switch statement, which depends on the user input again, but it uses the enum variables instead.
	case Direction::UP:
		print("You have moved upwards.");
		break;
	case Direction::DOWN:
		print("You have moved downwards.");
		break;
	case Direction::LEFT:
		print("You have moved to the left.");
		break;
	case Direction::RIGHT:
		print("You have moved to the right.");
		break;
	default:
		print("You have moved nowhere.");
	}//if the user enters anything but w, a, s or d, the program will print the default option.

	return 0;
}
