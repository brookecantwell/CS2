/*
 * Implementation for the Phone class
 *
 * phone.cpp
 *
 * Brooke Cantwell
 *
 * 24 February 2016
 *
 * Methods for the phone class
 *
 */

#include "phone.h"
#include <iostream>

using namespace std;

//default constructor, sets areaCode, exchange, and line to
//default values of 0's depending on their standard length
//and sets the constant variable maxTexts to 10

Phone::Phone( ):maxTexts(10) {
	areaCode = 000;
	exchange = 000;
	line = 0000;
}

//constructor that accepts 3 integer values for areaCode,
//exchange, and line, and sets the constant variable
//maxTexts to 10
Phone::Phone(int a, int e, int l):maxTexts(10) {
	areaCode = a;
	exchange = e;
	line = l;
}

//set functions, accept integer arguments for private data members

void Phone::setAreaCode(int a) {
	areaCode = a;
}

void Phone::setExchange(int e) {
	exchange = e;
}

void Phone::setLine(int l) {
	line = l;
}

void Phone::setAll(int a, int e, int l) {
	areaCode = a;
	exchange = e;
	line = l;
}

//input functions, accepts user input for private data members

void Phone::inputAreaCode( ) {
	cout << "Input the area code: ";
	cin >> areaCode;
}

void Phone::inputExchange( ) {
	cout << "Input exchange number: ";
	cin >> exchange;
}

void Phone::inputLine( ) {
	cout << "Input phone line: ";
	cin >> line;
}

//accessor methods, return private data members

int Phone::getAreaCode( ) {
	return(areaCode);
}

int Phone::getExchange( ) {
	return(exchange);
}

int Phone::getLine( ) {
	return(line);
}

int Phone::getMaxTexts( ) const {
	return(maxTexts);
}

//display function, displays phone number in proper format
void Phone::display( ) {
	cout << '(' << areaCode << ") " << exchange << " - " << line << endl;
}
