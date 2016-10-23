/*
 * Driver - Lab 2 Version 2
 *
 * driver.cpp
 *
 * Brooke Cantwell
 *
 * 20 February 2016
 *
 * Simple driver to test name, date, student, and program classes
 *
 */

#include "student.h"

main( ) {

	Student students[10];
	static int studentsEntered = 0;

	void test(Student&);
	void display(Student, Student);	
	void testCourse(Student&);
	bool continueEntering( );
	void displayStudents(Student[ ], int);

	bool cont = true;

	for (int i = 0; i < 10 && cont; i++) {		
		cout << endl << "Student #" << i+1 << endl;
		test(students[i]);
		cont = continueEntering( );
		studentsEntered++;
	}

	displayStudents(students, studentsEntered);

}

void test(Student&s) {
	bool cont = true;
	int i = 0;

	s.inputAll( );
	
	s.setNumCourses(0);	

	cout << "Enter course information: " << endl;

	for (int i = 0; i < 10 && cont == true; i++) {
		s.inc_numCourses( );
		cont = s.inputCourse(i);
	}
	
	s.setGPA(s.calculateGPA(i));
}


void displayStudents(Student students[ ], int studentsEntered) {

	cout << "Students entered: " << endl;

	for (int i = 0; i < studentsEntered; i++) {
		students[i].displayInfo( );
		students[i].displayCourseInfo( );
		cout << "---------------------------" << endl << endl;
	}
}

bool continueEntering( ) {

	char answer;
	bool cont;

	cout << endl << "To continue entering students enter 'C', to stop enter any other character: ";
	cin >> answer;

	switch(answer) {
		case 'C':
		case 'c':
			cont = true;
			break;
		default:
			cont = false;
	}

	return(cont);

}
