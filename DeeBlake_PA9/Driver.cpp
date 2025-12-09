/*
 * Description: This program asks the user to enter a password then verifies that it meets the stated criteria.
 *
 * INPUT:
 * 		Constants:
 * 			none
 * 		User input:
 * 			password
 *
 * COMPUTATION:
 * 		Determines whether the password meets the criteria or not.
 *
 * OUTPUT:
 * 		Whether the password inserted met the criteria. If not, what criteria it didn't meet.
 *
 **************************************************
 *
 * @author: Blake Dee
 * @contact: blake.dee@my.century.edu
 * @since: 04/06/2025
 *
 * Course: CSCI 1081-72
 *
 * Institution: Century College
 *
 * Instructor: Mathew Nyamagwa
 */
#include <iostream>
#include <cctype>

using namespace std;

// Function prototypes
bool isValidPassword(const string &password, bool &hasUpper, bool &hasLower, bool &hasDigit);
void getPassword();

int main() {
	cout << "This program verifies passwords based on the stated criteria\n";
	getPassword();
	return 0;
}

// Ensures password is valid by checking the length and required character types
bool isValidPassword(const string &password, bool &hasUpper, bool &hasLower, bool &hasDigit) {
	hasUpper = hasLower = hasDigit = false;

	// Check characters in the password for upper, lower, and digits
	for (unsigned int index = 0; index < password.length(); ++index) {
		if (isupper(password[index])) hasUpper = true;
		if (islower(password[index])) hasLower = true;
		if (isdigit(password[index])) hasDigit = true;
		}

	return password.length() >= 8 && hasUpper && hasLower && hasDigit;
}

// Function that obtains password and validates it
void getPassword() {
	string password;
	cout << "Insert password that is:\n*At least eight characters long\n "
		 << "*Has at least one uppercase and one lowercase letter\n "
		 <<	"*Has at least one digit\n";

	// Variable declarations
	bool hasUpper, hasLower, hasDigit;

	while (true) {
		cout << "Password: ";
		getline(cin, password);


		// Check if password is valid
		if (isValidPassword(password, hasUpper, hasLower, hasDigit)) {
			cout << "\nPassword is valid!\n";
			break; // Exit the loop if the password is valid
		}

		// If invalid, shows reasons
		cout << "Invalid password!: \n";

		if (password.length() < 8) cout << "Password must be at least 8 characters long.\n";
		if (!hasUpper) cout << "Password must contain at least one uppercase letter.\n";
		if (!hasLower) cout << "Password must contain at least one lowercase letter.\n";
		if (!hasDigit) cout << "Password must contain at least one digit.\n";
		cout << "Try again!\n";
	}
}
