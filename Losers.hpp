/*******************************************************************************
** Author:       Jacky Tran
** Date:         05/27/2019
** Description:  Losers (stack) class specification file. Has functions for
**               adding, removing, and printing nodes.
*******************************************************************************/

#ifndef LOSERS_HPP
#define LOSERS_HPP

#include "Character.hpp"

class Losers
{
	protected:
		struct StackNode
		{
			StackNode* next;
			Character* fighter;
			StackNode(Character* newFighter) 
			{ 
				fighter = newFighter; 
				next = nullptr; 
			}
		};
		StackNode* head;

	public:
		Losers();
		~Losers();
		bool isEmpty();
		void addHead(Character*);
		void printLosers();
};
#endif