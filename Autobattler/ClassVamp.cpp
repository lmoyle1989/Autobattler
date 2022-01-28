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


#include "ClassCharacter.hpp"
#include "ClassVamp.hpp"


/* Vampire()
 *
 * Summary: Constructor function for Vampire. Sets all relevant
 * 			member variables to values specific to the class.
 * Param:	N/A
 * Returns:	N/A
 */	
Vampire::Vampire()
{
	characterType = "Vampire";
	attackDieQty = 1;
	attackDieType = 12;
	defenseDieQty = 1;
	defenseDieType = 6;
	armor = 1;
	strength = 18;
	maxStrength = 18;
}	


/* virtual int attack()
 *
 * Summary:	Vampire's attack function. Identical to Barbarian's.
 * Param:	N/A
 * Returns:	Raw damage calculated from Vampire's dice rolls to be
 * 			applied to be used as input for the defender's defend
 * 			function.
 */
int Vampire::attack()
{
	int totalAttack = 0;
	int roll;

	for (int i = 0; i < attackDieQty; i++)
	{
		roll = ((rand() % attackDieType) + 1);

		if (i == 0)
		{
			//std::cout << "Attack Roll: ";
		}

		//std::cout << roll << " ";
		totalAttack = (totalAttack + roll);
	}

	//std::cout << " Total Attack Roll: " << totalAttack << std::endl;

	return totalAttack;
}


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
void Vampire::defend(int attackIn)
{
	int totalDefense = 0;
	int damageTaken = 0;
	int roll;

	//do the Charm roll first, if it succeeds, print a message and
	//then ignore the rest of the function which is identical
	//to Barbarian's.
	if ((rand() % 2) == 1)
	{
		//std::cout << "Vampire has used Charm and cancelled the attack!" << std::endl;
		//std::cout << "Defender Strength: " << strength << std::endl;
	}
	else
	{
		if (attackIn == 100)
		{
			//std::cout << "Defender has been turned to stone!" << std::endl;
			strength = 0;
		}
		else
		{
			for (int i = 0; i < defenseDieQty; i++)
			{
				roll = ((rand() % defenseDieType) + 1);

				if (i == 0)
				{
					//std::cout << "Defense Roll: ";
				}

				//std::cout << roll << " ";
				totalDefense = (totalDefense + roll);
			}

			//std::cout << " Total Defense Roll: " << totalDefense << std::endl;

			damageTaken = (attackIn - (totalDefense + armor));
			if (damageTaken <= 0)
			{
				damageTaken = 0;
			}
			//std::cout << "Total Damage Inflicted: " << damageTaken << std::endl;

			strength = (strength - damageTaken);
			if (strength <= 0)
			{
				strength = 0;
			}
			//std::cout << "New Defender Strength: " << strength << std::endl;
		}
	}
}
