#include<iostream>
#include<stdio.h>
using namespace std;

void InsertSort(int array[], int n) {
	int temp;
	for (int i = 1; i < n; ++i) {
		temp = array[i];
		int j=i-1;
		for (j; j >= 0 && temp < array[j]; --j) {
			array[j + 1] = array[j];
		}
		array[j + 1] = temp;
	}
}
void printArr(int array[], int n) {
	for (int i = 0; i < n; ++i) {
		cout << array[i]<<",";
	}
}
int main() {
	int arr[] = { 1,3,5,7,9,2,4,6,8,10 };
	InsertSort(arr, 10);
	printArr(arr, 10);

	return 0;
}