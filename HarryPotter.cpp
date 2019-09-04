/*******************************************************************************
** Author:       Jacky Tran
** Date:         05/27/2019
** Description:  HarryPotter class implementation file. Derived from the
**               Character class.
*******************************************************************************/

#include <iostream>
#include <cstdlib>
#include "HarryPotter.hpp"
#include "globalConstants.hpp"

/*******************************************************************************
** Default constructor
** Initializes the data members with the type name and appropriate global
** constants.
*******************************************************************************/
HarryPotter::HarryPotter()
{
	type = "Harry Potter";
	armor = HARRY_ARMOR;
	strength = HARRY_SP;
	lives = 2;
}

/*******************************************************************************
** Destructor
*******************************************************************************/
HarryPotter::~HarryPotter()
{

}

/*******************************************************************************
** attackRoll function
** Uses the random number function to generate the attack power. Displays and
** returns the attack power.
*******************************************************************************/
int HarryPotter::attackRoll()
{
	int die1 = rand() % 6 + 1;
	int die2 = rand() % 6 + 1;
	attack = die1 + die2;

	std::cout << "Attack power is " << attack << ".\n";

	return attack;
}

/*******************************************************************************
** defenseRoll function
** Uses the random number function to generate the defense power. Displays and
** returns the defense power.
*******************************************************************************/
int HarryPotter::defenseRoll()
{
	int die1 = rand() % 6 + 1;
	int die2 = rand() % 6 + 1;
	defense = die1 + die2;

	std::cout << "Defense power is " << defense << ".\n";

	return defense;
}

/*******************************************************************************
** damageCalc function
** Calculates the damage of an attack by subtracting defense and armor values.
** Revives Harry if he dies and he has a life left.
*******************************************************************************/
int HarryPotter::damageCalc(int attack)
{
	std::cout << "           Damage = " << attack << " - " << defense << " - " << armor << std::endl;

	damage = attack - defense - armor;

	if (damage < 0)
	{
		damage = 0;
	}

	strength -= damage;

	if (strength < 0)
	{
		strength = 0;
	}

	if (strength == 0 && lives == 2)
	{
		strength = 20;
		damage = 0;

		std::cout << "           Special ability Hogwarts activated!\n";
		std::cout << "           Harry Potter died but he revived!\n";

		lives--;
	}

	return damage;
}
/*******************************************************************************
** recover function
** Recovers 25% of the max character strength. Does not allow strength to
** exceed starting default starting amount.
*******************************************************************************/
void HarryPotter::recover()
{
	if (strength < HARRY_SP)
	{
		strength += HARRY_SP / 4;
	}

	if (strength > HARRY_SP)
	{
		strength = HARRY_SP;
	}
}

/*******************************************************************************
** printInfo function
** Displays the description and special ability of the type.
*******************************************************************************/
void HarryPotter::printInfo()
{
	std::cout << "Description:\n";
	std::cout << HARRY_CHAR << std::endl << std::endl;
	std::cout << "Special Ability:\n";
	std::cout << HARRY_SPEC << std::endl;
}