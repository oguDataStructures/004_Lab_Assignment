#include "Deque.h"

///------------------------------------------------------
/// Default constructor
/// 
Deque::Deque() {
	// Fill this in
	this->head = this->tail = NULL;
	this->noOfItems = 0;
} //end-Deque

///------------------------------------------------------
/// Destructor
/// 
Deque::~Deque() {
	// Fill this in
} //end-~Deque

///------------------------------------------------------
/// Adds a new item to the front of the Deque
/// 
void Deque::AddFront(int item) {
	// Fill this in
	
	DequeNode* newNode = new DequeNode(item);
	if (newNode == NULL) {
		throw "OverFlow\n";
	}
	else
	{
		if (this->head == NULL)
		{
			this->head = this->tail = newNode;
		}
		else
		{
			newNode->next = head;
			tail->prev = newNode;
			tail = newNode;
		}
		this->noOfItems++;
	}
} //end-AddFront

///------------------------------------------------------
/// Adds a new item to the end of the Deque
/// 
void Deque::AddRear(int item) {
	// Fill this in
	DequeNode* newNode = new DequeNode(item);
	if (newNode == NULL) {
		throw "OverFlow\n";
	}
	else
	{
		// If deque is empty 
		if (head == NULL)
			head = tail = newNode;

		// Inserts node at the rear end 
		else
		{
			newNode->prev = tail;
			tail->next = newNode;
			tail = newNode;
		}
		this->noOfItems++;
	}
	
} //end-AddRear

///------------------------------------------------------
/// Remove and return the item at the front of the Deque
/// If the Deque is empty, throw an exception
/// 
int Deque::RemoveFront() {
	// Fill this in
	return 0;
} //end-RemoveFront

///------------------------------------------------------
/// Remove and return the item at the rear of the Deque
/// If the Deque is empty, throw an exception
/// 
int Deque::RemoveRear() {
	// Fill this in
	return 0;
} //end-RemoveRear

///------------------------------------------------------
/// Return the item at the front of the Deque (do not remove the item)
/// If the Deque is empty, throw an exception
/// 
int Deque::Front() {
	// Fill this in
	if (noOfItems == 0)
		return -1;
	return this->head->item;
} //end-Front

///------------------------------------------------------
/// Return the item at the rear of the Deque (do not remove the item)
/// If the Deque is empty, throw an exception
/// 
int Deque::Rear() {
	// Fill this in
	if (noOfItems == 0)
		return -1;
	return this->tail->item;
} //end-Rear
