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
	while (this->head) {
		DequeNode* node = this->head;
		this->head = this->head->next;
		delete node;
	}
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
			head->prev = newNode;
			head = newNode;
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
			tail->next = newNode;
			newNode->prev = tail;
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
	if (this->IsEmpty())
	{
		throw "UnderFlow\n";
	}
	else
	{
		DequeNode* temp = head;
		head = head->next;
		int item;

		// If only one element was present 
		if (head == NULL) {
			tail = NULL;
			this->noOfItems--;
			 item = temp->item;
			delete(temp);
			return item;
		}
		head->prev = NULL;
		// Decrements count of elements by 1 
		this->noOfItems--;
		item =  temp->item;
		delete(temp);
		return item;
	}
} //end-RemoveFront

///------------------------------------------------------
/// Remove and return the item at the rear of the Deque
/// If the Deque is empty, throw an exception
/// 
int Deque::RemoveRear() {
	// Fill this in
	if (this->IsEmpty())
	{
		throw "UnderFlow\n";
	}
	else
	{
		DequeNode* temp = tail;
		tail = tail->prev;
		int item;
		// If only one element was present 
		if (tail == NULL) {
			head = NULL;
			this->noOfItems--;
			item = temp->item;
			delete(temp);
			return item;
		}
		tail->next = NULL;
		// Decrements count of elements by 1 
		this->noOfItems--;
		item = temp->item;
		delete(temp);
		return item;
	}
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
