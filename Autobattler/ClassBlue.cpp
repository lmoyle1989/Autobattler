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


#include "ClassCharacter.hpp"
#include "ClassBlue.hpp"


/* BlueMen()
 *
 * Summary: Constructor for the class, sets member variables that
 * 			are inherited from the Character class.
 * Param:	N/A
 * Returns:	N/A	
 */	
BlueMen::BlueMen()
{
	characterType = "Blue Men";
	attackDieQty = 2;
	attackDieType = 10;
	defenseDieQty = 3;
	defenseDieType = 6;
	armor = 3;
	strength = 12;
	maxStrength = 12;

	mob_1 = false;
	mob_2 = false;
}	


/* virtual int attack()
 *
 * Summary: Identical to the function of the same name
 * 			in the Barbarian class however uses different stats
 * 			that are set by the constructor.
 * Param:	N/A
 * Returns: An integer which is the total raw damage to be applied
 * 			to the defender.
 */	
int BlueMen::attack()
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
void BlueMen::defend(int attackIn)
{
	//this function is identical to Barbarian's except for the special
	//ability part. I will only comment that part, see Barbarian for
	//comments on the rest of the function
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
		
		//The following block of code is the portion that accounts for
		//the BlueMen special ability. The rest of the function is
		//identical to Barbarian's
		//
		//check for the the first 4 points of damage lost and reduce
		//the die qty, ensure it doesn't happen again on all following
		//function calls with the bool
		if ((strength <= 8) && (mob_1 == false))
		{
			//std::cout << "The mob of Blue Men has lost a defense die!" << std::endl;
			defenseDieQty = 2;
			mob_1 = true;
		}
		//check for the next 4 points of damage and do the same as
		//above
		if ((strength > 0) && (strength <= 4) && (mob_2 == false))
		{
			//std::cout << "The mob of Blue Men has lost a defense die!" << std::endl;
			defenseDieQty = 1;
			mob_2 = true;
		}

		//end special ability code block

		if (strength <= 0)
		{
			strength = 0;
		}

		//std::cout << "New Defender Strength: " << strength << std::endl;
	}
}
