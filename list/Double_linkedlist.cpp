#include"Double_linkedlist.h"

DoubleLinkedList:: DoubleLinkedList(){
	head = new DNode;
	tail = new DNode;
	head->next = tail;
	head->prev = NULL;
	tail->next = NULL;
	tail->prev = head;
	length = 0;
}

bool DoubleLinkedList::isEmplty(){
	return head->next== tail;
}
DNode* DoubleLinkedList::findByKey(int key){
	
	for (DNode *node = head->next; node!=tail; node = node->next) {
		if (node->value == key)
			return node;
	}
	return NULL;
}
DNode* DoubleLinkedList::findByIndex(int index) {
	if (index > 0 && index < length) {
		DNode *node = head->next;
		for (int i = 0; i < index; i++)
			node = node->next;
		return node;
	}
	return NULL;
}
int DoubleLinkedList::insert(int position, int value){
	if (position > 0 && position < length) {
		DNode *node = head->next;
		DNode *insertNode = new DNode;
		for (int i = 0; i < position; i++)
			node = node->next;
		insertNode->value = value;
		insertNode->next = node;
		insertNode->prev = node->prev;
		node->prev = insertNode;
		insertNode->prev->next = insertNode;
		length++;
		return SUCCESS;
	}
	return POSITION_INVALID;
}
bool DoubleLinkedList::removeByKey(int value){

	for (DNode *node = head->next; node != tail; node = node->next) {
		if (node->value == value) {
			node->prev->next = node ->next;
			node->next->prev = node->prev;
			delete node;
			length--;
			return true;
		}
	}
	return false;
}
int DoubleLinkedList::removeByIndex(int index){
	DNode *node = head->next;
	if (index < 0 || index >= length)
		return POSITION_INVALID;
	for (int i = 0; i < index; i++) 
		node = node->next;

		node->prev->next = node->next;
		node->next->prev = node->prev;
		delete node;
		length--;
		return SUCCESS;

}
int DoubleLinkedList::getLength(){
	return length;
}
void DoubleLinkedList::display(){
	for (DNode *node = head->next; node != tail; node = node->next)
		cout << node->value << " ";
	cout << endl;
}
DoubleLinkedList::~DoubleLinkedList(){
	DNode *node = head;
	DNode *temp = NULL;
	while (node != NULL)
	{
		temp = node;
		node = node->next;
		delete temp;

	}
}
DNode* DoubleLinkedList::reverseFind(int rIndex) {
	if (rIndex < 0 || rIndex >= length)
		return  NULL;
	DNode *node = tail->prev;
	for (int i = 0; i < rIndex; i++)
		node = node->prev;
	return node;

}
int DoubleLinkedList::reverseInsert(int rIndex) {
	if (rIndex < 0 || rIndex >= length)
		return  POSITION_INVALID;
	DNode *node = tail->prev;
	DNode *insertNode = new DNode;
	for (int i = 0; i < rIndex; i++)
		node = node->prev;

	insertNode->next = node->next;
	insertNode->prev = node;
	node->next = insertNode;
	insertNode->next->prev = insertNode;
	++length;
	return SUCCESS;
}