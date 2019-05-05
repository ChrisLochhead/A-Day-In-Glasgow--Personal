/*

Name: Christopher Lochhead

Student ID: B00306187

I declare that the following code was produced by Chris Lochheadas a group assignment for the GED module and that this is our own work.

I am aware of the penalties incurred by submitting in full or in part work that is not our own and that was developed by third parties that are not appropriately acknowledged.

*/


#include "NormalTextBattleSystem.h"

void NormalTextBattleSystem::BattleScript(Player* player1, EnemyEntity* enemy1, int scriptnumber) { // scripts during fight, randomly generated


	if (scriptnumber == 1) {
		cout << "You ready yourself for a tussle and the " << enemy1->getEnemyName() << " starts to come towards you, you begin shaking but" << "\n";
		cout << "your fear quickly turns into resolve.";

	}
	if (scriptnumber == 2) {
		cout << "the " << enemy1->getEnemyName() << " begins blasting their way towards you but you see an opportunity to make the first attack and" << "\n";
		cout << "attempt to take the " << enemy1->getEnemyName() << " by surprise" << "\n";
	}
	if (scriptnumber == 3) {
		cout << "using your " << player1->getWeaponItem() << " you begin an offensive against the " << enemy1->getEnemyName() << " and just hope all goes well" << "\n";
	}
	if (scriptnumber == 4) {
		cout << "you attempt to attack, but you barely scratch your assailant, pathetic" << "\n";
	}
	if (scriptnumber == 5) {
		cout << "you attack, mauling "<<enemy1->getEnemyName()<<" in the face pretty bad" << "\n";
	}
	if (scriptnumber == 6) {
		cout << "your attack devastates the "<< enemy1->getEnemyName()<<", Im amazed theyre even still standing" << "\n";
	}
	if (scriptnumber == 7) {
		cout << "aw! you totally probably killed that dude... yeah there not moving you should get the fuck out of here" << "\n";
	}
	if (scriptnumber == 8) {
		cout << "your assailant drops to the ground absolutely devoid of consciousness, nice one. " << "\n";
	}
	if (scriptnumber == 9) {
		cout << "your enemy attacks and completely whiffs and misses you by a fucking landslide. " << "\n";
	}
	if (scriptnumber == 10) {
		cout << "missing by a mile, you feel your confidence about this fight grow" << "\n";
	}
	if (scriptnumber == 11) {
		cout << "you get smashed in the face pretty good, and your dazed for sure. " << "\n";
	}
	if (scriptnumber == 12) {
		cout << "After a hit like that, there is absolutely zero change you aren't bleeding profusely. " << "\n";
	}

	if (scriptnumber == 13) {
		cout << "after recieving one to many blows to the face and chest area, you drop to the ground" << "\n";
		cout << "before you lost consciousness fully, you feel someone steal your shoes and rifle through your pockets" << "\n";
	}
	if (scriptnumber == 14) {
		cout << "you feel your legs give way, and after throwing up on youself, you see through tear filled eyes passersby laugh" << "\n";
		cout << "as you collapse in a pathetic heap" << "\n";
	}
}

bool NormalTextBattleSystem::fight(Player* player1, EnemyEntity* enemy1) {
	int choice;

	cout <<"\n";
	cout << player1->getPlayerName() <<" health: "<<player1->getPlayerHealth() << endl;
	cout << enemy1->getEnemyName() << " health: " <<enemy1->getEnemyHealth() << endl;
	srand(time(NULL));

	do{
		if (enemy1->getEnemyHealth() <= 0) {
			BattleScript(player1, enemy1, roll(7,9)); // win
			return true;
		}

		if (player1->getPlayerHealth() <= 0) {
			BattleScript(player1, enemy1, roll(13,15)); // lose
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
					int script = roll(5,7);
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

int NormalTextBattleSystem::roll(int min, int max)
{
	int randNum = (rand() % max) + min;
	// x is in [0,1[
	double x = rand() / static_cast<double>(RAND_MAX + 1);

	// [0,1[ * (max - min) + min is in [min,max[
	int that = min + static_cast<int>(x * (max - min));

	return that;
}