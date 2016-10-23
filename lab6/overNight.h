/*
 * Header File for Overnight Package Derived Class
 *
 * overnight.h
 *
 * Brooke Cantwell
 *
 * 1 May 2016
 *
 * Header file for the derived class overnight package.
 *
 */

#include <iostream>
#include "package.h"

using namespace std;

#ifndef OVERNIGHT_H
#define OVERNIGHT_H

class OverNightPackage: public Package {
	//global functions
	
	public:
		//constructors
		OverNightPackage( );
		OverNightPackage(int);
		//mutator methods
		//accessor methods
		static int getNumOvernight( );
		float calculateCost( );
		float getTotal( );
		virtual void print( );
		static float totalOverNight;
	private:
		float fee, total;
		static int numOvernight;
};

#endif
