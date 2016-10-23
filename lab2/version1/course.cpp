/*
 * Implementation for the Course class
 *
 * course.cpp
 *
 * Brooke Cantwell
 *
 * 24 February 2016
 *
 * Methods for the course class
 *
 */

#include "course.h"

//default constructor
Course::Course( ) {
	name = instructor = grade  = " ";
	id = numCredits = 0;
}

//constructor for all data members
Course::Course(string n, string in, string g, int i, int c) {
	name = n;
	instructor = in;
	grade = g;
	id = i;
	numCredits = c;	
}

//setName, sets course name
void Course::setName(string n) {
	name = n;
}

//setInstructorName, sets contents of Name object
void Course::setInstructorName(string f, char m, string l) {
	instructorName.setName(f, m, l);
}

//setInstructor, sets course instructor
void Course::setInstructor(string i) {
	instructor = i;
}

//setGrade, sets grade receieved for the course
void Course::setGrade(string g) {
	grade = g;
}

//setID, sets course ID
void Course::setID(int i) {
	id = i;
}

//setCredits, sets the number of credits for the course
void Course::setCredits(int c) {
	numCredits = c;
}

//inputName, accepts keyboard input for name
void Course::inputName( ) {
	cout << "Input course name: ";
	cin >> name;
}

//inputInstructor, accepts keyboard input for instructor
void Course::inputInstructor( ) {
	cout << "Input course instructor: ";
	cin >> instructor;
}

//inputInstructorName, accepts keyboard input for instructo
//name (object of Name)
void Course::inputInstructorName( ) {
	cout << "Instructor Name, ";
	instructorName.inputName( );
}

//inputGrade, accepts keyboard input for grade
void Course::inputGrade( ) {
	cout << "Input grade received: ";
	cin >> grade;
}

//inputID, accepts keyboard input for course ID
void Course::inputID( ) {
	cout << "Input course ID: ";
	cin >> id;
}

//inputCredits, accepts keyboard input for credits
void Course::inputCredits( ) {
	cout << "Input number of credits: ";
	cin >> numCredits;
}

//getName, returns name data member
string Course::getName( ) {
	return(name);
}

//getInstructor, returns instructor data member
string Course::getInstructor( ) {
	return(instructor);
}

//getGrade, returns grade data members
string Course::getGrade( ) {
	return(grade);
}

//getID, returns ID data member
int Course::getID( ) {
	return(id);
}

//getCredits, returns numCredits data member
int Course::getCredits( ) {
	return(numCredits);
}

//display, displays all information for the course class
void Course::display( ) {
	cout << endl << "Course Information: " << endl << endl;
	cout << "Course Name: " << name << endl;
	cout << "Instructor: ";
	instructorName.display( );
	cout << "Course ID: " << id << endl;
	cout << "Grade Received: " << grade << endl;
	cout << "Number of Credits: " << numCredits << endl << endl;
}

