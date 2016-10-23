/*
 * Date Class
 *
 * date.h
 *
 * Brooke Cantwell
 *
 * 20 February 2016
 *
 * Header file for the date class
 *
 */

#ifndef DATE_H
#define DATE_H

#include <iostream>

using namespace std;

class Date {
	//functions in global space
	friend istream& operator>> (istream&, Date&);
	friend ostream& operator<< (ostream&, const Date&);
	friend bool operator== (int, const Date&);

	public:
		//constructors
		Date( );
		Date(int, int, int);
		//mutator methods
		bool setDate(int, int, int);	
		void inputDate(istream&);
		//accessor methods
		int getMonth( ) const;
		int getDay( ) const;
		int getYear( ) const;
		//display
		void display(ostream&) const;
		//**can move display and input to private**

		//operator overloading
		//equality
		bool operator==(const Date&);
		bool operator==(int);
		//increment and decrement
		Date operator++(int);
		Date operator++( );
		Date operator--(int);
		Date operator--( );
	private:
		int month, day, year;
		//increment function
		int getMaxDays( );
		void increment( );
		void decrement( );
};

#endif
