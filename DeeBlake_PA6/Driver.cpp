/*
 * Description: This program calculates the area and perimeter of a polygon.
 *
 *
 * INPUT:
 * 		CONSTANTS:
 * 			PI: 3.14159265
 * 		USER INPUT:
 * 			The amount of sides of the polygon
 * 			The length of the sides of the polygon
 *
 * COMPUTATION:
 * 		Calculate the area of the polygon
 * 		Calculate the perimeter of the polygon
 *
 * OUTPUT:
 * 		Amount of sides, length of sides, area of polygon, and perimeter of polygon
 *
 ********************************
 *
 * @author: Blake Dee
 * @contact: blake.dee@my.century.edu
 * @since: 03/02/2025
 *
 * Course: CSCI 1081-72
 *
 * Institution: Century College
 *
 * Instructor: Mathew Nyamagwa
 */
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

// Constants
const double PI = 3.14159265;

// Function prototypes
double getUserInput(int &sides);
double calculatedArea(int sides, double length);
double calculatePerimeter(int sides, double length);
void display(double perimeter, double area, int sides, double length);

// Main
int main() {
	cout << "===== POLYGON AREA AND PERIMETER CALCULATOR =====\n"; // Outputs header
	cout << "This program calculates the area and perimeter of a given polygon.\n";
	cout << "============ INPUT ============\n";
	int sides;
	double length = getUserInput(sides);

	 // Obtains user input for sides and length

	double area = calculatedArea(sides, length); // Calculate area
	double perimeter = calculatePerimeter(sides, length); // Calculate perimeter

	cout << "============ OUTPUT ============\n";
	display(perimeter, area, sides, length); // Displays results

	cout << "================================ \n\n" << "END OF PROGRAM!";
	return 0;
}

// Gets the user's input regarding polygon
double getUserInput(int &sides) {
	do {
		cout << "Please enter the amount of sides: ";
		cin >> sides;
		if (sides < 3) { // Ensure sides are greater than or equal to 3
			cout << "INVALID ENTRY\nThe amount of sides should be greater than or equal to 3.\n";
	}
	} while (sides < 3);

	// Get length of a side
	double length;
	do{
		cout << "Please enter the length of the side: ";
		cin >> length;
		if (length <= 0) { // Ensure length is greater than 0
			cout << "INVALID ENTRY\nThe length of a side should be greater than 0.\n";
		}
	} while (length <= 0);

	return length; // Returns valid length value
}

double calculatedArea(int sides, double length) { // Calculates area
	return (sides * pow(length, 2)) / (4 * tan(PI / sides)); // Area formula
}

double calculatePerimeter(int sides, double length) { // Calculates perimeter
	return length * sides; // Perimeter formula
}

void display(double perimeter, double area, int sides, double length) { // Displays table of all variables
	cout << fixed << showpoint << setprecision(4);
	cout << setw(12) << left << "Sides " << ":" << setw(15) << right << sides << "\n";
	cout << setw(12) << left << "Length " << ":" << setw(15) << right << length << "\n";
	cout << setw(12) << left << "Area "  << ":" << setw(15) << right << area << "\n";
	cout << setw(12) << left << "Perimeter " << ":" << setw(15) << right << perimeter << "\n";
}
