/*
 *  Calculator.cpp
 *  
 *
 *  Created by Noah Greer on 10/28/09.
 *	Class: CS 210
 *	Instructor: Craig Niiyama
 *	
 *	Takes an operator and an operand,
 *	then performs the appropriate opperation,
 *	then displays the result,
 *	then returns to the first step.
 *
 *	Pre-Condition:
 *	Takes an operator and an operand
 *
 *	Post-Condition:
 *	Processes the input to find the operator and operand.
 *	Performs the operation indicated by the operator on the result using the value of the operand.
 *
 */

#include <iostream>	// Include standard library
#include <cmath>	// Include cmath library for the pow() function
#include <cctype>	// Include cctype library to check for digits in the input
#include <string>	// Include string library to work with strings
using namespace std;	// Use the standard namespace

void showIntructions();	// Display instructions to the user
// Analyze the input to see if it contains a valid operator and an operand
void processInput(string& inputString, char& mathOperator, double& operand);
// Perform the operation indicated by the operator with the operand collected by processInput()
void doNextOperation(char mathOperator, double operand, double& result);

bool	quit = false,	// Flag that is set to true when the user wants to quit
		gotOperand = false;	// Flag that is set to true when a valid operand was collected from input

int main()
{

	double	result = 0.0,	// The result of all of the operations performed
			operand;	// The operand of the operation
	string inputString;	// The input that the user enters that is to be processed
	char mathOperator;	// The operator that will determine which operation is performed
	
	do
	{
		
		showIntructions();	// Display the instructions to the user
		getline(cin, inputString);	// Capture the user's input in inputString

		// Process the users input to extract an operator and an operand
		processInput(inputString, mathOperator, operand);
		
		if(gotOperand)	// If processInput() was successful then gotOperand will be set to true
			// Perform the next operation indicated by the operator collected by processInput()
			doNextOperation(mathOperator, operand, result);
		// Display the result of the operation performed by doNextOperation()
		cout << endl << "Result so far: " << result << endl;
	 
	}while(!quit);	// Continue doing all of the above steps while the quit flag has not been set to true.
	
	return 0;

}

/*
 * Pre-Condition:
 * Call the function
 *
 * Post-Condition:
 * Instructions to the user are printed
 *
 */
void showIntructions()
{
	cout << "\nEnter an operator (+, -, *, /, ^),\nand a number sepparated by a space,\nor a q to quit: ";
}

/*
 * Pre-Condition:
 * Takes the string to be read character by character
 * and interpreted to get an operator and an operand
 * a char to put the operator in
 * a double to put the operand in
 *
 * Post-Condition:
 * The string is read character by character to check for an operator and an operand
 * If there is a single 'q' or 'Q' in the input the quit flag is set to true
 *
 * If the input contained an operator and a positive or negative integer or decimal,
 * then the operator is put in the operator is put in mathOperator,
 * and the operand is put in operand.
 * A check for division by zero is performed to prevent an error
 *
 */
void processInput(string& inputString, char& mathOperator, double& operand)
{	
	// A string to have pieces of the operand appended to it and to be eventually turned into a double
	string operandString;
	// Flag for if an operator was already found
	bool gotMathOperator = false,
	// Flag for if a decimal was already found
		 gotDecimal = false;
	
	// Read from the first position in inputString (i = 0) to
	// one less than the null terminator ( i < inputString.length() )
	for (int i = 0; i < inputString.length(); i++){
		// If there is just a q or a Q in inputString then set the quit flag to true and stop this loop
		if ( inputString.at(0) == 'q' || inputString.at(0) == 'Q' ){
			quit = true;
			break;
		}
		
		// If an operator has not been found and at the position i in inputString is a +, a -, a *, a /, or a ^
		// then put the character at position i into mathOperator and set the gotMathOperator flag to true
		if	( (!gotMathOperator) &&
			( (inputString.at(i) == '+') ||
			  (inputString.at(i) == '-') ||
			  (inputString.at(i) == '*') ||
			  (inputString.at(i) == '/') ||
			  (inputString.at(i) == '^') ) ){
			mathOperator = inputString.at(i);
			gotMathOperator = true;
		}
		// Otherwise, if an operator was already found and the character at i is a -, then append the - to operandString
		else if ( gotMathOperator && (inputString.at(i) == '-') )
			operandString.append(inputString, i, 1);
		// Otherwise, if an operator was already found and the character at i is a +, a *, a /, or a ^
		// then inform the user that there were too many operators and set the gotOperand flag to false, and stop this loop
		else if ( gotMathOperator &&
				( (inputString.at(i) == '+') ||
				  (inputString.at(i) == '*') ||
				  (inputString.at(i) == '/') ||
				  (inputString.at(i) == '^') )){
			cout << "\nToo many operators in input\n";
			gotOperand = false;
			break;
		}
		// If the character at i in inputString is a digit, then append it to operandString and set the gotOperand flag to true
		if ( isdigit( inputString.at(i) ) ){
			operandString.append(inputString, i, 1);
			gotOperand = true;
		}
		// Otherwise, if a decimal has not already been read
		// and the character at i in inputString is a '.'
		// then append it to operandString and set the gotDecimal flag to true
		else if ( !gotDecimal && inputString.at(i) == '.' ){
			operandString.append(inputString, i, 1);
			gotDecimal = true;
		}
		// Otherwise, if a decimal has already been read, and the character at i in inputString is a '.'
		// then inform the user and set the gotOperand flag to false, and stop this loop
		else if ( gotDecimal && inputString.at(i) == '.' ){
			cout << "\nToo many .'s in input\n\n";
			gotOperand = false;
			break;			
		}
	}
	
	// Convert operandString to a double and put the value in operand
	operand = strtod( operandString.c_str(), '\0' );
	// If the operator is a / and the operand is a 0
	// then set the gotOperand flag to false and inform the user
	if(mathOperator == '/' && operand == 0){
		gotOperand = false;
		cout << endl << "Cannot divide by zero." << endl;
	}
}

/*
 * Pre-Condition:
 * Takes an operator as a char, an operand as a double, and a place to put the result as a double
 *
 * Post-Condition:
 * The operation indicated by operator is performed using the operand and returned in result
 *
 */
void doNextOperation(char mathOperator, double operand, double& result)
{
	// Decide what operation to do based on what mathOperator contains
	switch (mathOperator){
	case '+':
		result += operand;
		break;
	case '-':
		result -= operand;
		break;
	case '*':
		result *= operand;
		break;
	case '/':
		result /= operand;
		break;
	case '^':
		result = pow(result, operand);
		break;
	}
}