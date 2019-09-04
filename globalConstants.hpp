/*******************************************************************************
** Author:       Jacky Tran
** Date:         05/27/2019
** Description:  Global constant variables that are used in Fantasy Combat
**               Tournament.
*******************************************************************************/

#include <string>

#ifndef GLOBAL_CONSTANTS_HPP
#define GLOBAL_CONSTANTS_HPP

// Character attack values
const int VAMP_NUM_ATK_DIE = 1;
const int VAMP_ATK_DIE_SIZE = 12;
const int BARB_NUM_ATK_DIE = 2;
const int BARB_ATK_DIE_SIZE = 6;
const int BLUE_NUM_ATK_DIE = 2;
const int BLUE_ATK_DIE_SIZE = 10;
const int MEDUSA_NUM_ATK_DIE = 2;
const int MEDUSA_ATK_DIE_SIZE = 6;
const int HARRY_NUM_ATK_DIE = 2;
const int HARRY_ATK_DIE_SIZE = 6;

// Character defense values
const int VAMP_NUM_DEF_DIE = 1;
const int VAMP_DEF_DIE_SIZE = 6;
const int BARB_NUM_DEF_DIE = 2;
const int BARB_DEF_DIE_SIZE = 6;
const int BLUE_NUM_DEF_DIE = 3;
const int BLUE_DEF_DIE_SIZE = 6;
const int MEDUSA_NUM_DEF_DIE = 1;
const int MEDUSA_DEF_DIE_SIZE = 6;
const int HARRY_NUM_DEF_DIE = 2;
const int HARRY_DEF_DIE_SIZE = 6;

// Character armor values
const int VAMP_ARMOR = 1;
const int BARB_ARMOR = 0;
const int BLUE_ARMOR = 3;
const int MEDUSA_ARMOR = 3;
const int HARRY_ARMOR = 0;

// Character strengh point values
const int VAMP_SP = 18;
const int BARB_SP = 12;
const int BLUE_SP = 12;
const int MEDUSA_SP = 8;
const int HARRY_SP = 10;

// Character characteristics
const std::string VAMP_CHAR = "Suave, debonair, but viciousand surprisingly resilient.";
const std::string BARB_CHAR = "Think Conan or Hercules from the movies.Big sword, big muscles, bare torso.";
const std::string BLUE_CHAR = "They are small, 6 inch tall, but fast and tough. They are hard to hit so they can take some damage. They can also do a LOT of damage when they crawl inside enemies’ armor or clothing.";
const std::string MEDUSA_CHAR = "Scrawny lady with snakes for hair which helps her during combat. Just don’t look at her!";
const std::string HARRY_CHAR = "Harry Potter is a wizard.";

// Character special ability descriptions
const std::string VAMP_SPEC = "Charm - Vampires can charm an opponent into not attacking. For a given attack there is a 50% chance that their opponent does not actually attack them.";
const std::string BARB_SPEC = "No special ability.";
const std::string BLUE_SPEC = "Mob: Blue Men are actually a swarm of small individuals. For every 4 points of damage, they lose one defense die.";
const std::string MEDUSA_SPEC = "Glare - If a Medusa rolls a 12 when attacking then the target instantly gets turned into stone and Medusa wins!";
const std::string HARRY_SPEC = "Hogwarts - If Harry Potter's strength reaches 0 or below, he immediately recovers and his total strength becomes 20. If he were to die again, then he’s dead.";

#endif