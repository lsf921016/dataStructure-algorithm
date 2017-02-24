#include<iostream>
using namespace std;

class Node {
public:
	int value;
	Node *next;
};
class LinkedStack {
private:
	Node *head;
public:
	LinkedStack() {
		head = NULL;
	}
	~LinkedStack() {
		while (head != NULL) {
			Node *deleteNode = head;
			head = head->next;
			delete deleteNode;
		}

	}
	bool isEmpty() {
		return head == NULL;
	}
	void push(int value) {
		Node *node = new Node;
		node->value = value;
		node->next = head;
		head = node;
	}
	int pop() {
		Node *temp = head;
		int value;

		head = head->next;

		value = temp->value;
		delete temp;
		return value;
	}

	bool getTwoOperant(int &left, int &right) {
		if (isEmpty()) {
			cout << "no operant" << endl;
			return false;
		}
		right = pop();
		if (isEmpty()) {
			cout << "no operant<<endl;" << endl;
			return false;
		}
		left = pop();
		return true;
	}
};

int main(){
	int leftOperant, rightOperant;
	char ch;
	LinkedStack link;
	while (cin >> ch&&ch != '=') {
		if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
			if (link.getTwoOperant(leftOperant,rightOperant)) {
				switch (ch) {
				case'+':link.push(leftOperant + rightOperant); break;
				case'-':link.push(leftOperant - rightOperant); break;
				case'*':link.push(leftOperant * rightOperant); break;
				case'/':if (right == 0) {
					cout << "invalid operant" << endl;
					break;
				}
					link.push(leftOperant / rightOperant);
					break;
				}
			}
		}
		else
			link.push(ch - '0');
	}
	if (!link.isEmpty()) {
		cout << link.pop();
	}
	
	return 0;
}
