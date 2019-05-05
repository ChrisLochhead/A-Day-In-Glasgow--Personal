/*

Name: Christopher Lochhead

Student ID: B00306187

I declare that the following code was produced by Chris Lochhead as a group assignment for the GED module and that this is our own work.

I am aware of the penalties incurred by submitting in full or in part work that is not our own and that was developed by third parties that are not appropriately acknowledged.

*/


#pragma once
#include "GameMap.h"
#include "AbstractMenu.h"

#include <iostream>

using namespace std;

class StartMenu: public AbstractMenu {

public:

	//constructor
	StartMenu(int difficulty);

	//additional functions
	void showInstructions();

	//inherited functions
	void changeDifficulty();
	void createPlayer(string name, int difficulty);

protected:
	//protected for use in GameMap and Player Functions
	int Difficulty;
private:
	string Name;
};
