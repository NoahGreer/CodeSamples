/*
 *  Euclid.cpp
 *  
 *	Created by Noah Greer on 10/14/09.
 *	Class: CS 210
 *	Instructor: Craig Niiyama
 *
 *	Finds the greatest common factor of two integers.
 *
 *	Pre-Condition:
 *	Input two numbers.
 *
 *	Post-Condition:
 *	Displays greatest common factor.
 *
 */


#include <iostream>
using namespace std;

int euclid(int m, int n);

int main()
{
	
	int m, n;
	
	cout << "Enter an integer: ";
	cin >> m;
	cout << "Enter another integer: ";
	cin >> n;
	cout << "The greatest common factor is: " << euclid(m, n) << endl;

}

int euclid(int m, int n)
{
	
	if(m < n)
		return euclid(n, m);
	else if( m % n == 0)
		return n;
	else
		return euclid(n, (m % n));
	
}