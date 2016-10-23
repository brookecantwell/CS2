/*
 * Implementation of Overnight Class
 *
 * overnight.cpp
 *
 * Brooke Cantwell
 *
 * 1 May 2016
 *
 * Methods and global functions for the overnight
 * package class.
 */

#include <iomanip>
#include <iostream>
#include "overNight.h"

using namespace std;

int OverNightPackage::numOvernight = 0;
float OverNightPackage::totalOverNight = 0.00;

OverNightPackage::OverNightPackage( ) {
	fee = 0;
	numOvernight++;
}

OverNightPackage::OverNightPackage(int f) {
	fee = f;
	numOvernight++;
}

float OverNightPackage::calculateCost( ) {
	
	total = Package::calculateCost( );
	total += fee;

	totalOverNight += total;	

	return(total);
}

float OverNightPackage::getTotal( ) {
	return(total);
}

//accessor methods

int OverNightPackage::getNumOvernight( ) {
	return(numOvernight);
}

void OverNightPackage::print( ){
	Package::print( );
	cout << std::fixed << setprecision(2) << "Fee: $" << fee << endl;
	cout << setprecision(2) << "Cost: $" << total << endl << endl;
}
