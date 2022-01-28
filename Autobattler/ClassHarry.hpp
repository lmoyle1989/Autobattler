/***********************************************************************
 * Class Name:	Harry Potter
 * Author:		Lucas Moyle
 * Date:		11/10/2019
 * Description:	The header file for the object class Harry Potter.
 * 				Harry has attack and defend functions based off of
 * 				Barbarian with additional code and one extra member var
 * 				to account for his special ability Hogwarts.
 **********************************************************************/


#ifndef CLASSHARRY_HPP
#define CLASSHARRY_HPP


#include "ClassCharacter.hpp"

class HarryPotter : public Character
{

	private:

		bool hogwartsUsed;

	public:

/* HarryPotter()
 *
 * Summary: Constructor function. Sets member variables to those that
 * 			are specific to the Harry Potter class.
 * Param:	N/A
 * Returns:	N/A	
 */	
		HarryPotter();


/* virtual int attack()
 *
 * Summary: Identical to the attack function in the Barbarian class.
 * Param:	N/A
 * Returns:	An integer which is the raw attack damage to be applied
 * 			to the defender.
 */
		virtual int attack();


/* virtual void defend(int)
 *
 * Summary:	Based off of and similar to the Barbarian's defend
 * 			function, however it accounts for Harry Potter's special
 * 			ability Hogwarts. The first time Harry's strength is
 * 			reduced to 0 or below, he will instantly regenerate to
 * 			20 strength points. This will only happen once in a given
 * 			combat session, which is accounted for by the extra
 * 			member variable.
 * Param:	An integer which is the raw damage from the attacked.
 * Returns:	N/A
 */		
		virtual void defend(int);

};


#endif
