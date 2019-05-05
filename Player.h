/*

Name: Christopher Lochhead

Student ID: B00306187

I declare that the following code was produced by Chris Lochheadas a group assignment for the GED module and that this is our own work.

I am aware of the penalties incurred by submitting in full or in part work that is not our own and that was developed by third parties that are not appropriately acknowledged.

*/


#pragma once
#include <iostream>
#include <string>
#include <ctime>
#include "Observer.h"
#include "Subject.h"
#include "AbstractPlayer.h"

using namespace std;

class Player : public AbstractPlayer, public Observer{

public:
	Player(string name, int difficulty);

	// inherited functions
	int getPlayerHealth() { return Health; }
	int getPlayerDifficulty() { return PlayerDifficulty; }
	int getPlayerDamage();
	string getPlayerName() { return PlayerName; }

	void checkBag();
	void usePainkiller();
	void switchWeapon();
	void setPlayerHealth(int damageTaken);
	void recievePickup();
	void BuyPainKillers(int MaximumNumber);
	void BuyArmour();
	string getWeaponItem() { return WeaponItem; }
	

	void setDifficulty(int newDifficulty) { PlayerDifficulty = newDifficulty; }
	int getDifficulty() { return PlayerDifficulty; }

	void changeDifficulty(Subject* subject, int newDiff)
	{
			subject->setDifficulty(newDiff);
		
	}
	
protected:
	string PlayerName;
	int PlayerDifficulty;
	int Health;
private:
	
	const int MAX_INVENTORY_SPACE = 10;

	string WeaponItem;
	string weapons[5] = { "fists", "empty", "empty", "empty", "empty" }; // weapon inventory 5 spaces
	string ArmourItem;
	string armours[3] = { "1 : jeans and duffel coat - 20 pounds", "2: donnay bottoms and white top - 35 pounds","3: nike tracksuit - 50 pounds" };

	int Armour;
	int Damage; 
	int Inventory;
	int HealthItem;
	int Cash;
};