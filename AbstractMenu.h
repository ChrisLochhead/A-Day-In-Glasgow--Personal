/*

Name: Christopher Lochhead

Student ID: B00306187

I declare that the following code was produced by Chris Lochheadas a group assignment for the GED module and that this is our own work.

I am aware of the penalties incurred by submitting in full or in part work that is not our own and that was developed by third parties that are not appropriately acknowledged.

*/


#pragma once
#include <string>
#include <iostream>

using namespace std; 

class AbstractMenu {

public:
	virtual void changeDifficulty() = 0;
	virtual void createPlayer(string name, int difficulty) = 0;

};