#include <iostream>
#include <string>
using namespace std;

int main() {
	string areWeThereYet;
	cout << "Are we there yet?" << endl;
	cin >> areWeThereYet;
	while (areWeThereYet == "No") {
		cout << "Are we there yet?" << endl;
		cin >> areWeThereYet;
	} if (areWeThereYet == "Yes") {
		cout << "Finally.";
	}
	else {
		cout << "Invalid reponse.";
	}
	return 0;
}
