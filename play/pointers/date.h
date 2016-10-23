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
	public:
		//constructors
		Date( );
		Date(int, int, int);
		//mutator methods
		bool setDate(int, int, int);	
		void inputDate( );
		//accessor methods
		int getMonth( ) const;
		int getDay( ) const;
		int getYear( ) const;
		//display
		void display( ) const;
	private:
		int month, day, year;
};

#endif
