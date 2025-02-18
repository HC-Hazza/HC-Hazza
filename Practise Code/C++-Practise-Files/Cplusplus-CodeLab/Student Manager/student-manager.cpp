#include "Student.h"
#include <fstream>
#include <array>
#include <iomanip>
#include "Functions.h"
#include <algorithm>

using namespace std;

bool highestComparison(const Students& high, const Students& low) {//this function will compare the higher marks to a mark that could be lower.
	if ((high.mark1 + high.mark2 + high.mark3 + high.examMark) > (low.mark1 + low.mark2 + low.mark3 + low.examMark)) {
		return true;
	}
	else {
		return false;
	}
}

void sortStudents(array<Students, 10> students, int loopNumber);//this function is used to sort the students from high to low.

Students maxScore(array<Students, 10> students, int loopNumber);//this function is used to find the student with the highest mark.

Students minScore(array<Students, 10> students, int loopNumber);//this function is used to find the student with the lowest mark.

int main() {

	ifstream marks("studentMarks.txt");//this will take data from the student marks text file.

	array<Students, 10> students;//this array will be used to store the students.

	Students highestGrade, lowestGrade;//this is a call from the class in its respected header file.

	int loopVariable = 0, numberOfStudents, menu;//these three integers will be used for outputting the menu.

	if (marks.is_open()) {//this will check if the file had been opened.

		marks >> numberOfStudents;//this takes the number from the start of the file and puts it into a variable.

		while (!marks.eof()){//this will loop through the file until the last piece of data is found.

			marks >> students[loopVariable].studentCode;//this will take the first piece of data.
			marks.ignore(10, ',');//this tells the program to ignore the comma.

			getline(marks, students[loopVariable].name, ',');//this will get the second piece of data.

			marks >> students[loopVariable].mark1;
			marks.ignore(10, ',');

			marks >> students[loopVariable].mark2;
			marks.ignore(10, ',');

			marks >> students[loopVariable].mark3;
			marks.ignore(10, ',');

			marks >> students[loopVariable].examMark;
			marks.ignore(10, '\n');//this will take the four numbers next to the name.

			loopVariable++;//the loopvariable will increase until all the data has been collected.
	
		}

		do {
			cout << string(50, '=') << endl << setw(27) << "Menu" << endl << string(50, '=') << endl;
			//this will print the top of the menu, with 50 equal signs, the word Menu, the another 50 equal signs underneath.

			cout << "1. View all student records" << endl
				<< "2. Sort records by total scores" << endl
				<< "3. View student record" << endl
				<< "4. Show student who gets the max total score" << endl
				<< "5. Show student who gets the min total score" << endl
				<< "6. Quit" << endl;//the menu is then printed to the screen.

			menu = checkMenu();//the user's input is checked using this function from the header.

			switch (menu) {
			case 1:
				for (int viewLoop = 0; viewLoop < students.size(); viewLoop++) {
					students[viewLoop].view();//if the user presses the number 1, the file is printed to the screen with this function.
				}
				cout << "The number of students in the class is: " << numberOfStudents << endl;//the number of students is also printed to the screen.
				break;
			case 2:
				for (int sortLoop = 0; sortLoop < students.size(); sortLoop++) {

					sortStudents(students, sortLoop);//the sort function is called if the user presses 2.

				}
				break;
			case 3:

				print("Please enter the student number that you wish to find:");//this is printed to the console if the user enters 3.
				int studentNumber;
				cin >> studentNumber;//a variable is declared and initialised via user input.
				for (int searchLoop = 0; searchLoop < students.size(); searchLoop++) {
					students[searchLoop].search(studentNumber);//the user's student is put through the search function.
				}
				break;
			case 4:
				for (int maxLoop = 0; maxLoop < students.size(); maxLoop++) {
					highestGrade = maxScore(students, maxLoop);
				}//if the user enters the number 4, they will get the student with the highest score printed to them.
				highestGrade.view();
				break;
			case 5:
				for (int minLoop = 0; minLoop < students.size(); minLoop++) {
					lowestGrade = minScore(students, minLoop);
				}//same here with the student with the lowest score for the number 5.
				lowestGrade.view();
				break;
			case 6://if 6 is entered, the program will end.
				break;
			}
		} while (menu != 6);

		marks.close();//the file is closed if the program ends.

	}
	else {
		print("File cannot be found...");
		return -1;
	}//if the file is not opened, this will be printed.

	return 0;
}

void sortStudents(array<Students, 10> students, int loopNumber) {

	sort(students.begin(), students.end(), highestComparison);//the array is sorted from highest to lowest.

	students[loopNumber].view();//the array is then printed to the user.
}

Students maxScore(array<Students, 10> students, int loopNumber) {
	sort(students.begin(), students.end(), highestComparison);//the array is once again sorted from highest to lowest.

	return students.front();//the one that is at the top will be sent back, since they will be the highest.
	
}

Students minScore(array<Students, 10> students, int loopNumber) {
	sort(students.begin(), students.end(), highestComparison);

	return students.back();//this is the same, but the one at the back will be sent since they are the lowest score.

}
