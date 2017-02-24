#include<iostream>
#include<stdio.h>

using namespace std;

class Node {
public:
	int value;
	Node *left;
	Node *right;
};

Node* rebuild(int *postOrder,int *inOrder,int length) {
	Node *node = new Node;
	node->left = NULL;
	node->right = NULL;
	//value of root node
	node->value= postOrder[length - 1];
	//find the position of root in inOrder
	int i = 0;
	for (i; i < length&&inOrder[i] != node->value; ++i);

	int lenL = i;
	int lenR = length - 1 - i;

	if (lenL > 0) {
		node->left = rebuild(&postOrder[0],&inOrder[0] , lenL);
	}
	if (lenR > 0) {
		node->right = rebuild(&postOrder[lenL],&inOrder[lenL+1] , lenR);
	}

	return node;
}

void printPreOrder(Node *root) {
	if (root != NULL) {
		cout << root->value << ' ';
		printPreOrder(root->left);
		printPreOrder(root->right);
	}

}

int main() {
	int postOrder[4];
	int inOrder[4];
	int len = 4;
	for (int i = 0; i < 4; ++i) {
		cin >> postOrder[i];
	}
	for (int i = 0; i < 4; ++i) {
		cin >> inOrder[i];
	}
	Node *root = rebuild(postOrder, inOrder, len);

	printPreOrder(root);

	return 0;
}