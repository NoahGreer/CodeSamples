/*
 *  1k1m.cpp
 *
 *	Created by Noah Greer on 9/30/09.
 *	Class: CS210
 *	Instructor: Craig Niiyama
 *
 *	Reads a number between 1000 and 1000000. Then, recalls the number with commas inserted every three digits.
 *
 */

#include <iostream>
using namespace std;

int main()
{
	
	const int	MAX_VALUE = 1000000,	// define the maximum of the range for input
				MIN_VALUE = 1000;		// define the minimum of the range for input
	
	int number = 0;	/* input - the number to be tested if its between 1000 and 1000000.
					 * Then, formatted and displayed with commas.
					 * Set to a starting value of 0 so the first while statement will be satisfied.
					 */
	int chunk1, chunk2; // output - two chunks of digits to have a comma placed between them
	
	// check that the input is a number between 1000 and 1000000
	while(number > MAX_VALUE || number < MIN_VALUE)
	{
		cout << "Enter a number between 1000 and 1000000: ";
		cin >> number;
		if(number > MAX_VALUE || number < MIN_VALUE)
		{
			cout << "Your number was not between 1000 and 1000000." << endl;
		}
	}
	
	// If the number is the maximum value, then just print it already formatted. No calculation required.
	if(number ==  MAX_VALUE)
	{
		cout << "Your number was: 1,000,000" << endl;
	}

	/* if the number is between the minimum and the maximum,
	 * then divide the number by 1000 to get the number of thousands, ten-thousands, and hundred-thousands and store it in chunk1
	 * then divide the number by 1000 and take the remainder to get the ones, tens, and hundreds places and put it in chunk2
	 * use printf to print chunk1
	 * then print chunk2 at least three digits wide and with zeros as padding
	 * so that a number like 12099 doesn't get displayed as 12,99 or a number like 12,001 doesn't get displayed as 12,1
	 */
	if(number < MAX_VALUE && number >= MIN_VALUE)
	{
		chunk1 = number / 1000;
		chunk2 = number % 1000;
		printf("Your number was: %d,%03d\n", chunk1, chunk2);
	}
	
	return 0;

}