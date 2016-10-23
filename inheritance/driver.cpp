#include <iostream>
#include "baseClass.h"
#include "derivedClass1.h"
#include "derivedClass2.h"

using namespace std;

int main () {
	
	baseClass b;
	derivedClass1 d1(1);
	derivedClass2 d2(2);

	cout << endl << "Output from base and derived objects...." << endl;
	b.print();
	d1.print();
	d2.print();

	baseClass *bptr = 0;

	cout << endl << "Setting base class pointer to derived class #1 object" << endl;
	bptr = &d1;
	bptr->print();

	cout << endl << "Setting base class pointer to derived class #2 object" << endl;
	bptr = &d2;
	bptr->print();
}

