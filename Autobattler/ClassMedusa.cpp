/***********************************************************************
 * Class Name:	Medusa
 * Author:		Lucas Moyle
 * Date:		11/10/2019
 * Description:	The implementation file for the object class Medusa.
 * 				Medusa is a derived class of the base Character class.
 * 				Medusa' attack and defend functoins are based off of
 * 				the Barbarian class, the attack function has been
 * 				modified to account for Medusa's special ability which
 * 				will turn the defender to stone on a roll of 12.
 **********************************************************************/


#include "ClassCharacter.hpp"
#include "ClassMedusa.hpp"


/* Medusa()
 *
 * Summary: Constructor function for Medusa. Sets member variables to
 * 			those specific for the Medusa class.
 * Param:	N/A
 * Returns:	N/A
 */
Medusa::Medusa()
{
	characterType = "Medusa";
	attackDieQty = 2;
	attackDieType = 6;
	defenseDieQty = 1;
	defenseDieType = 6;
	armor = 3;
	strength = 8;
	maxStrength = 8;
}	


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
int Medusa::attack()
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
	
	//if Medusa rolls 12 on her attack, the function will return 100.
	//the defender does not take 100 damage directly, but interprets
	//the 100 input as a flag to instant-kill itself.
	if (totalAttack == 12)
	{
		//std::cout << "Medusa rolled 12 and used glare!" << std::endl;
		totalAttack = 100;
	}

	return totalAttack;
}


/* virtual void defend(int)
 *
 * Summary: Identical to defend function in the Barbarian class.
 * Param:	An integer which is the raw damage that the defend function
 * 			will modify to calculate actual damage received.
 * Returns: N/A
 */
void Medusa::defend(int attackIn)
{
	int totalDefense = 0;
	int damageTaken = 0;
	int roll;

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
