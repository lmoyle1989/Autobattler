/***********************************************************************
 * Program:	Project 4 - Fantasy Battle Tournament
 * Author:	Lucas Moyle
 * Date:	11/24/2019
 * Descrip: This it the main file for the tournament sim. It allows
 * 			the user to start a new tournament fight and pick the
 * 			number of characters of each team. Then, it creates
 * 			the necessary Battle class object and calls its member
 * 			functions. When the tournament is over, main allows the user
 * 			to start a new game and the process repeats.
 **********************************************************************/

#include <iostream>
#include "Menu.hpp"
#include "ClassBattle.hpp"
#include "ClassCharList.hpp"
#include "StructCharCont.hpp"
#include "ClassCharacter.hpp"
#include <cstdlib>

int main()
{
	srand(time(0));
	Menu MainMenu;
	int	menuChoice;
	bool quit = false;
	int teamANoOfChars;
	int teamBNoOfChars;
	const int maxTeamSize = 10;
	
	while(!quit)
	{
		MainMenu.prompt("Welcome to the Fantasy Combat Team Tournament!");
		MainMenu.prompt("Please choose an option:");
		MainMenu.prompt("1. Start");
		MainMenu.prompt("2. Quit");

		menuChoice = MainMenu.integerInput(1, 2);
		
		if (menuChoice == 1)
		{
			teamANoOfChars = MainMenu.integerInput("How many fighters on Team A?", 1, maxTeamSize);
			teamBNoOfChars = MainMenu.integerInput("How many fighters on Team B?", 1, maxTeamSize);
			
			//create our battle object with the user input team numbers
			//battle will set up the teams with further user input
			Battle MyBattle(teamANoOfChars, teamBNoOfChars);

			//fight the tournament, when this function finishes the game
			//is over
			MyBattle.fightRound();	
		}
		else if (menuChoice == 2)
		{
			quit = true;
		}
	}

	return 0;
}
