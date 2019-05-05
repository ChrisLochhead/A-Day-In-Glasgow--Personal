/*

Name: Christopher Lochhead

Student ID: B00306187

I declare that the following code was produced by Chris Lochhead as a group assignment for the GED module and that this is our own work.

I am aware of the penalties incurred by submitting in full or in part work that is not our own and that was developed by third parties that are not appropriately acknowledged.

*/


#pragma once
#include <vector>
#include "Observer.h"

using namespace std;


class Subject
{
protected:
	vector<Observer*> observers;
public:
	virtual void registerObserver(Observer* observer) = 0;
	virtual void notifyObserver(int newDiff) = 0;
	virtual void removeObserver(Observer* observer) = 0;

	virtual void changeDifficulty(Subject* subject, int newDiff) = 0;
	virtual void setDifficulty(int newDiff) = 0;
};