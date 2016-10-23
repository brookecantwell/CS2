/*
 * Implementation of Student class
 *
 * student.cpp
 *
 * Brooke Cantwell
 *
 * 20 February 2016
 *
 * Method definitions for student class
 *
 */

#include "student.h"
#include <iomanip>

//default constructor, uses default constructors for name, date, and program, and 
//sets default values for student ID and gender
Student::Student( ) {
	studentID = 0;
	gender = ' ';
	numCourses = 0;
}

//constructor to instantiate object with name, date, and program
Student::Student(Name n, Date d, Program p, char g, int ID) {
	name = n;
	dob = d;
	program = p;
	gender = g;
	studentID = ID;
	numCourses = 0;
	preferredPhone = ' ';
}

//setName method calls name constructor to set student name
void Student::setName(string f, char m, string l) {
	name.setName(f, m, l);
}

//setDOB calls date constructor to set date of birth
void Student::setDOB(int m, int d, int y) {
	dob.setDate(m, d, y);
}

//setProgram calls program constructor to set campus, degree, major, and minor
void Student::setProgram(string c, string d, string ma, string mi) {
	program.setCampus(c);
	program.setDegree(d);
	program.setMajor(ma);
	program.setMinor(mi);
}

//setGender sets student gender and validates it as either m or f
bool Student::setGender(char g) {
	bool setValue;

	switch(g) {
		case 'M':
		case 'm':
		case 'F':
		case 'f':
			setValue = true;
			break;
		default:
			setValue = false;
	}

	return(setValue);
}

//setStudentID accepts value for student ID
void Student::setStudentID(int ID) {
	studentID = ID;
}	

//setCourseID calls set function of course class
void Student::setCourse(string n, string first, char mi, string last, string g, int i, int c, int index) {
	completedCourses[index].setName(n);
	completedCourses[index].setInstructorName(first, mi, last);
	completedCourses[index].setGrade(g);
	completedCourses[index].setID(i);
	completedCourses[index].setCredits(c);
}

void Student::setNumCourses(int n) {
	numCourses = n;
}

void Student::setGPA(double g) {
	GPA = g;
}

void Student::setHomeNumber(int a, int e, int l) {
	homePhone.setAll(a, e, l);
}

void Student::setCellNumber(int a, int e, int l) {
	cellPhone.setAll(a, e, l);
}

bool Student::setPreferredPhone(char p) {
	bool setValue;

	switch(p) {
		case 'C':
		case 'c':
		case 'H':
		case 'h':
			setValue = true;
			break;
		default:
			setValue = false;
	}

	return(setValue);
}

//inputName calls input function of name class
void Student::inputName( ) {
	name.inputName( );
}

//inputDate calls input function of date class
void Student::inputDate( ) {
	cout << "Date of Birth - ";
	dob.inputDate( );
}

//input program calls input functions for campus and degree and major and minor
void Student::inputProgram( ) {
	program.inputCampus_Degree( );
	program.inputMajor_Minor( );
}

//inputStudentID accepts user input for student ID
void Student::inputStudentID( ) {
	cout << "Enter student ID: ";
	cin >> studentID;
}

//inputGender accepts user input for gender and validates it with setGender
void Student::inputGender( ) {
	
	do {
		cout << "Enter gender (m/f): ";
		cin >> gender;
	} while (!setGender(gender));
}

//inputCourse, allows the user to input course information (up to 10) and
//gives them a choice to stop
bool Student::inputCourse(int i) {

	bool cont = true;
	char answer = 'C';

	cout << "To continue entering courses, enter 'C', to stop enter 'S': ";
	cin >> answer;

	if (answer == 'C' || answer == 'c') {
		completedCourses[i].inputName( );
		completedCourses[i].inputInstructorName( );
		completedCourses[i].inputGrade( );
		completedCourses[i].inputID( );
		completedCourses[i].inputCredits( );
	}
	
	else
		cont = false;
	
	return(cont);


}

//inputCellNumber accepts user input for cell phone area code, exchange
//and line
void Student::inputCellNumber( ) {
	cout << "Cell Phone Information" << endl;
	cellPhone.inputAreaCode( );
	cellPhone.inputExchange( );
	cellPhone.inputLine( );
}

//inputHomeNumber accepts user input for home phone area code, exchange
//and line
void Student::inputHomeNumber( ) {
	cout << "Home Phone Information" << endl;
	homePhone.inputAreaCode( );
	homePhone.inputExchange( );
	homePhone.inputLine( );
}	

