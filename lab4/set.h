/*
 * Set Class Definition
 *
 * set.h
 *
 * Brooke Cantwell
 *
 * 6 April 2016
 *
 * Definition for the Set class
 */

#ifndef SET_H
#define SET_H

#include <iostream>

using namespace std;

class Set {
	//global functions
	friend istream& operator>>(istream&, Set&);
	friend ostream& operator<<(ostream&, const Set&); 

	public:
		//constructors and destructors
		Set( );
		Set(int);
		Set(int[ ], int, char);
		Set(const Set&);
		~Set( );
		//element, searches for element
		bool element(int) const;
		//order set, orders the set
		Set orderSet(Set&);
		//operator overload methods
		const Set& operator= (const Set&);
		bool operator== (const Set&s) const;
		bool operator!=(const Set&s) const;
		//+ operator overload method that adds elements to the set
		void operator+(int);
		// - operator overload method that deletes an element
		bool operator-(int);
		//+ operator overload method that unions two sets
		Set operator+(const Set&s) const;
		//operator overload method for set intersection
		Set operator^(const Set&s) const;
		//operator overload method for set difference
		Set operator-(const Set&s) const;
		//operator overload methods for [ ]
		int operator[ ](int) const;
		int& operator[ ](int);
		//mutator method for set name
		void setSetName(char);
		void inputSetName( );
		//accessor method for set name
		char getSetName( ) const;
		void setOperation(char, char, char, bool);
	private:
		int *set;
		int pSize;
		int fSize;
		int numElements;
		char name;
		static const int DEFAULT_SIZE = 5;
		bool operationProduct;
		char op1, operation, op2;
};

#endif
