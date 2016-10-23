/*
 * Savings Account Class Definition
 *
 * savingsAccount.h
 *
 * Brooke Cantwell
 *
 * 9 March 2016
 *
 * Class definition for the savings account class.
 *
 */

#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H

//check
#include "date.h"
#include "name.h"

class SavingsAccount {

	public:
		//constructors
		SavingsAccount( );
		SavingsAccount(string, char, string, double, int);
		//mutator methods for static data members
		static void inputActiveOfficer( );
		static void inputCurrentDate( );
		static void inputInterestRate( );
		//mutator methods continued
		void inputCustomerName( );
		void inputStartingBalance( );
		//calculate interest
		double calculateInterest( );		
		//mutator method for annualInterestRate
		static void modifyInterestRate(double);
		void updateSavingsBalance( );
		//accessor methods
		static double getInterestRate( );
		//display method
		void display( );
	private:
		Name accountOfficer;
		Date oDate;
		static double annualInterestRate;
		Name customer;
		int accountNumber;
		double savingsBalance;
		static Name activeOfficer;
		static Date cDate;
};

#endif
