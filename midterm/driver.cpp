/*
 * Midterm Driver
 *
 * driver.cpp
 *
 * Brooke Cantwell
 *
 * 9 March 2016
 *
 * Driver to test the Savings Account class.
 *
 */

#include <iostream>
#include "savingsAccount.h"
#include <iomanip>

using namespace std;

main( ) {

	//declare local variables
	int MAX_ACCOUNTS = 3;
	int numAccounts = 0;

	void display(SavingsAccount *[ ], const int);

	//call SavingsAccount static functions to input static data members
	SavingsAccount::inputActiveOfficer( );
	SavingsAccount::inputCurrentDate( );
	SavingsAccount::inputInterestRate( );
	cout << endl;

	//array of SavingsAccount pointers
	SavingsAccount *ptrS[MAX_ACCOUNTS];

	//enter account information
	for (int i = 0; i < MAX_ACCOUNTS; i++) {
		ptrS[i] = new SavingsAccount;
		(*ptrS[i]).inputCustomerName( );
		(*ptrS[i]).inputStartingBalance( );
		cout << endl;
		numAccounts++;
	}		

	display(ptrS, MAX_ACCOUNTS);
}

//function to calculate interest, update the savings balance, and display the information
//for all of the account entered
void display(SavingsAccount *ptrS[ ], const int MAX_ACCOUNTS) {
	cout << "Account Officer\t\tDate Opened\tCustomer\t\tCurrent Balance" << endl;

	for (int i = 0; i < MAX_ACCOUNTS; i++) {
		ptrS[i] -> calculateInterest( );
		ptrS[i] -> updateSavingsBalance( );
		ptrS[i] -> display( );
		delete ptrS[i];
		ptrS[i] = NULL;
		cout << endl;
	}
}
