/*
 *  4words.cpp
 *  
 *	Created by Noah Greer on 10/8/09.
 *	Class: CS 210
 *	Instructor: Craig Niiyama
 *
 *	Reads four words sepparated by *'s and displays the words in reverse order with the *'s removed.
 *
 *	Pre-Condition:
 *	Instructs the user to enter four words sepparated by only *'s
 *	Takes a string of four words sepparated by only *'s
 *
 *	Post-Condition:
 *	Displays the four words that were entered and the original string with the *'s removed and the words in reverse order.
 *
 */

#include <iostream>
#include <string>
using namespace std;

int main()
{
	
	string	inputFourWords,		// Four words sepparated by *'s
	outputFourWords,	// The same four words as inputFourWords, but in reverse order and with *'s removed
	firstWord,			// The first of the words extracted from inputFourWords without an *
	secondWord,			// The second word extracted from inputFourWords without an *
	thirdWord,			// The third word extracted from inputFourWords	without an *
	fourthWord;			// The fourth word extracted from inputFourWords without an *
	
	// Prompt the user to enter four words with *'s between them.
	cout << "Enter four words sepparated by *'s: ";
	cin >> inputFourWords;
	
	// Display the text that was entered.
	cout << endl << "You entered:  " << inputFourWords << endl;
	
	// Assign to firstWord the substring in inputFourWords from the first character, up to but not including the first asterisk.
	firstWord.assign(inputFourWords, 0, inputFourWords.find('*'));
	
	// Erase the substring in inputFourWords from the first character, up to and including the first asterisk.
	inputFourWords.erase(0, inputFourWords.find('*') + 1);
	
	// Assign to secondWord the substring in inputFourWords from the first character, up to but not including the first asterisk.
	secondWord.assign(inputFourWords, 0, inputFourWords.find('*'));
	
	// Erase the substring in inputFourWords from the first character, up to and including the first asterisk.
	inputFourWords.erase(0, inputFourWords.find('*') + 1);
	
	// Assign to thirdWord the substring in inputFourWords from the first character, up to but not including the first asterisk.
	thirdWord.assign(inputFourWords, 0, inputFourWords.find('*'));
	
	// Erase the substring in inputFourWords from the first character, up to and including the first asterisk.
	inputFourWords.erase(0, inputFourWords.find('*') + 1);
	
	// Assign to fourthWord the substring in inputFourWords from the first character, up to but not including the first asterisk.
	fourthWord.assign(inputFourWords, 0, inputFourWords.find('*'));
	
	// Combine all four words in reverse order of how they were entered into one string
	outputFourWords	= fourthWord + " " + thirdWord + " " + secondWord + " " + firstWord;
	
	// Display the individual sepparated words. Each on their own line.
	cout << endl << "Your words are: " << endl;
	cout << firstWord << endl;
	cout << secondWord << endl;
	cout << thirdWord << endl;
	cout << fourthWord << endl;
	
	// Display the string outputFourWords
	cout << endl << "Here are your words in reverse order: " << outputFourWords << endl << endl;
	
	return 0;
	
}