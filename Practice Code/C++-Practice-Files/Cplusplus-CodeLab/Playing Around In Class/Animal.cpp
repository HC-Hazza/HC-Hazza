#include "Animal.h"//the animal classes are included.
#include "Functions.h"//the functions specified in another file are included.

Animal::Animal(string Type, string Name, string Colour, string Noise, int Age, double Weight) {//a constructor is called using the paramters.

	print("Let's go look for another animal!\n");

	this->type = Type;
	this->name = Name;
	this->colour = Colour;
	this->noise = Noise;
	this->age = Age;
	this->weight = Weight;

	//when the parameters are initialised in the main program, the initialisations are placed into the class in the animal header.
}

Animal::Animal() {//this uses the constructor called before, which initialises the first animal.
	
	print("Welcome to the zoo. Let's look at the animals!\n");//this is printed to the console.

	type = "Cow";
	name = "John";
	noise = "Moo!";
	colour = "Black and White.";
	age = 13;
	weight = 772.4;

	//the vasriables are all initialised from the class here.
}

Animal::~Animal(){
	print("Let's say goodbye to " + name + "\n");
}//when the program has no more use of the initialised variables, they are destroyed using this destructor. The message is printed after they are destroyed.

void Animal::sayHello() {
	print("Hello! My name is " + name + "!");
}//when this function is called in the source, the text is printed along with the name variable in the class in the animal.

void Animal::makeNoise() {
	print(name + " is a " + type + ". " + type + "'s go " + noise);
}//when this function is called in the source, the text is printed along with the name variable, the type variable and the noise variable from the class in the animal header.

void Animal::animalDetails() {
	cout << "Here is " << name << "'s details: " << endl << "Name: " << name
		<< endl << "Age: " << age
		<< endl << "Colour: " << colour
		<< endl << "Weight: " << weight << "kg" << endl;
}//when this function is called in the source, the details of the animal is printed to the console in a table like way.