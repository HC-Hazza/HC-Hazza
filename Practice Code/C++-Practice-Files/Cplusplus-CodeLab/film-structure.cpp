#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <array>
#include <vector>
#include <Windows.h>

using namespace std;

void print(string msg);

struct Films {
	string title;
	string director;
	int ageRange = 0;
	string genre;
	//these four variables will be used to for the films.
	Films() {};
	//this is a constructor.
	Films(string t, string d, int a, string g) {
		title = t;
		director = d;
		ageRange = a;
		genre = g;
	};//this is another constructor with variables inside it.
};

void printFilm(const Films& f, int i);//this function will be used to print out the variables from a constructor.

void checkInteger(int x) {
	while (cin.fail()) {
		print("Invalid input.");
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Please enter again: ";
		cin >> x;
	}//the while loop will check if the input for an integer has failed.
}

int main() {

	array<Films, 5> films;//the array will be used to store the user's input.

	for (int input = 0; input < films.size(); input++) {//this loop will count to the amount that is stored into the array.

		print(to_string(input + 1) + ".");

		Sleep(250);

		print("Please enter a film: ");//this text will be printed to the console.

		cout << "Title: ";
		getline(cin, films[input].title);//after the text is printed to the console, the user can enter their film title, director, film age rating and genre.

		cout << "Director: ";
		getline(cin, films[input].director);

		cout << "Age Rating: ";
		cin >> films[input].ageRange;
		checkInteger(films[input].ageRange);//this is used to make sure the user has entered a number.
		cin.ignore(10, '\n');//this will ignore the enter to be able to move onto the genre section.

		cout << "Genre: ";
		getline(cin, films[input].genre);

		print("\n");//this will print two line spaces
	}



	for (int output = 0; output < films.size(); output++) {//this for loop is similar to the loop for the user input.
		printFilm(films.at(output), output + 1);//this function will print the films throughout the array.
	}

	ofstream outputFile("films.txt");//this is used to put data into a text file.

	if (outputFile.is_open()) {//this will check if the text file was created.
		for (int file = 0; file < films.size(); file++) {
			outputFile << films[file].title << ","
				<< films[file].director << ","
				<< films[file].ageRange << ","
				<< films[file].genre << endl;
		}//the data from the array for the struct is inputted into the text file.

		outputFile.close();//this will close the text file.
	}
	else {
		cout << "The file was not created..." << endl;//if the text file is not created, this will print.

		return -1;//the program will throw an error.
	}

	vector<Films> fileFilms;//the vector will be used for the data in the file.
	fileFilms.reserve(5);//5 spaces are reserved in the vector.

	int loopCounter = 0;//this will be used in the output loop.

	ifstream inputFile("films.txt");//the text file is reopened to take out the data.

	if (inputFile.is_open()) {//this will again check if the file has been opened.
		while (!inputFile.eof()) {//this will loop until the file ends.
			Films fromFile;//this variable is called from the struct.

			getline(inputFile, fromFile.title, ',');//this will take the data from the file and put it into the vector.

			getline(inputFile, fromFile.director, ',');

			inputFile >> fromFile.ageRange;
			inputFile.ignore(10, ',');//this will ignore up to 10 characters or once it reaches a ,.

			getline(inputFile, fromFile.genre, '\n');

			fileFilms.push_back(fromFile);

		}

		inputFile.close();//this will again close the file.
	}

	else {
		print("File could not be accessed...");
		return -1;
	}//similar to before, if the file doesn't open, this will print.

	print("This is the films stored in the file: ");//this will be printed to the console.

	for (const Films& flm : fileFilms) {//this range based for loop will loop through the vector.
		cout << "Title: " << flm.title << endl;
		cout << "Director: " << flm.director << endl;
		cout << "Age: " << flm.ageRange << endl;
		cout << "Genre: " << flm.genre << endl;
		//this will print through the vector that took the data from the file.
		Sleep(500);//this will pause the program for half a second.

		cout << endl;

		if (loopCounter == 4) {
			return 0;
		}//because the file will print an empty section due to an extra space being inputted into it, the program is forced to end after the 5th piece of data is printed.
		loopCounter++;
	}

	
}

void printFilm(const Films& f, int i) {
	cout << i << ". " << f.title << ". Directed by "
		<< f.director << ". The film is rated age "
		<< f.ageRange << ". The film is an "
		<< f.genre << " film." << endl;
	Sleep(500);
}//this function is used to print the stuff from the structures in the main.

void print(string msg) { cout << msg << endl; }//this function is used to print text to the console.
