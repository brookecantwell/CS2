/*
 * Phone Class
 *
 * phone.h
 *
 * Brooke Cantwell
 *
 * 2 March 2016
 *
 * Header file for the phone class
 *
 */

#ifndef PHONE_H
#define PHONE_H

using namespace std;

class Phone {
	public:
		//constructors
		Phone( );
		Phone(int, int, int);
		//mutator methods
		void setAreaCode(int);
		void setExchange(int);
		void setLine(int);
		void setAll(int, int, int);
		void inputAreaCode( );
		void inputExchange( );
		void inputLine( );
		//accessor methods
		int getAreaCode( );
		int getExchange( );
		int getLine( );
		int getMaxTexts( ) const;
		//display method
		void display( );
	private:
		int areaCode, exchange, line;
		const int maxTexts;
};

#endif
