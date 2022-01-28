/***********************************************************************
 * Class Name:	Character
 * Author:		Lucas Moyle
 * Date:		11/10/2019
 * Description:	This is the header file for the base class
 * 				"Character". Character is an abstract object class that
 * 				provides the base for our 5 other character types.
 * 				Contains variables that will be inherited by the child
 * 				classes that correspond to common characteristics shared 
 * 				by all character types that will be instantiated
 * 				differently in their constructor functions.
 **********************************************************************/


#ifndef CLASSCHARACTER_HPP
#define CLASSCHARACTER_HPP


#include <iostream>
#include <string>


class Character
{

	protected:
		
		std::string name;
		std::string characterType;
		int attackDieQty;
		int attackDieType;
		int defenseDieQty;
		int defenseDieType;
		int armor;
		int strength;
		int maxStrength;
		
	public:

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
		virtual int attack() = 0;


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
		virtual void defend(int) = 0;


/* setName(string)
 *
 * Summary: Simple set function for the member variable name.
 * Param:	A string that the object's name variable will be set to.
 * Returns: N/A
 */
		void setName(std::string);


/* regainStrength()
 *
 * Summary: "Heals" the character for a random amount of strength
 * 			equal to %10-%50 of the difference between the character's
 * 			max strength and the character's current strength.
 * Param:	N/A
 * Returns: N/A
 */
		void regainStrength();


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
		std::string getName();
		std::string getCharacterType();
		int getAttackDieQty();
		int getAttackDieType();
		int getDefenseDieQty();
		int getDefenseDieType();
		int getArmor();
		int getStrength();

};

#endif
