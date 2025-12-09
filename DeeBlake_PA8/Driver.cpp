/*
 * Description: This program reads integers from a file, expands the array, and displays it
 *
 *
 * INPUT:
 * 		Constants:
 * 			size of data = 50
 * 		User Input:
 * 			number
 *
 * 	COMPUTATION:
 * 		None
 *
 * 	OUTPUT:
 * Values read from file as well as the expanded array.
 *
 * ****************************************
 *
 *  @author: Blake Dee
 *  @contact: blake.dee@my.century.edu
 *  @since: 3/30/3025
 *
 *  Course: CSCI 1081-72
 *
 *  Institution: Century College
 *
 *  Instructor: Mathew Nyamagwa
 */
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

// Constants
const int MAX_SIZE = 50;

// Function prototypes
int getInput();
void readData(int array[], int size);
int *expandArray(const int array[], int size);
void displayArray(const int array[], int size, string title);

// Introduces the program and calls functions
int main() {
	cout << "This program reads integers from a file, expands the array, and displays it.\n";
	cout << "=========== INPUT ===========\n";
	int N = getInput();
	int data[N];

	// Read data from file
	readData(data, N);

	cout << "=========== OUTPUT ==========\n";
	displayArray(data, N, "Values read from file:");

	// Expand array
	int *expandedArray = expandArray(data, N);

	// Display results
	displayArray(expandedArray, 2 * N, "Expanded Array:");

	// Free allocated memory
	delete[] expandedArray;

	return 0;
}

// Gets a valid integer between 1 and 50
int getInput(){
	int N;
	do{
		cout << "Enter the number of values to read (1-" << MAX_SIZE << "): ";
		cin >> N;
		if (N < 1 || N > MAX_SIZE) {
			cout << "Invalid input. Please enter a vlue between 1 and " << MAX_SIZE << ".\n";
		}
	} while (N < 1 || N > MAX_SIZE);
	return N;
}

// Reads data from data.md into an array
void readData(int array[], int size) {
	ifstream dataFile("data.md");
	if (!dataFile) {
		cerr << "Error: Unable to open file.\n";
		return;
	}
	for (int index = 0; index < size; index++) {
		dataFile >> array[index];
	}
	dataFile.close();
}

// Expands an integer array by doubling its size
int *expandArray(const int array[], int size) {
	int *newArray = new int[2 * size];

	// Copies original array
	for (int index = 0; index < size; index++) {
		newArray[index] = array[index];
	}

	// Copy original array agian into second half
	for (int index = 0; index < size; index++) {
		newArray[size + index] = array[index];
	}

	return newArray;
}

// Displays the elements of an array
void displayArray(const int array[], int size, string title) {
	cout << title << "\n";
	for (int index = 0; index < size; index++) {
		cout << array[index] << "\n";
	}
}
