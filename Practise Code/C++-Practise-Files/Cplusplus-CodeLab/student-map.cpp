#include <iostream>
#include <string>
#include <map>
#include <unordered_map>
using namespace std;

void print(string msg) {
	cout << msg;
}//this function is used for printing text to the console instead of cout.

int main() {
	int keyInput;//this is for the user to use to enter the student id in the first section of the map.
	char continueInput = 'Y';//this is for a while loop so the user can find as many students as they want.
	map<int, string> students{ //the map here hosts 5 student names and their ID numbers. These numbers are going to be used as keys to find the student names.
	{699128, "John Smith"},
	{707171, "Amy Gallagher"},
	{590893, "Steven Lewis"},
	{546997, "Mina Rosenthal"},
	{482493, "Daniel McGloughlin"}
	};

	while (continueInput == 'Y') {//the beginning of the while loop, so the program can loop as much as the user wants.

		print("Please enter the student's number. \nStudent #: ");//this is printed to the console.
		cin >> keyInput;//the user can input the key for the student name.
		while (cin.fail()) {//if the user enters anything but a number, the console will give them an error for it.
			cin.clear();
			cin.ignore();
			print("Please enter a number.\n");
			cin >> keyInput;
		}

		auto finder = students.find(keyInput);//this variable will use the number inputted by the user and iterate through the map to find it.
		if (finder != students.end()) {//if the iterator finds the value, it will not reach the end of the map. Instead, it will stop at the entered value.
			cout << "A student has been found with this ID: " << finder->second << endl;//the text will be printed to the console with the name that is alongside the number.
		}
		else {//if the iterator does reach the end, that would mean that the number the user entered is not in the map.
			cout << "No student was found with this ID." << endl;//this will print if no number is found in the map.
		}

		print("Would you like to find another student? (Y/N)\n");//this question is printed to the console.
		cin >> continueInput;//the user can say if they want to loop the code again or not.
		continueInput = toupper(continueInput);//this will make the input a capital letter.

		while (continueInput != 'Y' && continueInput != 'N') {//if the user enters anything but y or n, they will get an error message.
			cin.clear();
			cin.ignore(1000, '\n');
			print("Please enter whether Y for yes or N for no for this question.\n");
			cin >> continueInput;
			continueInput = toupper(continueInput);//the user is made capital again if they get it wrong.
		}
	}
	return 0;
}
