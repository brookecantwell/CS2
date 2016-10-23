/*
 * Set Class Implementation
 *
 * set.cpp
 *
 * Brooke Cantwell
 *
 * 10 April 2016
 *
 * Methods and functions for the Set class.
 */

#include <iostream>
#include "set.h"

using namespace std;

//global functions
istream& operator>>(istream&in, Set&s) {

	int newSize;
	const int SENTINAL = -999;

	if (s.set == NULL) {
		cout << "You are trying to populate an empty set, enter new size here: ";
		cin >> newSize;
		
		if (newSize > 0) {
			s.set = new int[newSize];
			s.pSize = newSize;
		}
	}

	if (s.set != NULL) { //check to make sure s isn't null anymore
		cout << "Enter an integer for the maximum number of integers in your set. You can stop at any time, or add or delete new elements through the menu." << endl;
		cout << "Maximum number of elements: ";
		cin>> newSize;
		//if there is not enough room
		if (newSize >= s.pSize) {
			delete [ ]s.set;
			s.set = NULL;
			s.set = new int[newSize];
		}
		s.pSize = newSize;	
		cout << "Enter integers to populate the set or -999 to stop:" << endl;
		for (int i = 0; i < s.pSize; i++) {
			in >> s[i];
			if (s[i] == SENTINAL)
				break;
			else
				s.fSize++;
		}
	}	

	return(in);
}

ostream& operator<<(ostream&out, const Set&s) {
	out << s.name << " = ";

	out << "{ ";

	for (int i = 0; i < s.fSize; i++) {
		//overloaded [ ] operator
		out << s[i] << " ";
	}

	if (s.operationProduct == true)
		out << '}';
	else
		out << '}' << endl;

	//if the set is the product of an operation
	//done by the user through the menu
	if (s.operationProduct == true)
		cout << "\tSet created by operation: " << s.op1 << ' ' << s.operation << ' ' << s.op2 << endl;

	return(out);
}

//default constructor
Set::Set( ){
	set = new int[DEFAULT_SIZE];
	pSize = DEFAULT_SIZE;
	fSize = 0;
	numElements = 0;
	name = ' ';
	operationProduct = false;
}

Set::Set(int s) { 
	set = new int[s];
	pSize = s;
	fSize = 0;
	numElements = s;
	operationProduct = false;
}

Set::Set(int sa[ ], int s, char n) {
	set = sa;
	pSize = s;
	fSize = 0;
	name = n;
	operationProduct = false;
}

//copy constructor
Set::Set(const Set&s) {

	fSize = s.fSize;
	pSize = s.pSize;
	operationProduct = s.operationProduct;

	//allocate memory of size pSize
	set = new int[pSize];

	//copy all elemets of s.set to set
	for (int i = 0; i < fSize; i++) {
		//overloaded [ ] operator
		set[i] = s[i];
	}
}

//destructor
Set::~Set( ) {
	if (set != NULL) {
		delete [ ] set;
		set = NULL;
	}
}

//assignment operator
const Set& Set::operator= (const Set&right) {
	if (&right != this) {
		if (pSize < right.fSize) {
			delete [ ]set;
			set = NULL;
			set = new int[right.fSize];
			//check that set is not null
			if (set == NULL)
				fSize = -999;
			else	
				pSize = right.fSize;
		}

		for (int i = 0; i < right.fSize; i++) {
			//overloaded [ ] operator
			set[i] = right[i];
			fSize++;
		}
	}

	return(*this);
}

//equality operator
bool Set::operator==(const Set&s) const {
	bool isEqual = true;

	if (fSize == s.fSize) {
		for (int i = 0; i < fSize; i++) {
			//overloaded [ ] operator
			if (set[i] != s[i]) {
				isEqual = false;
				break;
			}
		}
	}

	return(isEqual);
}

//inequality operator
bool Set::operator!= (const Set&s) const {
	bool unEqual;

	if (*this == s)
		unEqual = false;
	else
		unEqual = true;

	return(unEqual);
}

//element - searches for an element in a set
bool Set::element(int e) const {
	bool inSet = false;

	for (int i = 0; i < pSize; i++) {
		if (set[i] == e) {
			inSet = true;
			break;
		}
	}

	return(inSet);
}


