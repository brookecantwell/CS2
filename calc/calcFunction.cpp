/*
 * Practice Lab #2 - CS1 Review Lab (Functions)
 *
 * calcFunction.cpp
 *
 * Brooke Cantwell
 *
 * 9 February 2016
 *
 * Functions used in the calc.cpp file
 *
 */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

//function definition for generateEquation, randomly generates 2 operands and operator
bool generateEquation (int&op1, int&op, int&op2, char&opChar, int max, int min) {

	char convertToOperator (int);
	int randomize (int, int);

	op1 = randomize (min, max);

	op2 = randomize (min, max);	

	op = randomize (0, 4);

	opChar = convertToOperator (op);


	if (op2 == 0 && opChar == '/') {
		while (op2 == 0)
			op2 = randomize (min, max);
	}

}

//function definition for randomize, generates random numbers using max and min values
int randomize (int min, int max) {
	
	static bool firstTime = true;
	int rNum;

	if (firstTime == true) {
		srand (time(0) );
		firstTime = false;
	}

	rNum = rand() % max + min;
	
	return(rNum);

}

//function definition for convertToOperator, converts random integer to operator character
char convertToOperator (int op) {

	char opChar;	

	switch(op) {
		case 0:
			opChar = '+';
			break;
		case 1:
			opChar = '-';
			break;
		case 2:
			opChar = '*';
			break;
		case 3:
			opChar = '/';
			break;
		deafult:
			cout << "Error in random number generation of operator." << endl;
	}	
	
	return(opChar);
}

//function definition for getBounds, gets max and min values based on level
void getBounds (int level, int&min, int&max) {

	switch(level) {
		case 0:
			min = 0;
			max = 10;
			break;
		case 1:
			min = 0;
			max = 25;
			break;
		case 2:
			min = 10;
			max = 25;
			break;
		case 3:
			min = -25;
			max = 25;
			break;
	}

}

//function definition for displayEquation, displays the equation and prompts the user for input
double displayEquation (int op1, char opChar, int op2) {

	double answer;

	cout << "Equation: " << op1 << ' ' << opChar << ' ' << op2 << endl;
	cout << "Enter answer (or -999 to quit): ";
	cin >> answer;

	return(answer);
}

//function definition for evaluateEquation, compares user answer to computed answer
bool evaluateEquation (double answer, int op1, char opChar, int op2) {

	bool correct;
	double compAnswer;

	switch (opChar) {
		case '+':
			compAnswer = op1 + op2;
			break;
		case '-':
			compAnswer = op1 - op2;
			break;
		case '*':
			compAnswer = op1 * op2;
			break;
		case '/':
			compAnswer = (double)op1 / op2;
			break;
	}

	//multiply user answer and computed answer by 1,000 and store the results into separate integer
	//variables for comparison in the case of division

	if (opChar == '/') {

		int compInt, userInt, difference;
		
		compInt = compAnswer * 1000;
		userInt = answer * 1000;

		if (userInt == compInt) {
			correct = true;
			cout << "Correct!" << endl;
		}
		else {
			correct = false;
			cout << "Incorrect!" << endl;
		}
	}
	else
	if (compAnswer == answer) {
		correct = true;
		cout << "Correct!" << endl;
	}
	else {
		correct = false;
		cout << "Incorrect!" << endl;
	}	

	return(correct);

}

//function definition for storeEquation, stores operands, operator, and if the answer is correct into separate arrays
void storeEquation (int op1, char opChar, int op2, bool correct, int arrayOp1[ ], char arrayOpChar[ ], int arrayOp2[ ], bool arrayCorrect[ ], int index) {

	arrayOp1[index] = op1;
	arrayOpChar[index] = opChar;
	arrayOp2[index] = op2;
	arrayCorrect[index] = correct;

}

//function definition for searchArray, searches the arrays for repeats and returns true if the equation is a repeat with a correct answer
bool searchArray (int op1, char opChar, int op2, int arrayOp1[ ], char arrayOpChar[ ], int arrayOp2[ ], bool arrayCorrect[ ], int index, int&repeatPosition) {

	bool repeat = false;

	for (int i = 0; i < index; i++) {
		if (arrayOp1[i] == op1) {
			if (arrayOpChar[i] == opChar) {
				if (arrayOp2[i] == op2) {
					repeat = true;
					repeatPosition = i;
				}
				//if the question was answered incorrectly
				//set 'repeat' to false
				if (arrayCorrect[i] == 1)
					repeat = false;	
			}
		}
	}

	return (repeat);
}


