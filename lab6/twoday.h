/*
 * Two Day Package Class Definition
 *
 * twoday.h
 *
 * Brooke Cantwell
 *
 * 1 May 2016
 *
 * Definition for the derived class Two
 * Day Package.
 *
 */

#include <iostream>
#include "package.h"

using namespace std;

#ifndef TWODAY_H
#define TWODAY_H

class TwoDayPackage: public Package {
	public:
		//constructors
		TwoDayPackage( );
		TwoDayPackage(float);
		//accessor methods
		static int getNumTwoDay( );
		float calculateCost( );
		float getTotal( );
		virtual void print( );
		static float totalTwoDay;
	private:
		float fee, total;
		static int numTwoDay;

};

#endif
