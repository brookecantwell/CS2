/*
 * Implementation for the Date Class
 *
 * date.cpp
 *
 * Brooke Cantwell
 *
 * 5 May 2016
 *
 * Global functions and  methods for the
 * Date class for use in the Tic Tac Toe
 * class.
 *
 */

#include "date.h"

using namespace std;

//GLOBAL FUNCTIONS

//input operator
istream& operator>> (istream&inp, Date&d) {
	d.inputDate(inp);

	return(inp);
}

//output operator
ostream& operator<< (ostream&out, const Date&d) {

	out << d.month << '/' << d.day << '/' << d.year << endl;

	return(out);
}

//equality operator function
bool operator== (int y, const Date&d) {
	bool restat = false;

	if (d.year == y)
		restat = true;

	return(restat);
}

//CONSTRUCTORS
//default constructor
Date::Date( ) {
	month = day = year = 0;
}

//constructor for all data members
Date::Date(int m, int d, int y) {
	month = m;
	day = d;
	year = y;
}

//MUTATOR METHODS
//setDate, checks for valid date and assigns integers
//to data members if they are valid
bool Date::setDate(int m, int d, int y) {
	bool restat = false;
	int maxDays;

	//determine the maximum amount of days in the month
	maxDays = getMaxDays( );
	
	//check for a valid date
	if (month >=1 && month <= 12 && day > 0 && day <= maxDays) {
		restat = true;
		month = m;
		day = d;
		year = y;
	}

	return(restat);
}

//inputDate, gets user input for date and checks validity with setDate
void Date::inputDate(istream&inp) {
	char dummyChar;

	do {
		cout << "Input date in the for mm/dd/yyyy: ";
		cin >> month >> dummyChar >> day >> dummyChar >> year;
	} while (!setDate(month, day, year));
}

//ACCESSOR METHODS

int Date::getMonth( ) const {
	return(month);
}

int Date::getDay( ) const {
	return(day);
}

int Date::getYear( ) const {
	return(year);
}

//OPERATOR OVERLOADED METHODS

//equality operator (equality between 2 date objects)
bool Date::operator==(const Date&d) const {
	bool restat = false;

	if (month == d.month && day == d.day && year == d.year)
		restat = true;

	return(restat);
}

//equality operator (equality between the year data member
//of a date object and some integer for year)
bool Date::operator==(int y) const {
	bool restat = false;

	if (year == y)
		restat = true;

	return(restat);
}

//PRIVATE METHODS

//getMaxDays - returns the max number of days in a month
int Date::getMaxDays( ) {
	int maxDays;

	switch(month) {
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			maxDays = 31;
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			maxDays = 30;
			break;
		case 2:
			maxDays = 28;
	}

	return(maxDays);
}
