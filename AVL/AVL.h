#pragma once
#include<iostream>
using namespace std;
class Node {
public:
	int value;
	int height;
	Node *left;
	Node *right;
};
class AVL{
private:
	Node* root;
public:
	AVL();
	static int height(Node *node);
	Node* clear(Node *root);
	Node* find(int value, Node *root);
	Node* findMin(Node* root);
	Node* findMax(Node* root);
	Node* insert(int value, Node* root);
	Node* remove(int value, Node* root);
};