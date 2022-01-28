/***********************************************************************
 * Class Name:	Medusa
 * Author:		Lucas Moyle
 * Date:		11/10/2019
 * Description:	The header file for the object class Medusa.
 * 				Medusa is a derived class of the base Character class.
 * 				Medusa' attack and defend functoins are based off of
 * 				the Barbarian class, the attack function has been
 * 				modified to account for Medusa's special ability which
 * 				will turn the defender to stone on a roll of 12.
 **********************************************************************/


#ifndef CLASSMEDUSA_HPP
#define CLASSMEDUSA_HPP


#include "ClassCharacter.hpp"


class Medusa : public Character
{

	private:

	public:

/* Medusa()
 *
 * Summary: Constructor function for Medusa. Sets member variables to
 * 			those specific for the Medusa class.
 * Param:	N/A
 * Returns:	N/A
 */
		Medusa();


/* virtual int attack()
 *
 * Summary: The attack function for Medusa that is based off of the
 * 			Barbarian class' function of the same name. This function
 * 			has been modified to account for Medusa's special ability
 * 			Glare. If Medusa rolls a 12 on her attack, the opponent
 * 			is instantly killed by being turned to stone. Otherwise
 * 			identical to Barbarian.
 * Param:	N/A
 * Returns: An integer that is the raw damage to be applied to the
 * 			defender.
 */
		virtual int attack();


/* virtual void defend(int)
 *
 * Summary: Identical to defend function in the Barbarian class.
 * Param:	An integer which is the raw damage that the defend function
 * 			will modify to calculate actual damage received.
 * Returns: N/A
 */
		virtual void defend(int);

};


#endif
