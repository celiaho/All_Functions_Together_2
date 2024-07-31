// This program:
//		asks the user to enter a positive integer;
//		validates the user's input and prints a custom error message if needed;
//		reports the input as perfect, deficient, or abundant;
//		reports the input as prime or composite; and
// uses all five types of functions:
//		printing, 
//		input validation,
//		calculating,
//		classifying, and
//		testing/checking.
// Instruction file: https://bhcc.digication.com/cit120all_master_delta/all_at_once
// Title: All Functions Together
// Progammer: C. Ho
// Last Modified: Mon. Nov. 20, 2023 @ 5:10 PM

// PRE-PROCESSOR DIRECTIVE SECTION
#include <iostream>
using namespace std;

// FUNCTION DECLARATION SECTION
void printBanner();
void printInstructions();
int getPosInt();
// string classifyPAD(int usersPosInt);		// Function to classify perfect/abundant/deficient
bool isPrime(int usersPosInt);		// Function to classify prime/composite

// MAIN SECTION 
int main()
{
	// SET UP SECTION
	// System function call to change text in title bar
	system("title All function types in one program by C. Ho");
	// System function call to customize colors of cmp window (bg aqua, fg dkblue)
	system("color B1");

	// WYSIWYG banner
	// *** Does this section go before or after Var Dec? --> Doesn't matter, leave here is fine
	printBanner();

	// VARIABLE DECLARATION SECTION
	int
		usersPosInt;	// Variable to store user's number

	// INPUT SECTION
	// Force an infinite loop so program will run continuously.
	while (true)
	{
		// Print message prompting user for input.
		printInstructions();

		// Function call to get user's number & validate input
		usersPosInt = getPosInt();

		// PROCESSING SECTION
		
		// OUTPUT SECTION
		// Print statement classifying user's number.
		cout << "\nYou gave me " << usersPosInt << ", which is "
			<< "[a(n) PAD ]" // << classifyPAD(userInteger) 
			<< (isPrime(usersPosInt) ? "prime" : "composite") << " number.\n\n";
		
		// Print a line of asterisks to mark the end of the program.
		cout << "           ****************************\n\n";
	// Forced infinite loop ends.
	}

	// CLEAN UP SECTION
	system("pause");
	return 0;
// MAIN ENDS
}

// FUNCTION DEFINITION SECTION
// Define function for printing introductory banner
void printBanner()
{
	cout << "\n"
		<< "\t   A program that demonstrates functions that   \n"
		<< "\t calculate, classify, test, validate, and print \n"
		<< "\t                    by C. Ho                    \n\n\n";
}

// Define function for printing user instructions
// *** Add WYSIWYG     ****Confirm prof was confused about this
void printInstructions()
{
	cout << "I can classify positive integers as perfect, abundant or deficient.\n"
		<< "I am also able to tell you if they are prime or not.\n"
		<< "        Give me a positive integer: ";
}

// Define function for getting & validating user's number
// ******Include check for integer (i.e. probibit 3.5)
int getPosInt()
{
	int integer;			// Declare a local variable.
	cin >> integer;			// Get user number/Initialize that variable.
	cin.ignore(1000, '\n');	// Clear keyboard buffer.

	// If user input is not a positive integer...
	while (integer <= 0)
	{
		// ...print error message and prompt new input.
		cout << "        " << integer << " is not a POSITIVE number. Try again: ";
		cin >> integer;			// Get new user number.
		cin.ignore(1000, '\n');	// Clear keyboard buffer.
	}

	return integer;
}

// Define function that classifies user's number as perfect/abundant/deficient
string classifyPAD(int usersPosInt)
{
	// function here
}

// Define function that checks if user's number is prime
bool isPrime(int usersPosInt)
{
	double checkLimit = sqrt(usersPosInt);

	// Starting with Potential Divisor 2, if potential divisor is <= sq rt of user's number,
	// return false (not prime, i.e. composite) if user's number is divisible by potential divisor;
	// otherwise increase Potential Divisor by 1 and check again.
	for (int potDivisor = 2; potDivisor <= checkLimit; potDivisor++)
	{
		if (usersPosInt % potDivisor == 0)
			return false;
	}

	// Return true (prime) because user's number is not divisible by 
	// any potential divisors <= sq rt of user's number
	return true;
}