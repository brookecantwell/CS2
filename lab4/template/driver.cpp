/*
 * Driver - Lab 4 (Template)
 * 
 * driver.cpp
 *
 * Brooke Cantwell
 *
 * 18 April 2016
 *
 * Driver to test the Set class template.
 *
 */
	
#include <iostream>
#include "set.h"

using namespace std;

main( ) {

	const int MAX_SETS = 26;

//	Set<int> *iSet[MAX_SETS];
//	Set<char> *cSet[MAX_SETS];
//	Set<string> *sSet[MAX_SETS];
//	Set<double> *dSet[MAX_SETS];
	int dataType;
	const int SENTINAL = -999;
	int menuOption;
	int numSets = 0;
	int index = 0;
	char name;
	int checkName;
	int addToSet, addElement;
	int deleteFromSet, deleteElement;
	int deleteSet;
	char deleteSetName, addToSetName, deleteFromSetName;
	char op1, operation, op2;
	int setPosition1, setPosition2;
	int checkOp1, checkOp2;
	char newSetName;

	int setNametoNumber(Set *[ ], char, int);
	Set parseOperation(Set *[ ], char, char, int&, char&, int&, int);
	
	cout << "Set Class" << endl << endl;

	//get users datatype to know what set specialization to instatiate
	//an array of pointers to
	cout << "Choose the datatype you would like to work with." << endl;
	cout << "1. Integers" << endl;
	cout << "2. Characters" << endl;
	cout << "3. Strings" << endl;
	cout << "4. Doubles" << endl;
	cout << "Choose an option: ";
	cin >> dataType;

	switch(dataType) {
		case 1:
			Set<int> *pSet[MAX_SETS];
			break;
		case 2:
			Set<char> *pSet[MAX_SETS];
			break;
		case 3:
			Set<string> *pSet[MAX_SETS];
			break;
		case 4:
			Set<double> *pSet[MAX_SETS];
	}	
	
	do {
		//display menu
		cout << "Menu" << endl;
		cout << "1. Create a new set" << endl;
		cout << "2. Delete an existing set" << endl;
		cout << "3. Add an element to an existing set" << endl;
		cout << "4. Delete an element from an existing set" << endl;
		cout << "5. Apply a set operation on an existing set" << endl;
		cout << "6. Display all created sets" << endl;
		cout << "Choose an option, or -999 to quit: ";
		//user input for menuOption
		cin >> menuOption;
		
		//switch on menuOption
		switch(menuOption) {
			case 1:
				//create a new set
				pSet[index] = new Set;
				numSets++;
				cout << "Enter the set name (single character only): ";
				cin >> name;
				//check to see if a set with that name already exists
				checkName = setNametoNumber(pSet, name, numSets);
				//if the function doesn't return the sentinal value, tell
				//the user they have to pick a new name
				if (checkName != SENTINAL) {
					cout << "You already have a set with that name. To modify the elements, use the add or delete element menu options, to delete the set, use the delete menu option." << endl;
				}
				else {
					(*pSet[index]).setSetName(name);	
					cin >> *pSet[index];
					cout << *pSet[index];
					index++;
				}
				break;
			case 2:
				//delete an existing set
				cout << "Enter the name of the set you would like to delete: ";
				cin >> deleteSetName;
				deleteSet = setNametoNumber(pSet, deleteSetName, numSets);
				//if the function returns -999, alert the user that the set doesn't exist
				if (deleteSet == SENTINAL) {
					cout << "A set with that name has not been created." << endl;
				}
				else {
					//delete the set and shift the elements in the array

					delete pSet[deleteSet];
					pSet[deleteSet] = NULL;

					--numSets;
					--index;

                                        cout << "index: " << index << endl;
                                        cout << "numSets: " << numSets << endl;
                                        cout << "deleteSet: " << deleteSet << endl;

					for (int i = deleteSet; i < numSets; i++)
						pSet[i] = pSet[i + 1];

				}
				break;
			case 3:
				//add an element to an existing set
				cout << "Enter the name of the set you would like to add an element to: ";
				cin >> addToSetName;
				addToSet = setNametoNumber(pSet, addToSetName, numSets);
				//if the function returns -999, alert the user that the set doesn't exist
				if (deleteSet == SENTINAL)
					cout << "A set with that name has not been created." << endl;
				else {
					cout << "Enter the element you would like to add: ";
					cin >> addElement;
					*pSet[addToSet] + addElement;
					cout << *pSet[addToSet];
				}
				break;
			case 4:
				//delete an element from an existing set
				cout << "Enter the name of the set you would like to delete an element from: ";
				cin >> deleteFromSetName;
				deleteFromSet = setNametoNumber(pSet, deleteFromSetName, numSets);
				//if the function returns -999, alert the user that the set doesn't exist
				if (deleteFromSet == SENTINAL)
					cout << "A set with that name has not been created." << endl;
				else {
					cout << *pSet[deleteFromSet];
					cout << "Enter the element you would like to delete: ";
					cin >> deleteElement;
					*pSet[deleteFromSet] - deleteElement;
				}
				break;
			case 5:
				//preform a set operation on an existing set
				cout << "Enter the set operation you are trying to perform." << endl;
				cout << "Operation include + (union), ^ (intersection), and - (difference)" << endl;
				cin >> op1 >> operation >> op2;
				//check to make sure both sets already exist
				checkOp1 = setNametoNumber(pSet, op1, numSets);
				checkOp2 = setNametoNumber(pSet, op2, numSets);
				//alert the user if 1 or both don't exist
				if (checkOp1 == SENTINAL || checkOp2 == SENTINAL)
					cout << "One or both of these sets do not exist. To see existing sets, choose option 6 on the menu." << endl;
			
				//if both sets exist
				else {
					//store the new set returned from the parseOperation function
					//in the array
					cout << "Assign a name (one character) to the set resulting from the operation: ";
					cin >> newSetName;
					pSet[index] = new Set;
					*pSet[index] = parseOperation(pSet, op1, op2, setPosition1, operation, setPosition2, numSets);
					(*pSet[index]).setSetName(newSetName);

					//use setOperation method to store information to be
					//displayed with sets created by set operations
					(*pSet[index]).setOperation(op1, operation, op2, true);

					//increment numSets
					cout << *pSet[index];
					numSets++;
					index++;
				}
				break;
			case 6:
				//display all existing sets
				for (int i = 0; i < numSets; i++) 
					cout << *pSet[i];
				cout << endl;
				break;
		}
	
	} while (menuOption != SENTINAL);	

	cout << "Created Sets:" << endl;

	for (int i = 0; i < numSets; i++) { 
		cout << *pSet[i];
	}

}

int setNametoNumber(Set *pSet[ ], char setName, int numSets) {

	int position = -999;	

	for (int i = 0; i < numSets; i++) {
		if ((*pSet[i]).getSetName( ) == setName) {
			position = i;
			break;
		}
	}
	
	return(position);
}

Set parseOperation (Set *pSet[ ], char op1, char op2, int&setPosition1, char&operation, int&setPosition2, int numSets) {

	Set newSet;	
	//local variable to use in setOperation method
	bool setOperationProduct = true;

	//function prototype
	int setNametoNumber(Set *[ ], char, int);

	//use the setNametoNumber function to find the 
	//position in the array of the set name
	setPosition1 = setNametoNumber(pSet, op1, numSets);
	setPosition2 = setNametoNumber(pSet, op2, numSets);
	
	switch(operation) {
		case '+':
			newSet = *pSet[setPosition1] + *pSet[setPosition2];							break;
		case '^':
			newSet = *pSet[setPosition1] ^ *pSet[setPosition2];
			break;
		case '-':
			newSet = *pSet[setPosition1] - *pSet[setPosition2];
			break;
		default:
			cout << "Unrecognized operator." << endl;
	}

	return(newSet);
}
