#include<iostream>
using namespace std;



class Node {
public:
	int para;
	int power;
	Node *next;
	Node() {
		para = 0;
		power = 0;
	}
	Node(int para, int power) {
		this->para = para;
		this->power = power;
	}
};
class LinkedList{
private:
	Node *head;
public:
	LinkedList() {
		head = new Node();
		head->next = NULL;
	}

	bool add(Node *node) {
		Node *n = head;
		if (head->next == NULL) {
			node->next = head->next;
			head->next = node;
		}
		else {
			for (; n->next != NULL; n = n->next) {
				if (node->power > n->next->power) {
					node->next = n->next;
					n->next = node;
					return true;

				}
			}
			node->next = n->next;
			n->next = node;
			
			return true;
		}
	}

	void sum(LinkedList *li) {
		bool found;
		for (Node *node = li->head->next; node != NULL; node = node->next) {
			for (Node *node2 = head->next; node2 != NULL; node2 = node2->next) {
				found = (node->power == node2->power);
				if (found){
					node2->para = node2->para + node->para;
					break;
				}
			}
			if (!found)
				add(node);
		}
	}
	void display() {
		for (Node *node = head->next; node != NULL; node = node->next) {
			cout << '[' << node->para << ' ' << node->power << ']' << ' ';
		}
		cout << endl << endl;
	}

	~LinkedList() {
		for (Node *temp = head; temp != NULL;) {
			Node *deleteNode = temp;
			temp = temp->next;
			delete deleteNode;
		}
	}
};

int main() {
	int group;
	int para, power;
	LinkedList *link1 = new LinkedList;
	LinkedList *link2 = new LinkedList;
	cin >> group;
	while (true) {
		cin >> para >> power;
		if (power < 0)
			break;
		Node* node = new Node(para, power);
		link1->add(node);
	}
	while (true) {
		cin >> para >> power;
		if (power < 0)
			break;
		Node* node = new Node(para, power);
		link2->add(node);
	}

	link1->sum(link2);
	link1->display();
 	return 0;
}

/*

2 -1 17 2 20 5 9 -7 7 10 4 22 2 -15 0 16 5 0 -1 2 19 7 7 3 17 4 4 15 10 -10 5 13 2 -7 0 8 -8
*/