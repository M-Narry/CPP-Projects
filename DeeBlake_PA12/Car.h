#ifndef CAR_H
#define CAR_H

#include <string>
using namespace std;

class Car {
private:
	int yearModel;
	string make;
	int speed;

public:
	// Constructor
	Car(int year, string carMake) {
		yearModel = year;
		make = carMake;
		speed = 0;
	}

	// Default Constructor
	Car() {
		yearModel = 2022;
		make = "";
		speed = 0;
	}

	void setYearModel(int year) {
		yearModel = year;
	}
	void setMake(string carMake) {
		make = carMake;
	}
	void setSpeed(int carSpeed) {
		speed = carSpeed;
	}

	// Getters
	int getYearModel() const {
		return yearModel;
	}
	string getMake() {
		return make;
	}
	int getSpeed() {
		return speed;
	}

	void accelerate() {
		speed += 5;

	}
	void brake() {
		speed -= 5;
		if (speed < 0) {
			speed = 0;
		}

	}
};

#endif
