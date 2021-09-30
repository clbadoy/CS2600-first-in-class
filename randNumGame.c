#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

int createRandomNumber(int num)
{
	int newNumber, numCap;
	
	numCap = num;
	
	srand(time(0));
	newNumber = (rand() % numCap) + 1;
	
	return newNumber;
}

void game(int randNum, int maxRand)
{
	int inputNum = -7;
	char quit;

	while(randNum != inputNum)
	{
		printf("Guess a number (1 to %d), or press 'q' to return to the menu: ", maxRand);
		scanf("%u", &inputNum);
		scanf("%c", &quit);

		if(isalpha(quit) && quit == 'q')
			break;
		else if((isalpha(quit) && quit != 'q') || ispunct(quit))
			printf("Invalid input.\n\n");
		else if(inputNum < randNum)
			printf("Try again! Current value is too low.\n\n");
		else if(inputNum > randNum)
			printf("Try again! Current value is too high.\n\n");
		else if(inputNum == randNum)
			{
				printf("****************************************************************");
				printf("\n* Congratulations! You have guessed the right number! You win! *\n");
				printf("****************************************************************\n\n");
				break;
			}	
	}
}

int main(void) {
  
	int selectOptionNum, randNum, randNumMax;
	randNumMax = 10;
	char error;

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
	
	if(isalpha(error))
		selectOptionNum = -1;

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

	goto menu;

	settings:
	
	printf("\nSelect a maximum number ceiling in which you wish for the random number game to generate. \nDefault is 10. Minimum number is 1. Maximum number is %d.\nEnter value: ", RAND_MAX);
	scanf("%u", &randNumMax);
	scanf("%c", &error);
	if(isalpha(error) || ispunct(error))
		{
			printf("Invalid input.\n");
			goto settings;
		}
	if(randNumMax <= 0)
	{
		printf("\nInvalid number input. Value is less than 1. Input a new number.\n");
		goto settings;
	}
	else if(randNumMax > 214783647)
	{
		printf("\nInvalid number input. Value is too large. Input a new number.\n");
		goto settings;
	}
	else if(randNumMax > 0 && randNumMax <= 214783647)
	{
		printf("\nMax value to be guessed has been set!\n\n");
		goto menu;
	}
	else
	{	
		printf("\nInvalid input. Try again.\n");
		goto settings;
	}

	killProgram:

	printf("\nThank you for playing my Random Number Guesser game! Hope to see you next time!");
  return 0;
}