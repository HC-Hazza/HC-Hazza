#define _USE_MATH_DEFINES//this gives me the ability to use pi.

#include <iostream>
#include <string>
using namespace std;


void logMessage(string msg) {//a function for printing text for the console.
	cout << msg << endl;
}

void square() {//this function is for finding the area of a square.
	double length;//decimal variable declared for user input.
	logMessage("Please enter the length of a side of your square.");//this is printed to the console.
	cin >> length;//user input for the decimal.
	double sqrArea = pow(length, 2);//the pow function multiplies a number by itself as many times as the second number.
	cout << "This is the area of your square: " << sqrArea;//the text is printed to the console plus the answer.
}


void circle() {//this function is for finding the area of a circle.
	double radius;//decimal for the radius of the circle.
	logMessage("Please enter the radius of a side of your circle.");//this text is printed to the console.
	cin >> radius;//user input for the radius of the circle.
	double circArea = 2 * M_PI * (pow(radius, 2));//M_PI is pi. This formula calculates the area of a circle.
	cout << "This is the area of your circle: " << circArea;//the text is printed to the console as well as the answer.
}


void triangle() {
	double base, height;//two variables this time. One for the bottom of the triangle and one for the verticle height of it.
	logMessage("Please enter the base and height of your triangle.");//this text is printed to the console.
	cin >> base; cin >> height;//the two decimals can be entered by the user.
	double triArea = (base * height) / 2;//this is the formula for the area of a triangle.
	cout << "This is the area of your triangle: " << triArea;//this text is printed to the console plus the answer.
}



int main() {
	int menu; //integer for the menu that the user can use.
	logMessage("1. Calculate the area of a square. \n2. Calculate the area of a circle. \n3. Calculate the area of a triangle.");//this is printed to the console, with a new line after the \n.
	cin >> menu;//user input for the menu.
	while (cin.fail()) {
		cin.ignore(1000, '\n');
		cin.clear();
		logMessage("Please enter a proper answer to the menu above: ");
		cin >> menu;
	}//a while loop to make sure the user enters a number.

	bool doWhile = false;//this boolean will make sure the user enters a number between 1 and 3.

	do {//the do while will loop until the boolean switches to true.
		switch (menu) {
		case 1:
			square();//when 1 is entered, the square area function will run and the boolean will change.
			doWhile = true;
			break;
		case 2:
			circle();//2 entered means the circle area function.
			doWhile = true;
			break;
		case 3:
			triangle();// 3 is the triangle area function.
			doWhile = true;
			break;
		default://if something other than any of the other ones are entered, this will print.
			logMessage("Please enter a proper answer to the menu above: ");
			cin >> menu;
		}
	} while (doWhile == false);

	return 0;
}
