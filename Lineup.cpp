/*******************************************************************************
** Author:       Jacky Tran
** Date:         05/27/2019
** Description:  Lineup (queue) class specification file. Has functions for
**               adding, removing, and printing nodes.
*******************************************************************************/

#include <iostream>
#include "Lineup.hpp"

/*******************************************************************************
** Default constructor
** Initializes the data members.
*******************************************************************************/
Lineup::Lineup()
{
	head = nullptr;
}

/*******************************************************************************
** Destructor
** Frees the dynamically allocated data.
*******************************************************************************/
Lineup::~Lineup()
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
			QueueNode* temp = head;
			head = head->next;
			head->prev = temp->prev;
			head->prev->next = head;
			delete temp->fighter;
			delete temp;
			temp = nullptr;
		}
	}
}

/*******************************************************************************
** isEmpty function
** Checks if the queue is empty. If so, returns true; otherwise, returns false.
*******************************************************************************/
bool Lineup::isEmpty()
{
	if (head == nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}

/*******************************************************************************
** addBack function
** Creates a QueueNode with user-inputted info, and appends it to the back of 
** the queue.
*******************************************************************************/
void Lineup::addBack(Character* fighter)
{
	QueueNode* newNode = new QueueNode(fighter);

	if (isEmpty())
	{
		newNode->prev = newNode->next = newNode;
		head = newNode;
	}
	else
	{
		newNode->prev = head->prev;
		newNode->next = head;
		head->prev->next = newNode;
		head->prev = newNode;
	}
}

/*******************************************************************************
** moveBack function
** Move the head QueueNode to the back of the queue.
*******************************************************************************/
void Lineup::moveBack()
{
	this->head = this->head->next;
}

/*******************************************************************************
** getFront function
** Returns the value of the node at the front of the queue.
*******************************************************************************/
Character* Lineup::getFront()
{
	return head->fighter;
}

/*******************************************************************************
** removeFront function
** Removes the front QueueNode of the queue and free the memory.
*******************************************************************************/
void Lineup::removeFront()
{
	if (isEmpty())
	{
		return;
	}

	if (head->next == head)
	{
		delete head;
		head = nullptr;
	}
	else
	{
		QueueNode* temp = head;
		head = head->next;
		head->prev = temp->prev;
		head->prev->next = head;
		delete temp;
		temp = nullptr;
	}
}

/*******************************************************************************
** printQueue function
** Traverses through the queue from head using next pointers, and prints the
** values of each QueueNode in the queue.
*******************************************************************************/
void Lineup::printLineup()
{
	QueueNode* temp = head;

	do
	{
		std::cout << temp->fighter->getName() << " ";
		temp = temp->next;
	} while (temp != head);
	
	std::cout << std::endl;
}