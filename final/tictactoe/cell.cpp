/*
 * Cell Class Implementation
 *
 * cell.cpp
 *
 * Brooke Cantwell
 *
 * 8 May 2016
 *
 * Cell class methods.
 *
 */

#include <iostream>
#include "cell.h"

using namespace std;

//CONSTRUCTORS

//default constructor
Cell::Cell( ) {
	row = col = 0;
	marker = ' ';
	iVal = 0;
	iMarker = 0;
}

Cell::Cell(int r, int c, char m) {
	row = r;
	col = c;
	marker = m;
}

//MUTATOR METHODS

//setLocation, assign cell location
void Cell::setLocation(int r, int c) {
	row = r;
	col = c;
}

bool Cell::setMarker(char m) {
	bool restat = true;

	if (m == 'X' || m == 'O' || m == ' ') {
		marker = m;	
		
		//set ival from the marker
		switch(m) {
			case 'X':
				iMarker = 3;
				break;
			case 'O':
				iMarker = -3;
				break;
			default:
				iMarker = 0;
		}
	}
	else {
		iMarker = 0;
		restat = false;
	}
	
	return(restat);

}

//setTakenCell, determine if a cell is already taken
bool Cell::takenCell( ) {
	bool restat = true;

	if (iMarker == 0)
		restat = false;

	return(restat);
}

//ACCESSOR METHODS

char Cell::getMarker( ) {
	return(marker);
}

int Cell::getiMarker( ) {
	return(iMarker);
}
