/*
 * Program Class Implementation
 *
 * program.cpp
 *
 * Brooke Cantwell
 *
 * 20 February 2016
 *
 * Implementation of Program class
 */

#include "program.h"

//default constructor
Program::Program( ) {
	campus = degree = "N/A";
	major = "UNDECLARED";
	minor = "NONE";
}

//constructor for all data members
Program::Program(string c, string d, string ma, string mi) {
	campus = c;
	degree = d;
	major = ma;
	minor = mi;
}

//mutator method for set campus
bool Program::setCampus(string c) {
	bool setValue;

	if (c == "RH" || c == "LC" || c == "WC")
		setValue = true;
	else
		setValue = false;

	return(setValue);
}

//mutator method for set degree
bool Program::setDegree(string d) {
	bool setValue;
	
	if (d == "BS" || d == "BA")
		setValue = true;
	else
		setValue = false;

	return(setValue);

}

//mutator method for major
bool Program::setMajor(string ma) {
	major = ma;
}

//mutator method for minor
bool Program::setMinor(string mi) {
	minor = mi;
}

//mutator method to set campus and degree with keyboard input
void Program::inputCampus_Degree( ) {
	do {
		cout << "Enter campus (RH, LC, or WC): ";
		cin >> campus;
	} while (!setCampus(campus));

	do {
		cout << "Enter degree (BS/BA): ";
		cin >> degree;
	} while (!setDegree(degree));
}

//mutator method to populate major and minor with user input
void Program::inputMajor_Minor( ) {
	cout << "Enter major or UNDECLARED: ";
	cin >> major;
	
	cout << "Enter minor or NONE: ";
	cin >> minor;
}

//accessor method for campus
string Program::getCampus( ) {
	return(campus);
}

//accessor method for degree
string Program::getDegree( ) {
	return(degree);
}

//accessor method for major
string Program::getMajor( ) {
	return(major);
}

//accessor method for minor
string Program::getMinor( ) {
	return(minor);
}

//display method
void Program::display( ) {
	cout << "Campus: " << campus << endl;
	cout << "Degree: " << degree << endl;
	cout << "Major: " << major << endl;
	cout << "Minor: " << minor << endl;
}
