#include<iostream>
using namespace std;

class ArrayList {
private:
	static const int capacity=300;


public:
	int arr[capacity];
	void initi(int para, int power) {	
		arr[power] = para;
	}
	void setZero() {
		for (int i = 0; i <= capacity;++i)
			arr[i] = 0;

	}
	int* Add(ArrayList A) {
		int array[300];
		for (int i = 0; i < 300; ++i)
			array[i] = arr[i] + A.arr[i];
		return array;
	}
};

int main() {
	int para, power, group;
	int *arraySum=new int[300];
	for (int i = 0; i <= 300; ++i)
		arraySum[i] = 0;
	int count = 0;
	cin >> group;
	ArrayList line[2];
	line[0].setZero();
	line[1].setZero();
	while (true) {
		cin >> para >> power;
		if (power < 0) {
			++count;
			if (count == group)
				break;
			continue;
			
		}
		line[count].initi(para, power);
	}
	arraySum=line[0].Add(line[1]);
	for (int i = 0; i < 300; ++i)
		if (arraySum[i] != 0)
			cout << arraySum[i]<<' '<<i<<' ';

	return 0;
}