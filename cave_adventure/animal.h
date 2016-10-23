/*
 * Definition for the Animal Class
 *
 * animal.h
 *
 * Brooke Cantwell
 *
 * 20 March 2016
 *
 * Definition for the animal class
 */

#include <iostream>

using namespace std;

class Animal {
	//functions
	//output operator
	friend ostream& operator<< (ostream&, const Animal&);

	public:
		//constructors
		Animal( );
		Animal(string, string);
		//display method
		void display(ostream&) const;
		//mutator methods
		void setAnimal(string);
		void setSound(string);
		void setInfo(string, string);
		//accesor methods
		string getAnimal( ) const;
		string getSound( ) const;
	private:
		string animal;
		string sound;
};
