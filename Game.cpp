/*******************************************************************************
** Author:       Jacky Tran
** Date:         05/27/2019
** Description:  Game class implemention file. This class handles the gameplay.
**               Has data members required for running the game and member
**               functions that handle each step of the gameplay loop.
*******************************************************************************/

#include <iostream>
#include <iomanip>
#include <string>
#include "Game.hpp"
#include "menu.hpp"
#include "inputCheck.hpp"
#include "Lineup.hpp"
#include "Losers.hpp"
#include "Vampire.hpp"
#include "Barbarian.hpp"
#include "BlueMen.hpp"
#include "Medusa.hpp"
#include "HarryPotter.hpp"

/*******************************************************************************
** Default constructor
** Initializes the data members.
*******************************************************************************/
Game::Game()
{
	lineup1 = new Lineup;
	lineup2 = new Lineup;
	lineup1Score = lineup2Score = 0;
	loser = new Losers;
	round = 1;
	attacker = 0;
	attackValue = defenseValue = damage = lineup1num = lineup2num = -1;
	dead = false;
}

/*******************************************************************************
** Destructor
** Frees the dynamically allocated data.
*******************************************************************************/
Game::~Game()
{
	delete lineup1;
	delete lineup2;
	delete loser;
	lineup1 = lineup2 = nullptr;
	loser = nullptr;
}

/*******************************************************************************
** play function
** Controls the gameplay loop by calling other member functions and ending the
** game when a lineup has been wiped out.
*******************************************************************************/
void Game::play()
{
	do 
	{
		// First attacker is choosen at random
		attacker = rand() % 2 + 1;

		std::cout << "\nRound " << round << std::endl;
		std::cout << "--------------------------------------------\n\n";
		std::cout << "Lineup 1 - " << lineup1->getFront()->getName() << " vs ";
		std::cout << "Lineup 2 - " << lineup2->getFront()->getName() << ".\n";

			while (lineup1->getFront()->getStrength() > 0 && lineup2->getFront()->getStrength() > 0)
			{

				preCombatInfo();
				combatRoll();
				applyDamage();
				strengthUpdateDisplay();

				if (attacker == 1)
				{
					attacker = 2;
				}
				else
				{
					attacker = 1;
				}

				if (lineup1->getFront()->getStrength() > 0 && lineup2->getFront()->getStrength() > 0)
				{
					preCombatInfo();
					combatRoll();
					applyDamage();
					strengthUpdateDisplay();
				}
			}

		// Lineup 2 fighter wins
		if (lineup1->getFront()->getStrength() == 0)
		{
			std::cout << "\nRound " << round << " - Lineup 1: " << lineup1->getFront()->getName() << " vs ";
			std::cout << "Lineup 2: " << lineup2->getFront()->getName() << " - ";
			std::cout << lineup2->getFront()->getName() << " wins!\n";

			loser->addHead(lineup1->getFront()); // Send dead fighter to loser stack
			lineup1->removeFront();
			lineup2->getFront()->recover(); // Winning fighter partially recovers health
			lineup2->moveBack(); // Winning fighter sent to back of queue

			lineup2Score++;
			lineup1num--;
		}
		// Lineup 1 fighter wins
		else if (lineup2->getFront()->getStrength() == 0)
		{
			std::cout << "\nRound " << round << " - Lineup 1: " << lineup1->getFront()->getName() << " vs ";
			std::cout << "Lineup 2: " << lineup2->getFront()->getName() << " - ";
			std::cout << lineup1->getFront()->getName() << " wins!\n";

			loser->addHead(lineup2->getFront());
			lineup2->removeFront();
			lineup1->getFront()->recover();
			lineup1->moveBack();

			lineup1Score++;
			lineup2num--;
		}
		// Tie
		else
		{
			std::cout << "\nRound " << round << " - Lineup 1: " << lineup1->getFront()->getName() << " vs ";
			std::cout << "Lineup 2: " << lineup2->getFront()->getName() << " - ";
			std::cout << " Double K.O.!\n";

			loser->addHead(lineup1->getFront());
			loser->addHead(lineup2->getFront());
			lineup1->removeFront();
			lineup2->removeFront();

			lineup1Score++;
			lineup2Score++;
			lineup1num--;
			lineup2num--;
		}

		round++;
	} while (lineup1num > 0 && lineup2num > 0);

	finalDisplay();
}

/*******************************************************************************
** setup function
** Calls a menu function to prompt the user for number of fighters in both
** lineups. Then asks user to select the fighters and adds them to their 
** respective queue.
*******************************************************************************/
void Game::setup()
{
	std::cout << "\nHow many fighters will each lineup have? (1 - 5):\n";
	int numLineup = intCheck(1, 5);

	lineup1num = lineup2num = numLineup;

	std::cout << "\nLineup 1 Selection\n";
	
	for (int i = 0; i < numLineup; i++)
	{
		std::cout << "\nSelect fighter #" << (i + 1) << ":\n";
		lineup1->addBack(setLineup());
	}

	std::cout << "\nLineup 2 Selection\n";

	for (int i = 0; i < numLineup; i++)
	{
		std::cout << "\nSelect fighter #" << (i + 1) << ":\n";
		lineup2->addBack(setLineup());
	}

	std::cout << "\nLineup 1: ";
	lineup1->printLineup();

	std::cout << "\nLineup 2: ";
	lineup2->printLineup();

	std::cout << "\nEach kill earns the fighter's lineup 1 point.\n";
	std::cout << "\nFight!\n";
}

