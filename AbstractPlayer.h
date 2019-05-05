/*

Name: Christopher Lochhead

Student ID: B00306187

I declare that the following code was produced by Chris Lochhead as a group assignment for the GED module and that this is our own work.

I am aware of the penalties incurred by submitting in full or in part work that is not our own and that was developed by third parties that are not appropriately acknowledged.

*/


#pragma once
#include <iostream>

class AbstractPlayer { // abstract player class with essential functions

	virtual int getPlayerHealth() = 0;
	virtual int getPlayerDifficulty() = 0;
	virtual int  getPlayerDamage() = 0;
	virtual string getPlayerName() = 0;
};