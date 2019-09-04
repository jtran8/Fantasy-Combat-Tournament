/*******************************************************************************
** Author:       Jacky Tran
** Date:         05/27/2019
** Description:  Medusa class implementation file. Derived from the Character
**               class.
*******************************************************************************/

#include <iostream>
#include <cstdlib>
#include "Medusa.hpp"
#include "globalConstants.hpp"

/*******************************************************************************
** Default constructor
** Initializes the data members with the type name and appropriate global
** constants.
*******************************************************************************/
Medusa::Medusa()
{
	type = "Medusa";
	armor = MEDUSA_ARMOR;
	strength = MEDUSA_SP;
}

/*******************************************************************************
** Destructor
*******************************************************************************/
Medusa::~Medusa()
{

}

/*******************************************************************************
** attackRoll function
** Uses the random number function to generate the attack power. Displays and
** returns the attack power. Also uses the random number function to decide if
** the special ability is activated.
*******************************************************************************/
int Medusa::attackRoll()
{
	int die1 = rand() % 6 + 1;
	int die2 = rand() % 6 + 1;
	attack = die1 + die2;

	if (attack == 12)
	{
		std::cout << "\n           Special ability Glare activated!\n";
		std::cout << "           It's super effective! ";
		attack = 100; // Large number to ensure a kill
	}

	std::cout << "Attack power is " << attack << ".\n";

	return attack;
}

/*******************************************************************************
** defenseRoll function
** Uses the random number function to generate the defense power. Displays and
** returns the defense power.
*******************************************************************************/
int Medusa::defenseRoll()
{
	defense = rand() % 6 + 1;

	std::cout << "Defense power is " << defense << ".\n";

	return defense;
}

/*******************************************************************************
** damageCalc function
** Calculates the damage of an attack by subtracting defense and armor values.
*******************************************************************************/
int Medusa::damageCalc(int attack)
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

	return damage;
}
/*******************************************************************************
** recover function
** Recovers 25% of the max character strength. Does not allow strength to
** exceed starting default starting amount.
*******************************************************************************/
void Medusa::recover()
{
	if (strength < MEDUSA_SP)
	{
		strength += MEDUSA_SP / 4;
	}

	if (strength > MEDUSA_SP)
	{
		strength = MEDUSA_SP;
	}
}

/*******************************************************************************
** printInfo function
** Displays the description and special ability of the type.
*******************************************************************************/
void Medusa::printInfo()
{
	std::cout << "Description:\n";
	std::cout << MEDUSA_CHAR << std::endl << std::endl;
	std::cout << "Special Ability:\n";
	std::cout << MEDUSA_SPEC << std::endl;
}