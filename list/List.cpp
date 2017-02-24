#include"List.h"

ArrayList::ArrayList() {
	capacity = 32;
	arrayList = new int[capacity];
	length = 0;
}

ArrayList::ArrayList(int capacity) {
	this->capacity = capacity;
	arrayList = new int[capacity];
	length = 0;
}

ArrayList::~ArrayList() {
	delete[] arrayList;
}

bool ArrayList::isEmplty() {
	return length == 0 ? true : false;
}

int ArrayList::findByKey(int key) {
	for (int i = 0; i < length; i++) {
		if (arrayList[i] == key)
			return i;
	}
	return -1;
}
int ArrayList::findByIndex(int index) {
	return arrayList[index];
}

int ArrayList::insert(int position, int value) {
	if (length == capacity)
		return ARRAY_FULL;
	if (position <= length && position >= 0) {
		for (int i = length; i > position; i--) {
			arrayList[i] = arrayList[i - 1];
		}
		arrayList[position] = value;
		++length;
		return SUCCESS;
	}
	return POSITION_INVALID;
}
bool ArrayList::removeByKey(int value) {
	for (int i = 0; i < length; i++) {
		if (value == arrayList[i]) {
			length--;
			for (i; i < length; i++)
				arrayList[i] = arrayList[i + 1];
			return true;
		}
	}
	return false;
}
int ArrayList::removeByIndex(int index) {
	if (index > length - 1||index<0)
		return POSITION_INVALID;
	length--;
	for (int i = index; i < length; i++) {
		arrayList[index] = arrayList[index + 1];
	}
	return SUCCESS;
	
}
int ArrayList::getLength() {
	return length;
}

void ArrayList::display() {
	for (int i = 0; i < length; i++)
		cout << arrayList[i]<<" ";
	cout << endl;
}

LinkedList::LinkedList() {
	linkedlist = new Node;
	linkedlist->next = NULL;
	length = 0;
}
bool LinkedList::isEmplty(){
	return linkedlist->next == NULL;
}
Node* LinkedList::findByKey(int key) {
	
	for(Node *node = linkedlist->next;node!=NULL;node=node->next)
		if (key == node->value)
			return node;
	return NULL;
}
Node* LinkedList::findByIndex(int index) {
	if (index >= length || index<0)
		return NULL;
	Node *node = linkedlist->next;
	for (int i = 0; i < index; i++)
		node = node->next;
	return node;

}
int LinkedList::insert(int position, int value){
	if (position<0 || position>length)
		return POSITION_INVALID;

	Node *newNode = new Node;
	newNode->value = value;
	Node *node = linkedlist;

	for (int i = 0; i < position; i++)
		node = node->next;

	newNode->next = node ->next;
	node->next = newNode;
	length++;
	return SUCCESS;
}
bool LinkedList::removeByKey(int value) {
	for (Node *node = linkedlist; node->next != NULL; node = node->next) {
		if (node->next->value == value) {
			Node *tempNode = node->next;
			node->next = node->next->next;
			delete tempNode;
			length--;
			return true;
		}
	}
	return false;
}
int LinkedList::removeByIndex(int index){
	if (index < 0 || index >= length)
		return POSITION_INVALID;
	Node *node = linkedlist;
	for (int i = 0; i < index; i++)
		node = node->next;
	Node *tempNode = node->next;
	node->next = tempNode->next;
	delete tempNode;
	length--;
	return SUCCESS;
}
int LinkedList::getLength(){
	return length;
}
void LinkedList::display(){
	for (Node *node = linkedlist->next; node != NULL; node = node->next)
		cout << node->value << " ";
}
LinkedList::~LinkedList(){
	for (Node *tempNode = linkedlist; tempNode!= NULL;) {
		Node *deleteNode = tempNode;
		tempNode = tempNode->next;
		delete deleteNode;
	}
}