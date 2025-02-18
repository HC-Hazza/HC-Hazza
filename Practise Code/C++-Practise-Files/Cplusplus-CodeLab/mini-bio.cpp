#include <iostream>
#include <string>
using namespace std;


void logmessage(string msg) {//function declared with a string variable inside the brackets to be used within the function.
	cout << msg << endl;//you can also declare the variable inside the function.
}//this will print text in the console.

void bio(string name, string age) {//function declared with two string variables inside for the two values entered by the user.
	logmessage(name);//function from above used to print the entered text to the console from the main function.
	logmessage(age);//same for both values.
}

int main() {//this is the main function. The code will only work if this function is in the program
	logmessage("Please enter your name and age.");//this text inside the brackets will be printed to the console.
	string name, age;//declared string variables for the input.
	logmessage("Name:");//message for the console.
	getline(cin, name);//getline is for inputting string. It is better when entering more than one word for the text.
	logmessage("Age:");
	getline(cin, age);//same for the other variable.
	bio(name, age);//the bio function is then declared for printing the text that was entered by the user.

	return 0;
}
