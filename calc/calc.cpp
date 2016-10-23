/*
 * Practice Lab #2 - CS1 Review Lab
 *
 * calc.cpp
 *
 * Brooke Cantwell
 *
 * 9 February 2016
 *
 * Generates a random equation (randomizing operands 1 and
 * 2 (with upper and lower bounds depending on the level)
 * and the operator, accepts user input, compares answers
 * and stores the equation and if the user answered correctly
 * into arrays to prevent repeated questions. Also, a menu
 * is displayed with options to stay on the same level,
 * go to the next level, display statistics, or quit. If the
 * user quits the program, statistics are displayed for each
 * level the user completed.
 *
 */


#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

main() {

	//declare local variables
	int min = 0, max = 10;
	const int MAX_EQUATIONS = 150;
	int op1, op, op2;
	char opChar;
	int operators = 4;
	double answer;
	bool correct;
	int index = 0;
	bool repeat;
	int attempts = 1;
	int repeatPosition; 
	int level = 0;
	int countCorrect = 0;
	int addition = 0, subtraction = 0, multiplication = 0, division = 0;
	int additionCorrect = 0, subtractionCorrect = 0, multiplicationCorrect = 0, divisionCorrect = 0;
	int menuOption;
	int levels = 4, completedLevels = 1;

	//array declarations
	int arrayOp1[MAX_EQUATIONS];
	char arrayOpChar[MAX_EQUATIONS];
	int arrayOp2[MAX_EQUATIONS];
	bool arrayCorrect[MAX_EQUATIONS];
	double additionPercent[levels];
	double subtractionPercent[levels];
	double multiplicationPercent[levels];
	double divisionPercent[levels];

	//function prototypes
	void generateEquation (int&, int&, int&, char&, int, int);
	void getBounds (int, int&, int&);
	bool searchArray (int, char, int, int[ ], char[ ], int[ ], bool[ ], int, int&);
	double displayEquation (int, char, int);
	bool evaluateEquation (double, int, char, int);
	void storeEquation (int, char, int, bool, int[ ], char[ ], int[ ], bool[ ], int);
	int levelPrompt (int&, int&, double[ ], double[ ], double[ ], double[ ]);
	void levelOptions (int, int&);
	void statistics (int, int, char[ ], bool[ ], double[ ], double[ ], double[ ], double[ ]);
	void display (int, int, double[ ], double[ ], double[ ], double[ ]);

	//while the sentinal value hasn't been entered and the user hasn't completed all levels
	while (answer != -999 && completedLevels <= 4) {

		//get minimum and maximum values depending on level
		getBounds (level, min, max);

		//create equation
		generateEquation (op1, op, op2, opChar, max, min);
		
		//search arrays for a repeat that hasn't been correctly answered
		repeat = searchArray (op1, opChar, op2, arrayOp1, arrayOpChar, arrayOp2, arrayCorrect, index, repeatPosition);

		//if the equation is a repeat that has been answered correctly, go to the beginning of the loop
		if (repeat == true)
			continue;

		else {		
			//display the equation and prompt for answer from the user
			answer = displayEquation (op1, opChar, op2);

			if (answer == -999)
				break;

			else {	
				//evaluate the equation
				correct = evaluateEquation (answer, op1, opChar, op2);
				if (!correct) {
					//if the user is incorrect, give 2 more chances to answer
					do {
						answer = displayEquation (op1, opChar, op2);
						correct = evaluateEquation (answer, op1, opChar, op2);
						attempts++;

					} while (!correct && attempts <= 2);
				
					//if after chances the user is still incorrect, alert them and
					//reset variables
					if (!correct) {
						cout << "Max attempts reached." << endl;
						attempts = 1;
						countCorrect = 0;
					}
				}

				if (correct) 
					countCorrect++;
			}
			
			//display the menu if the user has answered 10 questions in a row correctly
			if (countCorrect == 10) {
				//compute statustucs
				statistics (index, level, arrayOpChar, arrayCorrect, additionPercent, subtractionPercent, multiplicationPercent, divisionPercent);
				//display menu and store user answer
				menuOption = levelPrompt(level, completedLevels, additionPercent, subtractionPercent, multiplicationPercent, divisionPercent);
				//reset count for correct answers
				countCorrect = 0;
				//break from the loop if the user wants to quit
				if (menuOption == 4)
					break;
			}

		}
		//store the equation in the array			
		storeEquation (op1, opChar, op2, correct, arrayOp1, arrayOpChar, arrayOp2, arrayCorrect, index);
		//increment index
		index++;
	}
		
	cout << "Goodbye!" << endl;
	
}
