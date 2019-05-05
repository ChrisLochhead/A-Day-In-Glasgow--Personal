/*

Name: Christopher Lochhead

Student ID: B00306187

I declare that the following code was produced by Chris Lochheadas a group assignment for the GED module and that this is our own work.

I am aware of the penalties incurred by submitting in full or in part work that is not our own and that was developed by third parties that are not appropriately acknowledged.

*/


#pragma once
#include "TextBattleSystem.h"


class NormalTextBattleSystem: public TextBattleSystem {
public:
	NormalTextBattleSystem(Player* player1, EnemyEntity* enemy1)
	{
		BattleScript(player1, enemy1, rand() % 3);		
		fight(player1, enemy1);
	}

	//inherited from battle system
	void BattleScript(Player* player1, EnemyEntity* enemy1, int scriptnumber);    // must write functions for these two
	bool fight(Player* player1, EnemyEntity* enemy1);

	//inherited from text battle system
	int roll(int min, int max);

private:

	int ScriptNumber;

	int InitialFightScript = roll(1, 3); // fight start script

};