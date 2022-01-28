/***********************************************************************
 * Class Name:	Vampire
 * Author:		Lucas Moyle
 * Date:		11/10/2019
 * Description:	The header file for the object class Vampire.
 * 				Vampire is a derived class of the base class Character.
 * 				Vampire is identical to Barbarian other than having
 * 				different values for its initialized member variables
 * 				and it's defend function has been modified to account
 * 				for its special ability Charm. Charm makes it so the
 * 				Vampire has a 50/50 chance to ignore any attack.
 **********************************************************************/


#ifndef CLASSVAMP_HPP
#define CLASSVAMP_HPP


#include "ClassCharacter.hpp"

class Vampire : public Character
{

	private:

	public:
	
/* Vampire()
 *
 * Summary: Constructor function for Vampire. Sets all relevant
 * 			member variables to values specific to the class.
 * Param:	N/A
 * Returns:	N/A
 */		
		Vampire();


/* virtual int attack()
 *
 * Summary:	Vampire's attack function. Identical to Barbarian's.
 * Param:	N/A
 * Returns:	Raw damage calculated from Vampire's dice rolls to be
 * 			applied to be used as input for the defender's defend
 * 			function.
 */
		virtual int attack();


/* virtual void defend(int)
 *
 * Summary:	Vampire's defend function. Based off of Barbarian's
 * 			defend function except modified to account for Vampire's
 * 			special ability Charm. Charm gives the vampire a 50/50
 * 			chance to completely ignore an attack given to him.
 * 			Otherwise identical to Barbarian's defend.
 * Param:	An integer that is calculated from the attacker's attack
 * 			function. Represents raw damage that the defend function
 * 			will use to calculate total actual damage dealt.
 * Returns:	N/A
 */
		virtual void defend(int);

};


#endif
