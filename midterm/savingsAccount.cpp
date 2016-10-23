/*
 * Savings Account Class Implementation
 *
 * savingsAccount.cpp
 *
 * Brooke Cantwell
 *
 * 9 March 2016
 *
 * Methods and implementation for the savings
 * account class.
 *
 */

#include "date.h"
#include "name.h"
#include "savingsAccount.h"
#include <iomanip>

using namespace std;

Name SavingsAccount::activeOfficer;
double SavingsAccount::annualInterestRate;
Date SavingsAccount::cDate;

//default constructor
SavingsAccount::SavingsAccount( ) {
	annualInterestRate = 0;
	accountNumber = 0;
	savingsBalance = 0;
	accountOfficer = activeOfficer;
	oDate = cDate;
}

//constructor to initialize customer, savingsBalance, and accountNumber
SavingsAccount::SavingsAccount(string f, char m, string l, double b, int a) {
	customer.setName(f, m, l);
	savingsBalance = b;
	accountNumber = a;
	accountOfficer = activeOfficer;
	oDate = cDate;
}

//mutator method inputActiveOfficer, accepts user input for activeOfficer
void SavingsAccount::inputActiveOfficer( ) {

	cout << "Current Active Officer, ";
	activeOfficer.inputName( );

}

//mutator method inputCurrentDate, accepts user input for current date
void SavingsAccount::inputCurrentDate( ) {	

	cout << "Current Date, ";
	cDate.inputDate( );

}

//mutator method inputInterestRate, accepts user input for static data member
//annualInterestRate
void SavingsAccount::inputInterestRate( ) {
	double i;

	cout << "Current Annual Interest Rate: ";
	cin >> annualInterestRate;
}

//mutator method, input customer name
void SavingsAccount::inputCustomerName( ) {
	cout << "Customer Name, ";
	customer.inputName( );
}

//mutator method, input starting balance
void SavingsAccount::inputStartingBalance( ) {
	cout << "Enter Starting Balance: ";
	cin >> savingsBalance;
}

//calculateInterest, calculates and returns monthly interest
double SavingsAccount::calculateInterest( ) {
	double interest;

	interest = savingsBalance * (annualInterestRate/12.0);

	return(interest);
}

//modifyInterestRate, modifies the static data member interest rate
void SavingsAccount::modifyInterestRate(double i) {
	annualInterestRate = i;
	annualInterestRate /= 100;
}

//updateSavingsBalance, calculates the monthly interest rate by invoking
//calculateInterest and updates the savings balance data member with
//the interest results
void SavingsAccount::updateSavingsBalance( ) {
	double interest;

	interest = calculateInterest( );

	savingsBalance += interest;
}

//accessor methods

double SavingsAccount::getInterestRate( ) {
	return(annualInterestRate);
}

//display method

void SavingsAccount::display( ) {
	accountOfficer.display( );
	cout << '\t';
	oDate.display( );
	cout << '\t';
	customer.display( );
	cout << '\t';
	cout << std::fixed << setprecision(2) << '$' << savingsBalance;
}
