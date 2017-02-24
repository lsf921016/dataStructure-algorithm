#include"Queue.h"

arrayQueue::arrayQueue(int capacity){
	this->capacity = capacity;
	arr = new int[capacity];
	pWrite = pRead = 0;
}
arrayQueue::~arrayQueue(){
	delete[]arr;
}
bool arrayQueue::push(int value){
	if ((pWrite + 2) % capacity == pRead)
		return false;
	arr[pWrite] = value;
	++pWrite;
	if (pWrite = capacity )
		pWrite = 0;
}
int arrayQueue::poll(){
	int value = arr[pRead];
	pRead = (pRead+1)%capacity;
	return value;
}
int arrayQueue::top(){
	return arr[pRead];
}
bool arrayQueue::isEmpty(){
	return pRead == pWrite;
}