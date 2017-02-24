#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<functional>
using namespace std;

void bucketSort(int array[], int len,int max) {
	int *tempArr = new int[len];
	int *count = new int[max];
	int i;
	//将数组复制到临时数组
	for (i = 0; i < len; ++i) {
		tempArr[i] = array[i];
	}
	//将桶子计数器重置
	for (i = 0; i < max; ++i) {
		count[i] = 0;
	}
	//统计每个值出现的次数
	for (i = 0; i < len; ++i) {
		count[array[i]]++;
	}
	//统计小于等于i的元素个数
	for (i = 1; i < max; ++i) {
		count[i] = count[i] + count[i - 1];
	}
	//为了稳定性，从数组末尾开始
	for (i = len - 1; i >= 0; --i) {
		array[--count[tempArr[i]]] = tempArr[i];
	}

}
void swap(int array[], int a, int b) {
	int temp = array[a];
	array[a] = array[b];
	array[b] = temp;
}
//partition function is used in quickSort to get the new pivot 
int partition(int array[], int left, int right) {
	int l = left;//左指针
	int r = right;//右指针
	int temp = array[r];//此时轴值在数组末尾，保存轴值
	while (l != r) {//l,r不断向中间移动，直到相遇循环停止
		while (array[l] <= temp&&r > l) {
			l++;//如果l位置元素比轴值小，则直接将l向右移动一位
		}
		//跳出循环时，此时的l位置的元素是大于轴值的
		if (l < r) {
			array[r] = array[l];
			--r;
			//将此时l位置的元素的值覆盖到r位置，并将r向左移动一位
		}

		while (array[r] >= temp&&r > l) {
			r--;
		}
		if (l < r) {
			array[l] = array[r];
			++l;
			
		}
	}//end while
	//此时l=r
	array[l] = temp;
	return l;
}
void quickSort(int array[], int left, int right) {
	if (left >= right) {
		return;
		
	}
	int pivot = (left + right) / 2;
	swap(array, pivot, right);//将轴值放到数组末端
	pivot = partition(array, left, right);//获得分割后轴值的位置
	quickSort(array, left, pivot - 1);
	quickSort(array, pivot + 1, right);
}
void sub_mergeSort(int array[], int *tempArr, int left, int right) {
	void _merge(int array[], int tempArr[], int left, int right, int mid);
	if (left >= right)
		return;
	int mid = (left + right) / 2;
	sub_mergeSort(array, tempArr, left, mid);
	sub_mergeSort(array, tempArr, mid + 1, right);
	_merge(array, tempArr, left, right, mid);
}
void _mergeSort(int array[], int len) {
	int *tempArr = new int[len];
	sub_mergeSort(array, tempArr, 0, len - 1);
}

void _merge(int array[], int tempArr[], int left, int right, int mid) {
	int index1 = left;//左子数组的起始位置
	int index2 = mid + 1;

	for (int i = 0; i <= right; ++i) {
		tempArr[i] = array[i];
	}

	int i = left;//归并后在array中的游标
	while (index1 <= mid&&index2 <= right) {
		if (tempArr[index1] <= tempArr[index2]) {
			array[i++] = tempArr[index1++];
		}
		else {
			array[i++] = tempArr[index2++];
		}
	}
	//跳出循环后，可能序列1或者序列2并未全部添加进array
	while (index1 <= mid) {
		array[i++] = tempArr[index1++];
	}
	while (index2 <= right) {
		array[i++] = tempArr[index2++];
	}
}



void InsertSort(int array[], int n) {
	int temp;
	for (int i = 1; i < n; ++i) {
		temp = array[i];
		int j = i - 1;
		for (j; j >= 0 && temp < array[j]; --j) {
			array[j + 1] = array[j];
		}
		array[j + 1] = temp;
	}
}
void selectSort(int array[], int len) {
	for (int i = 0; i < len; ++i) {
		for (int j = i + 1; j < len; ++j) {
			if (array[i] > array[j]) {
				int temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
		}
	}
}
void heapSort(int array[], int len) {
	vector<int> v(array, array + len);
	make_heap(v.begin(),v.end(),less<int>());
	sort_heap(v.begin(), v.end());
	for (int i = 0; i < len; ++i) {
		array[i] = v[i];
	}
}
void bubleSort(int array[], int len) {
	bool noSwap;
	int i, j;
	for (i = 0; i < len - 1; ++i) {
		noSwap = true;
		for (int j = len - 1; j > i; --j) {
			if (array[j] < array[j - 1]) {
				int temp = array[j - 1];
				array[j - 1] = array[j];
				array[j] = temp;

				noSwap = false;
			}
		}
		if (noSwap)
			return;
	}
}
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
int main() {
	int arr[] = { 1,3,5,7,9,2,4,6,8,10 };
	vector<int> v(arr, arr + 10);
	sort(v.begin(), v.end());
	printVector(v);
	return 0;
}