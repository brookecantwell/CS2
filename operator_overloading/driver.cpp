/*
 * Operator Overloading - Driver
 *
 * driver.cpp
 *
 * Brooke Cantwell
 *
 * 16 March 2016
 *
 */

#include <iostream>
#include "date.h"

using namespace std;

main( ) {

//	Date d1, d2;

	Date d1(10, 27, 1993);
	Date d2(10, 27, 1993);
	Date d3, d4;

//	cin >> d1 >> d2;
//	cout << d1 << endl << d2 << endl;

/*
	if (d1 == d2) 
		cout << "Equal" << endl;
	else
		cout << "Unequal" << endl;

	cout << "Testing global equality function: " << endl;
	if (1993 == d1)
		cout << "1993 = d1" << endl;
	else
		cout << "1993 != d1" << endl;	
*/
	cout << "d++: ";
	cout << d1++ << endl;

	cout << "++d: ";
	cout << ++d2 << endl;

	cout << "Enter a date (increment function test): ";
	cin >> d3;
	cout << "d3++: " << d3++ << endl;
	cout << "++d3: " << ++d3 << endl;

	cout << "Enter another date (decrement function test): ";
	cin >> d4;
	cout << "d4--: " << d4-- << endl;
	cout << "--d4: " << --d4 << endl;
}
