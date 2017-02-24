#pragma once
class MinHeap {
private:
	int* heapArray;
	int currentSize;
	int maxSize;
	void buildHeap();
public:
	MinHeap(const int max);
	virtual ~MinHeap();
	bool isLeaf(int pos);
	int leftChild(int pos);
	int rightChild(int pos);
	int parent(int pos);
	bool insert(int &node);
	bool remove(int pos, int &node);
	int removeMin();
	void siftUp(int pos);
	void siftDown(int pos);
	void buildHeap();
};