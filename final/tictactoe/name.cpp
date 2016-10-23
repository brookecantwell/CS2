/*
 * Implementation for the Name Class
 *
 * name.cpp
 *
 * Brooke Cantwell
 *
 * 5 May 2016
 *
 * Functions and methods for the Name
 * class, modified to be used in the 
 * Player class object of the Tic Tac 
 * Toe class.
 *
 */

#include <iostream>
#include "name.h"

using namespace std;

//GLOBAL FUNCTIONS

//input operator
istream& operator>> (istream&in, Name&n) {
	cout << "Enter name in the form First MI Last: ";
	in >> n.fname >> n.mi >> n.lname;
	
	return(in);
}

//output operator
ostream& operator<< (ostream&out, const Name&n) {
	out << n.fname << ' ' << n.mi << ' ' << n.lname << endl;	

	return(out);
}

//METHODS

//CONSTRUCTORS

//default constructor
Name::Name( ) {
	fname = "First";
	mi = 'M';
	lname = "Last";
}

//constructor for all data members
Name::Name(string f, char m, string l) {
	fname = f;
	mi = m;
	lname = l;
}

//MUTATOR METHODS

void Name::setName(string f, char m, string l) {
	fname = f;
	mi = m;
	lname = l;
}

//ACCESSOR METHODS

string Name::getFirstName( ) const {
	return(fname);
}

char Name::getMiddleInitial( ) const {
	return(mi);
}

string Name::getLastName( ) const {
	return(lname);
}
