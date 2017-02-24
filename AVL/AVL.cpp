#include"AVL.h"

AVL::AVL(){
	root = NULL;
}
Node* AVL::clear(Node *root){
	if (root != NULL) {
		clear(root->left);
		clear(root->right);
		delete root;
	}
}
int AVL::height(Node *node) {
	if (node == NULL)
		return 0;
	else
		return node->height;
}
Node* AVL::find(int value, Node *root){
	if (root == NULL)
		return NULL;
	if (value < root->value)
		return find(value, root->left);
	else if (value > root->value)
		return find(value, root->right);
	else
		return root;
}
Node* AVL::findMin(Node* root){
	if (root == NULL)
		return NULL;
	else if (root->left == NULL)
		return root;
	else
		return findMin(root->left);
}
Node* AVL::findMax(Node* root){
	if (root != NULL) {
		while (root->right != NULL)
			root = root->right;
	}
	return root;
}
Node* AVL::insert(int value, Node* root){
	if (root == NULL) {
		root = new Node;
		root->value = value;
		root->height = 0;
		root->left = root->right = NULL;
	}
	else(value < root->value){
		insert(value, root->left);
	}
	return root;
}
Node* AVL::remove(int value, Node* root){}