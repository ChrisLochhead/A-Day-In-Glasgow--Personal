/*

Name: Christopher Lochhead

Student ID: B00306187

I declare that the following code was produced by Chris Lochhead as a group assignment for the GED module and that this is our own work.

I am aware of the penalties incurred by submitting in full or in part work that is not our own and that was developed by third parties that are not appropriately acknowledged.

*/


#pragma once
#include "TextPuzzleSystem.h"

class TextPuzzleDecorator : public PuzzleSystem {
private:
	PuzzleSystem * P;
	float Modifier;
public:
	TextPuzzleDecorator(PuzzleSystem *p, float m) 
	{
		P = p;
		Modifier = m;
	}

	// decorator uses this function to modify which puzzle is being called
	void CallPuzzleScript(Player* player1, int puzzlescript) { P->CallPuzzleScript(player1, puzzlescript + Modifier); };
};
