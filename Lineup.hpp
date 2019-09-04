/*******************************************************************************
** Author:       Jacky Tran
** Date:         05/27/2019
** Description:  Lineup (queue) class specification file. Has functions for
**               adding, removing, and printing nodes.
*******************************************************************************/

#ifndef LINEUP_HPP
#define LINEUP_HPP

#include "Character.hpp"

class Lineup
{
	private:
		struct QueueNode
		{
			QueueNode* next;
			QueueNode* prev;
			Character* fighter;
			QueueNode(Character* newFighter)
			{
				fighter = newFighter;
				next = nullptr;
				prev = nullptr;
			}
		};
		QueueNode* head;

	public:
		Lineup();
		~Lineup();
		bool isEmpty();
		void addBack(Character*);
		void moveBack();
		Character* getFront();
		void removeFront();
		void printLineup();
};
#endif