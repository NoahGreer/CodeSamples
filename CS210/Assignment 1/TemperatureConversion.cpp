/*
 *  TemperatureConversion.cpp
 *
 *	Created by Noah Greer on 9/30/09.
 *	Class: CS210
 *	Instructor: Craig Niiyama
 *
 *	Asks user for a temperature in Fahrenheit converts that number into Celsius and displays the value.
 *
 */

#include <iostream>
using namespace std;

float fahrToCelsius(int Fahrenheit);	// Prototype for fahrToCelsius which will take the number that the user gives as the temperature in Fahrenheit 

int main()
{
	
	int Fahrenheit;	// input - the temperature in Fahrenheit
	
	cout << "Please enter the temperature in Fahrenheit: ";	// Prompts user for temperature in Fahrenheit to be converted
	cin >> Fahrenheit;	// captures user input
	cout << "The temperature in Celsius is: " << fahrToCelsius(Fahrenheit) << endl;

}

float fahrToCelsius(int Fahrenheit)
{	
	
	return (5.0/9.0) * (Fahrenheit - 32);
	
}