void Student::inputPreferredPhone( ) {

	do {
		cout << "Input preferred phone number, (H)ome or (C)ell: ";
		cin >> preferredPhone;
	} while (!setPreferredPhone(preferredPhone));
}

//inputAll calls all of the input functions created for each data member
void Student::inputAll( ) {
	name.inputName( );
	cout << "Date of Birth - ";
	dob.inputDate( );
	program.inputCampus_Degree( );
	program.inputMajor_Minor( );
	inputStudentID( );
	inputGender( );
	inputHomeNumber( );
	inputCellNumber( );
	inputPreferredPhone( );
}

//displayInfo displays all data members of the student class
void Student::displayInfo( ) {
	name.display( );
	cout << "Date of Birth: ";
	dob.display( );
	program.display( );
	cout << "Gender: " << gender << endl;
	cout << "Student ID: " << studentID << endl;
	cout << "Home Number: ";
	homePhone.display( );
	cout << "Cell Number: ";
	cellPhone.display( );
	cout << "Preferred Phone: ";
	
	switch(preferredPhone) {
		case 'C':
		case 'c':
			cout << "Cell Phone:";
			cellPhone.display( );
			break;
		case 'H':
		case 'h':
			cout << "Home Phone:";
			homePhone.display( );
	}
		
} 

//displayHomePhone displays the homePhone data members
void Student::displayHomePhone( ) {
	cout << "Home Number: ";
	homePhone.display( );
}

//displayCellPhone displays the cellPhone data members
void Student::displayCellPhone( ) {
	cout << "Cell Number: ";
	cellPhone.display( );
}	

//accessor methods

Name Student::getName( ) {
	return(name);
}

Date Student::getDate( ) {
	return(dob);
}

int Student::getStudentID( ) {
	return(studentID);
}

char Student::getGender( ) {
	return(gender);
}

Phone Student::getCellPhone( ) {
	return(cellPhone);
}

Phone Student::getHomePhone( ) {
	return(homePhone);
}

double Student::getGPA( ) {
	return(GPA);
}

char Student::getPreferredPhone( ) {
	return(preferredPhone);
}

//calculateGPA, stores grade values (integer) in a grade array depending
//on the letter grade they recieved, multiplies this value by the credits
//of the class, and stores it in a qualityPoints array. The contents of the
//quality points array are added and divided by the total credits to get GPA

double Student::calculateGPA(int i) {
	
	double grade[MAX_COURSES];
	double gradeSum = 0;
	int creditSum = 0;
	double qualityPoints[MAX_COURSES];
	double qualityPointsSum = 0;

	int credits = completedCourses[i].getCredits( );
	
	for (int i = 0; i < numCourses; i++) {

		if (completedCourses[i].getGrade( ) == "A")
			grade[i] = 4;
		else
		if (completedCourses[i].getGrade( ) == "A-")
			grade[i] = 3.70;
		else
		if (completedCourses[i].getGrade( ) == "B+")
			grade[i] = 3.33;
		else
		if (completedCourses[i].getGrade( ) == "B")
			grade[i] = 3;
		else
		if (completedCourses[i].getGrade( ) == "B-")
			grade[i] = 2.7;
		else
		if (completedCourses[i].getGrade( ) == "C+")
			grade[i] = 2.3;
		else
		if (completedCourses[i].getGrade( ) == "C")
			grade[i] = 2;
		else
		if (completedCourses[i].getGrade( ) == "C-")
			grade[i] = 1.7;
		else
		if (completedCourses[i].getGrade( ) == "D+")
			grade[i] = 1.3;
		else
		if (completedCourses[i].getGrade( ) == "D")
			grade[i] = 1;
		else
		if (completedCourses[i].getGrade( ) == "D-")
			grade[i] = .7;
		else
		if (completedCourses[i].getGrade( ) == "F")
			grade[i] = 0;

		qualityPoints[i] = grade[i] * credits;
	
	}

	//sum quality points
	for (int c = 0; c < numCourses; c++) {
		qualityPointsSum += qualityPoints[c];
	}

	//sum credits
	for (int c = 0; c < numCourses; c++) {
		creditSum += completedCourses[c].getCredits( );
	}	
	 	
	GPA = qualityPointsSum / creditSum;

}

void Student::displayCourseInfo( ) {

	for (int i = 0; i < numCourses--; i++) {
		completedCourses[i].display( );
	}

	cout << "GPA: " << std::fixed << setprecision(2) << GPA << endl;
}

void Student::inc_numCourses( ) {
	++numCourses;
}
