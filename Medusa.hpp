/*******************************************************************************
** Author:       Jacky Tran
** Date:         05/27/2019
** Description:  Medusa class specification file. Derived from the Character
**               class.
*******************************************************************************/

#ifndef MEDUSA_HPP
#define MEDUSA_HPP

#include "Character.hpp"

class Medusa : public Character
{
	public:
		Medusa();
		~Medusa();
		int attackRoll();
		int defenseRoll();
		int damageCalc(int);
		void recover();
		void printInfo();
};
#endif