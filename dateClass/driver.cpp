#include "date.h"

main() {
	Date d;
	Date d2(10, 27, 1993);
	const Date d3(2, 17, 2015);

	void test(Date&);

//	d.display( );
//	d2.display( );
//	d3.display( );

//	d.input( );
//	d.display( );

	test(d);
	test(d2);

	cout << "Display:" << endl;
	d.display( );
	d2.display( );

}

void test(Date&d) {

	d.display( );
	d.input( );
	d.display( );

}
