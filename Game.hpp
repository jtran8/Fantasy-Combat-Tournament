/*******************************************************************************
** Author:       Jacky Tran
** Date:         05/27/2019
** Description:  Game class specification file. This class handles the gameplay.
**               Has data members required for running the game and member
**               functions that handle each step of the gameplay loop.
*******************************************************************************/

#ifndef GAME_HPP
#define GAME_HPP

#include "Character.hpp"
#include "Lineup.hpp"
#include "Losers.hpp"

class Game
{
	private:
		Lineup* lineup1;
		Lineup* lineup2;
		Losers* loser;
		int lineup1Score;
		int lineup2Score;
		int lineup1num;
		int lineup2num;
		int round;
		int attacker;
		int attackValue;
		int defenseValue;
		int damage;
		bool dead;

	public:
		Game();
		~Game();
		void play();
		void setup();
		Character* setLineup();
		void preCombatInfo();
		void combatRoll();
		void applyDamage();
		void strengthUpdateDisplay();
		void finalDisplay();
};
#endif