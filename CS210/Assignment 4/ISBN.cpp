/*
 *  ISBN.cpp
 *  
 *
 *  Created by Noah Greer on 11/15/09.
 *	Class: CS 210
 *	Instructor: Craig Niiyama
 *	
 *	Either takes a file to be checked for valid ISBNs
 *	or checks the user's input to see if it is a valid ISBN
 *	
 *
 *	Pre-Condition:
 *	The user selects which mode they want to verify ISBNs in,
 *	and either the user enters a single ISBN to be verified,
 *	or ISBNs are read from the file isbntest.txt in the same directory
 *
 *	Post-Condition:
 *	ISBNs are verified individually and printed, and if any errors were found,
 *	the first error that is found is printed next to the ISBN,
 *	if no error was found with an ISBN "is a valid ISBN" is printed next to it.
 *	
 */

#include <iostream>	// Include standard library
#include <fstream>	// Include file stream library to work with a file
#include <cctype>	// Include cctype library to check for digits in the input
#include <string>	// Include string library to work with strings
using namespace std;	// Use the standard namespace

#define inFile "isbntest.txt"

void displayMenu();	// Display the menu to the user

// verifies that the inputString contains a valid ISBN
void verifyISBN(string& inputString);

int main()
{
			// A string to store input in
	string inputString;
			// The argument of the mode switch statement.
	char	modeSelector;
			// Flag that is set to true when the user wants to quit
	bool	quit = false,
			// Flag that is set to true when the user wants to go back on the menu
			goBack = false;
			// Input file stream to be read a line at a time into inputString and checked by verifyISBN
	ifstream ins;
	
	do {
	
		// Display the instructions to the user
		displayMenu();
		
		// Read the user's input into modeSelector to determine what mode they want to use
		cin >> modeSelector;
		
		/*
		Switch statement determines which mode to verify ISBNs in
		based on what the user entered for modeSelector.
		If a Q or q was entered, quit.
		If a 1 was entered read the user's input and verify it.
		If a 2 was entered read the file isbntest.txt and verify each line.
		 */
		switch (modeSelector) {
			case 'Q': case 'q':	// If a Q or q was read in the first position, then quit.
				quit = true;
				break;
			case '1':
				do {
					cout << "Please enter an ISBN or a B to go back: ";	// Insructions to user.
					cin >> inputString;	// Read the user's input
					// If a B or b was entered, then set goBack to true so that this loop will end,
					// and the main loop will begin again.
					if ( inputString.at(0) == 'B' || inputString.at(0) == 'b' ) {
						goBack = true;
					}
					// Otherwise, if a Q or a q was entered as the first character,
					// then set quit to true and end this loop, and since quit is set to true,
					// the main loop will end too, so the program will exit.
					else if ( inputString.at(0) == 'Q' || inputString.at(0) == 'q' ) {
						quit = true;
						break;
					}
					// Otherwise, run the verifyISBN() function.
					else {
						cout << endl;
						verifyISBN(inputString);
						cout << endl;
					}
				} while ( !goBack ); // Do all of the above steps while the goBack flag has not been set.
				break;
			case '2':
				ins.open(inFile); // Open the file and assign it to ins.
				// If the file could not be opened, report the error and end this loop.
				if (ins.fail()) {
					cout << "ERROR: Could not read isbntest.txt" << endl;
					break;
				}
				else {
					cout << endl;
					do {
						ins >> inputString;
						verifyISBN(inputString);
					} while ( !ins.eof() );
					cout << endl;
				}
				break;
		}
	
	} while ( !quit );
		
	return 0;

}

/*
 * Pre-Condition:
 * Call the function
 *
 * Post-Condition:
 * The menu is displayed
 *
 */
void displayMenu()
{
	cout << "***************************************" << endl;
	cout << "*        ISBN # verifier menu         *" << endl;
	cout << "*                                     *" << endl;
	cout << "*          Do you want to:            *" << endl;
	cout << "*  1. Verify ISBNs from input         *" << endl;
	cout << "*  2. Verify ISBNs from isbntest.txt  *" << endl;
	cout << "*  Q. Quit                            *" << endl;
	cout << "*                                     *" << endl;
	cout << "***************************************" << endl;
	cout << "Select your mode: ";
}

/*
 * Pre-Condition:
 * A string with a single ISBN to be verified.
 *
 * Post-Condition:
 * The ISBN is verified and the result of the verification is printed next to the ISBN.
 *
 */
