#pragma once
#include<iostream>
#define ARRAY_FULL -1
#define SUCCESS 0
#define POSITION_INVALID -2
using namespace std;

class DNode {
public:
	int value;
	DNode *next;
	DNode *prev;
};
class DoubleLinkedList {
private:
	DNode *head;
	DNode *tail;
	int length;
public:
	DoubleLinkedList();
	bool isEmplty();
	DNode* findByKey(int key);
	DNode* findByIndex(int index);
	int insert(int position, int value);
	bool removeByKey(int value);
	int removeByIndex(int index);
	int getLength();
	void display();
	bool isLast(DNode *node);
	~DoubleLinkedList();
	DNode* reverseFind(int rIndex);
	int reverseInsert(int rIndex);
};