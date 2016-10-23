/*
 * Implementation for Date class
 *
 * date.cpp
 *
 * Brooke Cantwell
 *
 * 20 February 2016
 *
 * Methods for date class
 *
 */

#include "date.h"


//operator overloading
//functions

//input operator
istream& operator>> (istream&inp, Date&d) {
	d.inputDate(inp);
	return(inp);
}

//output operator
ostream& operator<< (ostream&out, const Date&d) {
	d.display(out);
	return(out);
}

//equality operator
bool operator== (int y, const Date&d) {
	bool restat = false;

	if (d.year == y)
		restat = true;

	return(restat);
}

//operator overloading
//methods

//equality operator (equality between 2 date objects)
bool Date::operator==(const Date&d) {
	bool restat = false;
	
	if (month == d.month && day == d.day && year == d.year)
		restat = true;

	return(restat);
}

//equality operator (equality between the year data member of a
//date object and some integer for year)
bool Date::operator==(int y) {
	bool restat = false;

	if (year == y)
		restat = true;

	return(restat);
}

//increment operators

Date Date::operator++(int d) {
	Date tmp = *this;
	increment( );
	return(tmp);
}

Date Date::operator++( ) {
	increment( );
	return(*this);
}

//decrement operator

Date Date::operator--(int d) {
	Date tmp = *this;
	decrement( );
	return(tmp);
}

Date Date::operator--( ) {
	decrement( );
	return(*this);
}

//default constructor
Date::Date( ) {
	month = day = year = 0;
}

//constructor to set all data members
Date::Date(int m, int d, int y) {
	month = m;
	day = d;
	year = y;
}

//setDate, checks for valid date
bool Date::setDate(int m, int d, int y ) {
	bool setValue = false;
	int maxDays;


	//determine the maximum amount of days in every month
	maxDays = getMaxDays( );

	if (month >= 1 && month <= 12 && day > 0 && day <= maxDays) { 
		setValue = true;
		month = m;
		day = d;
		year = y;
	}
	
	return(setValue);

}

//inputDate, gets user input and checks validity
void Date::inputDate(istream&inp) {
	char dummyChar;

	do {
		cout << "Input date in the form mm/dd/yyyy: ";
		cin >> month >> dummyChar >> day >> dummyChar >> year;
	} while (!setDate(month, day, year));
}

//getMonth, accessor method for month data member
int Date::getMonth( ) const {
	return(month);
}


//getDay, accessor method for day data member
int Date::getDay( ) const {
	return(day);
}

//getYear, accessor method for year data member
int Date::getYear( ) const {
	return(year);
}

//display function
void Date::display(ostream&out) const {
	out << month << '/' << day << '/' << year;
}

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

void Date::increment( ) {
	int maxDays = getMaxDays( );


	if (day == maxDays) {
		if (month = 12) {
			day = 1;
			month = 1;
			year++;
		}
		else {
			day = 1;
			month++;
		}
	}
	else
		day++;

}

void Date::decrement( ) {
	int maxDays = getMaxDays( );	

	if (day == 1) {
		if (month = 1) {
			day = maxDays;
			month = 12;
			year--;
		}
		else {
			day = maxDays;
			month--;
		}
	}
	else
		day--;
} 	
