/*
 * Implementation of Name class
 *
 * name.cpp
 *
 * Brooke Cantwell
 *
 * 20 February 2016
 *
 * Method definitions for name class
 *
 */



#include "name.h"

//default constructor
Name::Name( ) {
	fname = "First";
	mi = 'I';
	lname = "Last";
}

//constructor for name
Name::Name(string f, char m, string l) {
	fname = f;
	mi = m;
	lname = l;
}

//mutator method
void Name::setName(string f, char m, string l) {
	fname = f;
	mi = m;
	lname = l;
}

//populate data with user input
void Name::inputName( ) {
	cout << "Input name in the format First MI Last: ";
	cin >> fname >> mi >> lname;
}

//accessor method for first name
string Name::getFirstName( ) const {
	return(fname);
}

//accessor method for middle initial
char Name::getMiddleInitial( ) const {
	return(mi);
}

//accessor method for last name
string Name::getLastName( ) const {
	return(lname);
}

//display method
void Name::display( ) {
	cout << "Name: " << fname << ' ' << mi << ' ' << lname;
}
