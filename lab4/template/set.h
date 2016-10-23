/*
 * Set Class Template Definition
 *
 * set.h
 *
 * Brooke Cantwell
 *
 * 17 April 2016
 *
 * Template for the Set class
 */

#ifndef SET_H
#define SET_H

#include <iostream>

using namespace std;

template <typename T>
class Set {
	//global functions
	friend istream& operator>>(istream&in, Set<T>&s) {
		int newSize;

		if (s.set == NULL) {
			cout << "Empty set, enter new size: ";
			cin >> newSize;

			if (newSize > 0) {
				s.set = new T[newSize];
				s.pSize = newSize;
			}
		}

		if (s.set != NULL) {
			cout << "Enter an integer for the maximum number of elements in your set. You can stop at any time, or add or delete new elements through the menu." << endl;
			cout << "Maximum number of elements: ";
			cin >> newSize;
			//if there is not enough room
			if (newSize >= s.pSize) {
				delete [ ]s.set;
				s.set = NULL;
				s.set = new T[newSize];		
			}
			s.pSize = newSize;
			cout << "Enter elements to populate the set or " << delim << " to stop:" << endl;
			for (int i = 0; i < s.pSize; i++) {
				in >> s[i];
				if (s[i] == delim)
					break;
				else
					s.fSize++;
			}
		}

		return(in);
	}

	friend ostream& operator<<(ostream&out, const Set<T>&s) {
		out << s.name << " = ";
		out << "{ ";

		for (int i = 0; i < s.fSize; i++) {
			out << s[i] << " ";
		}

		if (s.operationProduct == true)
			out << '}';
		else
			out << '}' << endl;

		//if the set is a product of an operation
		if (s.operationProduct == true)
			out << "\tSet created by operation: " << s.op1 << ' ' << s.operation << ' ' << s.op2 << endl;
		
		return(out);
	}

	//public interface
	public:
		//constructors and destructors
		Set( ) {
			set = new T[DEFAULT_SIZE];
			pSize = DEFAULT_SIZE;
			fSize = 0;
			numElements = 0;
			name = ' ';
			operationProduct = false;
		}


		Set(int s) {
			set = new T[s];
			pSize = s;
			fSize = 0;
			numElements = 0;
			operationProduct = false;
		}

		Set(T sa[ ], int s, char n) {
			set = sa;
			pSize = s;
			fSize = s;
			name = n;
			operationProduct = false;
		}

		Set(const Set<T>&s) {
			fSize = s.fSize;
			pSize = s.pSize;
			name = s.name;
			operationProduct = s.operationProduct;

			//allocate memory of size pSize
			set = new T[pSize];

			//copy all elements of s.set to set
			for (int i = 0; i < fSize; i++) {
				set[i] = s[i];
			}
		}

		//destructor
		~Set( ) {
			if (set != NULL) {
				delete [ ]set;
				set = NULL;
			}
		}


		//element, searches for element
		bool element(T element) const {
			bool inSet = false;

			for (int i = 0; i < pSize; i++) {
				if (set[i] == element) {
					inSet = true;
					break;
				}
			}
	
			return(inSet);
		}


		//operator overload methods

		const Set<T>& operator= (const Set<T>&right) {
			if (&right != this) {
				if (pSize < right.fSize) {
					delete [ ]set;
					set = NULL;
					set = new T[right.fSize];
					//check that set is not null
					if (set == NULL)
						fSize = -999;
					else
						pSize = right.fSize;
				}

				for (int i = 0; i < right.fSize; i++) {
					set[i] = right[i];
					fSize++;
				}
			}
			//assign the name for use in the template function in the driver
			name = right.name;
		
			return(*this);
		}


		//operator overload method for equality
		bool operator== (const Set<T>&s) const {
			bool isEqual = true;

			if (fSize == s.fSize) {
				for (int i = 0; i < fSize; i++) {
					//overloaded [ ] method
					if (set[i] != s[i]) {
						isEqual = false;
						break;
					}
				}
			}
		
			return(isEqual);
		}

		bool operator!=(const Set<T>&s) const {
			bool unEqual;

			if (*this == s)
				unEqual = false;
			else
				unEqual = true;

			return(unEqual);
		}

		//+ operator overload method that adds elements to the set
		void operator+(T e) {

			//if the element is not already in the set
			if (!element(e)) {
				//if there is no room for the new element
				if (fSize == pSize) {
					//create a temporary object equal to
					//contents of the this pointer
					Set<T> temp = *this;

					//delete the array the set is pointing to
					delete [ ]set;
					set = NULL;
					//allocate new memory and double pSize
					pSize *= 2;
					set = new T[pSize];

					//check if the set is still NULL
					if (set == NULL) {
						//if the set is still null set
						//fSize to the -999 for error
						fSize = -999;
						//quit
					}
					else {
						for (int i = 0; i < fSize; i++) {
							//reset array to temp
							set[i] = temp.set[i];
						}
					}
				}
				//increment fSize and set the last element in the
				//array to e
				set[fSize++] = e;
			}

		}


		// - operator overload method that deletes an element
		bool operator-(T e) {
			bool hasElement;
			int position;

			if (this->element(e)) {
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


		//+ operator overload method that unions two sets
		Set<T> operator+(const Set<T>&s) const {

			//create newSet with the copy constructor
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


		//operator overload method for set intersection
		Set<T> operator^(const Set<T>&s) const {
			bool inBoth = false;
			T add;

			//create an empty set to store elements of intersection in
			Set<T> newSet;

			for (int i = 0; i < pSize; i++) {
				add = set[i];
				//check if the element is in both sets
				if (element(add) && s.element(add))
					inBoth = true;
				else
					inBoth = false;

				if (inBoth == true) {
					newSet + add;
					if (newSet.fSize == -999)
						break;
				}
			}
		
			return(newSet);
		}


		//operator overload method for set difference
		Set<T> operator-(const Set<T>&s) const {
			Set<T> newSet;
			T deleteElement;
			bool difference;

			for (int i = 0; i < fSize; i++) {
				deleteElement = set[i];
				//if an element is in the first set and not in
				//the second set, add it to newSet
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

		//operator overload methods for [ ]
		T operator[ ](int i) const {
			
			if (i < 0 || i > pSize) {
				cout << "Index is out of range." << endl;
				//if it is return error
				set[i] = delim;
			}
			//return element with index i
			return(set[i]);
		}

		T& operator[ ](int i) {
			//check the index
			if (i < 0 || i > pSize) {
				cout << "Index is out of range." << endl;
				set[i] = delim;
			}
			
			return(set[i]);
		}

		//mutator method for set name
		void setSetName(char n) {
			name = n;
		}	

		void inputSetName( ) {
			cout << "Input set name (single character): ";
			cin >> name;
		}

		//accessor method for set name
		char getSetName( ) const {
			return(name);
		}

		//function to store information about user's set operations
		void setOperation(char o1, char op, char o2, bool product) {
			op1 = o1;
			operation = op;
			op2 = o2;
			operationProduct = product;
		}

		static void setDelim(T d) {
			delim = d;
		}
	private:
		T *set;
		int pSize;
		int fSize;
		int numElements;
		char name;
		static const int DEFAULT_SIZE = 5;
		bool operationProduct;
		char op1, operation, op2;
		static T delim;
};

template <class T> T Set<T>::delim;

#endif
