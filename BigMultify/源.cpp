#include<iostream>
using namespace std;



class BigNumber {
private:
	int number[200];
	int rNumber[200];
	int length=0;
public:
	BigNumber() {
		char *inputArray = new char[201];
		int i = 0;
		cin.getline(inputArray, 201, '\n');
		for (int i = 0; i < 201; ++i) {
			if (inputArray[i] == '\0')
				break;
			number[i] = inputArray[i] - '0';
			length++;
		}
		for (int i = 0; i < length; i++) {
			rNumber[i] = number[length - 1 - i];
		}

		/*test model
		for (int i = 0; i < length; ++i)
			cout << number[i];
		cout << endl;
		
		for (int i = 0; i < length; ++i)
			cout << rNumber[i];
		cout << endl;
		*/
	}

	int getLength() {
		return length;
	}

	int* getRArray() {
		return rNumber;
	}

	void multifyBy(BigNumber another) {
		int result[400];
		int resultLength=0;
		for (int i = 0; i < 400; ++i)
			result[i] = 0;
		for (int i = 0; i < this->length; ++i) {
			for (int j = 0; j < another.length; ++j) {
				result[i + j] += this->rNumber[i] * another.rNumber[j];
			}
		}

		for(int i=0;i<400;i++) {
			result[i + 1] = result[i + 1] + result[i] / 10;
			result[i] = result[i] % 10;

		}
		

		if (result[this->length + another.length - 2] / 10 == 0)
			resultLength = this->length + another.length - 1;
		else
			resultLength = this->length + another.length;
		
		//display
		for (int i = resultLength - 1; i >= 0; --i)
			cout << result[i];
	}

};

int main() {
	BigNumber n1;
	BigNumber n2;

	n1.multifyBy(n2);
	
	return 0;
}