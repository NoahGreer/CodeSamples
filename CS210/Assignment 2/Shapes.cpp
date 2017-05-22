/*
 *  Shapes.cpp
 *  
 *	Created by Noah Greer on 10/8/09.
 *  Class: CS 210
 *	Instructor: Craig Niiyama
 *	
 *	Prints a circle, a triangle, a rectangle, 
 *	two blank lines, another triangle, another circle, and another rectangle.
 *	
 *	Pre-Condition:
 *	There is no precondition.
 *	
 *	Post-Condition:
 *	A circle, a triangle, a rectangle,
 *	two blank lines, a triangle, a circle, and a rectangle are displayed.
 *
 */

#include <iostream>
using namespace std;

void printCircle();
void printTriangle();
void printRectangle();

int main()
{
	
	// Draw circle.
	printCircle();
	
	// Draw triangle.
	printTriangle();
	
	// Draw rectangle.
	printRectangle();
	
	// Display 2 blank lines.
	cout << endl << endl;
	
	// Draw triangle.
	printTriangle();
	
	// Draw circle.
	printCircle();
	
	// Draw rectangle.
	printRectangle();
	
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