/*******************************************************************************
** Author:       Jacky Tran
** Date:         05/27/2019
** Description:  Abstract Character base class implementation file. Holds the
**               characters stats and has get functions and virtual functions
**               to be overwritten.
*******************************************************************************/

#include <iostream>
#include "Character.hpp"

/*******************************************************************************
** Default constructor
** Overwritten in child classes as needed.
*******************************************************************************/
Character::Character()
{
	type = name = "Undefined";
	attack = defense = armor = strength = damage = -1;
}

/*******************************************************************************
** Destructor Constructor
** Overwritten in child classes as needed.
*******************************************************************************/
Character::~Character()
{

}

std::string Character::getType()
{
	return type;
}

std::string Character::getName()
{
	return name;
}

void Character::setName(std::string userInput)
{
	name = userInput;
}

int Character::getArmor()
{
	return armor;
}

int Character::getStrength()
{
	return strength;
}