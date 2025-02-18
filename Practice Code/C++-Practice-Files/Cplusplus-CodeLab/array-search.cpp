#include <iostream>
#include <string>
using namespace std;

int main() {
	string names[9]{ "Jake", "Jess", "Jeff", "Joe", "Jenny", "Jack", "Jonny", "Jasmine", "Josh" };//an string array for all the names.

	cout << "Please enter a name: ";//this is printed to the console to ask the user for their input.
	string username;
	getline(cin, username);//this as well as the string variable is for the user input.

	bool nameNumber = 0;//an integer to count if the user has entered the name.

	for (int nameFind = 0; nameFind < 9; nameFind++) {//this goes through the string array.
		if (username == names[nameFind]) {//if the console finds the name and it is the same as the one entered, it will change the number to 1.
			nameNumber = 1;
		}

	}
	if (nameNumber == 1) {//if the name is discovered, the boolean will turn on, and the first if will run.
		cout << username << " was in the database.";//this alongside the name will be printed to console.
	}
	else {
		cout << username << " was not in the database.";//if the name is not found, this will be printed to console.
	}
	return 0;
}
