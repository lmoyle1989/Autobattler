/***********************************************************************
 * Title:	CharacterContainer
 * Author:	Lucas Moyle
 * Date:	11/24/2019
 * Descrip: Header file for the container object that makes up our 
 * 			character lists. Contains index pointer and a pointer to a 
 * 			character object.
 **********************************************************************/

#ifndef STRUCTCHARCONT_HPP
#define STRUCTCHARCONT_HPP

#include "ClassCharacter.hpp"

struct CharacterContainer
{
	CharacterContainer* next;
	CharacterContainer* prev;

	Character* charPtr;

/* CharacterContainer(Character*)
 *
 * Summary: Constructor function that takes the a pointer to the
 * 			character object that will become what is containerized.
 * Param:	A character class pointer that will become charPtr.
 * Returns:	N/A
 */
	CharacterContainer(Character*);
};

#endif
