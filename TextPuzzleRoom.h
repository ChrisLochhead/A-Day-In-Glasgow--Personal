/*

Name: Christopher Lochhead

Student ID: B00306187

I declare that the following code was produced by Chris Lochheadas a group assignment for the GED module and that this is our own work.

I am aware of the penalties incurred by submitting in full or in part work that is not our own and that was developed by third parties that are not appropriately acknowledged.

*/


#pragma once
#include "TextPuzzleDecorator.h"

class TextPuzzleRoom : public TextPuzzleDecorator { // a decorated puzzle system
public:
	//contructor implements the puzzle decorator to change the script number
	TextPuzzleRoom(PuzzleSystem *n, float modifier) : TextPuzzleDecorator(n, modifier) 
	{

	}
	void CallPuzzleScript(Player* player1, int puzzleScript) 
	{
		TextPuzzleDecorator::CallPuzzleScript(player1, puzzleScript);
	}
};