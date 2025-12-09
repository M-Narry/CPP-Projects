/**
 * Description: This program calculates the amount of population increase from 2024 to 2030 as well as calculates per year.
 *
 *
 * INPUT:
 * 		Constants:
 * 			population of year 2024 = 345426571
 * 			population increase = 2780096
 * 		User Input:
 * 			Number of years
 *
 * 	COMPUTATION:
 * 		Calculate the population of years 2025-2030
 * 		Calculate projected population of years past 2024
 *
 * 	OUTPUT:
 * 		Population for years 2024-2030 and years input by user
 *
 *********************************************
 *
 *	@author Blake Dee
 *	@contact blake.dee@my.century.edu
 *	@since: 02/02/2025
 *
 *	Course: CSCI 1081-72
 *
 *	Institution: Century College
 *
 *	Instructor: Mathew Nyamagwa
 */
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	// Constants
	const int SECONDS_IN_YEAR = 365 * 24 * 60 * 60;
	const long INITIAL_YEAR_POPULATION = 345426571;
	const float BIRTH_RATE = SECONDS_IN_YEAR / 7.0;
	const float DEATH_RATE = SECONDS_IN_YEAR / 13.0;
	const float IMMIGRANT_RATE = SECONDS_IN_YEAR / 45.0;
	const int YEARLY_INCREASE = BIRTH_RATE + IMMIGRANT_RATE - DEATH_RATE;

	//Initial population for 2024
	int population = INITIAL_YEAR_POPULATION;


	// Population projections math
	population += YEARLY_INCREASE; int year2025 = population;
	population += YEARLY_INCREASE; int year2026 = population;
	population += YEARLY_INCREASE; int year2027 = population;
	population += YEARLY_INCREASE; int year2028 = population;
	population += YEARLY_INCREASE; int year2029 = population;
	population += YEARLY_INCREASE; int year2030 = population;

	// Output
	cout << "************ POPULATION PROJECTION ************* \n\n";
	cout << setw(35) << "Population year: 2024\n";
	cout << fixed << setprecision(0); // Set precision to 0 decimals for population
	cout << setw(37) << "Population by the end of 2024 was: " << INITIAL_YEAR_POPULATION << "\n";
	cout << setw(33) << "Estimated yearly increase: " << YEARLY_INCREASE << "\n\n";
	cout << "================================================\n\n"; // making it prettier

	// Yearly projections
	cout << setw(20) << "Yearly projections for the next six years: \n\n";

	// Header
	cout << setw(17) << "YEAR" << setw(13) << "Projection" << "\n";
	cout << setw(17) << "----" << setw(13) << "-----------" << "\n";

	// Projections
	cout << setw(17) << "2025" << setw(12) << year2025 << "\n";
	cout << setw(17) << "2026" << setw(12) << year2026 << "\n";
	cout << setw(17) << "2027" << setw(12) << year2027 << "\n";
	cout << setw(17) << "2028" << setw(12) << year2028 << "\n";
	cout << setw(17) << "2029" << setw(12) << year2029 << "\n";
	cout << setw(17) << "2030" << setw(12) << year2030 << "\n\n";

	// Input
	int yearNumber;
	cout << setw(40) << "------------- INPUT -------------\n\n";
	cout << "Enter the number of years you would like to project: ";
	cin >> yearNumber;

	// Calculate projection
	int populationNumber = INITIAL_YEAR_POPULATION + (YEARLY_INCREASE * yearNumber);

	// Output
	cout << "\n------------- OUTPUT -------------\n\n";
	cout << "Population projection by the end of " << yearNumber << " year(s) will be: " << populationNumber << "\n\n";
	cout << "END OF PROGRAM!!";

	return 0;
}
