/*******************************************************************************
** Author:       Jacky Tran
** Date:         05/27/2019
** Description:  Losers (stack) class specification file. Has functions for
**               adding, removing, and printing nodes.
*******************************************************************************/

#include <iostream>
#include "Losers.hpp"

/*******************************************************************************
** Default constructor
** Initializes the data members.
*******************************************************************************/
Losers::Losers()
{
	head = nullptr;
}

/*******************************************************************************
** Destructor
*******************************************************************************/
Losers::~Losers()
{
	while (!isEmpty())
	{
		if (head->next == head)
		{
			delete head->fighter;
			delete head;
			head = nullptr;
		}
		else
		{
			StackNode* temp = head;
			head = head->next;
			delete temp->fighter;
			delete temp;
			temp = nullptr;
		}
	}
}

/*******************************************************************************
** isEmpty function
** Checks if the stack is empty. If so, returns true; otherwise, returns false.
*******************************************************************************/
bool Losers::isEmpty()
{
	if (!head)
	{
		return true;
	}
	else
	{
		return false;
	}
}

/*******************************************************************************
** addHead function
** Creates a StackNode with user-inputted info, and appends it to the front of
** the stack.
*******************************************************************************/
void Losers::addHead(Character* fighter)
{
	StackNode* newNode = new StackNode(fighter);
	newNode->next = head;
	head = newNode;
}

/*******************************************************************************
** printLosers function
** Traverses through the stack from top using next pointers, and prints the
** values of each StackNode in the stack.
*******************************************************************************/
void Losers::printLosers()
{
	StackNode* temp = head;

	std::cout << "\nHere are the losers: ";

	do
	{
		std::cout << temp->fighter->getName() << " ";
		temp = temp->next;
	} while (temp);

	std::cout << std::endl;
}
