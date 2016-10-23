/*
 * Header file for the Customer class
 *
 * customer.h
 *
 * Brooke Cantwell
 *
 * 27 April 2016
 *
 * Header for for the customer class.
 *
 */

#include <iostream>

using namespace std;

#ifndef CUSTOMER_H
#define CUSTOMER_H

class Customer {
	//global functions
	friend istream& operator>>(istream&, Customer&);
	friend ostream& operator<<(ostream&, Customer);	

	public:
		//constructors
		Customer( );
		Customer(string, string);
		Customer(string, string, string, string, string, int);
		//mutator methods
		void setName(string, string);
		void setAddress(string, string, string, int);
		//accessor methods
		string getfName( ) const;
		string getlName( ) const;
		string getAddress( ) const;
		string getCity( ) const;
		string getState( ) const;
		int getZipCode( ) const;
	private:
		string fname, lname;
		string address, city, state;
		int zipCode;
};

#endif
