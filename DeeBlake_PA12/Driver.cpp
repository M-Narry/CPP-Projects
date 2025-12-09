/*
 * Description: This program creates a car from user input and tests its acceleration and braking
 *
 * INPUT:
 * 		User Input:
 * 			car's yearmodel
 * 			car's make
 *
 * COMPUTATION:
 * 		Takes the Car class and accelerates it and brakes it
 *
 * OUTPUT:
 * 		The test of the acceleration and braking.
 *
 *******************************************
 * @author: Blake Dee
 * @contact: blake.dee@my.century.edu
 * @since: 05/04/2025
 *
 * Course: CSCI 1081-72
 *
 * Institution: Century College
 *
 * Instructor: Mathew Nyamagwa
 */
#include <iostream>
#include "Car.h"

using namespace std;

//Function prototypes
Car createCarFromUserInput();
void testCar(Car &car);

int main(){

	// Introduction
	cout << "This program creates a car from user input and tests its acceleration and braking.\n";

	Car userCar = createCarFromUserInput();

	testCar(userCar);

	return 0;
}

// Creates a car using user input
Car createCarFromUserInput() {
	int year;
	string make;

	cout << "Enter the car's year model: ";
	cin >> year;
	if (year < 1886 || year > 2025) {
		cout << "Invalid year model. Please try again: ";
		cin >> year;
	}
	cout << "Enter the car's make: ";
	cin >> make;

	Car car(year, make);
	return car;
}

// Test accelerating and braking
void testCar(Car &car) {
	cout << "\n Initial speed: " << car.getSpeed() << " mph\n";

	// Accelerate 5 times
	for (int i = 0; i < 5; i++) {
			car.accelerate();
			cout << "Accelerating... Speed is now " << car.getSpeed() << " mph" << "\n";
		}

	// Brake 5 times
	for (int i = 0; i < 5; i++) {
			car.brake();
			cout << "Braking... Speed is now " << car.getSpeed() << " mph" << "\n";
		}
}
