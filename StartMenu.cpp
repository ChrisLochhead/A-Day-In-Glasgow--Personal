/*

Name: Christopher Lochhead

Student ID: B00306187

I declare that the following code was produced by Chris Lochhead as a group assignment for the GED module and that this is our own work.

I am aware of the penalties incurred by submitting in full or in part work that is not our own and that was developed by third parties that are not appropriately acknowledged.

*/


#include "StartMenu.h"

 StartMenu::StartMenu(int difficulty) { // create initial menu

	Difficulty = difficulty; // assign difficulty
	int choice;
	do {
		// create menu display
		cout << "Welcome to a day in Glasgow!" << endl;
		cout << "0: exit this program" << endl;
		cout << "1: Start game" << endl;
		cout << "2: Instructions" << endl;
		cout << "3: Game settings" << endl;
		cout << "Select an option by pressing the corresponding key" << endl;
		cin >> choice;  // get choice
		switch (choice) {
		case 0:
			exit(0);
			// exit menu
			break;
		case 1:
			// create player
			system("CLS");
			cout << "Enter your characters name" << endl;
			cin >> Name;
			createPlayer(Name, Difficulty);
			break;
		case 2:
			//show instructions
			system("CLS");
			showInstructions();
			break;
		case 3:
			//change difficulty
			changeDifficulty();
			break;
		default:
			cout << "Invalid entry, please select one of the available options." << endl;
			break;
		}
	} while (choice != 0);

}
void  StartMenu::createPlayer(string name, int difficulty) {// create an instance of game

	AbstractGameMap* game = new GameMap(name, difficulty);
}

void StartMenu::showInstructions() { // instructions

	cout << "					INSTRUCTIONS:					" << "\n";
	cout << "" << "\n" << "\n";
	cout <<"You play as a naive young Edinburgh resident who has went to Glasgow to visit family."<< "\n"; 
	cout <<"Your day goes from bad to worse as you witness and experience the madness Glasgow has to offer." << "\n";
	cout <<"This game is a text-based RPG  and the only controls are to press the corresponding number on" << "\n";
	cout <<"the option you wish to take. The aim of this game is to get to your extended families home in" << "\n";
	cout <<"an affluent south-side neighborhood, but you will soon realise things wont be so simple." << "\n";
	system("pause");
	system("CLS");
}


void StartMenu::changeDifficulty() { // set difficulty, in this particular type of start menu, difficulty is based on number that difficulty corresponds to

	string difficulty;
	int choice;
	if (Difficulty == 1) {
		difficulty = "easy";
	}else
		if (Difficulty == 2) {
			difficulty = "medium";
		}else
			if (Difficulty == 3) {
				difficulty = "hard";
			}
	cout << " The current difficulty is "<< difficulty << ", would you like to change this?" << endl;
	cout << "1: yes" << "\n" << "2: no" << endl;
	cin >> choice;

	switch (choice) {
	case 1:
		cout << "1: easy" << endl;
		cout << "2: medium" << endl;
		cout << "3: hard" << endl;
		cout << "choose difficulty" << endl;
		do {
			cin >> Difficulty;
		} while (Difficulty <= 0 || Difficulty > 3);

		if (Difficulty == 1) {
			difficulty = "easy";
		}
		else
			if (Difficulty == 2) {
				difficulty = "medium";
			}
			else
				if (Difficulty == 3) {
					difficulty = "hard";
				}
		cout << "Difficulty is now " << difficulty << endl;
		system("pause");
		system("CLS");
		break;
	}
}

