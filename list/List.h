#pragma once
#define ARRAY_FULL -1
#define SUCCESS 0
#define POSITION_INVALID -2
#include<iostream>
using namespace std;
class List {
public:
	virtual bool isEmplty() = 0;
	virtual int findByKey(int key) = 0;
	virtual int findByIndex(int index) = 0;
	virtual int insert(int position,int value) = 0;
	virtual bool removeByKey(int value) = 0;
	virtual int removeByIndex(int index) = 0;
	virtual int getLength()=0;
	virtual void display()=0;
};

class Node{
public:
	int value;
	Node *next;
};

class ArrayList : public List {
private:
	int *arrayList;
	int length;
	int capacity;
public:
	ArrayList();
	ArrayList(int capacity);
	bool isEmplty() ;
	int findByKey(int key) ;
	int findByIndex(int index) ;
	int insert(int position, int value) ;
	bool removeByKey(int value) ;
	int removeByIndex(int index) ;
	int getLength();
	void display();
	~ArrayList();
};

class LinkedList {
private:
	Node *linkedlist;
	int length;
public:
	LinkedList();
	bool isEmplty();
	Node* findByKey(int key);
	Node* findByIndex(int index);
	int insert(int position, int value);
	bool removeByKey(int value);
	int removeByIndex(int index);
	int getLength();
	void display();
	~LinkedList();
};