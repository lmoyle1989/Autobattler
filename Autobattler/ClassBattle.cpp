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


#include "ClassBattle.hpp"
#include "ClassCharacter.hpp"
#include "ClassCharList.hpp"
#include "StructCharCont.hpp"
#include "Menu.hpp"
#include "ClassBarb.hpp"
#include "ClassVamp.hpp"
#include "ClassMedusa.hpp"
#include "ClassBlue.hpp"
#include "ClassHarry.hpp"


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
Battle::Battle(int teamAIn, int teamBIn)
{
	Menu MyMenu;
	int fighterChoice;
	Character* tempChar;

	MyMenu.prompt("1. Barbarian");
	MyMenu.prompt("2. Vampire");
	MyMenu.prompt("3. Medusa");
	MyMenu.prompt("4. BlueMen");
	MyMenu.prompt("5. Harry Potter");

	for (int i = 0; i < teamAIn; i++)
	{
		std::cout << "Choose fighter #" << (i + 1) << " for Team A: ";
		fighterChoice = MyMenu.integerInputNoPrompt(1, 5);
		
		if (fighterChoice == 1)
		{
			tempChar = new Barbarian;
		}
		else if (fighterChoice == 2)
		{
			tempChar = new Vampire;
		}
		else if (fighterChoice == 3)
		{
			tempChar = new Medusa;
		}
		else if (fighterChoice == 4)
		{
			tempChar = new BlueMen;
		}
		else if (fighterChoice == 5)
		{
			tempChar = new HarryPotter;
		}

		std::cout << "Enter name for fighter #" << (i + 1) << ": ";
		tempChar->setName(MyMenu.stringInput());

		teamA.addBack(tempChar);
		tempChar = nullptr;
	}

	for (int i = 0; i < teamBIn; i++)
	{
		std::cout << "Choose fighter #" << (i + 1) << " for Team B: ";
		fighterChoice = MyMenu.integerInputNoPrompt(1, 5);
		
		if (fighterChoice == 1)
		{
			tempChar = new Barbarian;
		}
		else if (fighterChoice == 2)
		{
			tempChar = new Vampire;
		}
		else if (fighterChoice == 3)
		{
			tempChar = new Medusa;
		}
		else if (fighterChoice == 4)
		{
			tempChar = new BlueMen;
		}
		else if (fighterChoice == 5)
		{
			tempChar = new HarryPotter;
		}

		std::cout << "Enter name for fighter #" << (i + 1) << ": ";
		tempChar->setName(MyMenu.stringInput());

		teamB.addBack(tempChar);
		tempChar = nullptr;
	}
}


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
void Battle::fightRound()
{
	int attackDmg;
	bool combatOver = false;
	int roundCounter = 1;
	bool newRound = true;
	Menu BattleMenu;
	int loserListChoice;
	int teamAScore = 0;
	int teamBScore = 0;
	
	while(!combatOver)
	{
		//at the beginning of each new character pair fight, output
		//the combatant info
		if (newRound == true)
		{
			std::cout << "Round " << roundCounter << ": ";
			std::cout << "Team A - ";
			std::cout << (((teamA.getHead())->charPtr)->getCharacterType());
			std::cout << " ";
			std::cout << (((teamA.getHead())->charPtr)->getName());
			std::cout << " vs. ";
			std::cout << "Team B - ";
			std::cout << (((teamB.getHead())->charPtr)->getCharacterType());
			std::cout << " ";
			std::cout << (((teamB.getHead())->charPtr)->getName());
			newRound = false;
		}

		//team A attacks team B first
		attackDmg = ((teamA.getHead())->charPtr)->attack();

		//the head of team B defends against the attack roll of the
		//head of team A
		((teamB.getHead())->charPtr)->defend(attackDmg);

		//check if the head of team B has been defeated afer each attack
		if (((teamB.getHead())->charPtr)->getStrength() == 0)
		{
			//set newRound such that a new fight will be moved to the
			//head of the losing teams roster and it can be output
			newRound = true;
			roundCounter++;
			teamAScore = teamAScore + 2;
			teamBScore = teamBScore - 1;

			std::cout << ", ";
			std::cout << ((teamA.getHead())->charPtr)->getName();
			std::cout << " wins!" << std::endl;

			//move loser to loser list
			loserList.addFront(teamB.getHead()->charPtr);	
			
			//remove loser from team list
			teamB.removeFront();

			//winner regains some strength
			teamA.getHead()->charPtr->regainStrength();

			//winner is moved to the bottom of their team's queue
			teamA.incrementHead();

			//if the team list is empty, the game is over
			if (teamB.getHead() == nullptr)
			{	
				combatOver = true;
			}
		}
		
		//the next block of code is identical to above, except this time
		//team B attacks team A
		if (!combatOver)
		{
			if (newRound == true)
			{
				std::cout << "Round " << roundCounter << ": ";
				std::cout << "Team A - ";
				std::cout << (((teamA.getHead())->charPtr)->getCharacterType());
				std::cout << " ";
				std::cout << (((teamA.getHead())->charPtr)->getName());
				std::cout << " vs. ";
				std::cout << "Team B - ";
				std::cout << (((teamB.getHead())->charPtr)->getCharacterType());
				std::cout << " ";
				std::cout << (((teamB.getHead())->charPtr)->getName());
				newRound = false;
			}

			attackDmg = ((teamB.getHead())->charPtr)->attack();

			((teamA.getHead())->charPtr)->defend(attackDmg);

			if (((teamA.getHead())->charPtr)->getStrength() == 0)
			{
				newRound = true;
				roundCounter++;
				teamBScore = teamBScore + 2;
				teamAScore = teamAScore - 1;

				std::cout << ", ";
				std::cout << ((teamB.getHead())->charPtr)->getName();
				std::cout << " wins!" << std::endl;

				loserList.addFront(teamA.getHead()->charPtr);

				teamA.removeFront();

				teamB.getHead()->charPtr->regainStrength();

				teamB.incrementHead();	
				
				if (teamA.getHead() == nullptr)
				{
					combatOver = true;
				}
			}
		}
	}

	//display final score and determine winner
	std::cout << std::endl;
	std::cout << "FINAL SCORE:" << std::endl;
	std::cout << "Team A - " << teamAScore << " points" << std::endl;
	std::cout << "Team B - " << teamBScore << " points" << std::endl;
	
	if (teamAScore > teamBScore)
	{
		std::cout << "Team A Wins!";
	}
	else if (teamAScore < teamBScore)
	{
		std::cout << "Team B Wins!";
	}
	else if (teamAScore == teamBScore)
	{
		std::cout << "Tie! No Winner.";
	}
	std::cout << std::endl;
	std::cout << std::endl;
	
	//ask the user if they would like to see the loser list, otherwise
	//go back to main menu
	loserListChoice = BattleMenu.integerInput("Would you like to view the loser list? (1 = yes, 2 = no)", 1, 2);

	if (loserListChoice == 1)
	{
		std::cout << "Loser List:" << std::endl;
		loserList.printList();
	}
}

