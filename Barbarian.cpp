/*******************************************************************************
** Author:       Jacky Tran
** Date:         05/27/2019
** Description:  Barbarian class implementation file. Derived from the Character
**               class.
*******************************************************************************/

#include <iostream>
#include <cstdlib>
#include "Barbarian.hpp"
#include "globalConstants.hpp"

/*******************************************************************************
** Default constructor
** Initializes the data members with the type name and appropriate global
** constants.
*******************************************************************************/
Barbarian::Barbarian()
{
	type = "Barbarian";
	armor = BARB_ARMOR;
	strength = BARB_SP;
}

/*******************************************************************************
** Destructor
*******************************************************************************/
Barbarian::~Barbarian()
{

}

/*******************************************************************************
** attackRoll function
** Uses the random number function to generate the attack power. Displays and
** returns the attack power.
*******************************************************************************/
int Barbarian::attackRoll()
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
int Barbarian::defenseRoll()
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
*******************************************************************************/
int Barbarian::damageCalc(int attack)
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
void Barbarian::recover()
{
	if (strength < BARB_SP)
	{
		strength += BARB_SP / 4;
	}

	if (strength > BARB_SP)
	{
		strength = BARB_SP;
	}
}

/*******************************************************************************
** printInfo function
** Displays the description and special ability of the type.
*******************************************************************************/
void Barbarian::printInfo()
{
	std::cout << "Description:\n";
	std::cout << BARB_CHAR << std::endl << std::endl;
	std::cout << "Special Ability:\n";
	std::cout << BARB_SPEC << std::endl;
}