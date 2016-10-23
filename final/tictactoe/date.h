/*
 * Date Class Header File
 *
 * date.h
 *
 * Brooke Cantwell
 *
 * 5 March 2016
 *
 * Modification of the original Date from
 * previous labs to be used in the TicTacToe
 * class.
 *
 */

#ifndef DATE_H
#define DATE_H

#include <iostream>

using namespace std;

class Date {
	//global functions
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
		//operator overloading
		//equality
		bool operator==(const Date&) const;
		bool operator==(int) const;
	private:
		//getMaxDays( ) - returns max days for a given month
		int getMaxDays( );
		int month, day, year;
};

#endif
