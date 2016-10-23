/* Implementation of the Level Class
 *
 * level.cpp
 *
 * Brooke Cantwell
 *
 * 20 March 2016
 *
 * Implementation for the level class
 */

#include "level.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

//static variables
int Level::trickLevel;

//functions

/*
//setTrickLevel, determines which level of the adventure will
//contain a trick present
int setTrickLevel( ) {
	static bool firstTime = true;
	int rNum;

	if (firstTime == true) {
		strand (time(0) );
		firstTime = false;
	}

	trickLevel = rand( ) % 3 + 0;

}
*/
//methods for operator overloading

//output operator
ostream& operator<< (ostream&out, const Level&l) {
/*
	out << "Level Number: " << levelNumber << endl;
	out << "Monster Name: " << monster << endl;
	out << "Treasure: " << treasure << endl;
	out << "Level Mission: " << adventure << endl;
	out << "Trick Level: ";
	if (trick == true)
		out << "Yes" << endl;
	else
		out << "No" << endl;
*/
	l.displayLevelInfo(out);

	return(out);
}

//constructors

//default constructor
Level::Level( ) {
	monster = "Monster";
	treasure = "Treaure";
	levelNumber = 0;
	adventure = "Level Objective";
}

//constructor for monster name, treasure, and level number
Level::Level(string m, string t, int l, string a) {
	monster = m;
	treasure = t;
	levelNumber = l;
	adventure = a;
}


//setTrickLevel, determines which level of the adventure will
////contain a trick present
int Level::setTrickLevel( ) {
        static bool firstTime = true;
        int rNum;

        if (firstTime == true) {
                srand (time(0) );
                firstTime = false;
        }

        trickLevel = rand( ) % 3 + 1;

}

//mutator methods, set methods

//setTrick, if the level number is the same as the static integer
//determines as the level containing the trick, set the boolean
//data member trick to true
void Level::setTrick( ) {
	if (trickLevel == levelNumber)
		trick = true;
	else
		trick = false;
}

//setMonster, mutator method for the monster name
void Level::setMonster(string m) {
	monster = m;
}

//setTreasure, mutator method for the treasure
void Level::setTreasure(string t) {
	treasure = t;
}

//setLevelNumber, mutator method for the level number
void Level::setLevelNumber(int l) {
	levelNumber = l;
}

//setAdventure, mutator method that sets the mission of the level
void Level::setAdventure(string a) {
	adventure = a;
}

//displayLevelInfo, displays all information about a level
void Level::displayLevelInfo(ostream&out) const {
	out << "Level Number: " << levelNumber << endl;
	out << "Monster Name: " << monster << endl;
	out << "Treasure: " << treasure << endl;
	out << "Level Mission: " << adventure << endl;
	out << "Trick Level: ";
	if (trick == true)
		out << "Yes" << endl;
	else
		out << "No" << endl;

}

//accessor methods

string Level::getMonster( ) const {
	return(monster);
}	

string Level::getTreasure( ) const {
	return(treasure);
}

string Level::getAdventure( ) const {
	return(adventure);
}

int Level::getLevelNumber( ) const {
	return(levelNumber);
}

bool Level::getTrickValue( ) const {
	return(trick);
}

int Level::getTrickLevel( ) {
	return(trickLevel);
}
