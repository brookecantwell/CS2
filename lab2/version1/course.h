/*
 * Course Class
 *
 * course.h
 *
 * Brooke Cantwell
 *
 * 24 February 2015
 *
 * Header file for the course class
 *
 */

#ifndef COURSE_H
#define COURSE_H

#include <iostream>
#include "name.h"

using namespace std;

class Course {
	public:
		Course( );
		Course(string, string, string, int, int);
		//mutator methods
		void setName(string);		
		void setInstructor(string);
		void setInstructorName(string, char, string);
		void setGrade(string);
		void setID(int);
		void setCredits(int);
		void inputName( );
		void inputInstructor( );
		void inputInstructorName( );
		void inputGrade( );
		void inputID( );
		void inputCredits( );
		//accessor methods
		string getName( );
		string getInstructor( );
		string getGrade( );
		int getID( );
		int getCredits( );
		void display( );
	private:
		string name, instructor;
		//grade as a string for + and -
		string grade;
		int id, numCredits;
		Name instructorName;
};

#endif
