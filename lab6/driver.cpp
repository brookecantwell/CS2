/*
 * Lab #6 - Driver
 *
 * driver.cpp
 *
 * Brooke Cantwell
 *
 * 27 April 2016
 *
 * Driver for the package inheritance / polymorphism lab
 *
 */

#include <iostream>
#include <iomanip>
#include "customer.h"
#include "package.h"
#include "overNight.h"
#include "twoday.h"

using namespace std;

template <typename T>
void testPackage(T package) {
	package.inputSender( );
	package.inputRecipient( );	
	package.inputPackageWeight( );
	package.inputCostPerOunce( );
	package.calculateCost( );

	package.print( );

}

main( ) {
	const int SIZE = 100;
	TwoDayPackage *TwoDayPackages[SIZE];
	OverNightPackage *OverNightPackages[SIZE];
	int index2 = 0, indexON = 0;
	int option;
	float total2Day, totalON;

	do {

		cout << "Which type of package would you like to send?" << endl;
		cout << "1. Overnight" << endl;
		cout << "2. Two Day" << endl;
		cout << "3. Quit" << endl;
		cout << "Enter option: " << endl;
		cin >> option;

		switch (option) {
			case 1:
				OverNightPackages[indexON] = new OverNightPackage(6);
				testPackage(*OverNightPackages[indexON]);
				indexON++;
				break;
			case 2:
				TwoDayPackages[index2] = new TwoDayPackage(3);
				testPackage(*TwoDayPackages[index2]);
				index2++;
				break;
		}
	} while (option != 3 && index2 <= 100 & indexON <= 100);


	cout << setprecision(2) << "Overnight Package Total: " << OverNightPackage::totalOverNight << endl;
	cout << setprecision(2) << "Two Day Package Total: " << TwoDayPackage::totalTwoDay << endl;

	cout << "Overnight Packages: " << indexON << endl;
	cout << "Two Day Packages: " << index2 << endl;
}


