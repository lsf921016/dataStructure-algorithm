#pragma once
#include<iostream>
using namespace std;
class arrayQueue{
private:
	int *arr;
	int pWrite;
	int pRead;
	int capacity;
public:
	arrayQueue(int capacity);
	~arrayQueue();
	bool push(int value);
	int poll();
	int top();
	bool isEmpty();
};