/*
 * Brooke Cantwell
 *
 * 31 January 2016
 *
 * play.cpp
 *
 * Practice Lab #1 - CS1 Review Lab!
 *
 * Creates one dimensional arrays, 1 with
 * odd numbers and 1 with even numbers,
 * swaps every odd position in the single
 * arrays, and fills every alternate row
 * in a 2 dimensional array with the values
 * of the swapped one dimensional arrays.
 *
 */

#include <iostream>

using namespace std;

main() {

	const int MAX = 10;
	//row and column dimensions for the 2 dimensional array
	const int ROW = 7, COL = 4;

	//single dimensional arrays
	int arrayEven[MAX] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
	int arrayOdd[MAX] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};

	//two dimesnional array initialized to zero
	int array2D[ROW][COL] = {0};

	//function prototypes
	void swap (int&, int&);
	void swap (int[ ], int[ ], const int);
	void display (int[ ], int[ ], const int);
	void initialize (int[ ][4], const int, const int, int[ ], int[ ], const int);
	void display (int[ ][4], const int, const int);

	//display content of one dimensional arrays
	display (arrayOdd, arrayEven, MAX);

	//swap the contents of every odd positioned element of the arrays
	swap (arrayOdd, arrayEven, MAX);

	//display the new single dimensional arrays
	cout << endl << "After call to swap" << endl << endl;
	display (arrayOdd, arrayEven, MAX);	

	cout << endl;

	//use single dimensional arrays to initialize the two dimensional array
	initialize (array2D, ROW, COL, arrayEven, arrayOdd, MAX);

	//display the contents of the 2 dimensional array
	display (array2D, ROW, COL);
	
}

//function definition for swap function that deals with single values
void swap (int&x, int&y) {

	int x2 = x;

	x = y;
	y = x2;	
}

//function definition for the swap function that deals with arrays
void swap (int arrayOdd[ ], int arrayEven[ ], const int MAX) {

	int swap (int&, int&);

	for (int i = 0; i < MAX; i+=2) {
		swap(arrayEven[i], arrayOdd[i]);
	}
}

//function definition for display function that outputs the one dimensional arrays
void display (int arrayOdd[ ], int arrayEven[ ], const int MAX) {
	for (int i = 0; i < MAX; i++) {
		cout << arrayOdd[i] << '\t' << arrayEven[i] << endl;
	}
}

//function definition for initialize that fills the two dimensional array with the
//contents of the one dimensional arrays (after swapping)
void initialize (int array2D[ ][4], const int ROW, const int COL, int arrayEven[ ], int arrayOdd[ ], const int MAX) {
	
	//counter variables for the even and odd single dimensional arrays
	int e = 0;
	int o = 0;
	//boolean variables that control the direction of the single dimensional
	//arrays by changing the value of the index from (counter) to MAX - counter	
	bool reverseE = false;
	bool reverseO = false;

	//for loop to input the value of the one dimensional arrays into the 2d array
	for (int r = 0; r < ROW; r++) {
		for (int c = 0; c < COL; c++) {
			//use array arrayEven
			if (r%2 != 0) {

				//if the counter variable used as the index reaches the
				// maximum number of elements, and the reverse variable
				// is false, make the reverse variable true, and if the
				// index variable reaches zero, and reverse is true, set
				// reverse to false
		
				if (e == (MAX-1) && reverseE == false)
					reverseE = true;
				if (e == 0 && reverseE == true)
					reverseE = false;

				array2D[r][c] = arrayEven[e];

				//if the reverse variable is true, decerement the index,
				//and if it's false, increment the index

				if (reverseE == true)
					e--;
				else
					e++;

			}

			//use array arrayOdd
			else {
				//repeat above steps for rows filled with values from arrayOdd

				if (o == (MAX-1) && reverseO == false)
					reverseO = true;
				if (o == 0 && reverseO == true)
					reverseO = false;		

				array2D[r][c] = arrayOdd[o];
				
				if (reverseO == true)
					o--;
				else
					o++;
			}

		}
	}	
}

//function definition for display that outputs the contents of the two dimensional array
void display (int array2D[ ][4], const int ROW, const int COL) {
	for (int r = 0; r < ROW; r++) {
		for (int c = 0; c < COL; c++) {
			cout << array2D[r][c] << "  ";
		}
		cout << endl;
	}
}
