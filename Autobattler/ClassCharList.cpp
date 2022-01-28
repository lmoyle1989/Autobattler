/***********************************************************************
 * Class:	CharacterList
 * Author:	Lucas Moyle
 * Date:	11/24/2019
 * Descrip:	CharacterList is a queue-like circularly double linked
 * 			list of CharacterContainers (which contain index pointers
 * 			and a Character pointer. It contains all functions
 * 			necessary to manipulate the list as needed for the
 * 			fantasy tournament game.
 **********************************************************************/


#include "ClassCharList.hpp"
#include "StructCharCont.hpp"
#include "ClassCharacter.hpp"


/* CharacterList()
 *
 * Summary: Simple constructor function that instantiates the lists
 * 			head pointer to null which will be changed later when
 * 			containers are added.
 * Param:	N/A
 * Returns:	N/A
 */
CharacterList::CharacterList()
{
	head = nullptr;
}


/* ~CharacterList()
 *
 * Summary: Destructor function that delets all dynamically allocated
 * 			memory from the list and its containers. Works by
 * 			repeatedly deleting the head until the list is empty.
 * Param:	N/A
 * Returns: N/A
 */
CharacterList::~CharacterList()
{
	while (!isEmpty())
	{
		//delete container contents
		delete head->charPtr;
		//delete container itself
		removeFront();
	}
}


/* bool isEmpty()
 *
 * Summary: Checks if the current list has any containers in it.
 * Param:	N/A
 * Returns: True if the list has no containers, false if it has at least
 * 			one.
 */
bool CharacterList::isEmpty()
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


/* addFront(Character*)
 *
 * Summary:	Adds a new character container to the front of the list.
 * 			Dynamically allocates memory for the container and modifies
 * 			necessary index pointers.
 * Param:	Pointer to a character object which will become the
 * 			contents of the new container in the list.
 * Returns: N/A
 */
void CharacterList::addFront(Character* charIn)
{
	//empty list case
	if (isEmpty())
	{
		head = new CharacterContainer(charIn);
		head->next = head;
		head->prev = head;
	}
	//list with 1 element
	else if (head->next == head)
	{
		CharacterContainer* newChar = new CharacterContainer(charIn);

		newChar->prev = head;
		newChar->next = head;
		head->next = newChar;
		head->prev = newChar;
		head = newChar;
	}
	//list with 2 or more elements
	else
	{
		CharacterContainer* newChar = new CharacterContainer(charIn);
		
		((head->prev)->next) = newChar;
	   	newChar->prev = head->prev;
		head->prev = newChar;
		newChar->next = head;
		head = newChar;
	}
}


/* addBack(Character*)
 *
 * Summary: Almost identical to addFront however it adds the new
 * 			container to the last element of the list. Only difference
 * 			is that it reassigns the head in such a way that the new
 * 			container is "before" the head as opposed to becoming the
 * 			new head.
 * Param:	N/A
 * Returns: N/A
 */
void CharacterList::addBack(Character* charIn)
{
	//empty list case
	if (isEmpty())
	{
		head = new CharacterContainer(charIn);
		head->next = head;
		head->prev = head;
	}
	//list with 1 element
	else if (head->next == head)
	{
		CharacterContainer* newChar = new CharacterContainer(charIn);

		newChar->prev = head;
		newChar->next = head;
		head->next = newChar;
		head->prev = newChar;
	}
	//list with 2 or more elements
	else
	{
		CharacterContainer* newChar = new CharacterContainer(charIn);
		
		//set the old last node's next pointer to the new node
		((head->prev)->next) = newChar;
		//set the new node's prev pointer to the old last node
	   	newChar->prev = head->prev;
		//set the head's prev pointer to the new node
		head->prev = newChar;
		//set the new node's next pointer to the head
		newChar->next = head;
	}
}


/* removeFront()
 *
 * Summary: Removes the front (head) elements of the list and sets
 * 			the next element to the new head or, if it is the last
 * 			element, sets it to null. Also deletes dynamic memory
 * 			that was created for the container (but does not delete
 * 			the container's content).
 * Param:	N/A
 * Returns: N/A
 */
void CharacterList::removeFront()
{
	if (isEmpty())
	{
		std::cout << "List is empty." << std::endl;
	}
	else if (head->next == head)
	{		
		delete head;
		head = nullptr;	
	}
	else
	{
		//store the current head's memory location in a pointer so we
		//can delete it after we set the new head
		CharacterContainer* deletePtr = head;
		
		//set the new head's prev pointer to the last node
		((head->next)->prev) = head->prev;
		//set the last node's next pointer to the new head
		((head->prev)->next) = head->next;
		//set the new head
		head = head->next;
		
		//delete the old head
		delete deletePtr;
	}
}


/* incrementHead()
 *
 * Summary: Moves the head pointer to point and the next elment in the
 * 			list, making it the new head. This effectively puts the
 * 			current head container at the back of the list.
 * Param:	N/A
 * Returns:	N/A
 */
void CharacterList::incrementHead()
{
	head = head->next;
}


/* printList()
 *
 * Summary:	Outputs the list elements to the terminal in the order
 * 			head to last element or, if the list is empty, an error
 * 			message.
 * Param:	N/A
 * Returns: N/A
 */
void CharacterList::printList()
{
	//case where list is empty
	if (isEmpty())
	{
		std::cout << "List is empty." << std::endl;
	}
	//case where list has only 1 element
	else if (head->next == head)
	{
		std::cout << (head->charPtr)->getName() << " - " << (head->charPtr)->getCharacterType();
		std::cout << std::endl;
	}
	//case where list has 2 or more elements
	else
	{
		CharacterContainer* printPtr = head;
		
		do
		{
			std::cout << (printPtr->charPtr)->getName() << " - " << (printPtr->charPtr)->getCharacterType();
			std::cout << std::endl;
			printPtr = printPtr->next;
		}
		while(printPtr != head);

		std::cout << std::endl;	
	}
}


/* CharacterContainer* getHead()
 *
 * Summary: Simple get function that returns a the head pointer that
 * 			would otherwise be private. Does not need to take into
 * 			account an empty list because it will never be called
 * 			on an empty list.
 * Param:	N/A
 * Returns: A pointer to the current CharacterContainer at the head
 * 			of the current list.
 */
CharacterContainer* CharacterList::getHead()
{
	return head;
}
