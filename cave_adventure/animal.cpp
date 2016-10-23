/*
 * Implementation for the Animal Class
 *
 * animal.cpp
 *
 * Brooke Cantwell
 *
 * 20 March 2016
 *
 * Implementation of the animal class.
 */

#include "animal.h"

//functions

//operator overloading - output operator
ostream& operator<< (ostream&out, const Animal&a) {
	a.display(out);
	return(out);
}

//constructors

//default constructor
Animal::Animal( ) {
	animal = "Animal Name";
	sound = "Animal Sound";
}

//constructor for animal name and sound
Animal::Animal(string a, string s) {
	animal = a;
	sound = s;
}

//display function
void Animal::display(ostream&out) const{
	out << "Animal Name: " << animal << endl;
	out << "Animal Sound: " << sound << endl;
}

//mutator methods

void Animal::setAnimal(string a) {
	animal = a;
}

void Animal::setSound(string s) {
	sound = s;
}

void Animal::setInfo(string a, string s) {
	animal = a;
	sound = s;
}

//accesor methods

string Animal::getAnimal( ) const{
	return(animal);
}

string Animal::getSound( ) const{
	return(sound);
}
