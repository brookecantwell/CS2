/*
 * Set Class (Template) Driver
 *
 * driver2.cpp
 *
 * Brooke Cantwell
 *
 * 18 April 2016
 *
 * Driver to test Set Class template.
 */

#include <iostream>
#include "set.h"

using namespace std;

template <typename T>
Set<T> testSet(Set<T> s1, Set<T> s2) {

	int menuOption;
	Set<T> newSet;

	cout << "Input into Set 1" << endl;
	s1.inputSetName( );
	cin >> s1;
	cout << s1;

	cout << "Input into Set2" << endl;
	s2.inputSetName( );
	cin >> s2;
	cout << s2;

	cout << "Choose an operation to perform" << endl;
	cout << "1. Set Union" << endl;
	cout << "2. Set Intersection" << endl;
	cout << "3. Set Difference" << endl;
	cout << "Choose an option: ";
	cin >> menuOption;

	switch(menuOption) {
		case 1:
			newSet = s1 + s2;
			break;
		case 2:
			newSet = s1 ^ s2;
			break;
		case 3:
			newSet = s1 - s2;
			break;
			
	}

	return(newSet);	
}

main( ) {
	//set delim for each specialization
	Set<int>::setDelim(-999);
	Set<char>::setDelim('!');
	Set<string>::setDelim("quit");
	Set<double>::setDelim(-99.99);

	//instantiate sets of each specialization
	Set<int> intSet1, intSet2, intSetProduct;
	Set<char> charSet1, charSet2, charSetProduct;
	Set<string> stringSet1, stringSet2, stringSetProduct;
	Set<double> doubleSet1, doubleSet2, doubleSetProduct;

	cout << "Testing function template & Set class specialization with integers" << endl;
	intSetProduct = testSet(intSet1, intSet2);
	intSetProduct.inputSetName( );
	cout << intSetProduct << endl << endl;

	cout << "Testing function template & Set class specialization with characters" << endl;
	charSetProduct = testSet(charSet1, charSet2);
	charSetProduct.inputSetName( );
	cout << charSetProduct << endl << endl;

	cout << "Testing function template & Set class specialization with strings" << endl;
	stringSetProduct = testSet(stringSet1, stringSet2);
	stringSetProduct.inputSetName( );
	cout << stringSetProduct << endl << endl;
	
	cout << "testing function template & Set class specialization with doubles" << endl;
	doubleSetProduct = testSet(doubleSet1, doubleSet2);
	doubleSetProduct.inputSetName( );
	cout << doubleSetProduct << endl;
}


