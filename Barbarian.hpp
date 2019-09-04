/*******************************************************************************
** Author:       Jacky Tran
** Date:         05/27/2019
** Description:  Barbarian class specification file. Derived from the Character
**               class.
*******************************************************************************/

#ifndef BARBARIAN_HPP
#define BARBARIAN_HPP

#include "Character.hpp"

class Barbarian : public Character
{
	public:
		Barbarian();
		~Barbarian();
		int attackRoll();
		int defenseRoll();
		int damageCalc(int);
		void recover();
		void printInfo();
};
#endif