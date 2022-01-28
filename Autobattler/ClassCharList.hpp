/***********************************************************************
 * Class:	CharacterList
 * Author:	Lucas Moyle
 * Date:	11/19/2019
 * Descrip:	CharacterList is a queue-like circularly double linked
 * 			list of CharacterContainers (which contain index pointers
 * 			and a Character pointer. It contains all functions
 * 			necessary to manipulate the list as needed for the
 * 			fantasy tournament game.
 **********************************************************************/


#ifndef CLASSCHARLIST_HPP
#define CLASSCHARLIST_HPP


#include "StructCharCont.hpp"
#include "ClassCharacter.hpp"

class CharacterList
{
	protected:
	
		CharacterContainer* head;		


	public:

/* CharacterList()
 *
 * Summary: Simple constructor function that instantiates the lists
 * 			head pointer to null which will be changed later when
 * 			containers are added.
 * Param:	N/A
 * Returns:	N/A
 */
		CharacterList();


/* ~CharacterList()
 *
 * Summary: Destructor function that delets all dynamically allocated
 * 			memory from the list and its containers. Works by
 * 			repeatedly deleting the head until the list is empty.
 * Param:	N/A
 * Returns: N/A
 */
		~CharacterList();


/* bool isEmpty()
 *
 * Summary: Checks if the current list has any containers in it.
 * Param:	N/A
 * Returns: True if the list has no containers, false if it has at least
 * 			one.
 */
		bool isEmpty();


/* addFront(Character*)
 *
 * Summary:	Adds a new character container to the front of the list.
 * 			Dynamically allocates memory for the container and modifies
 * 			necessary index pointers.
 * Param:	Pointer to a character object which will become the
 * 			contents of the new container in the list.
 * Returns: N/A
 */
		void addFront(Character*);


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
		void addBack(Character*);


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
		void removeFront();


/* incrementHead()
 *
 * Summary: Moves the head pointer to point and the next elment in the
 * 			list, making it the new head. This effectively puts the
 * 			current head container at the back of the list.
 * Param:	N/A
 * Returns:	N/A
 */
		void incrementHead();


/* printList()
 *
 * Summary:	Outputs the list elements to the terminal in the order
 * 			head to last element or, if the list is empty, an error
 * 			message.
 * Param:	N/A
 * Returns: N/A
 */
		void printList();


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
		CharacterContainer* getHead();

};

#endif
