/*
 *  Shapes.cpp
 *  
 *	Created by Noah Greer on 10/12/09.
 *  Class: CS 210
 *	Instructor: Craig Niiyama
 *	
 *	Prints a circle, or a triangle, or a rectangle, depending on if the user enters a C/c or T/t or R/r.
 *
 *	Pre-Condition:
 *	Takes in a C or c, a T or t, a R or r.
 *
 *	Post-Condition:
 *	If a C or c was entered, a circle is printed.
 *	If a T or t was entered, a triangle is printed.
 *	If a R or r was entered, a rectangle is printed.
 *
 */

#include <iostream>
using namespace std;

void printCircle();
void printTriangle();
void printRectangle();

int main()
{
	
	bool gotCorrectInput = false;
	char selector;
	
	do
	{
		cout << "Enter a letter to choose which shape to draw:" << endl;
		cout << "enter a C to draw a circle." << endl;
		cout << "or a T to draw a triangle." << endl;
		cout << "or an R to draw a rectangle. " << endl;
		cin >> selector;
		
		switch (selector)
		{
			case 'C': case 'c':
				printCircle();
				gotCorrectInput = true;
				break;
			case 'R': case 'r':
				printRectangle();
				gotCorrectInput = true;
				break;
			case 'T': case 't':
				printTriangle();
				gotCorrectInput = true;
				break;
		}
	}while(!gotCorrectInput);
	
	return 0;

}

void printCircle()	// Draws a circle.
{

	cout << "   *********   " << endl;
	cout << " *           * " << endl;
	cout << "*             *" << endl;
	cout << "*             *" << endl;
	cout << "*             *" << endl;
	cout << " *           * " << endl;
	cout << "   *********   " << endl;

}

void printTriangle()	// Draws a triangle.
{

	cout << "       /\\       " << endl;
	cout << "      /  \\      " << endl;
	cout << "     /    \\     " << endl;
	cout << "    /      \\    " << endl;
	cout << "   /        \\   " << endl;
	cout << "  /          \\  " << endl;
	cout << " /____________\\ " << endl;

}

void printRectangle()	// Draws a rectangle.
{

	cout << " ************* " << endl;
	cout << " *           * " << endl;
	cout << " *           * " << endl;
	cout << " *           * " << endl;
	cout << " *           * " << endl;
	cout << " *           * " << endl;
	cout << " ************* " << endl;

}