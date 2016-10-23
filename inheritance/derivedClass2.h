#include <iostream>
#include "baseClass.h"

using namespace std;

#ifndef DERIVEDCLASS2_H
#define DERIVEDCLASS2_H

class derivedClass2: public baseClass {

public:
	derivedClass2( int i ) : baseClass(i) {}
	void print() {
		cout << "Derived Class #2 print(): id == " << id << endl;
	}
};

#endif
