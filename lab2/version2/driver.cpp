/*
 * Driver - Lab 2 Version 2
 *
 * driver.cpp
 *
 * Brooke Cantwell
 *
 * 20 February 2016
 *
 * Simple driver to test name, date, student, and program classes
 *
 */



#include "name.h"

main( ) {
	
	Name name1;

	void test(Name&);

	test(name1);
}

void test(Name&n) {

	string f, l;
	char m;

	n.setName("John", 'D', "Doe");
	n.display( );
	cout << "Input Test:" << endl;
	n.inputName( );
	cout << "Test Accessor Methods:" << endl;
	cout << n.getFirstName( ) << endl;
	cout << n.getMiddleInitial( ) << endl;
	cout << n.getLastName( ) << endl;
	cout << "Display:" << endl;
	n.display( );
}
