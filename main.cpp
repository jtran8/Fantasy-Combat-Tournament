/*******************************************************************************
** Program Name: Fantasy Combat Tournament
** Author:       Jacky Tran
** Date:         05/27/2019
** Description:  An expansion of the Fantasy Combat Game. Now the game can be
**               played between two teams of fighters.
*******************************************************************************/

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Game.hpp"
#include "menu.hpp"
#include "inputCheck.hpp"

int main()
{
	if (startMenu() == 2)
	{
		return 0;
	}

	std::cout << "\nWelcome to the Fantasy Combat Tournament!\n";
	std::cout << "--------------------------------------------\n";

	srand(time(NULL));

	do
	{
		Game game;
		game.setup();
		game.play();
	} while (playAgain());

	return 0;
}
