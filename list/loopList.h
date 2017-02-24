#pragma once
#include<iostream>
#include"List.h"
using namespace std;

class LoopList {
private:
	Node *head;
	//Node *tail;
	int length;
	Node *position;
public:
	int getLength();
	bool insertToFirst(int value);
	bool deleteByKey(int value);
	bool deleteByIndex(int index);
	Node* getNext();
	LoopList();
	~LoopList();
};