/*******************************************************************************
** setLineup function
** Function that dynamically allocates memory for each selected fighter and
** prompts the user for a name.
*******************************************************************************/
Character* Game::setLineup()
{
	Character* fighter = nullptr;
	std::string fighterName;

	switch (fighterSelect())
	{
		case 1:
		{
			fighter = new Vampire();

			std::cout << "Choose a name for the Vampire: \n";
			std::getline(std::cin, fighterName);
			fighter->setName(fighterName);

			break;
		}
			case 2:
		{
			fighter = new Barbarian();

			std::cout << "Choose a name for the Barbarian: \n";
			std::getline(std::cin, fighterName);
			fighter->setName(fighterName);

			break;
		}
			case 3:
		{
			fighter = new BlueMen();

			std::cout << "Choose a name for the BlueMen: \n";
			std::getline(std::cin, fighterName);
			fighter->setName(fighterName);

			break;
		}
			case 4:
		{
			fighter = new Medusa();

			std::cout << "Choose a name for this Medusa clone: \n";
			std::getline(std::cin, fighterName);
			fighter->setName(fighterName);

			break;
		}
			case 5:
		{
			fighter = new HarryPotter();

			std::cout << "Choose a name for this Harry Potter clone: \n";
			std::getline(std::cin, fighterName);
			fighter->setName(fighterName);
		}
	}

	return fighter;
}

/*******************************************************************************
** preCombatInfo function
** Displays the attacking and defending fighters and the defending fighters
** stats before combat.
*******************************************************************************/
void Game::preCombatInfo()
{
	if (attacker == 1)
	{
		std::cout << "Lineup 1 - " << lineup1->getFront()->getName() << " attacks.\n";
		std::cout << "Lineup 2 - " << lineup2->getFront()->getName() << " defends.\n";
		std::cout << "Lineup 2 - " << lineup2->getFront()->getName() << " has ";
		std::cout << lineup2->getFront()->getArmor() << " armor";
		std::cout << " and " << lineup2->getFront()->getStrength() << " strength points.\n";
	}
	else
	{
		std::cout << "Lineup 2 - " << lineup2->getFront()->getName() << " attacks.\n";
		std::cout << "Lineup 1 - " << lineup1->getFront()->getName() << " defends.\n";
		std::cout << "Lineup 1 - " << lineup1->getFront()->getName() << " has "; 
		std::cout << lineup1->getFront()->getArmor() << " armor";
		std::cout << " and " << lineup1->getFront()->getStrength() << " strength points.\n";
	}
}

/*******************************************************************************
** combatRoll function
** Makes calls to the fighters' member functions to get and display attack and
** defense values.
*******************************************************************************/
void Game::combatRoll()
{
	if (attacker == 1)
	{
		std::cout << "Lineup 1 - " << lineup1->getFront()->getName() << " attack dice is rolled. ";
		attackValue = lineup1->getFront()->attackRoll();

		std::cout << "Lineup 2 - " << lineup2->getFront()->getName() << " defense dice is rolled. ";
		defenseValue = lineup2->getFront()->defenseRoll();
	}
	else
	{
		std::cout << "Lineup 2 - " << lineup2->getFront()->getName() << " attack dice is rolled. ";
		attackValue = lineup2->getFront()->attackRoll();

		std::cout << "Lineup 1 - " << lineup1->getFront()->getName() << " defense dice is rolled. ";
		defenseValue = lineup1->getFront()->defenseRoll();
	}
}

/*******************************************************************************
** applyDamage function
** Makes calls to the fighters' member functions to calculate and apply damage.
** Displays the amount of damage.
*******************************************************************************/
void Game::applyDamage()
{
	if (attacker == 1)
	{
		damage = lineup2->getFront()->damageCalc(attackValue);
		std::cout << "Lineup 2 - " << lineup2->getFront()->getName() << " takes " << damage << " damage.\n";
	}
	else
	{
		damage = lineup1->getFront()->damageCalc(attackValue);
		std::cout << "Lineup 1 - " << lineup1->getFront()->getName() << " takes " << damage << " damage.\n";
	}
}

/*******************************************************************************
** strengthUpdateDisplay function
** Displays the fighers' remaing strength values after combat.
*******************************************************************************/
void Game::strengthUpdateDisplay()
{
	std::cout << "Lineup 1 - " << lineup1->getFront()->getName() << " has "; 
	std::cout << lineup1->getFront()->getStrength() << " strength left.\n";
	std::cout << "Lineup 2 - " << lineup2->getFront()->getName() << " has ";
	std::cout << lineup2->getFront()->getStrength() << " strength left.\n";
}

/*******************************************************************************
** finalDisplay function
** Displays the winning lineup when the game is over and prompts user for
** choice on printing losers stack.
*******************************************************************************/
void Game::finalDisplay()
{
	std::cout << "\nFight Over\n";
	std::cout << "--------------------------------------------\n";
	std::cout << "\nFinal Scores\n";

	if (lineup2Score > lineup1Score)
	{
		std::cout << "\nLineup 1: " << lineup1Score;
		std::cout << "\nLineup 2: " << lineup2Score;
		std::cout << "\nLineup 2 wins!\n";
	}
	else if (lineup1Score > lineup2Score)
	{
		std::cout << "\nLineup 1: " << lineup1Score;
		std::cout << "\nLineup 2: " << lineup2Score;
		std::cout << "\nLineup 1 wins!\n";
	}
	else
	{
		std::cout << "\nLineup 1: " << lineup1Score;
		std::cout << "\nLineup 2: " << lineup2Score;
		std::cout << "\nIt's a tie!\n";
	}

	std::cout << "\nPrint list of losers?\n";
	int choice = losers();

	if (choice == 1)
	{
		loser->printLosers();
	}

}