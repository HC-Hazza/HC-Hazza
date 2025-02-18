#include <iostream>
#include <string>
using namespace std;

int main() {
	string date;
	cout << "What's the date? " << endl;
	cin >> date;
	cout << "What's the time? " << endl;
	string time;
	cin >> time;

	if (date == "Wednesday" && time == "11am") {
		cout << "It is time for CodeLab!" << endl;
	}
	else {
		cout << "Time for bed." << endl;
	}

	return 0;
}
