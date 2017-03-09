#include"BST.h"

BST::BST(int value){
	root = new Node;
	root->value = value;
}
BST::~BST(){
	clear(root);
	
}
Node* insert(int value, Node* root) {
	if (root == NULL) {
		root = new Node();
		root->value = value;
		root->left = root->right = NULL;
	}
	else if(value<root->value){
		root->left = insert(value, root->left);
	}
	else if (value > root->value) {
		root->right = insert(value, root->right);
	}
	return root;
}
Node* BST::clear(Node *rt) {
	if (rt != NULL) {
		clear(rt->left);
		clear(rt->right);
		delete rt;
	}
	return NULL;
}
Node* BST::find(int value, Node *rt){
	if (rt == NULL)
		return NULL;
	if (value < rt->value)
		return find(value, rt->left);
	else if (value > rt->value)
		return find(value, rt->right);
	else
		return rt;
}
Node* BST::remove(int value, Node *rt) {
	if (rt == NULL)
		cout << value << "is not in the tree\n" << endl;
	else if (value < rt->value)
		remove(value, rt->left);
	else if (value > rt->value)
		remove(value, rt->right);
	else
	{
		Node *temp = rt;
		if (rt->left == NULL)
			rt = rt->right;
		else if (rt->right == NULL)
			rt = rt->left;
		else {
			temp=deleteMin(rt->right);
			rt->value=temp->value;
		}
	}
}
//找rt的右子树的最小结点并删除
Node* BST::deleteMin(Node *rt) {
	if (rt->left != NULL)
		return deleteMin(rt->left);
	else
	{
		Node *temp=rt;
		rt = rt->right;
		return temp;
	}
}