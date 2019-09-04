/*******************************************************************************
** Author:       Jacky Tran
** Date:         05/27/2019
** Description:  HarryPotter class specification file. Derived from the
**               Character class.
*******************************************************************************/

#ifndef HARRYPOTTER_HPP
#define HARRYPOTTER_HPP

#include "Character.hpp"

class HarryPotter : public Character
{
	private:
		int lives;

	public:
		HarryPotter();
		~HarryPotter();
		int attackRoll();
		int defenseRoll();
		int damageCalc(int);
		void recover();
		void printInfo();
};
#endif