/**
 * @file            restaurantBill.c
 * @author          Christian Badoy (clbadoy@cpp.edu)
 * @professor       Professor Davarpanah
 * @brief           The purpose of this program is to calcilate a restaurant bill with a tax rate
 *                  and a tip rate of the user's preference.
 * @version         0.1
 * @date            2021-09-30
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

int createRandomNumber(int num)
{
	int newNumber, numCap;
	
	numCap = num;
	
	srand(time(0));
	newNumber = rand() % numCap;
	
	return newNumber;
}

float calculateTip(float price, float tipRate)
{
	float tipValue;

	tipValue = price * (tipRate / 100);
	return tipValue;
}

float calculateTax(float price, float taxRate)
{
	float taxValue;

	taxValue = price * (taxRate / 100);
	return taxValue;
}

int printBill(float cost, float tax, float tip)
{
	float total = cost + tax + tip;

	printf("|\t\t\t\tCost: $%.2f\n", cost);
	printf("|\t\t\t\tTax: $%.2f\n", tax);
	printf("|\t\t\t\tTip: $%.2f\n", tip);
	printf("|\t\t\t\tTOTAL: $%.2f\n", total);
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

	saladPrice = 9.95;
	soupPrice = 4.55;
	sandwichPrice = 13.25;
	pizzaPrice = 22.35;

	printf("Some Restaurant's Menu\n");
	printf("1. Salad: $%.2f\n", saladPrice);
	printf("2. Soup: $%.2f\n", soupPrice);
	printf("3. Sandwich: $%.2f\n", sandwichPrice);
	printf("4. Pizza: $%.2f\n", pizzaPrice);
	
	inputTax:

	printf("Input the tax rate (e.g. 8.375%% Tax = 8.375): ");
	scanf("%f", &taxRate);
	scanf("%c", &error);
	if(isalpha(error) || (ispunct(error) && error != '.'))
	{
		printf("Invalid input.\n");
		error = '\0';
		goto inputTax;
	}
	else if(taxRate < 0 || taxRate >100)
	{
		printf("Invalid percentage.\n");
		goto inputTax;
	}

	inputTip:

	printf("Input the tip rate (e.g. 20%% Tip = 20): ");
	scanf("%f", &tipRate);
	scanf("%c", &error);
	if(isalpha(error) || (ispunct(error) && error != '.'))
	{
		printf("Invalid input.\n");
		error = '\0';
		goto inputTip;
	}
	else if(tipRate < 0 || tipRate >100)
	{
		printf("Invalid percentage.\n");
		goto inputTip;
	}


	randomNumber = createRandomNumber(4);

	printf("=============SOME RESTAURANT BILL=============\n");
	printf("|\t\t\t\tOrdered: ");
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

	return 0;
}