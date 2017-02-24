#include"stack.h"

ArrayStack::ArrayStack(int capacity){
	this->capacity = capacity;
	arr = new int[capacity];
	position = -1;
}
ArrayStack::~ArrayStack(){
	delete[] arr;
}
bool ArrayStack::push(int value){
	if (position == capacity - 1)
		return false;
	++position;
	arr[position] = value;
	return true;
}
int ArrayStack::pop(){
	position--;
	return arr[position+1];
}
int ArrayStack::top(){
	return arr[position];
}
bool ArrayStack::isEmpty(){
	return position == -1;
}

LinkedStack::LinkedStack() {
	head = NULL;
}
LinkedStack::~LinkedStack() {
	while (head != NULL) {
		Node *temp = head;
		head = head->next;
		delete temp;
	}
}

void LinkedStack::push(int value){
	Node *newNode = new Node;
	newNode->value = value;
	newNode->next = head;
	head = newNode;
}
int LinkedStack::pop(){
	Node *temp = head;
	head = temp->next;
	int value = temp->value;
	delete temp;
	return value;
}
Node* LinkedStack::top(){
	return head;
}
bool LinkedStack::isEmpty(){
	return head== NULL;
}