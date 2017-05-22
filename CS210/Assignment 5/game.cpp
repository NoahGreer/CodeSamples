/*
 *  game.cpp
 *  
 *
 *  Created by Noah Greer on 11/28/09.
 *	Class: CS 210
 *	Instructor: Craig Niiyama
 *	
 *	
 *	
 *
 *	Pre-Condition:
 *	The Player chooses which mode they want to use for gameplay.
 *	They enter letters until they have either run out of guesses,
 *	or they have guessed all of the letters.
 *
 *	Post-Condition:
 *	A menu is displayed telling the user how to interact with the game.
 *	A hangman figure is drawn and the part of the word that has been guessed is displayed
 *	with *'s for every letter that has not been guessed yet.
 *	
 */

#include <iostream>
#include <string>	// Needed to use strings
#include <cctype>	// Needed for isalpha()
#include <ctime>	// Needed for time()
// hangman class to update and display
// a picture of a hangman after each turn.
#include "hangman.h"
// secretWord class is for keeping track of the word the user must guess
// and creating a string of correct letters that is the same length
// but with just *'s for the letters that have not been guessed yet
// which will be all *'s since the user will not have guessed anything yet
// and it keeps track of what letters the user has guessed
// and when a correct letter is guessed
// update the correct letters string in the correct position
#include "secretWord.h"
using namespace std;


// Prototypes
void displayMenu();
void getMode(char& modeSelector);
char getGuess();
void onePlayer();
void twoPlayer();
void gameLogic(string chosenWord);
// End prototypes

// Words for the computer to pick from at random.
const string words[] = {	"integer",
							"boolean",
							"object",
							"header",
							"function",
							"class",
							"loop",
							"statement",
							"programming",
							"cast",
							"method"		};

int main()
{
	
	// A flag for the do while loop
	// that is set when the user chooses to quit.
	bool quit = false;
	// A place to put the user's mode selection for use in switch.
	char modeSelector;
	
	// Do the main game loop while the user hasn't chosen to quit.
	do {
		displayMenu();
		cout << "Select your mode: "; 
		cin >> modeSelector;
		cout << endl;
		switch (modeSelector) {
			case '1':
				onePlayer();
				break;
			case '2':
				twoPlayer();
				break;
			case 'Q': case 'q':
				quit = true;
				break;
			default:
				cout << "Invalid mode selection!" << endl;
				cout << endl;
				break;
		}
	} while (!quit);
	

}

/*	Displays the main menu for the game
 *	
 *
 *	Pre-Condition:
 *	The function is called
 *
 *	Post-Condition:
 *	A menu is displayed telling the user how to interact with the game.
 *	
 */
void displayMenu()
{
	cout << "*******************************************" << endl;
	cout << "*             C++ Hangman menu            *" << endl;
	cout << "*                                         *" << endl;
	cout << "*             Do you want to:             *" << endl;
	cout << "*  1. Play One-Player Hangman             *" << endl;
	cout << "*     (The computer chooses a             *" << endl;
	cout << "*     random word related to C++)         *" << endl;
	cout << "*  2. Play Two-Player Hangman             *" << endl;
	cout << "*     (One player chooses the word,       *" << endl;
	cout << "*     the other tries to guess the word)  *" << endl;
	cout << "*  Q. Quit                                *" << endl;
	cout << "*                                         *" << endl;
	cout << "*******************************************" << endl;
}

/*	Prompts for a character for the guess
 *
 *
 *	Pre-Condition:
 *	The function is called
 *
 *	Post-Condition:
 *	Dialogue is displayed asking the user
 *	to enter a letter for their guess.
 *	the user's input is returned
 *	
 */
char getGuess()
{
	char guessedLetter;
	
	cout << "Enter a single letter for your guess: ";
	cin >> guessedLetter;
	cout << endl;
	
	return guessedLetter;
}