void verifyISBN(string& inputString)
{
	string stringISBNdigits;	// A string to put just the digits from inputString into.
	bool error = false;			// A flag that is set once an error is found.
	int	dashesCount,			// A counter to keep track of the number of dashes.
		digitsCount,			// A counter to keep track of the number of digits.
		sum = 0,				// The checksum.
		// An array to put the digits from stringISBNdigits into, so they can be worked with mathematically.
		arrayISBNdigits[10];
	
	// If the first character in inputString is a -
	if ( inputString.at(0) == '-'  && !error ) {
		// Report the the error next to the ISBN, and set the error flag. 
		cout << inputString << " has a - for the first character." << endl;
		error = true;
	}
	// Otherwise, if the second to last character in inputString is a -
	else if ( inputString.at(inputString.length() - 1) == '-'  && !error ) {
		// Report the the error next to the ISBN, and set the error flag.
		cout << inputString << " has a - for the last character." << endl;
		error = true;
	}
	
	// Repeat the following steps until the second to last character in inputString has been reached
	// (Second to last, because it is the last printable character.)
	for ( int i = 0; i < inputString.length() && !error; i++) {
		// If the character at the current position i, is not a - and it is a digit.
		if ( (inputString.at(i) != '-') && isdigit(inputString.at(i)) ) {
			// Then append the character to stringISBNdigits
			stringISBNdigits.append(inputString, i, 1);
		}
		// Otherwise, if the character at the current position is a - and the character at the next position is a -
		else if (inputString.at(i) == '-'
			  && inputString.at( i + 1 ) == '-') {
			// Then report the error next to the ISBN and set the error flag.
			cout << inputString << " has consecutive dashes." << endl;
			error = true;
		}
		// Otherwise, if the character a the current position is a -
		else if (inputString.at(i) == '-') {
			// Then increment the dash counter.
			dashesCount++;
		}
		// Otherwise, if the current character is second to last in inputString, and it is an X or an x
		else if ( ( i == (inputString.length() - 1) )
				&& ( inputString.at(i) == 'X'
				||   inputString.at(i) == 'x' ) ) {
			// Then append it to stringISBNdigits.
			stringISBNdigits.append(inputString, i, 1);
		}
		// Otherwise, if the character at the current position is
		// not a digit, a -, an X, or an x, then the current character is invalid.
		else if ( !(isdigit(inputString.at(i))
				|| inputString.at(i) == '-'
				|| inputString.at(i) == 'X'
				|| inputString.at(i) == 'x') ) {
			// Report the the error next to the ISBN, and set the error flag.
			cout << inputString << " has an invalid character at position " << i + 1 << endl;
			error = true;
		}
	
	}
	
	// If there are more than three dashes
	if (dashesCount != 0 && dashesCount < 3 && !error) {
		// Report the the error next to the ISBN, and set the error flag.
		cout << inputString << " does not have enough dashes." << endl;
		error = true;
	}
	// Otherwise, if there are more than three dashes
	else if (dashesCount > 3 && !error) {
		// Report the the error next to the ISBN, and set the error flag.
		cout << inputString << " has too many dashes." << endl;
		error = true;
	}

	// If the length of stringISBNdigits is 10 and there is no error
	if ( stringISBNdigits.length() == 10 && !error ) {
	
		// Then for each character in stringISBNdigits see
		for (int i = 0; i < 10; i++) {
			// If it is a digit
			if ( isdigit( stringISBNdigits.at(i) ) ) {
				// Then subtract 48 (ASCII base number) from the integer value
				// of the digit character to get its actual value,
				// and put it in the equivalent position in arrayISBNdigits[]
				arrayISBNdigits[i] = int(stringISBNdigits[i]) - 48;
			}
			// Otherwise, if the character at the current position is an X or an x,
			// then put a 10 in the equivalent position in arrayISBNdigits
			// (There is a check performed before this test to ensure that
			// an X or an x are never in any position other than the 10th)
			else if ( stringISBNdigits.at(i) == 'X' || stringISBNdigits.at(i) == 'x' ) {
				arrayISBNdigits[i] = 10;
			}
		}
		
		// Add up the products of the values and their positions
		// of all but the last value in arrayISBNdigits
		// and put the total in sum
		for (int i = 0; i < 9; i++) {
			sum += (arrayISBNdigits[i] * (i+1));
		}
		// If the remainder of the checksum and 11
		// is equal to the last value in arrayISBNdigits
		if ( (sum % 11) == arrayISBNdigits[9] ) {
			// Then report the correct checksum next to the ISBN.
			cout << inputString << " is a valid ISBN." << endl;
		}
		// Otherwise, if the remainder of the checksum and 11
		// is not equal to the last value in arrayISBNdigits
		else if ( (sum % 11) != arrayISBNdigits[9] ) {
			// Then report the bad checksum next to the ISBN, and set the error flag.
			cout << inputString << " has a bad checksum." << endl;
			error = true;
		}
	
	}
	// Otherwise, if the length of stringISBNdigits is greater than 10
	else if ( stringISBNdigits.length() > 10 && !error) {
		// Then report that there are too many digits and set the error flag.
		cout << inputString << " has too many digits." << endl;
		error = true;
	}
	// Otherwise, if the length of stringISBNdigits is smaller than 10
	else if (stringISBNdigits.length() < 10 && !error) {
		// Then report that there are not enough digits and set the error flag.
		cout << inputString << " has too few digits." << endl;
		error = true;
	}
	
}