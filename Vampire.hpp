/*******************************************************************************
** Author:       Jacky Tran
** Date:         05/27/2019
** Description:  Vampire class specification file. Derived from the Character
**               class.
*******************************************************************************/

#ifndef VAMPIRE_HPP
#define VAMPIRE_HPP

#include "Character.hpp"

class Vampire : public Character
{
	public:
		Vampire();
		~Vampire();
		int attackRoll();
		int defenseRoll();
		int damageCalc(int);
		void recover();
		void printInfo();
};
#endif