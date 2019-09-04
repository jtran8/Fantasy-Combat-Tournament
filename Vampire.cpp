/*******************************************************************************
** Author:       Jacky Tran
** Date:         05/27/2019
** Description:  Vampire class implementation file. Derived from the Character
**               class.
*******************************************************************************/

#include <iostream>
#include <cstdlib>
#include "Vampire.hpp"
#include "globalConstants.hpp"

/*******************************************************************************
** Default constructor
** Initializes the data members with the type name and appropriate global
** constants.
*******************************************************************************/
Vampire::Vampire()
{
	type = "Vampire";
	armor = VAMP_ARMOR;
	strength = VAMP_SP;
}

/*******************************************************************************
** Destructor
*******************************************************************************/
Vampire::~Vampire()
{

}

/*******************************************************************************
** attackRoll function
** Uses the random number function to generate the attack power. Displays and
** returns the attack power.
*******************************************************************************/
int Vampire::attackRoll()
{
	attack = rand() % 12 + 1;

	std::cout << "Attack power is " << attack << ".\n";

	return attack;
}

/*******************************************************************************
** defenseRoll function
** Uses the random number function to generate the defense power. Displays and
** returns the defense power.
*******************************************************************************/
int Vampire::defenseRoll()
{
	defense = rand() % 6 + 1;

	std::cout << "Defense power is " << defense << ".\n";

	return defense;
}

/*******************************************************************************
** damageCalc function
** Calculates the damage of an attack by subtracting defense and armor values.
** Uses the random number function to decide if the special ability is
** activated (50% odds).
*******************************************************************************/
int Vampire::damageCalc(int attack)
{
	int chance = rand() % 2 + 1;

	if (chance == 2)
	{
		std::cout << "           Special ability Charm activated!\n";
		std::cout << "           Vampire's Charm negated the attack!\n";
		damage = 0;

		return damage;
	}

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
void Vampire::recover()
{
	if (strength < VAMP_SP)
	{
		strength += VAMP_SP / 4;
	}

	if (strength > VAMP_SP)
	{
		strength = VAMP_SP;
	}
}

/*******************************************************************************
** printInfo function
** Displays the description and special ability of the type.
*******************************************************************************/
void Vampire::printInfo()
{
	std::cout << "Description:\n";
	std::cout << VAMP_CHAR << std::endl << std::endl;
	std::cout << "Special Ability:\n";
	std::cout << VAMP_SPEC << std::endl;
}