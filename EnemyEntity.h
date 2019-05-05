/*

Name: Christopher Lochhead

Student ID: B00306187

I declare that the following code was produced by Chris Lochhead as a group assignment for the GED module and that this is our own work.

I am aware of the penalties incurred by submitting in full or in part work that is not our own and that was developed by third parties that are not appropriately acknowledged.

*/


#pragma once
#include <string>
#include <iostream>
using namespace std;

class EnemyEntity // class from which all enemies will inherit from with essential functions
{

public:

	virtual void setEnemyHealth(int damageTaken) = 0;
	virtual string getEnemyName() = 0; 
	virtual int getEnemyHealth() = 0;
	virtual int getEnemyDamage() = 0;

};
