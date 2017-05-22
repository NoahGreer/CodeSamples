/*
 *  4words.cpp
 *  
 *	Created by Noah Greer on 10/8/09.
 *	Class: CS 210
 *	Instructor: Craig Niiyama
 *
 *	Reads four words sepparated by *'s
 *	then displays the words in reverse order with the *'s removed.
 *
 *	Pre-Condition:
 *	Instructs the user to enter four words sepparated by only *'s
 *	Takes a string of four words sepparated by only *'s
 *
 *	Post-Condition:
 *	Displays the the original string with the *'s removed and the words in reverse order.
 *
 */

#include <iostream>
#include <string>
using namespace std;

int main()
{
	
	string	inputFourWords,		// Four words sepparated by *'s
			outputFourWords;	// The same four words as inputFourWords, but in reverse order and with *'s removed
	
	// Prompt the user to enter four words with *'s between them.
	cout << endl << "Enter four words sepparated by *'s: ";
	cin >> inputFourWords;
	
	// Display the text that was entered.
	cout << endl << "You entered:  " << inputFourWords << endl;
	
	// Assign to outputFourWords the substring in inputFourWords
	//	from the last asterisk, up to but not including the null terminator.
	outputFourWords.assign(inputFourWords, inputFourWords.find_last_of('*') + 1, inputFourWords.find('\0'));
	inputFourWords.erase(inputFourWords.find_last_of('*'), inputFourWords.find('\0') - 1);
	
	// Append a space to outputFourWords.
	outputFourWords.append(" ");
	// Append to outputFourWords the substring in inputFourWords
	// from the last asterisk, up to but not including the null terminator.
	outputFourWords.append(inputFourWords, inputFourWords.find_last_of('*') + 1, inputFourWords.find('\0'));
	// Erase from inputFourWords the substring from last asterisk up to but not including the null terminator
	inputFourWords.erase(inputFourWords.find_last_of('*'), inputFourWords.find('\0') - 1);

	// Append a space to outputFourWords.
	outputFourWords.append(" ");
	// Append to outputFourWords the substring in inputFourWords
	// from the last asterisk, up to but not including the null terminator.
	outputFourWords.append(inputFourWords, inputFourWords.find_last_of('*') + 1, inputFourWords.find('\0'));
	// Erase from inputFourWords the substring from last asterisk up to but not including the null terminator
	inputFourWords.erase(inputFourWords.find_last_of('*'), inputFourWords.find('\0') - 1);
	
	// Append a space to outputFourWords.
	outputFourWords.append(" ");
	// Append to outputFourWords the substring in inputFourWords
	// from the last asterisk, up to but not including the null terminator.
	outputFourWords.append(inputFourWords, inputFourWords.find_last_of('*') + 1, inputFourWords.find('\0'));
	// Erase the entire contents of inputFourWords.
	inputFourWords.erase();
	
	// Display the string outputFourWords
	cout << endl << "Here are your words in reverse order: " << outputFourWords << endl << endl;
	
	return 0;
	
}