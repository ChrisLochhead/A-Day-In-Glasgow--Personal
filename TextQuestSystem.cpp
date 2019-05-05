/*

Name: Christopher Lochhead

Student ID: B00306187

I declare that the following code was produced by Chris Lochhead as a group assignment for the GED module and that this is our own work.

I am aware of the penalties incurred by submitting in full or in part work that is not our own and that was developed by third parties that are not appropriately acknowledged.

*/


#include "TextQuestSystem.h"
#include <iostream>

using namespace std;


bool TextQuestSystem::getQuestCompleted()
{
	bool value;
	int counter = 0;
	for (int i = 0; i < QuestNames->length(); i++)
	{
		if (QuestsCompleted[i] == false)
		{
			counter++;
		}
		
	}
	if (counter == 3)
	{
		value = true;
	}
	else {
		value = false;
	}
	return value;
}

void TextQuestSystem::checkQuests(Player* player1)
{
	int choice;
	int startQuest;
	cout << "		Quest List" << endl;

	cout << "Quest Journal" << endl;

	for (int i = 0; i < 3; i++)
	{
		if (QuestsCompleted[i] == true) {
			cout << QuestNames[i] << " completed" << endl;
		}
		else {
			cout << QuestNames[i] << " not completed." << endl;
		}

	}

	cout << "Do you wish to start a quest?" << endl;
	cout << "1: Yes" << "\n" << "2: No" << endl;
	cin >> choice;
	if (choice == 1) {

		for (int i = 0; i < 3; i++)
		{
			if (QuestsCompleted[i] == false) {
				cout <<"Starting "<< QuestNames[i] << endl;
				break;
			}
		}
		if (getQuestCompleted() == true)
		{
			cout << "You have completed all available quests" << endl;
			system("pause");
		}
		else {
			cout << "You begin your quest..." << endl;
			CallQuestScript(player1, choice);
			//call right script
		}
	}
	else {
		cout << "You go off your phone and back to the matter at hand" << endl;
		system("pause");
	}


}

void TextQuestSystem::	CallQuestScript(Player* player1, int questnumber)
{
	if (questnumber == 1)
	{
		cout << "You have chosen an easy puzzle-based quest" << endl;
		//first quest
	}
	if (questnumber == 2)
	{
		cout << "you have chosen a difficult, puzzle-based quest" << endl;
		//second quest
	}
	if (questnumber == 3)
	{
		cout << "You have chosen a hard, battle-based quest" << endl;
		//third quest
	}
	if (questnumber == 6)
	{
		cout << "You have chosen the secret, extremely difficult quest" << endl;
	}
}