//add element (+ operator)
void Set::operator+(int e) {

	//if the element is not already in the set
	if ( !element( e ) ) {
		//if there is no room for the new element
		if ( fSize == pSize ) {
			//create a temporary object and set it equal to *this
			Set temp = *this;

			//delete the array set is pointing to
			delete [ ] set;

			set = NULL;
			//allocate new memory (twice the physical size)
			pSize *= 2;
			set = new int[pSize];

			if (set == NULL) {
				//if the set is still null, set f.Size to
				//to error code -999 and check in main 
				//program for errors
				(*this).fSize = -999;
				cout << "set = NULL" << endl;
				//quit the program
			}
			else {
				for (int i = 0; i < fSize; i++) {
					//reset array to contents of temp
					set[i] = temp.set[i];
				}
			}
		}
		//increase the fill size by 1
		//set the last element in the array to e
		set[fSize++] = e;
	}
}

//operator overload method to delete an element from a set
bool Set::operator-(int e) {
	bool hasElement;
	int position;

	if ( this->element(e)) {
		hasElement = true;

		for (int i = 0; i < fSize; i++) {
			if (set[i] == e)
			position = i;
		}		

		for (int j = position; j < fSize; j++)
			set[j] = set[j+1];

		fSize--;
	}
	else
		hasElement = false;

	return(hasElement);

}

//set union operator
Set Set::operator+ (const Set&s) const {

	//create newSet using the copy constructor
	Set newSet = *this;

	//add the elements from the second set into newSet
	for (int j = 0; j < s.fSize; j++) {
		newSet + s[j];
		//check for error
		if (newSet.fSize == -999)
			break;
	}

	return(newSet);
}		

//explanation of the intersection operator overload method
//the product of a Set intersection is the elements that are
//contained in both sets, so you use the boolean element
//function to determine if the set it in both *this and s
//I do it: ((element(add) && s.element(add)) to determine
//if add (aka s.set[i]) is in both sets, and if it is
//I do newSet + add (operator overload insert element method)
//so that all of the common elements are stored into newSet

//set intersection operator
Set Set::operator^ (const Set&s) const {
	bool inBoth = false;
	int add;	

	//create an empty set to store the elements in if they
	//appear in both sets
	Set newSet;

	for (int i = 0; i < pSize; i++) {
		add = set[i];
		//check if the element is in both sets
		if (element(add) && s.element(add))
			inBoth = true;
		else
			inBoth = false;

		//if the element is in both sets
		if (inBoth == true) {
			//operator overloaded +
			newSet + add;
			if (newSet.fSize == -999)
				break;
		}
		
	}

	return(newSet);
}

//set difference: overloaded method for the - operator
Set Set::operator- (const Set&s) const {
	Set newSet;
	int deleteElement;
	bool difference;

	for (int i = 0; i < fSize; i++) {
		deleteElement = set[i];
		//if an element is in the first set, and not in the second set
		//add the element to newSet;
		if (element(deleteElement) && !s.element(deleteElement))
			difference = true;
		else
			difference = false;
		
		if (difference) {
			newSet + deleteElement;
			if (newSet.fSize == -999)
				break;
		}
	}

	return(newSet);
}

//operator overload method for [ ] as the second operand (right side)
int Set::operator[ ](int i) const {
	int error = -999;

	//check to make sure the index is 0 or greater
	if (i < 0 || i > pSize) {
		cout << "Index is out of range." << endl;		
		//if it isn't, return error (sentinal value of -999)
		return(error);
	}
	else
		//if the index is ok, return the integer with the
		//provided index (i) 
		return(set[i]);
}


//operator overload method for [ ] as the first operand (left side)
int& Set::operator[ ](int i) {
	int error = -999;

	//check to make sure the index is 0 or greater
	if (i < 0 || i > pSize) {
		cout << "Index is our of range." << endl;
		//set set[i] to the error value
		set[i] = error;
	}

	//return integer of the set with the index i
	return(set[i]);
}


//mutator method for set name
void Set::setSetName(char n) {
	name = n;
}

//method to input set name from user input
void Set::inputSetName( ) {
	cout << "Input set name (single character): ";
	cin >> name;

}

//accessor method for set name
char Set::getSetName( ) const{
	return(name);
}

//function to store the set operation so it can be displayed
//with sets that were created through operations
void Set::setOperation(char o1, char op, char o2, bool product) {
	op1 = o1;
	operation = op;
	op2 = o2;
	operationProduct = product;
}	
