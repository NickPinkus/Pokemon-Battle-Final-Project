#include "Items.h"



Items::Items(string ItemName, int ItemCount) : ItemName(ItemName), ItemCount(ItemCount)
{
}


Items::~Items()
{
}

void Items::UseItem()
{
	if (ItemCount > 0)
	{
		ItemCount--;
	}
}

string Items::GetItemName()
{
	return ItemName;
}

int Items::GetItemCount()
{
	return ItemCount;
}
