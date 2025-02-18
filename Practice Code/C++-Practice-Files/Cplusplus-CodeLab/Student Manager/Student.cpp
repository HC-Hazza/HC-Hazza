#include "Student.h"
#include "Functions.h"

using namespace std;

void Students::view() {

	cout << "Name: " << name << endl
		<< "Student #: " << studentCode << endl
		<< "Marks from assessments: \n\t1. " << mark1 << "\n\t2. " << mark2 << "\n\t3. " << mark3 << endl
		<< "Examination grade: " << examMark << endl;

	//the data from the file is put into the class and it is printed through here.

	double totalMark = mark1 + mark2 + mark3 + examMark;//the marks are then added up together for the total mark.

	int percentage = (totalMark / 160) * 100;//this will calculate the percentage of the marks.

	Sleep(500);//this will pause the program for half a second.

	print("The percentage this student got for their exam is " + to_string(percentage) + "%");//this will print to the console.

	Sleep(250);//this will pause the program for a quartar of a second.

	if (percentage >= 70) {
		cout << "This student got an A." << endl;
	}

	else if (percentage >= 60 && percentage <= 69) {
		cout << "This student got a B." << endl;
	}

	else if (percentage >= 50 && percentage <= 59) {
		cout << "This student got a C." << endl;
	}

	else if (percentage >= 40 && percentage <= 49) {
		cout << "This student got a D." << endl;
	}

	else if (percentage < 40) {
		cout << "This student has failed. They get an F as a result." << endl;
	}
}//these conditionals will give out grades for the percentage the students got.

void Students::search(int num) {

	if (studentCode == num) {
		view();
	}
}