/***********************************************************************
 * Class Name:	Blue Men
 * Author:		Lucas Moyle
 * Date:		11/10/2019
 * Description:	This is the header file for the object class
 * 				Blue Men. Blue Men is a derived class of the base
 * 				Character class. It has attack and defend functions
 * 				that are based on the same functions in the Barbarian
 * 				class. The attack function is exactly the same, the
 * 				defend function has been modified to account for
 * 				the BlueMen's special ability (two bool member
 * 				variables were also added to the class to account for
 * 				the special ability).
 **********************************************************************/


#ifndef CLASSBLUE_HPP
#define CLASSBLUE_HPP


#include "ClassCharacter.hpp"

class BlueMen : public Character
{

	private:

		bool mob_1;
		bool mob_2;

	public:

/* BlueMen()
 *
 * Summary: Constructor for the class, sets member variables that
 * 			are inherited from the Character class.
 * Param:	N/A
 * Returns:	N/A	
 */	
		BlueMen();


/* virtual int attack()
 *
 * Summary: Identical to the function of the same name
 * 			in the Barbarian class however uses different stats
 * 			that are set by the constructor.
 * Param:	N/A
 * Returns: An integer which is the total raw damage to be applied
 * 			to the defender.
 */	
		virtual int attack();


/* virtual void defend(int)
 *
 * Summary:	The defend function is almost identical to the defend
 * 			function in the Barbarian class. However, this function
 * 			account for the BlueMen's special ability, Mob. Every
 * 			time the total strength of BlueMen goes down by 4 total,
 * 			it will lose one of its original 3dy defense dice. The
 * 			two boolean member variables that are added to this
 * 			derived class account for that and make sure that it can
 * 			only happen twice (if the simulation were to account for
 * 			healing, this would need to be changed).
 * Param:	An integer which is the raw damage given to the BlueMen.
 * Returns:	N/A
 */
		virtual void defend(int);

};


#endif
