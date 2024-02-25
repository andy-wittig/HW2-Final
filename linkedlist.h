#pragma once
#ifndef LINKED_LIST
#define LINKED_LIST

#include "list.h"
#include "node.h"

template<class ItemType>
class LinkedList : public ListInterface<ItemType>{
	Node<ItemType>* headPtr; 
	int itemCount; // Current count of list items

	Node<ItemType>* getNodeAt(int position) const {
		// enforce precondition
		if ((position >= 1) && (position <= itemCount)) {
			// Count from the beginning of the chain
			Node<ItemType>* curPtr = headPtr;
			for (int skip = 1; skip < position; skip++) {
				curPtr = curPtr->getNext();
			}
			return curPtr;
		}
		return nullptr;
	}
public:
	LinkedList() : headPtr(nullptr), itemCount(0) {}

	LinkedList(const LinkedList<ItemType>& aList) {
		cout << "implement me!" << endl; //remove this and add the correct code
	}

	bool isEmpty() const {
		return itemCount == 0;
	}

	int getLength() const {
		return itemCount;
	}

	bool insert(int newPosition, const ItemType& newEntry) {
		bool ableToInsert = (newPosition >= 1) && (newPosition <= itemCount+1);
		if (ableToInsert) 
		{
			if (newPosition == 1)
			{
				if (headPtr == nullptr)
				{
					headPtr = new Node<ItemType>(newEntry);
				}
				else
				{
					Node<ItemType>* oldHead = headPtr;
					headPtr = new Node<ItemType>(newEntry);
					headPtr->setNext(oldHead);
				}
			}
			else
			{
				Node<ItemType>* newPtr = new Node<ItemType>(newEntry);
				Node<ItemType>* prevPtr = getNodeAt(newPosition-1);
				Node<ItemType>* curPtr = getNodeAt(newPosition);

				prevPtr->setNext(newPtr);
				newPtr->setNext(curPtr);
				
			}
			itemCount++;
			return ableToInsert;
		}
	}

	bool remove(int position) {
		bool ableToRemove = (position >= 1) && (position <= itemCount);
		if (ableToRemove) {
			Node<ItemType>* ptrToDelete = nullptr;
			if (position == 1) {
				// Remove the first node in the chain
				ptrToDelete = headPtr; // Save pointer to node 
				headPtr = headPtr->getNext();// save pointer to next node
			}
			else {
				// Find node that is before the one to remove
				Node<ItemType>* prevPtr = getNodeAt(position - 1);
				// Point to node to remove
				ptrToDelete = prevPtr->getNext();
				// Disconnect indicated node from chain by connecting the prior node with the one after
				prevPtr->setNext(ptrToDelete->getNext());
			}

			ptrToDelete->setNext(nullptr);
			delete ptrToDelete;
			ptrToDelete = nullptr;
			itemCount--; // Decrease count of entries
		}
		return ableToRemove;
	}

	void clear() {
		Node<ItemType>* curPtr = headPtr;
		Node<ItemType>* nextPtr = nullptr;
		while (curPtr != nullptr)
		{
			nextPtr = curPtr->getNext();
			delete curPtr;
			curPtr = nextPtr;
		}
		headPtr = nullptr;
		itemCount = 0;
	}

	ItemType getEntry(int position) const {
		bool ableToGet = (position >= 1) && (position <= itemCount);
		if (ableToGet)
		{
			Node<ItemType>* nodePtr = getNodeAt(position);
			ItemType temp_item = nodePtr->getItem();
			return temp_item;
		}
		throw "Index out of range";
	}

	ItemType replace(int position, const ItemType& newEntry) {
		// enforce precondition
		bool ableToReplace = (position >= 1) && (position <= itemCount);
		if (ableToReplace) {
			Node<ItemType>* nodePtr = getNodeAt(position);
			ItemType oldEntry = nodePtr->getItem();
			nodePtr->setItem(newEntry);
			return oldEntry;
		}
		throw "Item not found";
	}

	~LinkedList() {
		clear();
	}
};
#endif