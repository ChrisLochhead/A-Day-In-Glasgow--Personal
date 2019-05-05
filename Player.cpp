/*

Name: Christopher Lochhead

Student ID: B00306187

I declare that the following code was produced by Chris Lochheadas a group assignment for the GED module and that this is our own work.

I am aware of the penalties incurred by submitting in full or in part work that is not our own and that was developed by third parties that are not appropriately acknowledged.

*/


#include "Player.h"


Player::Player(string name, int difficulty) {

	PlayerName = name;
	PlayerDifficulty = difficulty;
	Health = 30 / difficulty;
	Armour = 1;
	Damage = 5;
	HealthItem = 5 - difficulty;
	Inventory = MAX_INVENTORY_SPACE - HealthItem;
	ArmourItem = "casual blazer and jeans combo";
	WeaponItem = weapons[0]; // set initial weapon to fists
	Cash = 90 / difficulty;
}

void Player::checkBag() {

	cout << "		INVENTORY		" << endl;
	cout << "Health = " << Health << endl;
	cout << "Armour = " << Armour << endl;
	cout << "Damage output =  " << Damage << endl;
	cout << "\n" << "\n" << endl;
	cout << "Clothes = " << ArmourItem << endl;
	cout << "Weapon = " << WeaponItem << endl;
	for (const string &weapon : weapons) {
		cout << weapon << endl;
	}
	cout << "Painkillers = " << HealthItem << endl;
	cout << "Cash = £" << Cash << endl;
	system("pause");
	system("CLS");

}

int Player::getPlayerDamage()
{
	srand(time(NULL));
	int hit = rand() % Damage;
	return hit;
}

void Player::setPlayerHealth(int damageTaken) {

	if (damageTaken > 0) {
		int setDamage = (damageTaken / Armour);
		Health -= setDamage;
	}

}

void Player::usePainkiller() {
		
	if (HealthItem > 0) {
		HealthItem--;
		Health += 10;
	}
	else {
		cout << "you have no painkillers left." << endl;
	}
}

void Player::switchWeapon() 
{
	int choice = 0;
	cout << "     Weapons     " << endl;
	for (const string &weapon : weapons) {
		cout << weapon << endl;
	}
	cout << "choose your weapon." << endl;
	do {
		cin >> choice;
		if (weapons[choice] == "empty") {
			cout << "selection is invalid, try again." << endl;
		}
		WeaponItem = weapons[choice];
	} while (weapons[choice] == "empty");
	
	cout << " assigned weapon = " << WeaponItem << endl;
	if (WeaponItem == "broken bottle") {
		Damage = 10 - PlayerDifficulty;
	}
	if (WeaponItem == "mad samurai sword") {
		Damage = 20 - PlayerDifficulty;
	}
	if (WeaponItem == "wee penknife") {
		Damage = 13 - PlayerDifficulty;
	}
	if (WeaponItem == "big kitchen blade") {
		Damage = 16 - PlayerDifficulty;
	}
	if (WeaponItem == "brass knuckles") {
		Damage = 17 - PlayerDifficulty;
	}
	system("pause");

}

void Player::recievePickup()
{

	srand(time(NULL));
	int loot = rand() % 3;

	if (loot == 0) {
		HealthItem += rand() % Inventory;
		cout << "You found some painkillers." << endl;
		cout << "You now have " << HealthItem << " painkillers." << endl;
		// give health 
	}
	if (loot == 1) {
		// give weapon
		cout << "You find a weapon!" << endl;
		bool set = false;
		int weaponSelection = rand() % 5;
		bool selected = false;
		for (int i = 0; i < 5; i++) {
			if (weapons[i] == "empty" && set == false) {
				if (weaponSelection == 0) {
					weapons[i] = "broken bottle";
				}
				if (weaponSelection == 1) {
					weapons[i] = "mad samurai sword";
				}
				if (weaponSelection == 2) {
					weapons[i]= "wee penknife";
				}
				if (weaponSelection == 3) {
					weapons[i]= "big kitchen blade";
				}
				if (weaponSelection == 4) {
					weapons[i]= "brass knuckles";
				}
				set = true;
			}
			cout << weapons[i] << endl;
		}
	}
	if (loot == 2) {
		// give cash 
		int additionalCash;
		srand(time(NULL));
		additionalCash = rand() % 30;
		cout << "You find " << additionalCash << " pounds." << endl;
		Cash += additionalCash;
		cout << "You now have " << Cash << " pounds." << endl;
	}

	system("pause");
	system("CLS");
}

void Player::BuyPainKillers(int MaximumNumber) 
{
	system("CLS");
	int Price = 3 * PlayerDifficulty;
	int choice;
	cout << "Painkillers are " << Price << " each, there are "<<MaximumNumber<<" in stock.";
	cout << "How many would you like to buy?" << endl;
	do {
		cin >> choice;
	} while (choice > 0 && choice < MaximumNumber);

		if (Cash >= Price * choice) {
			//give pain killers
			HealthItem += choice;
			Cash -= Price * choice;
			cout << "You now have " << HealthItem << " painkillers and " << Cash << " pounds." << endl;
			system("pause");
			system("CLS");
		}
		else if (Cash <= Price * choice) {
			cout << "You dont have enough money for this purchase, you attempt to barter with the man, which goes down badly." << endl;
			cout << "You swiftly make for the exit." << endl;
			system("pause");
			system("CLS");
		}
}

void Player::BuyArmour()
{
	int choice;
	system("CLS");
	cout << "You walk into the clothes store and see a few things. " <<"\n\n"<< endl;

	cout << "Clothes			" << endl;

	for (int i = 0; i < 3; i++) 
	{
		cout << armours[i] << endl;
	}
	
	cout << "Make a selection." << endl;
	do {
		cin >> choice;
	} while (choice <1 || choice >3 );

	if (choice == 1)
	{//25 pounds
		if (Cash >= 25)
		{
			ArmourItem = armours[0];
			Armour = 2;
		}
		else {
			cout << "You go to pay and realise you cannot afford this, embarrassed, you quickly make your exit" << endl;
		}
	}
	if (choice == 2)
	{//35 pounds
		if (Cash >= 35)
		{
			ArmourItem = armours[1];
			Armour = 3;
		}
		else {
			cout << "You go to pay and realise you cannot afford this, embarrassed, you quickly make your exit" << endl;
		}

	}
	if (choice == 3)
	{//50 pounds
		if (Cash >= 50) 
		{
			ArmourItem = armours[2];
			Armour = 4;
		}
	}
	else {
		cout << "You go to pay and realise you cannot afford this, embarrassed, you quickly make your exit" << endl;
	}
	cout << "Satisfied with your purchase, you leave the shop" << endl;
	system("CLS");
	system("pause");




}
