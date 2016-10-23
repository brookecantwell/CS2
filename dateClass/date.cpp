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

	if (month >= 1 && month <= 12 && day > 0 && day <= maxDays) { 
		setValue = true;
		month = m;
		day = d;
		year = y;
	}
	
	return(setValue);

}

//inputDate, gets user input and checks validity
void Date::inputDate( ) {
	char dummyChar;

	do {
		cout << "Input date in the form mm/dd/yyyy: ";
		cout >> month >> dummyChar >> day >> dummyChar >> year;
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
void Date::display( ) const {
	cout << month << '/' << day << '/' << year;
}
