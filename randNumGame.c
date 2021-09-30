/**
 * @file 		randNumGame.c
 * @author 		Christian Badoy (clbadoy@cpp.edu)
 * @class 		CS2600-02
 * @professor 	Professor Davarpanah
 * @brief 		This program allows users to play a game of guessing what the randomly generated number is.
 * 				Users have the ability to set a ceiling on what range of numbers the user may want to guess for. 
 * @version 	0.2
 * @date 		2021-09-30
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

/**
 * Generates a random number for the user to guess for.
 * 
 * @param num The number ceiling that the user inputted or the default ceiling.
 * @return newNumber The number the user has to guess for.
 */
int createRandomNumber(int num)
{
	int newNumber, numCap;
	
	numCap = num;
	
	srand(time(0));
	newNumber = (rand() % numCap) + 1;
	
	return newNumber;
}

/**
 * Runs the random number guessing game.
 * The user has to guess what the randomly generated number randNum is.
 * The user will have to input an integer number that is within the range.
 * The user may also return to the menu by entering the char 'q'.
 * Any other char or value outside of char 'q' or numerical values will be considered invalid.
 * 
 * @param randNum The random number that was generated from createRandomNumber(int num).
 * @param maxRand The ceiling number that either the user or default settings created.
 */
void game(int randNum, int maxRand)
{
	int inputNum = -7;
	char quit;

	// While loop will loop until user guesses right.
	while(randNum != inputNum)
	{
		printf("Guess a number (1 to %d), or press 'q' to return to the menu: ", maxRand);
		scanf("%u", &inputNum);
		scanf("%c", &quit);

		// Checks for q or Q to return to menu.
		if((isalpha(quit) && quit == 'q') || (isalpha(quit) && quit == 'Q'))
			break;
		// Checks for any invalid input.
		else if((isalpha(quit) && quit != 'q') || ispunct(quit))
			printf("Invalid input.\n\n");

		// Determines whether user is above, below, or exactly on the randomly generated number.
		else if(inputNum < randNum)
			printf("Try again! Current value is too low.\n\n");
		else if(inputNum > randNum)
			printf("Try again! Current value is too high.\n\n");
		else if(inputNum == randNum)
			{
				printf("****************************************************************");
				printf("\n* Congratulations! You have guessed the right number! You win! *\n");
				printf("****************************************************************\n\n");
			}	
	}
}

int main(void) {
  
	int selectOptionNum, randNum, randNumMax;
	randNumMax = 10;
	char error;

	FILE *fp, *fr;
	// Implements the max number ceiling the user last established in previous game.
	// A max_number_keep_file.txt file must be present, or else the program will not function.
	fr = fopen("max_number_keep_file.txt", "r");
	fscanf(fr,"%d", &randNumMax);
	fclose(fr);
	
	menu:

	printf("****************************************");
	printf("\n*         RANDOM NUMBER GAME           *");
	printf("\n* Press '1' to play a game.            *\n");
	printf("* Press '2' to change the max number.  *\n");
	printf("* Press '3' to quit.                   *\n");
	printf("****************************************\n");
	printf("\n-Note: Any invalid input may crash the program.\n");

	select:
	scanf("%u", &selectOptionNum);
	scanf("%c", &error);
	
	// Checks for any invalid input.
	if(isalpha(error) || ispunct(error))
		selectOptionNum = -1;

	/**
	 * Switch method that moves user to proper line of code.
	 * case 1: Initializes a brand new game. Generates a new random number.
	 * case 2: Moves user to settings in order to adjust number ceiling for RNG generator to adjust.
	 * case 3: Terminates the program.
	 * default: Prompts user to enter a valid input.
	 */
	switch(selectOptionNum)
	{
		case 1:
			randNum = createRandomNumber(randNumMax);

			game(randNum, randNumMax);
			goto menu;
		case 2:
			goto settings;
		case 3:
			goto killProgram;
		default:
			printf("Invalid selection, please enter a valid option.\n");
			goto select;
	}

	// Modifies number ceiling that the psuedo-random number generator can generate.
	settings:
	
	printf("\nSelect a maximum number ceiling in which you wish for the random number game to generate. \n");
	printf("Default is 10. Minimum number is 1. Maximum number is %d.\nEnter value: ", RAND_MAX);
	scanf("%u", &randNumMax);
	scanf("%c", &error);

	// Checks for any invalid input.
	if(isalpha(error) || ispunct(error))
		{
			printf("Invalid input.\n");
			goto settings;
		}
	// Checks if number ceiling is greater than zero.
	if(randNumMax <= 0)
	{
		printf("\nInvalid number input. Value is less than 1. Input a new number.\n");
		goto settings;
	}
	// Checks if ceiling number is less than 214,783,647, the maximum number rand() can handle.
	else if(randNumMax > 214783647)
	{
		printf("\nInvalid number input. Value is too large. Input a new number.\n");
		goto settings;
	}
	// Validates that the number is within range.
	else if(randNumMax > 0 && randNumMax <= 214783647)
	{
		printf("\nMax value to be guessed has been set!\n\n");

		// Writes and saves max number to a text file.
		fp = fopen("max_number_keep_file.txt","w+");
		fprintf(fp, "%d", randNumMax);
		fclose(fp);

		goto menu;
	}

	// Terminates the program from running.
	killProgram:

	printf("\nThank you for playing my Random Number Guesser game! Hope to see you next time!");
  	return 0;
}