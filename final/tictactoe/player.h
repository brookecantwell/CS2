/*
 * Player Class Definition
 *
 * player.h
 *
 * Brooke Cantwell
 *
 * 5 May 2016
 *
 * Definition for the Player class
 * to be used in the Tic Tac Toe class.
 *
 */

#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include "name.h"

using namespace std;

class Player {
	//global functions
	friend istream& operator>>(istream&, Player&);	
	friend ostream& operator<<(ostream&, const Player&);

	public:
		//constructors
		Player( );
		Player(string, char, string, string, char);
		//mutator methods
		bool setMarker(char);
		void setName(string, char, string);
		//accessor methods
		char getMarker( );
		string getHandle( );
		//public static data member gamesWon
		int gamesWon;
	private:
		Name name;
		string handle;
		char marker;
};
#endif
