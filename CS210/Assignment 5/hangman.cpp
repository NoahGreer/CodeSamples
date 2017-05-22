/*
 *  hangman.cpp
 *  
 *
 *  Created by Noah Greer on 11/28/09.
 *
 *
 */

#include "hangman.h"
#include <iostream>

// The maximum number of parts allowed on the hangman
int MAX_PARTS = 6;

// Default constructor
hangman::hangman()
{
	int partsCount = 0;
}

// Add one to partsCounter only if the maximum has not already been reached
void hangman::addPart()
{
	if (partsCount != MAX_PARTS)
		partsCount++;
	else
		cout << "Error: maximum number of parts has already been reached." << endl;
}

// Get the value of partsCount
int hangman::getParts()
{
	return partsCount;
}

// Reset the number of parts on the hangman
void hangman::reset()
{
	partsCount = 0;
}

// Display the hangman in it's current state
void hangman::display()
{

	if (partsCount == 6) {
		cout << "  _____________________                    " << endl;
		cout << "  |                   |                    " << endl;
		cout << "  |                   |                    " << endl;
		cout << "  |                 *****                  " << endl;
		cout << "  |                *     *                 " << endl;
		cout << "  |                *     *                 " << endl;
		cout << "  |                 *****                  " << endl;
		cout << "  |                   |                    " << endl;
		cout << "  |                   |                    " << endl;
		cout << "  |                  /|\\                   " << endl;
		cout << "  |                 / | \\                  " << endl;
		cout << "  |                /  |  \\                 " << endl;
		cout << "  |               /   |   \\                " << endl;
		cout << "  |                  / \\                   " << endl;
		cout << "  |                 /   \\                  " << endl;
		cout << "  |                /     \\                 " << endl;
		cout << "  |               /       \\                " << endl;
		cout << "  |                                        " << endl;
		cout << "  |___________________________________     " << endl;
	}
	else if (partsCount == 5) {
		cout << "  _____________________                    " << endl;
		cout << "  |                   |                    " << endl;
		cout << "  |                   |                    " << endl;
		cout << "  |                 *****                  " << endl;
		cout << "  |                *     *                 " << endl;
		cout << "  |                *     *                 " << endl;
		cout << "  |                 *****                  " << endl;
		cout << "  |                   |                    " << endl;
		cout << "  |                   |                    " << endl;
		cout << "  |                  /|\\                   " << endl;
		cout << "  |                 / | \\                  " << endl;
		cout << "  |                /  |  \\                 " << endl;
		cout << "  |               /   |   \\                " << endl;
		cout << "  |                  /                     " << endl;
		cout << "  |                 /                      " << endl;
		cout << "  |                /                       " << endl;
		cout << "  |               /                        " << endl;
		cout << "  |                                        " << endl;
		cout << "  |___________________________________     " << endl;
	}
	else if (partsCount == 4) {
		cout << "  _____________________                    " << endl;
		cout << "  |                   |                    " << endl;
		cout << "  |                   |                    " << endl;
		cout << "  |                 *****                  " << endl;
		cout << "  |                *     *                 " << endl;
		cout << "  |                *     *                 " << endl;
		cout << "  |                 *****                  " << endl;
		cout << "  |                   |                    " << endl;
		cout << "  |                   |                    " << endl;
		cout << "  |                  /|\\                   " << endl;
		cout << "  |                 / | \\                  " << endl;
		cout << "  |                /  |  \\                 " << endl;
		cout << "  |               /   |   \\                " << endl;
		cout << "  |                                        " << endl;
		cout << "  |                                        " << endl;
		cout << "  |                                        " << endl;
		cout << "  |                                        " << endl;
		cout << "  |                                        " << endl;
		cout << "  |___________________________________     " << endl;
	}
	else if (partsCount == 3) {
		cout << "  _____________________                    " << endl;
		cout << "  |                   |                    " << endl;
		cout << "  |                   |                    " << endl;
		cout << "  |                 *****                  " << endl;
		cout << "  |                *     *                 " << endl;
		cout << "  |                *     *                 " << endl;
		cout << "  |                 *****                  " << endl;
		cout << "  |                   |                    " << endl;
		cout << "  |                   |                    " << endl;
		cout << "  |                  /|                    " << endl;
		cout << "  |                 / |                    " << endl;
		cout << "  |                /  |                    " << endl;
		cout << "  |               /   |                    " << endl;
		cout << "  |                                        " << endl;
		cout << "  |                                        " << endl;
		cout << "  |                                        " << endl;
		cout << "  |                                        " << endl;
		cout << "  |                                        " << endl;
		cout << "  |___________________________________     " << endl;
	}
	else if (partsCount == 2) {
		cout << "  _____________________                    " << endl;
		cout << "  |                   |                    " << endl;
		cout << "  |                   |                    " << endl;
		cout << "  |                 *****                  " << endl;
		cout << "  |                *     *                 " << endl;
		cout << "  |                *     *                 " << endl;
		cout << "  |                 *****                  " << endl;
		cout << "  |                   |                    " << endl;
		cout << "  |                   |                    " << endl;
		cout << "  |                   |                    " << endl;
		cout << "  |                   |                    " << endl;
		cout << "  |                   |                    " << endl;
		cout << "  |                   |                    " << endl;
		cout << "  |                                        " << endl;
		cout << "  |                                        " << endl;
		cout << "  |                                        " << endl;
		cout << "  |                                        " << endl;
		cout << "  |                                        " << endl;
		cout << "  |___________________________________     " << endl;
	}
	else if (partsCount == 1) {
		cout << "  _____________________                    " << endl;
		cout << "  |                   |                    " << endl;
		cout << "  |                   |                    " << endl;
		cout << "  |                 *****                  " << endl;
		cout << "  |                *     *                 " << endl;
		cout << "  |                *     *                 " << endl;
		cout << "  |                 *****                  " << endl;
		cout << "  |                                        " << endl;
		cout << "  |                                        " << endl;
		cout << "  |                                        " << endl;
		cout << "  |                                        " << endl;
		cout << "  |                                        " << endl;
		cout << "  |                                        " << endl;
		cout << "  |                                        " << endl;
		cout << "  |                                        " << endl;
		cout << "  |                                        " << endl;
		cout << "  |                                        " << endl;
		cout << "  |                                        " << endl;
		cout << "  |___________________________________     " << endl;
	}
	else if (partsCount == 0) {
		cout << "  _____________________                    " << endl;
		cout << "  |                   |                    " << endl;
		cout << "  |                   |                    " << endl;
		cout << "  |                                        " << endl;
		cout << "  |                                        " << endl;
		cout << "  |                                        " << endl;
		cout << "  |                                        " << endl;
		cout << "  |                                        " << endl;
		cout << "  |                                        " << endl;
		cout << "  |                                        " << endl;
		cout << "  |                                        " << endl;
		cout << "  |                                        " << endl;
		cout << "  |                                        " << endl;
		cout << "  |                                        " << endl;
		cout << "  |                                        " << endl;
		cout << "  |                                        " << endl;
		cout << "  |                                        " << endl;
		cout << "  |                                        " << endl;
		cout << "  |___________________________________     " << endl;
	}
}