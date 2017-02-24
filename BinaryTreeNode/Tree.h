#pragma once
#include<iostream>
using namespace std;

class BinaryTreeNode {
	friend class BinaryTreeNode;
private:
	int info;
	BinaryTreeNode *left;
	BinaryTreeNode *right;
public:
	BinaryTreeNode();
	BinaryTreeNode(int info);
	BinaryTreeNode(int info, BinaryTreeNode *left, BinaryTreeNode *right);
	void visit();
	int value()const;
	BinaryTreeNode* leftChild()const;
	BinaryTreeNode* rightChild()const;
	void setLeftChild(BinaryTreeNode *left);
	void setRightChild(BinaryTreeNode *right);
	void setValue(const int& value);
	bool isLeaf()const;
	BinaryTreeNode& operator=(BinaryTreeNode& node);
};
class StackNode {
public:
	BinaryTreeNode *root;
	StackNode *next;
};
class Stack {
private:
	StackNode *head;
public:
	Stack();
	~Stack();
	void push(BinaryTreeNode *binaryTreeNode);
	BinaryTreeNode* pop();
	BinaryTreeNode* top();
	bool isEmpty();
};
class Queue {
private:
#define CAPACITY 50
	BinaryTreeNode **arr;
	int front;
	int rear;
public:
	Queue();
	~Queue();
	bool enqueue(BinaryTreeNode *binaryTreeNode);
	bool dequeue();
	BinaryTreeNode* getFront();
	int getLength();
	bool isEmpty();
};

class BinaryTree {
private:
	BinaryTreeNode *root;
public:
	BinaryTree();
	~BinaryTree();
	bool isEmpty();
	void visit(BinaryTreeNode *binaryTreeNode);
	BinaryTreeNode* Root();
	BinaryTreeNode* parent(BinaryTreeNode *curRoot,BinaryTreeNode *current);
	BinaryTreeNode* parent(BinaryTreeNode *current);
	BinaryTreeNode* leftSibling(BinaryTreeNode *current);
	BinaryTreeNode* rightSibling(BinaryTreeNode *current);
	void createTree(int info, BinaryTreeNode leftTree, BinaryTreeNode rightTree);
	void preOrder(BinaryTreeNode *root);//访问根节点—》按前序遍历左子树-》按前序遍历右子树
	void inOrder(BinaryTreeNode *root);//按中序遍历左子树-》访问根节点-》按中序遍历右子树
	void postOrder(BinaryTreeNode *root);//按后序遍历左子树-》按后序遍历右子树-》访问根结点
	void levelOrder(BinaryTreeNode *root);//宽度优先遍历
	void depthOrder(BinaryTreeNode *root);//前中后序都是深度优先遍历
	void deleteBinaryTree(BinaryTreeNode *root);
};