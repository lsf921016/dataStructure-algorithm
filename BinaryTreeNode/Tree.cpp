#include"Tree.h"

BinaryTreeNode::BinaryTreeNode(){}
BinaryTreeNode::BinaryTreeNode(int info){}
BinaryTreeNode::BinaryTreeNode(int info, BinaryTreeNode *left, BinaryTreeNode *right){}
int BinaryTreeNode::value()const{
	return info;
}

void BinaryTreeNode::visit() {
	cout << info << endl;
}

BinaryTreeNode* BinaryTreeNode::leftChild()const{}
BinaryTreeNode* BinaryTreeNode::rightChild()const{}
void BinaryTreeNode::setLeftChild(BinaryTreeNode *left){}
void BinaryTreeNode::setRightChild(BinaryTreeNode *right){}
void BinaryTreeNode::setValue(const int& value){}
bool BinaryTreeNode::isLeaf()const{}
BinaryTreeNode& BinaryTreeNode::operator=(BinaryTreeNode& node){}

// Stack model
Stack::Stack(){
	head = NULL;
}
Stack::~Stack(){
	while (head != NULL) {
		StackNode *temp = head;
		head = head->next;
		delete temp;
	}
}
void Stack::push(BinaryTreeNode *binaryTreeNode){
	StackNode *newNode = new StackNode;
	newNode->root = binaryTreeNode;
	newNode->next = head;
	head = newNode;

}
BinaryTreeNode* Stack::pop(){
	StackNode *temp = head;
	BinaryTreeNode *toBeReturn = temp->root;
	head = head->next;
	delete temp;
	return toBeReturn;

}
//队列数据结构
Queue::Queue(){
	arr = new BinaryTreeNode*[CAPACITY];
	front = 0;
	rear = -1;
}
Queue::~Queue(){
	delete[] arr;
}
bool Queue::enqueue(BinaryTreeNode *binaryTreeNode){
	if ((rear + 2) % CAPACITY == front)
		return false;
	rear = (rear + 1) % CAPACITY;
	arr[rear] = binaryTreeNode;
	return true;
}
bool Queue::dequeue(){
	if (isEmpty())
		return false;
	front=(front+1)%CAPACITY;
	return true;
}
BinaryTreeNode* Queue::getFront(){
	return arr[front];
}
bool Queue::isEmpty(){
	return rear == front + 1;
}
int Queue::getLength(){}


BinaryTreeNode* Stack::top(){
	return head->root;
}
bool Stack::isEmpty(){
	return head == NULL;
}

BinaryTree::BinaryTree(){root = NULL;}
BinaryTree::~BinaryTree() { deleteBinaryTree(root); }
void BinaryTree::visit(BinaryTreeNode *binaryTreeNode) {
	cout << binaryTreeNode->value() << endl;
}
bool BinaryTree::isEmpty(){}
BinaryTreeNode* BinaryTree::Root() { return root; }
BinaryTreeNode* BinaryTree::parent(BinaryTreeNode *curRoot,BinaryTreeNode *current){
	/*
	由于此二叉树没有指向父亲的指针（三叉树有），所以需要从根结点root开始搜索current结点的父节点
	递归实现：
	*/
	BinaryTreeNode *temp;
	if (curRoot == NULL)
		return NULL;
	if (current == curRoot->leftChild() || current == curRoot->rightChild())
		return curRoot;
	if ((temp = parent(curRoot->leftChild(), current)) != NULL)
		return temp;
	if ((temp = parent(curRoot->rightChild(), current)) != NULL)
		return temp;
	return NULL;
}
BinaryTreeNode* BinaryTree::parent(BinaryTreeNode *current) {
	//非递归实现
	Stack aStack;
	BinaryTreeNode *pointer = root;
	aStack.push(NULL);
	while (pointer) {
		if (current == pointer->leftChild() || current == pointer->rightChild())
			return pointer;
		if (pointer->rightChild() != NULL)
			aStack.push(pointer->rightChild());
		if (pointer->leftChild() != NULL)
			pointer = pointer->leftChild();
		else {
			pointer = aStack.pop();
		}
		
	}
}
BinaryTreeNode* leftSibling(BinaryTreeNode *current){}
BinaryTreeNode* rightSibling(BinaryTreeNode *current){}
void BinaryTree::createTree(int info, BinaryTreeNode leftTree, BinaryTreeNode rightTree){}
void BinaryTree::preOrder(BinaryTreeNode *root){
	/*非递归的先序遍历
	steps:
	1:构建一个空栈，并将一个值为NULL的栈底监视哨压入栈中
	2.从root开始，遇到一个节点就访问它，并将它的非空右孩子压入栈中
	3.然后下降去遍历其左子树
	4.遍历完左子树，就从栈中弹出一个结点，并按照相同的策略访问此结点的子树
	*/
	stack<int> aStack;
	BinaryTreeNode *pointer = root;
	aStack.push(NULL);//栈底监视哨
	while (pointer) {
		visit(pointer);//访问当前节点
		if (pointer->rightChild() != NULL)
			aStack.push(pointer->rightChild());//右孩子入栈

		if (pointer->leftChild() != NULL)//左孩子下降
			pointer = pointer->leftChild();
		else//此分支为访问到了叶子节点，即左孩子右孩子都为空
			pointer = aStack.pop();//pointer变为栈顶元素，并将此元素弹栈
	}

}
void BinaryTree::inOrder(BinaryTreeNode *root){
	/*
	steps：
	1.遇到一个节点，将其压栈，并遍历其左子树。
	2.遍历完左子树，从栈顶弹出一个结点并访问之。
	3.按照其右链地址遍历该结点的右子树。
	*/
	Stack aStack;
	BinaryTreeNode *pointer = root;
	while (pointer != NULL || !aStack.isEmpty()) {
		if (pointer) {
			//visit(pointer);
			aStack.push(pointer);
			pointer = pointer->leftChild();
		}
		else {
			pointer = aStack.pop();
			visit(pointer);//访问当前结点
			pointer = pointer->rightChild();
		}
	}
	
}
void BinaryTree::postOrder(BinaryTreeNode *root){

}
void BinaryTree::levelOrder(BinaryTreeNode *root){
	/*
	1.将根结点放入队列
	2.队列不为空，则取出出列一个结点并访问之，并将根节点的左孩子右孩子入列
	3.队列不为空，则取出出列一个结点并访问之，并将根节点的左孩子右孩子入列
	*/
	Queue aQueue;
	BinaryTreeNode* pointer = root;
	aQueue.enqueue(pointer);
	while (!aQueue.isEmpty()) {
		pointer = aQueue.getFront();
		aQueue.dequeue();
		visit(pointer);
		if (pointer->leftChild() != NULL)
			aQueue.enqueue(pointer->leftChild());
		if (pointer->rightChild() != NULL)
			aQueue.enqueue(pointer->rightChild());
	}
}
void BinaryTree::depthOrder(BinaryTreeNode *root) {
	//递归地访问树中的每个结点
	if (root != NULL) {
		//visit(root);前序
		depthOrder(root->leftChild());//递归访问左子树
		//visit(root);中序
		depthOrder(root->rightChild());//递归访问右子树
		//visit(root);后序
	}
}
void BinaryTree::deleteBinaryTree(BinaryTreeNode *root){}