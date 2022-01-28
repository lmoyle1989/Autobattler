/***********************************************************************
 * Class Name:	Barbarian
 * Author:		Lucas Moyle
 * Date:		11/10/2019
 * Description:	This is the implementation file for the object class 
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


#include "ClassCharacter.hpp"
#include "ClassBarb.hpp"
#include "Menu.hpp"

/* Barbarian()
 *
 * Summary:	The constructor function for the class Barbarian. Sets
 * 			all member variables that are inherited from the Character
 * 			base class to the values that are unique to the Barbarian.
 * Param:	N/A
 * Returns:	N/A
 */
Barbarian::Barbarian()
{
	characterType = "Barbarian";
	attackDieQty = 2;
	attackDieType = 6;
	defenseDieQty = 2;
	defenseDieType = 6;
	armor = 0;
	strength = 12;
	maxStrength = 12;
}	


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
 * 			applied to a defender.
 */	
int Barbarian::attack()
{
	int totalAttack = 0;
	int roll;

	//roll the number and type of die that correspond to Barbarian's
	//attack. in this case it is 2 dice with 6 sides each.
	for (int i = 0; i < attackDieQty; i++)
	{
		roll = ((rand() % attackDieType) + 1);

		if (i == 0)
		{
			//std::cout << "Attack Roll: ";
		}
	
		//add the rolls together to get raw base damage and return it
		//std::cout << roll << " ";
		totalAttack = (totalAttack + roll);
	}

	//std::cout << " Total Attack Roll: " << totalAttack << std::endl;

	return totalAttack;
}


/* virtual void defend(int)
 *
 * Summary: This function represents a character defending themselves
 * 			against an opponents attack. Using data in its member
 * 			variables specific to a given character type, the function
 * 			will calculate the amount of damage that the raw attack
 * 			will be reduced by. Like the attack() function above, this
 * 			Barbarian class' defend function serves as the base on
 * 			which the other class's defend function are modified.
 * Param:	An integer that represents the raw attack damage being
 * 			applied to the character.
 * Returns:	N/A
 */
void Barbarian::defend(int attackIn)
{
	int totalDefense = 0;
	int damageTaken = 0;
	int roll;
	
	//check for Medusa's glare attack first. 100 damage can only
	//ever be passed when her glare ability activates,
	//instantly kill the character if so
	if (attackIn == 100)
	{
		//std::cout << "Defender has been turned to stone!" << std::endl;
		strength = 0;
	}
	//if the character isn't hit by glare, then perform normal attack
	//calculations
	else
	{	
		//roll the number and type of dice that correspond to the
		//character's defense member variables. in this case 2 dice
		//with 6 sides
		for (int i = 0; i < defenseDieQty; i++)
		{
			roll = ((rand() % defenseDieType) + 1);

			if (i == 0)
			{
				//std::cout << "Defense Roll: ";
			}
			
			//add the sum of the rolls to the characters defense stat
			//and subtract it from the raw damage applied
			//std::cout << roll << " ";
			totalDefense = (totalDefense + roll);
		}

		//std::cout << " Total Defense Roll: " << totalDefense << std::endl;

		damageTaken = (attackIn - (totalDefense + armor));

		//we can't take negative damage, so account for that here
		if (damageTaken <= 0)
		{
			damageTaken = 0;
		}

		//std::cout << "Total Damage Inflicted: " << damageTaken << std::endl;

		//remove attack-defense from the characters strength value
		strength = (strength - damageTaken);
		if (strength <= 0)
		{
			strength = 0;
		}

		//std::cout << "New Defender Strength: " << strength << std::endl;
	}	
}
