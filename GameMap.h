/*

Name: Christopher Lochhead

Student ID: B00306187

I declare that the following code was produced by Chris Lochhead as a group assignment for the GED module and that this is our own work.

I am aware of the penalties incurred by submitting in full or in part work that is not our own and that was developed by third parties that are not appropriately acknowledged.

*/


#pragma once

#include "AbstractTextMap.h"
#include "Player.h"

//enemies
#include "Enemy.h"
#include "BossEnemy.h"

//battlesystems
#include "NormalTextBattleSystem.h" 
#include "BossTextBattleSystem.h"

//puzzlesystems
#include "TextPuzzleDecorator.h"
#include "TextPuzzleSystem.h"
#include "TextPuzzleRoom.h"

//questsystems
#include "TextQuestSystem.h"
#include "TextQuestWithEnemies.h"

#include "Subject.h"

class GameMap : public Player, public AbstractTextMap, public Subject{

public:

	GameMap(string Name, int difficulty) : Player(Name, difficulty) // constructor creates a player and calls introductory script 
	{
		Player* player1 = new Player(Name, difficulty);
		system("CLS");
		Intro(player1, Name); 

	};

	//inherited functions required of any gamemap that is text-based
	void Intro(Player* player1, string Name);// calls introduction
	void CallScript(Player* player1, int ScriptNumber); // the story of the game

	// functions unique to this type of game
	void changeDifficulty(Subject* subject, int newDiff) { subject->setDifficulty(newDiff); }
	void setDifficulty(int newDiff) {PlayerDifficulty = newDiff;}
	int getDifficulty() { return PlayerDifficulty; }
	void HealthScript(Player* player1); // called if player finds a healthshop

	void registerObserver(Observer * observer);

	// This method implements the removal of the observer from the observers vector
	void removeObserver(Observer* observer);

	// This methods notify when the event of interest (in this case a change in position) has appened
	void notifyObserver(int newDiff);

private:
	int ScriptNumber; // determines where in the story the player is

};