//function definition for levelPrompt, shows menu after the user has completed a level
int levelPrompt (int&level, int&completedLevels, double additionPercent[ ], double subtractionPercent[ ], double multiplicationPercent[ ], double divisionPercent[ ]) {
	
	int menuOption;
	
	void displayStatistics (int, double[ ], double[ ], double[ ], double[ ]);
	void display (int, int, double[ ], double[ ], double[ ], double[ ]);

	cout << "Enter menu option: " << endl;
	cout << "1. Continue at the current level." << endl;
	cout << "2. Go to the next level." << endl;
	cout << "3. Display summary statistics for the current level." << endl;
	cout << "4. Quit." << endl;	
	cout << "Enter option: ";

	cin >> menuOption;

	switch (menuOption) {
		case 1:
			level = level;
			break;
		case 2:
			level++;
			completedLevels++;
			break;
		case 3:
			displayStatistics (level, additionPercent, subtractionPercent, multiplicationPercent, divisionPercent);
			levelPrompt (level, completedLevels, additionPercent, subtractionPercent, multiplicationPercent, divisionPercent);
			break;
		case 4:
			//quit, break is included in main program
			display (level, completedLevels, additionPercent, subtractionPercent, multiplicationPercent, divisionPercent);
			return(menuOption);
			break;
	}

}

//function definition for displayStatistics, used to display the statistics for a certain level if the menu option is chosen
void displayStatistics (int level, double additionPercent[ ], double subtractionPercent[ ], double multiplicationPercent[ ], double divisionPercent[ ]) {

	        cout << "Addition: ";
                if (additionPercent[level] > 1)
                        cout << additionPercent[level] << '%' << endl;
		//if statement prevents empty values from array from being displayed if there were no questions using an operator
                else
                        cout << "N/A" << endl;

                cout << "Subtraction: ";
                if (subtractionPercent[level] > 1)
                        cout << subtractionPercent[level] << '%' << endl;
                else
                        cout << "N/A" << endl;

                cout << "Multiplication: ";
                if (multiplicationPercent[level] > 1)
                        cout << multiplicationPercent[level] << '%' << endl;
                else
                        cout << "N/A" << endl;

                cout << "Division: ";
                if (divisionPercent[level] > 1)
                        cout << divisionPercent[level] << '%' << endl;
                else
                        cout << "N/A" << endl;
}

//function definition for statistics, goes through the array and increments variables that are used to calculate percentage of
//questions answered correctly for operator, which are then stored in separate arrays
void statistics (int index, int level, char arrayOpChar[ ], bool arrayCorrect[ ], double additionPercent[ ], double subtractionPercent[ ], double multiplicationPercent[ ], double divisionPercent[ ]) {

	double addition = 0, subtraction = 0, multiplication = 0, division = 0;
	double additionCorrect = 0, subtractionCorrect = 0, multiplicationCorrect = 0, divisionCorrect = 0;

	for (int i = 0; i < index; i++) {
		switch(arrayOpChar[i]) {
			case '+':
				addition++;
				if (arrayCorrect[i] == 1)
					additionCorrect++;
				break;
			case '-':
				subtraction++;
				if (arrayCorrect[i] == 1)
					subtractionCorrect++;
				break;
			case '*':
				multiplication++;
				if (arrayCorrect[i] == 1)
					multiplicationCorrect++;
				break;
			case '/':
				division++;
				if (arrayCorrect[i] == 1)
					divisionCorrect++;
				break;
		}
		
	
	}

	//if statements prevent division by zero
        if (addition > 0)
                additionPercent[level] = (additionCorrect / addition) * 100;
        if (subtraction > 0)
                subtractionPercent[level] = (subtractionCorrect / subtraction) * 100;
        if (multiplication > 0)
                multiplicationPercent[level] = (multiplicationCorrect / multiplication) * 100;
        if (division > 0)
                divisionPercent[level] = (divisionCorrect / division) * 100;


}

//function definition for display, displays the percentage of correctly answered questions by operator for each completed level
void display (int level, int completedLevels, double additionPercent[ ], double subtractionPercent[ ], double multiplicationPercent[ ], double divisionPercent[ ]) {
	for (int i = 0; i < completedLevels; i++) {
		cout << "Level: " << i + 1 << endl;

		cout << "Addition: ";
		if (additionPercent[i] > 1)
			cout << additionPercent[i] << '%' << endl;
		else
			cout << "N/A" << endl;
	
		cout << "Subtraction: ";
		if (subtractionPercent[i] > 1)
			cout << subtractionPercent[i] << '%' << endl;
		else
			cout << "N/A" << endl;

		cout << "Multiplication: ";
		if (multiplicationPercent[i] > 1)
			cout << multiplicationPercent[i] << '%' << endl;
		else
			cout << "N/A" << endl;
		
		cout << "Division: ";
		if (divisionPercent[i] > 1)
			cout << divisionPercent[i] << '%' << endl;
		else
			cout << "N/A" << endl;
	}	

}
