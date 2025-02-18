#pragma once

#include <iostream>
#include <string>

using namespace std;

class Animal {
public:
	string type, name, noise, colour;//four strings for the name of the animal, what type of animal it is, what noise it makes and what colour it is.
	int age;//an integer variable for the age of the animal.
	double weight;//a decimal variable for the weight of the animal.

	Animal();//a constrcutor for creating an animal.
	Animal(string Type, string Name, string Noise, string Colour, int Age, double Weight);//the constructor is then given some parameters.
	~Animal();//a destructor for taking away data for the animal.

	void sayHello();//a function for the parameters that will be used to print a message.

	void makeNoise();//another function for the parameters that will be used to determine the noise it makes.

	void animalDetails();//another function for the parameters that will print the details of the animal.


};
