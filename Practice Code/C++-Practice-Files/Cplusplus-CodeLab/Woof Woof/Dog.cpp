#include "Dog.h"
//this will include the header where the class declarations are.

Dog::Dog(string name, string breed, int age) {
	this->name = name;
	this->breed = breed;
	this->age = age;
}

Dog::Dog() {
	name = "Ratbag";
	breed = "German Shepherd";
	age = 7;
}


void Dog::dogPrint() {
	cout << name << endl
		<< breed << endl
		<< age << endl << endl;
}

