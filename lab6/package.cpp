/*
 * Package Base Class Implementation
 *
 * package.cpp
 *
 * Brooke Cantwell
 *
 * 27 April 2016
 *
 * Methods and functions for the package
 * base class.
 */

#include <iostream>
#include "package.h"

using namespace std;

//constructors

Package::Package( ) {
	packageWeight = 0;
	costPerOunce = 0;
}

Package::Package(float w, float c) {
	packageWeight = w;
	costPerOunce = c;
}

//setPackageWeight, checks to make sure the weight isn't negative,
//and if the weight is valid, assign it to the data member
bool Package::setPackageWeight(float w) {
	bool valid = true;

	if (w > 0)
		packageWeight = w;
	else {
		valid = false;
		cout << "Invaid package weight." << endl;
	}

	return(valid);
}

//mutator methods for Customer data members
void Package::setSender(string f, string l, string a, string c, string s, int z){
	sender.setName(f, l);
	sender.setAddress(a, c, s, z);
}

void Package::setRecipient(string f, string l, string a, string c, string s, int z) {
	recipient.setName(f, l);
	recipient.setAddress(a, c, s, z);
}

void Package::inputSender( ) {
	cout << "Sender:" << endl;
	cin >> sender;
}

void Package::inputRecipient( ) {
	cout << "Recipient:" << endl;
	cin >> recipient;
}

//setCostPerOunce, checks to make sure the cost isn't negative,
//and if the cost is valid, assign it to the data members
bool Package::setCostPerOunce(float c) {
	bool valid = true;

	if (c > 0)
		costPerOunce = c;
	else {
		valid = false;
		cout << "Invalid cost per ounce." << endl;
	}

	return(valid);
}

void Package::inputCostPerOunce( ) {

	do {
		cout << "Enter cost per ounce: ";
		cin >> costPerOunce;
	} while (!setCostPerOunce(costPerOunce));
}

void Package::inputPackageWeight( ) {
	
	do {
		cout << "Enter package weight: ";
		cin >> packageWeight;
	} while (!setPackageWeight(packageWeight));
}

//accessor methods
float Package::getPackageWeight( ) const {
	return(packageWeight);
}

float Package::getCostPerOunce( ) const{
	return(costPerOunce);
}

//calculateCost, calculates the cost of shipping the package by
//multiplying the weight in ounces by the cost per ounce
float Package::calculateCost( ) const{
	float cost;

	cost = packageWeight * costPerOunce;

	return(cost);
}

//print method
void Package::print( ) const {
	cout << "Sender:" << endl;
	cout << sender << endl;
	cout << "Recipient:" << endl;
	cout << recipient << endl;
}
