/*
 *
 * Name Class
 *
 * name.h
 *
 * Brooke Cantwell
 * 
 * 20 February 2016
 *
 * Header file for the name class
 *
 */

#include <iostream>
using namespace std;

class Name {
	public:
		//constructors
		Name( );
		Name(string, char, string);
		//mutator methods
		void setName(string, char, string);
		void inputName( );
		//accessor methods
		string getFirstName( ) const;
		char getMiddleInitial( ) const;
		string getLastName( ) const;
		//display method
		void display( );


	private:
		string fname, lname;
		char mi;

};
