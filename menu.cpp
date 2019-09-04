/*******************************************************************************
** Author:       Jacky Tran
** Date:         05/27/2019
** Description:  Functions for the user choices.
*******************************************************************************/

#include <iostream>
#include "menu.hpp"
#include "inputCheck.hpp"
#include "globalConstants.hpp"

/*******************************************************************************
** startMenu function
** Displays starting menu options, prompts user for input and validates input
** by calling the intCheck function.
*******************************************************************************/
int startMenu()
{
	int start = 0;

	std::cout << "\n1. Play\n";
	std::cout << "2. Exit\n";

	start = intCheck(1, 2);

	if (start == 2)
	{
		std::cout << "\nQuitting...Goodbye.\n";
	}

	return start;
}

/*******************************************************************************
** fighterSelect function
** Displays and prompts user for fighter choice. Validates input by calling the
** intCheck function.
*******************************************************************************/
int fighterSelect()
{
	int fighter = 0;

	std::cout << "1. Vampire\n";
	std::cout << "2. Barbarian\n";
	std::cout << "3. Blue Men\n";
	std::cout << "4. Medusa\n";
	std::cout << "5. Harry Potter\n";

	fighter = intCheck(1, 5);

	return fighter;
}

/*******************************************************************************
** losers function
** Displays starting menu options, prompts user for input and validates input
** by calling the intCheck function.
*******************************************************************************/
int losers()
{
	int choice = 0;

	std::cout << "1. Yes\n";
	std::cout << "2. No\n";

	choice = intCheck(1, 2);

	return choice;
}

/*******************************************************************************
** playAgain function
** Displays menu options, prompts user for input by calling another function
** and returns the valid input or takes an appropriate action.
*******************************************************************************/
int playAgain()
{
	int again = 2;

	std::cout << "\nDo you want to play again?\n";
	std::cout << "0. Quit\n";
	std::cout << "1. Play Again\n";

	again = intCheck(0, 1);

	if (again == 0)
	{
		std::cout << "\nQuitting...goodbye.\n";
	}

	return again;
}