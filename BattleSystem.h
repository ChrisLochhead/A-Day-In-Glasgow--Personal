/*

Name: Christopher Lochhead

Student ID: B00306187

I declare that the following code was produced by Chris Lochhead as a group assignment for the GED module and that this is our own work.

I am aware of the penalties incurred by submitting in full or in part work that is not our own and that was developed by third parties that are not appropriately acknowledged.

*/

#pragma once
#include <ctime>
#include "Player.h"
#include "EnemyEntity.h"
#include "BossEnemy.h"

class BattleSystem{ // highest abstract class for all battlesystems

public:

	virtual void BattleScript(Player* player1, EnemyEntity* enemy1, int scriptnumber) = 0; 
	virtual bool fight(Player* player1, EnemyEntity* enemy1) = 0;

};