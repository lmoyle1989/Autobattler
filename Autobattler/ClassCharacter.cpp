/***********************************************************************
 * Class Name:	Character
 * Author:		Lucas Moyle
 * Date:		11/24/2019
 * Description:	This is the header file for the base class
 * 				"Character". Character is an abstract object class that
 * 				provides the base for our 5 other character types.
 * 				Contains variables that will be inherited by the child
 * 				classes that correspond to common characteristics shared 
 * 				by all character types that will be instantiated
 * 				differently in their constructor functions.
 **********************************************************************/


#include <iostream>
#include <string>
#include "ClassCharacter.hpp"


/* virtual int attack()
 *
 * Summary: A purely virtual function that is overwritten in each
 * 			child class. Represents the attack action of a given
 * 			character type and performs all necessary dice rolls and
 * 			accounts for any special abilities a child class may have
 * 			when attacking.
 * Param:	N/A
 * Returns:	An integer which is the final calculated value of the
 * 			character type's attack. This value will be passed to the
 * 			defender's defend function.
 */	
int Character::attack()
{
}


/* virtual void defend(int)
 *
 * Summary:	A purely virtual function that is overwritten in each
 * 			child class. Represents the actions that a character would
 * 			take while being attacked. Calculates all necessary defense
 * 			dice rolls and applies any special defense abilities that
 * 			a character type may have.
 * Param:	An integer that is the raw attack value to be defended 
 * 			against.
 * Returns: N/A
 */
void Character::defend(int)
{
}


/* int/string get(member variable name)()
 *
 * Summary:	All of the following functions are simple "get" functions
 * 			that will return their corresponding member variable
 * 			value of the same name. These will be inherited and used
 * 			by all child classes.
 * Param:	N/A
 * Returns: The the value of the corresponding member variable (eg.
 * 			getStrength() will return the current integer strength
 * 			value of an instance of a character-derived object).
 */
std::string Character::getName()
{
	return this->name;
}

std::string Character::getCharacterType()
{
	return this->characterType;
}

int Character::getAttackDieQty()
{
	return this->attackDieQty;
}

int Character::getAttackDieType()
{
	return this->attackDieType;
}

int Character::getDefenseDieQty()
{
	return this->defenseDieQty;
}

int Character::getDefenseDieType()
{
	return this->defenseDieType;
}

int Character::getArmor()
{
	return this->armor;
}

int Character::getStrength()
{
	return this->strength;
}


/* setName(string)
 *
 * Summary: Simple set function for the member variable name.
 * Param:	A string that the object's name variable will be set to.
 * Returns: N/A
 */
void Character::setName(std::string stringIn)
{
	this->name = stringIn;
}


/* regainStrength()
 *
 * Summary: "Heals" the character for a random amount of strength
 * 			equal to %10-%50 of the difference between the character's
 * 			max strength and the character's current strength.
 * Param:	N/A
 * Returns: N/A
 */
void Character::regainStrength()
{
	int strengthDifference;
	int healAmount;

	strengthDifference = (this->maxStrength - this->strength);

	healAmount = ((strengthDifference) / ((rand() % 5) + 1));

	this->strength = this->strength + healAmount;

	std::cout << this->name << " regained " << healAmount << " strength.";
	std::cout << std::endl;
}
