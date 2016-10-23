#include <iostream>
#include "baseClass.h"

using namespace std;

#ifndef DERIVEDCLASS1_H
#define DERIVEDCLASS1_H

class derivedClass1: public baseClass  {

public:
	derivedClass1( int i ) : baseClass(i) {}

	void print() {
		cout << "Derived Class #1 print(): id == " << id << endl;
	}
};

#endif
