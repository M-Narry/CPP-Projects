/*
 * Description: This program calculates and displays amount paid for shares, commission, and total amount paid
 *
 * INPUT:
 * 		Constants:
 * 			Number of stocks purchased: 821
 * 			Cost per Stock: $35.5
 * 			Commission rate: 2%
 *
 * COMPUTATION:
 * 		Calculate total cost of stocks
 * 		Calculate total commission paid
 * 		Calculate the total cost
 *
 * OUTPUT:
 * 		total cost of stocks, commission paid, and total sum of the two
 *
 ********************************
 *
 * @author Blake Dee
 * @contact: blake.dee@my.century.edu
 * @since: 01/26/2025
 *
 * Course CSCI 1081-72
 *
 * Instiution: Century College
 *
 * Instructor: Mathew Nyamagwa
 */
#include <iostream>
using namespace std;

int main()
{
	// Constants
	const float STOCKS = 821,
				COST = 35.50,
				COMMISSION_RATE = 0.02;


	// Calculations
	float 	totalStockCost = STOCKS * COST,
			commissionPaid = totalStockCost * COMMISSION_RATE,
			totalCost = totalStockCost + commissionPaid;

	// Display results
	cout << "********** STOCK COMMISSION CALCULATOR **********\n\n"
		 << "Number of Stocks Purchased: " << STOCKS << "\n"
		 << "Cost of Stock: $" << COST << "\n"
		 << "---------------------------------------------------------------\n\n"
		 << "Total cost of Stocks: $" << totalStockCost << "\n"
		 << "Commission paid: $" << commissionPaid << "\n"
		 << "Total Cost: $" << totalCost << "\n"
		 << "---------------------------------------------------------------\n\n"
		 << "END OF PROGRAM!";

	return 0;
}
