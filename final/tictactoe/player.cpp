/*
 * Player Class Implementation
 *
 * player.cpp
 *
 * Brooke Cantwell
 *
 * 5 May 2016
 *
 * Functions and methods for the Player class
 * for use in the Tic Tac Toe class.
 *
 */

#include <iostream>
#include "player.h"
#include "name.h"

using namespace std;

//GLOBAL FUNCTIONS

//input operator
istream& operator>>(istream&in, Player&p) {
	in >> p.name;
	cout << "Enter your desired player handle: ";
	in >> p.handle;

	return(in);
}

//output operator
ostream& operator<<(ostream&out, const Player&p) {
	out << "Name: " << p.name << endl;
	out << "Handle: " << p.handle << endl;
	out << "Marker: " << p.marker << endl;
	out << "Games Won: " << p.gamesWon << endl;

	return(out);
}

//METHODS

//CONSTRUCTORS

Player::Player( ) {
	handle = "Your Handle";
	marker = '0';
	gamesWon = 0;
}

Player::Player(string f, char m, string l, string hand, char mark) {
	name.setName(f, m, l);
	handle = hand;
	marker = mark;
	gamesWon = 0;
}

//MUTATOR METHODS

bool Player::setMarker(char mark) {
	bool restat = true;

	if (mark != 'X' && mark != 'x' && mark != 'O' && mark != 'o')
		restat = false;
	else
		marker = mark;

	return(restat);
}

void Player::setName(string f, char m, string l) {
	setName(f, m, l);
}

//ACCESSOR METHODS

char Player::getMarker( ) {
	return(marker);
}

string Player::getHandle( ) {
	return(handle);
}
