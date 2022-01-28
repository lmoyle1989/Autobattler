/***********************************************************************
 * Title:	CharacterContainer
 * Author:	Lucas Moyle
 * Date:	11/24/2019
 * Descrip: Header file for the container object that makes up our 
 * 			character lists. Contains index pointer and a pointer to a 
 * 			character object.
 **********************************************************************/

#include "ClassCharacter.hpp"
#include "StructCharCont.hpp"

/* CharacterContainer(Character*)
 *
 * Summary: Constructor function that takes the a pointer to the
 * 			character object that will become what is containerized.a
 * 			Also instantiates index pointers to null.
 * Param:	A character class pointer that will become charPtr.
 * Returns:	N/A
 */
CharacterContainer::CharacterContainer(Character* charIn)
{
	next = nullptr;
	prev = nullptr;

	charPtr = charIn;
}
