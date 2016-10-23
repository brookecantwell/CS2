#include "gpa.h"

GPA::GPA ( ) {
	grade = credits = qualityPoints = 0;
}

GPA::GPA (double g, int c, double q) {
	grade = g;
	credits = c;
	qualityPoints = q;
}

void GPA::setGrade(double g) {
	grade = g;
}

void GPA::setCredits(int c) {
	credits = c;
}

void GPA::setInfo(double g, int c) {
	grade = g;
	credits = c;
}

void GPA::setLetterGrade(string g) {
	letterGrade = g;
}

void GPA::inputGrade( ) {
	cout << "Input grade: ";
	cin >> grade;
}

void GPA::inputCredits( ) {
	cout << "Input credits: ";
	cin >> credits;
}

void GPA::inputLetterGrade( ) {
	cout << "Input letter grade: ";
	cin >> letterGrade;
}

double GPA::getGrade( ) {
	return(grade);
}

int GPA::getCredits( ) {
	return(credits);
}

double GPA::getQualityPoints( ) {
	return(qualityPoints);
}

string GPA::getLetterGrade( ) {
	return(letterGrade);
}

void GPA::display( ) {
	cout << "Grade: " << grade << endl;
	cout << "Credits: " << credits << endl;
	cout << "Quality Points: " << qualityPoints << endl;
}
