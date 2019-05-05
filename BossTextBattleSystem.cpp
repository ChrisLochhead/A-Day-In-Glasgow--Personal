/*

Name: Christopher Lochhead

Student ID: B00306187

I declare that the following code was produced by Chris Lochhead as a group assignment for the GED module and that this is our own work.

I am aware of the penalties incurred by submitting in full or in part work that is not our own and that was developed by third parties that are not appropriately acknowledged.

*/


#include "BossTextBattleSystem.h"

int BossTextBattleSystem::roll(int min, int max)
{
	int randNum = (rand() % max) + min;
	// x is in [0,1[
	double x = rand() / static_cast<double>(RAND_MAX + 1);

	// [0,1[ * (max - min) + min is in [min,max[
	int that = min + static_cast<int>(x * (max - min));

	return that;
}

bool BossTextBattleSystem::fight(Player* player1, EnemyEntity* enemy1) {
	int choice;

	cout << "\n";
	cout << player1->getPlayerName() << " health: " << player1->getPlayerHealth() << endl;
	cout << enemy1->getEnemyName() << " health: " << enemy1->getEnemyHealth() << endl;
	srand(time(NULL));

	do {
		if (enemy1->getEnemyHealth() <= 0) {
			BattleScript(player1, enemy1, roll(7, 9)); // win
			return true;
		}

		if (player1->getPlayerHealth() <= 0) {
			BattleScript(player1, enemy1, roll(13, 15)); // lose
			return false;
		}

		cout << "Do you..." << "\n";
		cout << "1: attack" << endl;
		cout << "2: use a painkiller" << endl;
		cout << "3: switch weapons" << endl;
		cin >> choice;
		do {
			switch (choice) {
			case 1:
				enemy1->setEnemyHealth(player1->getPlayerDamage());
				if (player1->getPlayerDamage() == 0) {
					BattleScript(player1, enemy1, 4);
				}
				else {
					int script = roll(5, 7);
					BattleScript(player1, enemy1, script);
				}
				break;
			case 2:
				// health function
				player1->usePainkiller();
				system("CLS");
				break;

			case 3:
				// switch weapon function
				player1->switchWeapon();
				system("CLS");
				break;

			default:
				cout << "invalid choice" << endl;
				break;

			}
		} while (choice != 1 && choice != 2 && choice != 3);

		///// end of player hit
		if (enemy1->getEnemyHealth() > 0) {
			cout << enemy1->getEnemyName() << " health: " << enemy1->getEnemyHealth() << "\n";
			system("pause");
			cout << "\n";
		}

		cout << enemy1->getEnemyName() << " attempts to attack you" << endl;
		player1->setPlayerHealth(enemy1->getEnemyDamage());

		if (enemy1->getEnemyDamage() == 0)
		{
			int script = roll(9, 11);
			BattleScript(player1, enemy1, script);
		}
		else
		{
			int script = roll(11, 13);
			BattleScript(player1, enemy1, script);
		}

		///// end of enemy hit
		cout << player1->getPlayerName() << " health: " << player1->getPlayerHealth() << endl;
		system("pause");
		cout << "\n";

	} while (enemy1->getEnemyHealth() > 0 && player1->getPlayerHealth() > 0);

	return true;

}