#include <iostream>
#include "date.h"

using namespace std;

main( ) {

	Date d(10, 27, 1993);

	Date *ptrD = new Date;

	d.display( );

	//dot operator takes prescedence, (*ptrD) dereferences
	(*ptrD).display( );	

	delete ptrD;

/*	int *ptrX;

	//dynamically allocated
	ptrX = new int;

	cout << ptrX << ' ' << &ptrX << ' ' << *ptrX << endl;
	
	*ptrX = 17;

	cout << ptrX << ' ' << &ptrX << ' ' << *ptrX << endl;
*/
}
