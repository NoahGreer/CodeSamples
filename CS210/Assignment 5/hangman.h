/*
 *  hangman.h
 *	
 *	hangman class header
 *
 *  Created by Noah Greer on 11/28/09.
 *	
 *
 */

#ifndef HANGMAN_H

#define HANGMAN_H

#include <iostream>
using namespace std;

class hangman {

private:
	
	// The number of parts on the hangman
	int partsCount;
	
public:
	
	// Default Constructor
	hangman();
	
	// Method to display the hangman
	void display();
	
	// Adds the next bodypart to the hangman by adding to partsCount
	void addPart();
	
	// Finds out how many parts the hangman currently has on it
	int getParts();
	
	// Resets partsCount to 0
	void reset();
	
};

#endif // HANGMAN_H