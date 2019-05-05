/*

Name: Christopher Lochhead

Student ID: B00306187

I declare that the following code was produced by Chris Lochheadas a group assignment for the GED module and that this is our own work.

I am aware of the penalties incurred by submitting in full or in part work that is not our own and that was developed by third parties that are not appropriately acknowledged.

*/


#pragma once
#include <string>
#include <iostream>

#include "EnemyEntity.h"
using namespace std;

class Enemy : public EnemyEntity {

public:

	Enemy(string name, int health, int damage, int armour) 
	{
		EnemyName = name;
		EnemyArmour = armour;
		EnemyHealth = health;
		EnemyDamage = damage;
	}

	// inherited functions
	string getEnemyName() { return EnemyName; }
	int getEnemyHealth() { return EnemyHealth; }
	int getEnemyDamage() { return EnemyDamage; }
	int getEnemyArmour() { return EnemyArmour; }

	//unique functions
	void setEnemyHealth(int damageTaken);


private:
	string EnemyName;
	int EnemyHealth;
	int EnemyDamage;
	int EnemyArmour;

};
