/*

Name: Christopher Lochhead

Student ID: B00306187

I declare that the following code was produced by Chris Lochheadas a group assignment for the GED module and that this is our own work.

I am aware of the penalties incurred by submitting in full or in part work that is not our own and that was developed by third parties that are not appropriately acknowledged.

*/


#pragma once
#include "BossEnemyEntity.h"
class BossEnemy : public BossEnemyEntity
{

public:

	BossEnemy(string name, int health, int damage, int armour, int shields) : EnemyName(name) //constructor
	{
		EnemyName = name;
		EnemyArmour = armour;
		EnemyHealth = health;
		EnemyDamage = damage;
		EnemyShield = shields;

	}

	// inherited functions from EnemyEntity
	string getEnemyName() { return EnemyName; }
	int getEnemyHealth() { return EnemyHealth; }
	int getEnemyDamage() { return EnemyDamage; }
	int getEnemyArmour() { return EnemyArmour; }

	//unique functions to Boss type
	int getEnemyShields() { return EnemyShield; }
	void setEnemyShields(int damageTaken) { EnemyShield -= damageTaken; }

	void setEnemyHealth(int damageTaken) {};

private:
	
	int EnemyShield;
	string EnemyName;

	int EnemyHealth;
	int EnemyDamage;
	int EnemyArmour;
	
};