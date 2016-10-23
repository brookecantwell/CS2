/*
 * Polygon Class definition
 *
 * polygon.h
 *
 * Brooke Cantwell
 *
 * 6 March 2016
 *
 * Class definition for the polygon class
 *
 */

#ifndef POLYGON_H
#define POLYGON_H

class Polygon {
	public:
		//constructors
		Polygon( );
		Polygon(int, int);
		Polygon(int, int, int, int);
		//destructor
		~Polygon( );
		//accessor method for numPolygons
		static int getNumPolygons( );
		static int getMaxPolygons( );
		//set methods
		bool setLength(int);
		bool setWidth(int);
		//input methods
		void inputLength( );
		void inputWidth( );
		//method to draw polygons
		void drawShape( );
		//methods for statistics
		void calculateStatistics( );
		void displayStatistics( );
		void calculateAverages( );
		static void displayAverages( );
	private:
		static const int MAX_POLYGONS = 25;
		static int numPolygons;
		int length;
		int width;
		int perimeter;
		int area;
		const int MIN;
		const int MAX;
		static const int DEFAULT_MIN = 0;
		static const int DEFAULT_MAX = 10;
		//static variables for class level calculations
		static double averageArea, areaSum;
		static double averagePerimeter, perimeterSum;
};

#endif
