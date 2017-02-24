#include<iostream>
#include<stdio.h>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<functional>
#include<allocators>
#include <sstream>
#include<unordered_map>
using namespace std;
void printArr(int array[], int len) {
	for (int i = 0; i < len; ++i) {
		cout << array[i] << ",";
	}
}
void printVector(vector<int> &v) {
	for (int i = 0; i < v.size(); ++i) {
		cout << v[i];
	}
}
struct RandomListNode {
	int label;
	RandomListNode *next, *random;
	RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};
RandomListNode *copyRandomList(RandomListNode *head) {
	// write your code here
	RandomListNode *myhead = new RandomListNode(0);
	RandomListNode *cursor = myhead;
	unordered_map<int, RandomListNode*> itop;
	unordered_map<int, int> itoi;
	for (head; head != NULL; head = head->next) {
		RandomListNode *newNode = new RandomListNode(head->label);
		cursor->next = newNode;
		cursor = cursor->next;
		itop[newNode->label] = newNode;
		itoi[head->label] = head->random->label;
	}
	cursor->next = NULL;

	for (cursor = myhead; cursor->next != NULL; cursor = cursor->next) {
		cursor->next->random = itop[itoi[cursor->next->label]];
	}
	return myhead->next;
}


int main() {
	RandomListNode *head=new RandomListNode()
		//test test test
	return 0;
}