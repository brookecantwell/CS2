/*
 * Polygon Class Implementation
 *
 * polygon.cpp
 *
 * Brooke Cantwell
 *
 * 6 March 2016
 *
 * Implementation for the polygon class.
 */


#include "polygon.h"
#include <iomanip>
#include <iostream>

using namespace std;

//initialize static variables
int Polygon::numPolygons = 0;
double Polygon::averageArea = 0;
double Polygon::averagePerimeter = 0;
double Polygon::areaSum = 0;
double Polygon::perimeterSum = 0;

//constructors

Polygon::Polygon( ):MIN(DEFAULT_MIN), MAX(DEFAULT_MAX) {
	length = width = 0;
	perimeter = (length * 2) + (width * 2);
	area = length * width;
	numPolygons++;
}

Polygon::Polygon(int min, int max):MIN(min), MAX(max) {
	length = width = 0;
	perimeter = (length * 2) + (width * 2);
	area = length * width;
	numPolygons++;
}

Polygon::Polygon(int min, int max, int l, int w):MIN(min), MAX(max) {
	length = l;
	width = w;
	perimeter = (length * 2) + (width * 2);
	area = length * width;
	numPolygons++;
}

//destructor
Polygon::~Polygon( ) {
	//subtract the area of the destructed polygon from the areaSum
	//and the perimeter from the perimeterSum
	areaSum -= area;
	perimeterSum -= perimeter;
	//decrement the number of polygons
	numPolygons--;
}

//mutator methods, set methods

bool Polygon::setWidth(int w) {
	bool setValue = false;

	if (w >= MIN && w <= MAX) {
		width = w;
		setValue = true;
	}

	return(setValue);
}

bool Polygon::setLength(int l) {
	bool setValue = false;

	if (l >= MIN && l <= MAX) {
		length = l;
		setValue = true;
	}

	return(setValue);
}

//mutator methods, accept user input

void Polygon::inputLength( ) {
	do {
		cout << "Input length: ";
		cin >> length;
	} while (!setLength(length));
}

void Polygon::inputWidth( ) {
	do {
		cout << "Input width: ";
		cin >> width;
	} while(!setWidth(width));
}

//accessor functions

int Polygon::getNumPolygons( ) {
	return(numPolygons);
}

int Polygon::getMaxPolygons( ) {
	return(MAX_POLYGONS);
}

//calculateStatistics, calculates the area and perimeter of the polygon
void Polygon::calculateStatistics( ) {

	perimeter = (length * 2) + (width * 2);
	area = length * width;

}


//displayStatistics, displays length, width, area, and perimeter
void Polygon::displayStatistics( ) {
	cout << "Length: " << length << endl;
	cout << "Width: " << width << endl;
	cout << "Perimeter: " << perimeter << endl;
	cout << "Area: " << area << endl;
}

//drawShape, draws polygon with specifies length and width
void Polygon::drawShape( ) {
	for (int l = 1; l <= length; l++) {
		for (int w = 1; w <= width; w++) {
			if (w == 1 || w == width || l == 1 || l == length) 
				cout << '*';				
			else
				cout << ' ';
		}
	cout << endl;
	}
}

//calculateAverages, updates the average statistics
void Polygon::calculateAverages( ) {
	areaSum += area;
	perimeterSum += perimeter;
	averageArea = areaSum / numPolygons;
	averagePerimeter = perimeterSum / numPolygons;

}

//displayAverages, displays average statistics
void Polygon::displayAverages( ) {
	cout << endl << "AVERAGES" << endl;
	cout << "Average area: " << setprecision(2) << averageArea << endl;
	cout << "Average perimeter: " << averagePerimeter << endl << endl;
}
