#pragma once
#include<iostream>
using namespace std;

class ArrayStack {
private:
	int *arr;
	int capacity;
	int position;
public:
	ArrayStack(int capacity);
	~ArrayStack();
	bool push(int value);
	int pop();
	int top();
	bool isEmpty();
};
class Node {
public:
	int value;
	Node *next;
};
class LinkedStack {
private:
	Node *head;
public:
	LinkedStack();
	~LinkedStack();
	void push(int value);
	int pop();
	Node* top();
	bool isEmpty();
};