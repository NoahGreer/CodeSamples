/*
 *  secretWord.cpp
 *  
 *
 *  Created by Noah Greer on 11/28/09.
 *
 *
 */

#include "secretWord.h"
#include <iostream>
#include <string>
using namespace std;

// Default constructor
secretWord::secretWord()
{
	
}

// Constructor that imediately takes a string,
// makes it lowercase as it's storing it,
// and fills another string with as many *'s as there were letters
secretWord::secretWord(string inputString)
{
	for(int i = 0; i < inputString.length(); i++){
		gameWord.append( 1, char(tolower(inputString.at(i))) );
	}
	correctLetters.insert( 0, gameWord.length(), '*' );
}

// Modifier that takes a string, makes it lowercase as it's storing it,
// and fills another string with as many *'s as there were letters
void secretWord::setWord(string inputString)
{
	for(int i = 0; i < inputString.length(); i++){
		gameWord.append( 1, char(tolower(inputString.at(i))) );
	}
	correctLetters.insert( 0, gameWord.length(), '*' );
}

string secretWord::getWord()
{
	return gameWord;
}

string secretWord::getCorrectLetters()
{
	return correctLetters;
}

bool secretWord::gameWordHasBeenGuessed()
{
	return (correctLetters == gameWord);
}

void secretWord::guess(char guessedLetter)
{
	lastGuess = guessedLetter;
	
	if ( guessedLetters.find(tolower(guessedLetter)) != -1 ) {
		cout << "You already guessed '" << guessedLetter << "'" << endl << "please enter a different letter: ";
		cin >> guessedLetter;
		secretWord::guess(guessedLetter);
	}
	else if ( guessedLetters.find(tolower(guessedLetter)) == -1 ) {
		guessedLetters.append( 1, tolower(guessedLetter) );
	}
}

bool secretWord::lastGuessWasCorrect()
{

	bool isCorrect = false;

	for (int i = 0; i < gameWord.length(); i++) {
			
		if ( gameWord.at(i) == char(tolower(lastGuess) ) ) {
			correctLetters.replace( i, 1, 1, char(tolower(lastGuess)) );
			guessedLetters.append( 1, tolower(lastGuess) );
			isCorrect = true;
		}
	}

	return isCorrect;
	
}