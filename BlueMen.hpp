/*******************************************************************************
** Author:       Jacky Tran
** Date:         05/27/2019
** Description:  BlueMen class specification file. Derived from the Character
**               class.
*******************************************************************************/

#ifndef BLUEMEN_HPP
#define BLUEMEN_HPP

#include "Character.hpp"

class BlueMen : public Character
{
	public:
		BlueMen();
		~BlueMen();
		int attackRoll();
		int defenseRoll();
		int damageCalc(int);
		void recover();
		void printInfo();
};
#endif