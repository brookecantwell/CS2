/* Level Class Definition
 *
 * level.h
 *
 * Brooke Cantwell
 *
 * 20 March 2016
 *
 * Definition of the level class.
 */

#ifndef LEVEL_H
#define LEVEL_H

#include <iostream>

using namespace std;

class Level {
	//operator overloading
	friend ostream& operator<< (ostream&, const Level&);

	public:
		//constructors
		Level( );
		Level(string, string, int, string);
		//determines which level has the trick
		static int setTrickLevel( );
		void setTrick( );
		void setMonster(string);
		void setTreasure(string);
		void setLevelNumber(int);
		void setAdventure(string);
		void displayLevelInfo(ostream&) const;
		//accessor methods
		string getMonster( ) const;
		string getTreasure( ) const;
		string getAdventure( ) const;
		int getLevelNumber( ) const;
		static int getTrickLevel( );
		bool getTrickValue( ) const;
	private:
		string monster;
		string treasure;
		int levelNumber;
		string adventure;
		static int trickLevel;
		bool trick;
};
#endif
