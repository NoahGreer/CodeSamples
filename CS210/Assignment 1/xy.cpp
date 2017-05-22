/*
 *  xy.cpp
 *  
 *	Created by Noah Greer on 9/30/09.
 *	Class: CS210
 *	Instructor: Craig Niiyama
 *	
 *	Collects two numbers and finds their sum, difference, product, and quotient. Then displays the results.
 *
 */

#include <iostream>		// include the standard library
using namespace std;	// use the standard namespace

int main()	// Begining of main function
{
	
	int		x, y,		// input - two variables
			sum,		// output - the sum of x and y
			difference,	// output - the difference of x and y
			product;	// output - the product of x and y
	float	quotient;	// output - the product of x and y
	
	/* Prompt user for two numbers and put them in x and y */
	cout << endl << "Enter a numeric value for x: ";
	cin >> x;
	cout << "Enter a numeric value for y: ";
	cin >> y;
	
	/* Perform sum, difference, product, and quotient opperations on x and y */
	sum = x + y;
	difference = x - y;
	product = x * y;
	quotient = (x * 1.0) / (y * 1.0);
	
	/* Display the results of the previous operations */
	cout << endl << "The sum of x and y is: " << sum << endl;	// display the sum of x and y
	cout << "The difference of x and y is: " << difference << endl;		// display and difference of x and y
	cout << "The product of x and y is: " << product << endl;		// display the product of x and y
	cout << "The quotient of x and y is: " << quotient << endl << endl;		// display the quotient of x and y
	
	return 0;
	
}