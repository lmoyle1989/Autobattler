/***********************************************************************
 * Class:	Battle	
 * Author:	Lucas Moyle
 * Date:	11/24/2019
 * Descrip:	This is the header file for the object class battle. Battle
 * 			is the object that controls the character lists of team
 * 			A, B, and the loser list for the fantasy battle tournament
 * 			simulator. The lists of characters are private members and
 * 			the public functions serve to set up the teams and 
 * 			instantiate their characters via user input and also to
 * 			control the flow of the fighting rounds. By create an
 * 			object of the Battle class and bringing it in and out of
 * 			scope allows for easy resets and new games.
 **********************************************************************/


#ifndef CLASSBATTLE_HPP
#define CLASSBATTLE_HPP


#include "ClassCharacter.hpp"
#include "ClassCharList.hpp"
#include "StructCharCont.hpp"
#include "Menu.hpp"
#include "ClassBarb.hpp"
#include "ClassVamp.hpp"
#include "ClassMedusa.hpp"
#include "ClassBlue.hpp"
#include "ClassHarry.hpp"


class Battle
{

	private:
		
		CharacterList teamA;
		CharacterList teamB;
		CharacterList loserList;


	public:

/* Battle(int, int)
 *
 * Summary: The constructor function for the Battle class. Allows
 * 			the user to select and name members of each team and
 * 			then dynamically allocates memory for the characters.
 * Param:	An integer that represents the number of characters on
 * 			team A. This is input by the user in Main and should be
 * 			limited to a positive integer via input validation.
 * Param:	See above, but for team B.
 * Returns:	N/A
 */
		Battle(int, int);


/* fightRound()
 *
 * Summary: fightRound simulates the entire fight between both teams.
 * 			It battles the current heads of each team using their
 * 			attack and defense functions until one of them reaches
 * 			strength 0. When a character has 0 strength, the character
 * 			is moved to the top of the loser list and the surviving
 * 			character restores a portion of their strength and it moved
 * 			to the bottom of their team queue. Each defeated character
 * 			earns the defeating team 2 points and the defeated team 
 * 			loses 1 point. The fight is over when an entire team has
 * 			been moved to the loser list.
 * Param:	N/A
 * Returns:	N/A
 */
		void fightRound();
};

#endif
