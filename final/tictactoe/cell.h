/*
 * Cell Class Definition
 * 
 * cell.h
 *
 * Brooke Cantwell
 *
 * 8 May 2016
 *
 * Definition for the Cell class to be
 * used in the Tic Tac Toe class.
 */

#ifndef CELL_H
#define CELL_H

#include <iostream>

using namespace std;

class Cell {
	public:
		//constructors
		Cell( );
		Cell(int, int, char);
		//mutator methods
		void setLocation(int, int);
		//set marker and iMarker
		bool setMarker(char);
		bool takenCell( );
		//accessor methods
		char getMarker( );
		int getiMarker( );
	private:
		int row, col;
		char marker;
		int iVal, iMarker;
};

#endif
