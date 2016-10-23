/*
 * Brooke Cantwell
 *
 */


#include <iostream>

using namespace std;

class Date {

public:

	void initialize () {
		month = day = year = -1;
	}

	void display () {
		cout << month << '/' << day << '/' << year << endl;
	}

	void input();

private:
	int month, day, year;

};

void Date::input () {

	char dummyVar;

	cout << "Enter the date as dd/mm/yyyy: ";
	cin >> month >> dummyVar >> day >> dummyVar >> year;
}

main() {

	Date d, d2;

	d.initialize ();
	d.input();
	d.display();

	d2.initialize();
	d2.input();
	d2.display();

}
