/*
 * Definition for the Name Class
 *
 * name.h
 *
 * Brooke Cantwell
 *
 * 5 May 2016
 *
 * Header file for the Name class.
 *
 */

#ifndef NAME_H
#define NAME_H

#include <iostream>

using namespace std;

class Name {
	//global functions
	friend istream& operator>> (istream&, Name&);
	friend ostream& operator<< (ostream&, const Name&);

	public:
		//constructors
		Name( );
		Name(string, char, string);
		//mutator methods
		void setName(string, char, string);
		//accessor methods
		string getFirstName( ) const;
		char getMiddleInitial( ) const;
		string getLastName( ) const;
	private:
		string fname, lname;
		char mi;
};

#endif
