/*
 * Student Class 
 *
 * student.h
 *
 * Brooke Cantwell
 *
 * 20 February 2016
 *
 * Header file for the student class
 *
 */

#ifndef STUDENT_H
#define STUDENT_H

#include "date.h"
#include "name.h"
#include "program.h"
#include "course.h"
#include "phone.h"

class Student {
	public:
		//constructors
		Student( );
		Student(Name, Date, Program, char, int);
		//mutator methods
		//methods to set data members with specific values
		void setName(string, char, string);
		void setDOB(int, int, int);
		void setProgram(string, string, string, string);
		bool setGender(char);
		void setStudentID(int);
		void setCourse(string, string, char, string, string, int, int, int);
		void setNumCourses(int);
		void setGPA(double);
		void setHomeNumber(int, int, int);
		void setCellNumber(int, int, int);
		bool setPreferredPhone(char);
		//mutator methods to populate with user input
		void inputName( );
		void inputDate( );
		void inputProgram( );
		void inputGender( );
		void inputStudentID( );
		bool inputCourse(int);
		void inputAll( );
		void inputCellNumber( );
		void inputHomeNumber( );
		void inputPreferredPhone( );
		//display method
		void displayInfo( );
		void displayCourseInfo( );
		void displayHomePhone( );
		void displayCellPhone( );
		//accessor functions
		Name getName( );
		Date getDate( );
		int getStudentID( );
		char getGender( );
		Phone getCellPhone( );
		Phone getHomePhone( );
		double getGPA( );
		char getPreferredPhone( );
		//methods for course array
		double calculateGPA(int);
		//method to increment course number
		void inc_numCourses( );
	private:
		int studentID;
		Name name;
		Date dob;
		char gender;
		Program program;
		static const int MAX_COURSES = 10;
		Course completedCourses[MAX_COURSES];
		int numCourses;
		int creditsEarned;
		double GPA;
		Phone cellPhone, homePhone;
		char preferredPhone;
};

#endif
