#pragma once

#include <iostream>
#include <string>
using namespace std;

class Dog{
public:

	string name;
	string breed;
	int age;
	
	Dog();
	Dog(string name, string breed, int age);

	void dogPrint();
};




