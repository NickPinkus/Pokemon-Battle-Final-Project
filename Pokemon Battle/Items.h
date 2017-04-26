#pragma once
#include <string>
using namespace std;

class Items
{
private:
	string ItemName;
	int ItemCount;
	bool UseItemAttempt;

public:
	Items(string ItemName, int ItemCount);
	~Items();

	void UseItem();
	string GetItemName();
	int GetItemCount();
};