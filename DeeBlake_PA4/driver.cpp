/**
 * Description: This program calculates the amount of sales needed to hit target amount
 *
 *
 * INPUT:
 * 		Constants:
 * 			rate of commissions on each tier
 * 			tier 1 = 0.08
 * 			tier 2 = 0.10
 * 			tier 3 = 0.12
 * 		User input:
 * 			none
 *
 * Computation:
 * 		Calculate target commission based on the goal and salary
 * 		Calculate commission based on tier 1
 * 		Calculate commission based on tier 2
 * 		Calculate commission for sales above 10000
 *
 * OUTPUT:
 * 		Minimum sales based on target amount and rates of commission
 *
 **********************************************
 *
 *	@author: Blake Dee
 *	@contact: blake.dee@my.century.edu
 *	@since: 2/16/2025
 *
 *	Course: 1081-72
 *
 *	Institution: Century College
 *
 *	Instructor: Mathew Nyamagwa
 *
 */

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

int main()
{

	double base_salary = 10000; // Set up the base salary
	double tier1_limit = 5000, tier2_limit = 5000;
	double const RATE1 = 0.08, RATE2 = 0.10, RATE3 = 0.12;
	double goal;

	ofstream outFile("sales.txt"); // Creates and opens a file in the directory


// Set up the table
outFile << "********** Sales Amount Calculator ********** \n\n";
outFile << "This program estimates minimum sales\n\n";
outFile << setw(15) << "Minimum Sales" << setw(20) << "Target Amount\n";
outFile << "----------------------------------------\n";
outFile << fixed << setprecision(2);

// Start the loops
for (goal = 40000.00; goal <= 80000.00; goal += 10000.00) {
	double targetCommission = goal - base_salary;
	double sales = 0.00;
	double commission;

		// Calculate that commission
		while (commission < targetCommission) {
			sales += 1.00; // Increase sales in steps of $1

			// Calculate commission based on sales tiers
			commission = 0;
			if (sales <= tier1_limit) {
				commission = sales * RATE1;
			}
			else if (sales <= tier2_limit) {
				commission = (tier1_limit * RATE1) + ((sales - tier1_limit) * RATE2);
			} else
			{
				commission = (tier1_limit * RATE1) + ((tier2_limit -tier1_limit) * RATE2) + ((sales - tier2_limit) * RATE3);
			}
		}
	// OUTPUT them results
	outFile << setw(5) << "$" << sales << setw(10) << "$" << goal << "\n";

}

	outFile << "\n\n END OF PROGRAM!!!";

	//Close File
	outFile.close();

	cout << "Output saved to sales.txt\n";

	return 0;
}
