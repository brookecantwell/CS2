/*
 * Base Class Header File
 *
 * baseClass.h
 *
 * Brooke Cantwell
 *
 * 27 April 2016
 *
 * Header file for the base class.
 */

#include <iostream>

using namespace std;

#ifndef BASECLASS_H
#define BASECLASS_H

class baseClass {

	public:
	//constructors
	baseClass( ) {
		id = -1;
	}

	baseClass(int i) {
		id = i;
	}
	

	virtual void print( ) { 
		cout << "Base Class print(): id == " << id << endl; 
	}

	protected:
		int id;
};

#endif
