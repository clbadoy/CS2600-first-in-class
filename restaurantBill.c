/**
 * @file            restaurantBill.c
 * @author          Christian Badoy (clbadoy@cpp.edu)
 * @professor       Professor Davarpanah
 * @brief           The purpose of this program is to calculate a restaurant bill with a tax rate
 *                  and a tip rate of the user's preference.
 * @version         0.1
 * @date            2021-09-30
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

/**
 * Creates a random number to pick a random food item
 * from the ment.
 * @param num Size of the menu population
 * @return int newNumber the (n-1)th item on the menu, from 0 to 3.
 */
int createRandomNumber(int num)
{
	int newNumber, numCap;
	
	numCap = num;
	
	srand(time(0));
	newNumber = rand() % numCap;
	
	return newNumber;
}

/**
 * Calculates the value of the tip based on the user's inputted rate.
 * 
 * @param price The price of the item purchased.
 * @param tipRate The percentage of the tip.
 * @return float tipValue The calculated tip value to add to total bill.
 */
float calculateTip(float price, float tipRate)
{
	float tipValue;

	tipValue = price * (tipRate / 100);
	return tipValue;
}

/**
 * Calculates the value of the tax based on the user's inputted rate.
 * 
 * @param price The price of the item purchased.
 * @param taxRate The percentage of the tax.
 * @return float taxValue The calculated tax value to add to total bill.
 */
float calculateTax(float price, float taxRate)
{
	float taxValue;

	taxValue = price * (taxRate / 100);
	return taxValue;
}
/**
 * Prints the bill onto console. Calculates total bill.
 * 
 * @param cost The cost of the item purchased.
 * @param tax The value of the tax based on item purchased.
 * @param tip The value of the tip based on item purchased
 * @return int 0 exits the printBill method.
 */
int printBill(float cost, float tax, float tip)
{
	float total = cost + tax + tip;

	printf("|\t\tCost: $%.2f\n", cost);
	printf("|\t\tTax: $%.2f\n", tax);
	printf("|\t\tTip: $%.2f\n", tip);
	printf("|\t\tTOTAL: $%.2f\n", total);
	printf("|\tThank you for eating at Some Restaurant.\n");
	printf("==============================================\n");
	return 0;
}

int main()
{
	int randomNumber;
	float saladPrice, soupPrice, sandwichPrice, pizzaPrice, taxRate, tipRate;
	float cost, tax, tip;
	char error;

	// Given Menu Prices.
	saladPrice = 9.95;
	soupPrice = 4.55;
	sandwichPrice = 13.25;
	pizzaPrice = 22.35;

	// Prints Menu for user to read.
	printf("Some Restaurant's Menu\n");
	printf("1. Salad: $%.2f\n", saladPrice);
	printf("2. Soup: $%.2f\n", soupPrice);
	printf("3. Sandwich: $%.2f\n", sandwichPrice);
	printf("4. Pizza: $%.2f\n", pizzaPrice);
	
	// Allows user to input the rate of tax.
	inputTax:

	printf("Input the tax rate (e.g. 8.375%% Tax = 8.375): ");
	scanf("%f", &taxRate);
	scanf("%c", &error);
	// Checks if invalid characters are inputted into the text.
	if(isalpha(error) || (ispunct(error) && error != '.'))
	{
		printf("Invalid input.\n");
		error = '\0';
		goto inputTax;
	}
	// Checks if the tax rate is a valid percentage.
	else if(taxRate < 0 || taxRate >100)
	{
		printf("Invalid percentage.\n");
		goto inputTax;
	}

	// Allows user to input the rate of tip.
	inputTip:

	printf("Input the tip rate (e.g. 20%% Tip = 20): ");
	scanf("%f", &tipRate);
	scanf("%c", &error);
	// Checks if invalid characters are inputted into the text.
	if(isalpha(error) || (ispunct(error) && error != '.'))
	{
		printf("Invalid input.\n");
		error = '\0';
		goto inputTip;
	}
	// Checks if the tip rate is a valid percentage.
	else if(tipRate < 0 || tipRate >100)
	{
		printf("Invalid percentage.\n");
		goto inputTip;
	}

	// Selects which food item is chosen.
	randomNumber = createRandomNumber(4);
	
	/**
	 * 1. Begins to print out the restaurant bill onto console/terminal.
	 * 2. Console prints item onto bill.
	 * 3. Tax and tip are calculated.
	 * 4. printBill() calculates total and prints the cost, tax, tip, and total values onto console.
	 */
	printf("=============SOME RESTAURANT BILL=============\n");
	printf("|\t\tOrdered: ");
	switch(randomNumber)
	{
		case 0:
			cost = saladPrice;
			printf("Salad\n");
			break;
		case 1:
			cost = soupPrice;
			printf("Soup\n");
			break;
		case 2:
			cost = sandwichPrice;
			printf("Sandwich\n");
			break;
		case 3:
			cost = pizzaPrice;
			printf("Pizza\n");
			break;
	}
	tax = calculateTax(cost, taxRate);
	tip = calculateTip(cost, tipRate);


	printBill(cost, tax, tip);

	// Ends Program.
	return 0;
}