/*
 * Description: This program gets all of the reported number of crashes in an area and compares it to the rest.
 *
 *
 * INPUT:
 * 		User Input:
 * 			number of automobile accidents reported.
 *
 * COMPUTATION:
 * 		Takes all of the given values and computes which one is the lowest.
 *
 * OUTPUT:
 *		Region with the lowest amount of accidents according to user input.
 *
 ***************************************************
 *
 *	@author Blake Dee
 *	@contact: blake.dee@my.century.edu
 *	@since: 02/23/2025
 *
 *	Course CSCI 1081-72
 *
 *	Institution: Century College
 *
 *	Instructor: Mathew Nyamagwa
 */
#include <iostream> //header
#include <string>

using namespace std;

int getNumAccidents(string region) { // Obtains user input for reported accidents
	int accidents;
	do {
		cout << "Enter the number of automobile accidents reported in the " << region << " region last year: ";
		cin >> accidents;

		if (accidents < 0) {
			cout << "Invalid input. Please enter a non-negative integer.\n";
			cin.clear();

		}
	} while (accidents < 0);

	return accidents;
}

void findLowest(int north, int south, int east, int west, int central) { // Calculates the lowest region
	int minAccidents = north;
	string minRegion = "North";

	if (south < minAccidents) {
		minAccidents = south;
		minRegion = "South";
	}
	if (east < minAccidents) {
		minAccidents = east;
		minRegion = "East";
	}
	if (west < minAccidents) {
		minAccidents = west;
		minRegion = "West";
	}
	if (central < minAccidents) {
		minAccidents = central;
		minRegion = "Central";
	}
// Output
	cout << "The " << minRegion << " region had the lowest number of accidents: " << minAccidents << " accidents.\n";
}

int main() { // Back to Main Calling the two functions
	int north = getNumAccidents("North");
	int south = getNumAccidents("South");
	int east = getNumAccidents("East");
	int west = getNumAccidents("West");
	int central = getNumAccidents("Central");

	findLowest(north, south, east, west, central);

	return 0;
}
