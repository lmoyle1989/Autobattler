/***********************************************************************
 * Class Name:	Barbarian
 * Author:		Lucas Moyle
 * Date:		11/10/2019
 * Description:	This is the header file for the object class 
 * 				Barbarian. Barbarian is derived class from the base
 * 				class Character. Barbarian has no new additional
 * 				member variables and its only functions are a 
 * 				constructor and the attack & defend functions which
 * 				are overwritten from the base class. Since Barbarian
 * 				has no special abilities, this class' attack and defend
 * 				functions serve as the base for the other derived 
 * 				classes which modify each according to their special 
 * 				abilities.
 **********************************************************************/


#ifndef CLASSBARB_HPP
#define CLASSBARB_HPP


#include "ClassCharacter.hpp"

class Barbarian : public Character
{

	private:

	public:
		
/* Barbarian()
 *
 * Summary:	The constructor function for the class Barbarian. Sets
 * 			all member variables that are inherited from the Character
 * 			base class to the values that are unique to the Barbarian.
 * Param:	N/A
 * Returns:	N/A
 */
		Barbarian();
		
		
/* virtual int attack()
 *
 * Summary: The function that represents the character attacking
 * 			another character. Calculates the amount of raw damage
 * 			that will be dealt by rolling dice according to the
 * 			Barbarian type description. This attack function is the
 * 			most "vanilla" amongst the derived classes of this program
 * 			because Barbarian has no special abilities. As such,
 * 			all other class' attack functions are modifications of
 * 			this function.
 * Param:	N/A
 * Returns:	An integer that represents the raw attack damage to be 
 * 			applied to a defender. This will be used as the input
 * 			parameter for the defender's defend function.
 */		
		virtual int attack();


/* virtual void defend(int)
 *
 * Summary: This function represents a character defending themselves
 * 			against an opponents attack. Using data in its member
 * 			variables specific to a given character type, the function
 * 			will calculate the amount of damage that the raw attack
 * 			will be reduced by based on the defender's defense die 
 * 			rolls. Like the attack() function above, the
 * 			Barbarian class' defend function serves as the base on
 * 			which the other class' defend functions are modified from.
 * Param:	An integer that represents the raw attack damage being
 * 			applied to the character from the attacker's attack
 * 			function.
 * Returns:	N/A
 */
		virtual void defend(int);

};


#endif
