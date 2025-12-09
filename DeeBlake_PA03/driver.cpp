/**
 * Description: This program computes a random number and compares the user number to that number
 *
 *
 * INPUT:
 * 		Lottery number
 * 		User input:
 * 			predicted lottery number
 *
 * 	COMPUTATION:
 * 		Calculates whether or not the numbers match in any way.
 *
 *  OUTPUT:
 *  	Cash prize based on the amount of correct numbers.
 *
 ***************************************************************
 *
 *	@author: Blake Dee
 *	@contact: blake.dee@mycentury.edu
 *	@since: 2/9/2025
 *
 *	Course: CSCI 1081-72
 *
 *	Institution: Century College
 *
 *	Instructor: Mathew Nyamagwa
 */

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	// create random integer
	srand(time(0));
		int lotteryNumber = rand() % 1000; // Generate number between 0 and 999
		int userInput;

	cout << "**************** CENTURY COLLEGE LOTTERY ****************\n\n";
	cout << "Welcome to Century College Lottery Club!\n"
			"Please follow the instructions below to WIN!!!\n\n";
	cout << "============ INPUT ============\n\n";
	cout << "Enter a three digit number: ";

	char first, second, third;
	cin >> first >> second >> third; // Reads only the first three numbers

	// Let's convert the characters into an integer
	userInput = (first - '0') * 100 + (second - '0') * 10 + (third - '0');

	// Extracting digits of the lottery number
	int lotteryFirst = lotteryNumber / 100;
	int lotterySecond = (lotteryNumber / 10) % 10;
	int lotteryThird = lotteryNumber % 10;

	// Extracting the digits of the users number
	int userFirst = userInput / 100;
	int userSecond = (userInput / 10) % 10;
	int userThird = userInput % 10;

	// Output
	cout << "\n============ OUTPUT ============\n\n";
	cout << "Today's Lottery number is: " << lotteryNumber << "\n\n";

	// Match set to 0
	int matches = 0;

	if (userInput == lotteryNumber) {
		cout << "You have an EXACT MATCH: You WIN $10,000!\n";
	} else if (userInput != lotteryNumber) {
	// Checking if any of the digits match regardless of order
	if (userFirst == lotteryFirst || userFirst == lotterySecond || userFirst == lotteryThird) {
		matches = matches + 1;
	}
	if	(userSecond == lotteryFirst || userSecond == lotterySecond || userSecond == lotteryThird) {
		matches = matches + 1;
	}
	if	(userThird == lotteryThird || userThird == lotterySecond || userThird == lotteryFirst) {
		matches = matches + 1;
	}

	// Output based on number of matches
	if (matches == 3) {
		cout << "Matching all numbers: You WIN $3,000\n\n";
	} else if (matches == 1) {
		cout << "Matching one number: You WIN $1,000!\n\n";
	} else if (matches == 2) {
		cout << "Matching two numbers: You WIN $1,500!\n\n";
	} else if (matches == 0) {
		cout << "Sorry, no luck! Better luck next time!\n\n";
	}

		cout << "END OF PROGRAM!!!";
	}
	return 0;
}
