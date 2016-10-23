/*
 * Lab #3 - Polygon Lab
 *
 * driver.cpp
 *
 * Brooke Cantwell
 *
 * 6 March 2016
 *
 * Driver for the polygon class, displays a menu
 * and allows the user to build a new polygon, 
 * print an existing polygon, display statistics,
 * or delete an existing polygon.
 */

#include <iostream>
#include "polygon.h"
#include <iomanip>

using namespace std;

main( ) {
	//local variables
	int menuOption;	
	int index = 0;
	int draw;
	int deleteNum;

	//array of pointers
	Polygon *ptrP[Polygon::getMaxPolygons( )];

	//function declarations
	int displayMenu( );
	void buildPolygon(Polygon*[ ], int);
	void displayStatistics(Polygon*[ ]);
	void drawPolygons(Polygon*[ ]);

	//keep displaying the menu until the user quits
	while (menuOption != 5) {

		//display the menu and return the user's choice
		menuOption = displayMenu( );

		switch (menuOption) {
			case 1:
				//build a new polygon
				ptrP[index] = new Polygon;				
				//use pointer to input length, width, and draw shape
				//with the buildPolygon function
				buildPolygon(ptrP, index);
				//increment the index of the array of pointers
				index++;
				break;
			case 2:
				cout << "Choose polygon to draw: ";
				cin >> draw;
				draw--;
				//draw shape
				(*ptrP[draw]).drawShape( );
				break;
			case 3:
				//calculate the statistics for every polygon constructed
				for (int i = 0; i < index; i++) {
					cout << "Polygon #" << i + 1 << endl;
					(*ptrP[i]).displayStatistics( );
				}
				Polygon::displayAverages( );	
				break;
			case 4:
				cout << "Enter polygon to be deleted: ";
				cin >> deleteNum;
				
				//decrement deleteNum so it can be used as an index for
				//the array of pointers
				deleteNum--;

				//delete object that has been dynamically allocated
				delete ptrP[deleteNum];
		
				index--;
				
				//move the elements in the array one over starting from
				//the deleted element
				for (int i = deleteNum; i < index; i++) {
					ptrP[i] = ptrP[i+1];
				}

		
				break;
			case 5:
				cout << "OK!" << endl << endl;
				break;
			default:
				cout << "Error, please choose a valid menu option." << endl;
				continue;
		}
	}

	//display the final statistics
	displayStatistics(ptrP);

	//draw all of the polygons the user created
	drawPolygons(ptrP);		
}

//displayMenu function, displays the menu to the user
int displayMenu( ) {

	int menuOption;

	cout << "MENU: " << endl;
	cout << "1. Build a new polygon" << endl;
	cout << "2. Draw an existing polygon" << endl;
	cout << "3. Show summary statistics" << endl;
	cout << "4. Delete an existing object" << endl;
	cout << "5. Quit" << endl;

	cout << "Option: ";
	cin >> menuOption;

	return(menuOption);

}

//buildPolygon, uses the inputLength, inputWidth, and drawShape methods of the polygon class
void buildPolygon (Polygon *ptrP[ ], int index) {
	//get length and width from user input
	ptrP[index] -> inputLength( );
	ptrP[index] -> inputWidth( );
	//draw polygon
	ptrP[index] -> drawShape( );
	//update statistics and averages
	ptrP[index] -> calculateStatistics( );
	ptrP[index] -> calculateAverages( );
}

//displayStatistics, displays statistics for every constructed polygon and averages
void displayStatistics(Polygon *ptrP[ ]) {

	int max;

	max = Polygon::getNumPolygons( );

	for (int i = 0; i < max; i++) {
		cout << "Polygon #" << i + 1 << endl;
		ptrP[i] -> displayStatistics( );
	}

	//call static method displayAverages( );		
	Polygon::displayAverages( );
}

//drawPolygons, draws all of the polygons created by the user that have not been deleted
void drawPolygons(Polygon *ptrP[ ]) {

	int numPolygons = Polygon::getNumPolygons( );

	for (int i = 0; i < numPolygons; i++) {
		cout << "Polygon #" << i + 1 << endl;
		ptrP[i] -> drawShape( );
	}
}
