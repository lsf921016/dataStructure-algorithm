#include<iostream>
using namespace std;

class Yoseff {
private:
	int m, n;
	int *arr;
	int currlen;
public:
	Yoseff(int n2, int m2) {
		n = n2;
		if (m2 < n2)
			m = m2;
		else
			m = m2 - n2;
		arr = new int[n];
		for (int i = 0; i < n; i++)
			arr[i] = i + 1;
		int currlen = n;
	}
	bool kill() {
		int i;
		if (currlen = 1)
			return false;
		if (m > currlen)
			m = m%currlen;
		for (i = m; i < currlen - 1; i++)
			arr[i] = arr[i + 1];
		--currlen;
		return true;
	}
	void print() {
		cout << arr[0];
	}
};

int main(){
	int m1, n1;
	cin >> n1 >> m1;
	Yoseff y(n1, m1);
	while (y.kill());
	y.print();

}



