/*
 * Package (Base Class) Header File
 *
 * package.h
 *
 * Brooke Cantwell
 *
 * 27 April 2016
 *
 * Header file for the base package class.
 *
 */

#include <iostream>
#include "customer.h"

using namespace std;

#ifndef PACKAGE_H
#define PACKAGE_H

class Package {
	public:
		Package( );
		Package(float, float);
		//mutator methods
		bool setPackageWeight(float);
		bool setCostPerOunce(float);
		//parameters are fname, lname, address, city, state, zipCode
		void setSender(string, string, string, string, string, int);
		void setRecipient(string, string, string, string, string, int);
		void inputSender( );
		void inputRecipient( );
		void inputCostPerOunce( );
		void inputPackageWeight( );
		//accessor methods
		float getPackageWeight( ) const;
		float getCostPerOunce( ) const;
		float calculateCost( ) const;
		//print method
		virtual void print( ) const;
	protected:
		Customer sender, recipient;
		float packageWeight;
		float costPerOunce;
	private:
};

#endif
