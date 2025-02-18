#pragma once

#include <Windows.h>
#include <iostream>
#include <string>

using namespace std;

class Students {
public:

	int studentCode, mark1, mark2, mark3, examMark;
//these 5 integers are for the 5 in the file.

	string name;
//this string is for the name of the student.

	void view();//this declares the function to view the data in the file.

	void search(int userNum);//this delcares the function to find a specific student.


};