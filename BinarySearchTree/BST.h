#pragma once
#include<iostream>
using namespace std;

class Node {
public:
	int value;
	Node *left;
	Node *right;
};
class BST {
private:
	Node *root;
public:
	BST(int value);
	~BST();
	Node* clear(Node *rt);
	Node* remove(int value, Node *rt);
	Node* deleteMin(Node *rt);
	Node* find(int value, Node *rt);

};