/*
 * Customer Class Implementation
 *
 * customer.cpp
 *
 * Brooke Cantwell
 *
 * 27 April 2016
 *
 * Methods and functions for the customer class.
 *
 */

#include <iostream>
#include "customer.h"

using namespace std;

//global functions
istream& operator>>(istream&in, Customer&c) {

	cout << "Input name in the format First Last: ";
        in >> c.fname >> c.lname;

        cout << "Enter the street address: ";
        in >> c.address;

        cout << "Enter the city: ";
        in >> c.city;

        cout << "Enter the state: ";
        in >> c.state;

        cout << "Enter the zip code: ";
        in >> c.zipCode;


	return(in);
}

ostream& operator<<(ostream&out, Customer c) {
	out << "Name: " << c.fname << ' ' << c.lname << endl;
	out << "Address:" << endl;
	out << c.address << endl;
	out << c.city << ", " << c.state << ' ' << c.zipCode << endl;

	return(out);
}

//constructors
Customer::Customer( ) {
	fname = "First";
	lname = "Last";
	address = "Address";
	city = "City";
	state = "State";
	zipCode = 0;
}

Customer::Customer(string f, string l) {
	fname = f;
	lname = l;
}

Customer::Customer(string f, string l, string a, string c, string s, int z) {
	fname = f;
	lname = l;
	address = a;
	city = c;
	state = s;
	zipCode = z;
}

//mutator methods

void Customer::setName(string f, string l) {
	fname = f;
	lname = l;
}

void Customer::setAddress(string a, string c, string s, int z) {
	address = a;
	city = c;
	state = s;
	zipCode = z;
}

//accessor methods
string Customer::getfName( ) const{
	return(fname);
}

string Customer::getlName( ) const{
	return(lname);
}

string Customer::getAddress( ) const{
	return(address);
}

string Customer::getCity( ) const{
	return(city);
}

string Customer::getState( ) const{
	return(state);
}

int Customer::getZipCode( ) const{
	return(zipCode);
}
