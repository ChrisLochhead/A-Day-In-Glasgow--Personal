/*

Name: Christopher Lochhead

Student ID: B00306187

I declare that the following code was produced by Chris Lochhead as a group assignment for the GED module and that this is our own work.

I am aware of the penalties incurred by submitting in full or in part work that is not our own and that was developed by third parties that are not appropriately acknowledged.

*/


#pragma once
#include "EnemyEntity.h"

class BossEnemyEntity: public EnemyEntity  // abstract class that adds functions specific for the boss enemy type
{
public:
	virtual int getEnemyShields() = 0;
	virtual void setEnemyShields(int damageTaken) = 0;
};