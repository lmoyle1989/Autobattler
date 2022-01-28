/***********************************************************************
 * Class Name:	Harry Potter
 * Author:		Lucas Moyle
 * Date:		11/10/2019
 * Description:	The implementation file for the object class Harry 
 * 				Potter. Harry has attack and defend functions based off of
 * 				Barbarian with additional code and one extra member var
 * 				to account for his special ability Hogwarts.
 **********************************************************************/


#include "ClassCharacter.hpp"
#include "ClassHarry.hpp"


/* HarryPotter()
 *
 * Summary: Constructor function. Sets member variables to those that
 * 			are specific to the Harry Potter class.
 * Param:	N/A
 * Returns:	N/A	
 */	
HarryPotter::HarryPotter()
{
	characterType = "Harry Potter";
	attackDieQty = 2;
	attackDieType = 6;
	defenseDieQty = 2;
	defenseDieType = 6;
	armor = 0;
	strength = 10;
	maxStrength = 10;

	hogwartsUsed = false;
}	


/* virtual int attack()
 *
 * Summary: Identical to the attack function in the Barbarian class.
 * Param:	N/A
 * Returns:	An integer which is the raw attack damage to be applied
 * 			to the defender.
 */
int HarryPotter::attack()
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
void HarryPotter::defend(int attackIn)
{
	//the majority of this function is identical to Barbarian's
	//I will only comment the unique part for the special ability
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
	
	//after the attack, check if Harry has zero strength and if he
	//has already used Hogwarts or not
	if ((strength == 0) && (hogwartsUsed == false))
	{
		//if he uses it, set his strength to 20 and toggle our bool var
		//std::cout << "Harry Potter used Hogwarts!" << std::endl;
		strength = 20;
		maxStrength = 20;
		//std::cout << "New Defender Strength: " << strength << std::endl;
		hogwartsUsed = true;
	}
}

