/*
 * Two Day Package Class Implementation
 *
 * twoday.cpp
 *
 * Brooke Cantwell
 *
 * 1 May 2016
 *
 * Methods and functions for the derived
 * two day package class.
 */

#include <iomanip>
#include <iostream>
#include "twoday.h"

using namespace std;

int TwoDayPackage::numTwoDay = 0;
float TwoDayPackage::totalTwoDay = 0;

//constructors

TwoDayPackage::TwoDayPackage( ) {
	fee = 0;
	numTwoDay++;
}

TwoDayPackage::TwoDayPackage(float f) {
	fee = f;
	numTwoDay++;
}

float TwoDayPackage::calculateCost( ) {

	total = Package::calculateCost( );
	total += fee;

	totalTwoDay += total;
}

//accessor methods

float TwoDayPackage::getTotal( ) {
	return(total);
}

int TwoDayPackage::getNumTwoDay( ) {
	return(numTwoDay);
}

void TwoDayPackage::print( ) {
	Package::print( );
	cout << std::fixed << setprecision(2) << "Fee: $" << fee << endl;
	cout << setprecision(2) << "Cost: $" << total << endl;
}
