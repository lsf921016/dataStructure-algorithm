#include"loopList.h"

int LoopList::getLength(){
	return length;
}
bool LoopList::insertToFirst(int value){
	Node *Newnode = new Node;
	Newnode->next = head->next;
	head->next = Newnode;
	++length;
}
bool LoopList::deleteByKey(int value){

	if (position->value == value)
		position = position->next;
	for (Node *node = head; node->next != head;
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		node = node->next) {

		if (node->next->value == value) {
			Node *temp = node->next;
			node->next = node->next->next;
			--length;
			delete temp;
			return true;
		}
	}
	return false;
}
bool LoopList::deleteByIndex(int index){
	
	if (index < 0 || index >= length)
		return false;
	Node *node = head;
	for (int i = 0; i < index; ++i) {
		node = node->next;
	}
	if (node == position)
		position = position->next;
	Node *temp = node->next;
	node->next = node->next->next;
	delete temp;
	--length;
	return true;
}
Node* LoopList::getNext() {
	if (head->next == head)
		return NULL;
	position = position->next;
	if (position == head)
		position = head->next;
	return position;
}
LoopList::LoopList(){
	head = new Node;
	head->next =head;
	position = head;
}
LoopList::~LoopList(){
	for (Node *deleteNode = head->next; deleteNode != head;) {
		Node *temp = deleteNode;
		deleteNode = deleteNode->next;
		delete  temp;
	}
	delete head;
	
}