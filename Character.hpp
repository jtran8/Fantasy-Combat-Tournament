/*******************************************************************************
** Author:       Jacky Tran
** Date:         05/27/2019
** Description:  Abstract Character base class specification file. Holds the
**               characters stats and has get functions and virtual functions
**               to be overwritten.
*******************************************************************************/

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <string>

class Character
{
	protected:
		std::string type;
		std::string name;
		int attack;
		int defense;
		int armor;
		int strength;
		int damage;

	public:
		Character();
		virtual ~Character();
		int getArmor();
		int getStrength();
		std::string getType();
		std::string getName();
		void setName(std::string);
		virtual int attackRoll() = 0;
		virtual int defenseRoll() = 0;
		virtual int damageCalc(int) = 0;
		virtual void recover() = 0;
		virtual void printInfo() = 0;
};
#endif