#pragma once
#ifndef ARRAY_LIST
#define ARRAY_LIST

#include "list.h"

template<class ItemType>
class ArrayList : public ListInterface<ItemType>{
    static const int DEFAULT_CAPACITY = 100;
    ItemType items[DEFAULT_CAPACITY + 1]; //(ignore item[0])
    int itemCount;
    int maxCount;
public:
	ArrayList() : maxCount(DEFAULT_CAPACITY), itemCount(0) {}

	ArrayList(const ArrayList<ItemType>& aList) {
		cout << "implement me!" << endl; //remove this and add the correct code
	}

	bool isEmpty() const {
		bool empty = (itemCount == 0);
		return empty;
	}

	int getLength() const {
		return itemCount;
	}

	bool insert(int newPosition, const ItemType& newEntry) {
		bool ableToInsert = (newPosition >= 1) &&
			(newPosition <= itemCount + 1) &&
			(itemCount < maxCount);
		if (ableToInsert) {
			for (int pos = itemCount + 1; pos > newPosition; pos--) {
				items[pos] = items[pos - 1];
			}
			items[newPosition] = newEntry;
			itemCount++;
		}
		return ableToInsert;
	}

	bool remove(int position)
	{
		bool ableToRemove = (position >= 1) && (position <= itemCount);

		if (ableToRemove)
		{
			for (int pos = position; pos < itemCount; pos++)
			{
				items[pos] = items[pos + 1];
			}
			itemCount--;
		}
		return ableToRemove;
	}

	void clear() {
		itemCount = 0;
	}

	ItemType getEntry(int position) const {
		bool ableToGet = (position >= 1) && (position <= itemCount);

		if (ableToGet) {
			return items[position];
		}
		throw "Item not found";
	}

	ItemType replace(int position, const ItemType& newEntry) {
		bool ableToReplace = (position >= 1) && (position <= itemCount);
		if (ableToReplace)
		{
			items[position] = newEntry;
		}
		throw "Index out of range";
		ItemType temp;
		return temp; //SHOULD RETURN OLD ENTRY
	}
	
	~ArrayList() {}
};
#endif
