/*******************************************************************************
** Author:       Jacky Tran
** Date:         05/27/2019
** Description:  BlueMen class implementation file. Derived from the Character
**               class.
*******************************************************************************/

#include <iostream>
#include <cstdlib>
#include "BlueMen.hpp"
#include "globalConstants.hpp"

/*******************************************************************************
** Default constructor
** Initializes the data members with the type name and appropriate global
** constants.
*******************************************************************************/
BlueMen::BlueMen()
{
	type = "Blue Men";
	armor = BLUE_ARMOR;
	strength = BLUE_SP;
}

/*******************************************************************************
** Destructor
*******************************************************************************/
BlueMen::~BlueMen()
{

}

/*******************************************************************************
** attackRoll function
** Uses the random number function to generate the attack power. Displays and
** returns the attack power.
*******************************************************************************/
int BlueMen::attackRoll()
{
	int die1 = rand() % 10 + 1;
	int die2 = rand() % 10 + 1;
	attack = die1 + die2;

	std::cout << "Attack power is " << attack << ".\n";

	return attack;
}

/*******************************************************************************
** defenseRoll function
** Uses the random number function to generate the defense power. Displays and
** returns the defense power. Decreases the number of die used to generate
** the defense power in accordance with the special ability.
*******************************************************************************/

int BlueMen::defenseRoll()
{
	if (strength > 8)
	{
		int die1 = rand() % 6 + 1;
		int die2 = rand() % 6 + 1;
		int die3 = rand() % 6 + 1;
		defense = die1 + die2 + die3;
	}
	else if (strength > 4 && strength <= 8)
	{
		int die1 = rand() % 6 + 1;
		int die2 = rand() % 6 + 1;
		defense = die1 + die2;
	}
	else
	{
		int die1 = rand() % 6 + 1;
		defense = die1;
	}
	std::cout << "Defense power is " << defense << ".\n";

	return defense;
}

/*******************************************************************************
** damageCalc function
** Calculates the damage of an attack by subtracting defense and armor values.
*******************************************************************************/
int BlueMen::damageCalc(int attack)
{
	std::cout << "           Damage = " << attack << " - " << defense << " - " << armor << std::endl;

	damage = attack - defense - armor;

	if (damage < 0) // To prevent negative damage numbers
	{
		damage = 0;
	}

	strength -= damage;

	if (strength < 0) // To prevent negative strength numbers
	{
		strength = 0;
	}

	return damage;
}
/*******************************************************************************
** recover function
** Recovers 25% of the max character strength. Does not allow strength to
** exceed starting default starting amount.
*******************************************************************************/
void BlueMen::recover()
{
	if (strength < BLUE_SP)
	{
		strength += BLUE_SP / 4;
	}

	if (strength > BLUE_SP)
	{
		strength = BLUE_SP;
	}
}

/*******************************************************************************
** printInfo function
** Displays the description and special ability of the type.
*******************************************************************************/
void BlueMen::printInfo()
{
	std::cout << "Description:\n";
	std::cout << BLUE_CHAR << std::endl << std::endl;
	std::cout << "Special Ability:\n";
	std::cout << BLUE_SPEC << std::endl;
}