/*	Sets the word to be guessed at random from the words[] array
 *	and calls the game logic function to get the user's guess
 *	and check the guess against the secret word.
 *
 *	Pre-Condition:
 *	Call the function
 *	
 *
 *	Post-Condition:
 *	The game executes until the user wins or looses
 *
 */
void onePlayer()
{	
	srand ( time(NULL) );	// Set the random number function seed based on the current system time.

	// Get the game word from words[]
	// by choosing a random number and moding it with the size of words[]
	// so that the random number is within the range of subscripts in words[]
	gameLogic( words[ rand() % (sizeof words / sizeof words[0]) ] );
}

/*	Gets the word to be guessed from a second player
 *	and puts a bunch of space between where
 *	the second player entered the word
 *	and where the first player begins entering their guesses.
 *
 *	Pre-Condition:
 *	Call the function
 *	
 *
 *	Post-Condition:
 *	The game executes until the user wins or looses
 *
 */
void twoPlayer()
{
	
	string chosenWord;
	bool chosenWordIsValid = false;
	
	if (!chosenWordIsValid) {
		cout << "Player 2, please enter a word for player one to guess: ";
		cin >> chosenWord;
		
		for ( int i = 0; i < chosenWord.length(); i++ ) {
			
			if ( !isalpha( chosenWord.at(i) ) ) {
				chosenWordIsValid = false;
				break;
			}
			else if ( isalpha( chosenWord.at(i) ) )
				chosenWordIsValid = true;
		}
	}
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << endl;
	
	gameLogic(chosenWord);	
	
}

/*	Performs the main logic of the game
 *
 *	Pre-condition:
 *	Takes a string for the word to put into
 *	the instance of secretWord called gameWord
 *
 *	Post-condition:
 *	creates an instance of hangman called thisRoundHangman
 *	and creates an instance of secretWord called gameWord
 *	then uses their member functions to get information about the word
 *	and the part of the word that has been guessed
 *	to determine if a player has won or lost
 *
 */
void gameLogic(string chosenWord)
{
	
	// A flag to be set to true when the player has won the game
	bool	win = false,
	// A flag to be set to true when the player has lost the game
			lose = false;
	// create an instance of hangman for this round of the game
	hangman thisRoundHangman;
	// create an instance of secretWord for this roung of the game
	secretWord gameWord(chosenWord);
	
	// Do all of the following steps while the player has not won or lost
	do {
		thisRoundHangman.display();	// Display the hangman in it's current state
		// Print the part of the word that has been guessed with *'s hiding the part that has not
		cout << gameWord.getCorrectLetters() << endl;
		// If the word has been guessed then reset the hangman's state,
		// and set the win flag to true,
		// and display you win, then exit the loop so that no further checks are performed.
		if ( gameWord.gameWordHasBeenGuessed() ) {
			thisRoundHangman.reset();
			win = true;
			cout << "You win!" << endl;
			break;
		}
		gameWord.guess(getGuess());	// Make a guess using the getGuess function to ask the user for input
		// If the last guess was incorrect
		// and the number of parts on the hangman is less than six,
		// increment the number of parts.
		if (!gameWord.lastGuessWasCorrect() && thisRoundHangman.getParts() < 6) {
			thisRoundHangman.addPart();
		}
		// Otherwise, if the word has been guessed and the parts count is 6
		// then reset the hangman's state,
		// and set the win flag to true,
		// and display you win.
		else if ( gameWord.gameWordHasBeenGuessed() && thisRoundHangman.getParts() == 6 ) {
			thisRoundHangman.reset();
			win = true;
			cout << "You win!" << endl;
		}
		// Otherwise, if the parts count is 6,
		// and the word has not been guessed
		// then reset the hangman's state,
		// and set the lose flag to true,
		// and display you win.
		else if ( thisRoundHangman.getParts() == 6 && !gameWord.gameWordHasBeenGuessed() ) {
			thisRoundHangman.reset();
			lose = true;
			cout << "Sorry, you lost :(" << endl << "The word was: " << gameWord.getWord() << endl;
		}
	} while (!win && !lose);
}