/*
 *  secretWord.h
 *
 *  secretWord class definition
 *
 *  Created by Noah Greer on 11/28/09.
 *	
 *
 */

#ifndef SECRETWORD_H

#define SECRETWORD_H

#include <iostream>
#include <string>
using namespace std;

class secretWord {

private:
			// The word that the player needs to guess
	string	gameWord,

			// Letters that have been guessed
			guessedLetters,
	
			// The letters that have been guessed correctly,
			// and * in place of letters than have not been guessed yet
			correctLetters;

			// The letter that was guessed most recently.
	char	lastGuess;
	
public:
	
	// Default Constructor
	secretWord();
	
	// Constructor that initializes gameWord imediately
	secretWord(string inputString);
	
	// Method to set the gameWord
	void setWord(string inputString);

	// Method to get the gameWord
	string getWord();
	
	// Method to get the string of *'s and correctly guessed letters
	string getCorrectLetters();
	
	// Method to check if the gameWord has been guessed
	bool gameWordHasBeenGuessed();
	
	// Method for guessing a letter in the secret word
	void guess(char guessedLetter);
	
	// Method for checking to see if the last guess was correct
	bool lastGuessWasCorrect();
};

#endif SECRETWORD_H