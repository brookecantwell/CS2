/*
 * Program Class
 *
 * program.h
 *
 * Brooke Cantwell
 *
 * 20 February 2016
 *
 * Header file for the program class
 *
 */

#ifndef PROGRAM_H
#define PROGRAM_H

#include <iostream>

using namespace std;

class Program {
	public:
		//constructors
		Program( );
		Program(string, string, string, string);
		//mutator methods
		bool setCampus(string);
		bool setDegree(string);
		bool setMajor(string);
		bool setMinor(string);
		//mutator methods with user input
		void inputCampus_Degree( );
		void inputMajor_Minor( );
		//accessor methods
		string getCampus( );
		string getDegree( );
		string getMajor( );
		string getMinor( );
		void display( );
	private:
		string campus, degree, major, minor;



};

#endif
