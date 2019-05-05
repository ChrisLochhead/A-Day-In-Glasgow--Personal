/*

Name: Christopher Lochhead

Student ID: B00306187

I declare that the following code was produced by Chris Lochhead as a group assignment for the GED module and that this is our own work.

I am aware of the penalties incurred by submitting in full or in part work that is not our own and that was developed by third parties that are not appropriately acknowledged.

*/


#pragma once
#include "TextBattleSystem.h"


class BossTextBattleSystem : public TextBattleSystem {
public:

	BossTextBattleSystem(Player* player1, EnemyEntity* boss1)
	{
		BattleScript(player1, boss1, InitialFightScript);
		fight(player1, boss1);
	}

	//inherited from battlesystem, 
	void BattleScript(Player* player1, EnemyEntity* enemy1, int scriptnumber){};
	bool fight(Player* player1, EnemyEntity* boss1);
	//inherited from text battle system
	int roll(int min, int max);


private:

	int ScriptNumber;

	int InitialFightScript = roll(1, 3); // fight start script
	
};