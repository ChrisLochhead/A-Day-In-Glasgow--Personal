/*

Name: Christopher Lochhead

Student ID: B00306187

I declare that the following code was produced by Chris Lochhead as a group assignment for the GED module and that this is our own work.

I am aware of the penalties incurred by submitting in full or in part work that is not our own and that was developed by third parties that are not appropriately acknowledged.

*/


#pragma once
#include "QuestSystem.h"
class TextQuestSystem : public QuestSystem { // ask about how to implement this as a decorator for different types of text based puzzles

public:
	TextQuestSystem(Player* player1, int questscript)
	{

	}
// add method
	/*void CallQuestScript(Player* player1, int questscript)
	{
	}; //*/
	void checkQuests(Player* player1);
	void CallQuestScript(Player* player1, int questscript);
	bool getQuestCompleted();
private:
	string QuestNames[3] = { "1: Quest1 - easy", "2: Quest2 - medium ", "3: Quest3 - hard" };
	bool QuestsCompleted[3] = { false, false, false };


};
