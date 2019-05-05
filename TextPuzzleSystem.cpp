/*

Name: Christopher Lochhead

Student ID: B00306187

I declare that the following code was produced by Chris Lochheadas a group assignment for the GED module and that this is our own work.

I am aware of the penalties incurred by submitting in full or in part work that is not our own and that was developed by third parties that are not appropriately acknowledged.

*/


#include "TextPuzzleSystem.h"
#include <iostream>

using namespace std;

void TextPuzzleSystem::CallPuzzleScript(Player* player1, int puzzlescript)
{
	if (puzzlescript == 1)
	{
		bool win = NULL;
		int choice;
		int numberOfAttempts = 4 - player1->getPlayerDifficulty();

		do {
			if (numberOfAttempts != 0) {
				//trying to gather clues 
				cout << "You are looking for clues and there is stuff everywhere, you reckon you have time to " << "\n";
				cout << "search " << numberOfAttempts << "things before that door gives away and those neds get in. You see a desk filled with old papers " << "\n";
				cout << "and some unlocked desk drawers. There is some cardboard boxes in the corner, a chair with a piece of paper" << "\n";
				cout << "stuck in the back, a desolate looking bookshelf with a few dusty books and a single solitary window with some torn curtains" << "\n";
				cout << "Do you:" << "\n\n";
				cout << "1: check the desk" << "\n";
				cout << "2: check the boxes" << "\n";
				cout << "3: check the chair" << "\n";
				cout << "4: check the bookshelf" << "\n";
				cout << "5: look out the window to try escape" << "\n";
				cout << "6: check your bag	" << "\n";
				cin >> choice;

				switch (choice)
				{
				case 1:
					cout << "checked desk" << endl;
					numberOfAttempts--;
					break;
				case 2:
					cout << "checked boxes" << endl;
					numberOfAttempts--;
					break;
				case 3:
					cout << "checked chair" << endl;
					numberOfAttempts--;
					break;
				case 4:
					cout << "checked bookshelf" << endl;
					numberOfAttempts--;
					break;
				case 5:
					cout << "looked out window" << endl;
					numberOfAttempts--;
					break;
				case 6:
					player1->checkBag();
					break;
				}
			}
			else {
				//trying to crack the door
				int tries = 3;
				int door = 147036;
				cout << door << endl;
				int code;
				system("CLS");
				cout << "You have ran out of time, its now or never, it looks like you only have 3 tries at getting this door open" << "\n";
				cout << "Hurry up and enter the what you think the code is, from the keypad you deduce that its 6 digits" << "\n";
				cout << "Enter the code" << "\n";

			do{
					cin >> code;
					tries--;
				
					if (code == door)
					{
						//you succeed
						win = true;
						cout << "SUCESS" << endl;
						system("pause");
						break;

					}
					else
					{
						cout << "Code is incorrect, try again." << endl;
					}
				} while (tries > 0);
				win = false;
				cout << "Your dead" << "\n";
				cout << "" << "\n";
				cout << "" << "\n";
				cout << "" << "\n";
				system("pause");
				exit(0);

			}

		} while (win == NULL);

	}
}