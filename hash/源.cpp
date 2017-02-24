#include<iostream>
using namespace std;

class Student {
public:
	int id;
	int age;
	string name;
	Student(int id, int age, string name) {
		this->id = id;
		this->age = age;
		this->name = name;
	}
};
class Bucket {
private:
#define CAPACITY 10
	int length = 0;
	Student *s[CAPACITY];
public:
	Student* find(int key) {
		for (int i = 0; i < length; ++i) {
			if (s[i]->id == key)
				return s[i];
		}
		return NULL;
	}

	int remove(int key) {
		int count = 0;
		int i = 0;
		while (i < length) {
			if (key == s[i]->id) {
				delete s[i];
				s[i] = s[length - 1];
				--length;
				++count;
			}
			else {
				++i;
			}
		}
		return count;
	}
	void add(Student *student) {
		s[length] = student;
		++length;
	}

	bool isFull() {
		return length == CAPACITY;
	}
	int getLength() {
		return length;
	}
	Student* get(int index) {
		return s[index];
	}

	void moveTo(int index, Bucket* to) {
		to->add(s[index]);
		s[index] = s[length - 1];
		length--;
	}
};


class HashMap {
private:
	unsigned int bucketNum;
	Bucket **hashMap;

public:
	HashMap() {
		bucketNum = 32;
		hashMap = new Bucket*[bucketNum];
		for (int i = 0; i < bucketNum; i++) {
			hashMap[i] = new Bucket;
		}
	}
	Student* find(int key) {
		return hashMap[key%bucketNum]->find(key);
	}

	int remove(int key) {
		return hashMap[key%bucketNum]->remove(key);
	}
	bool add(Student *student) {
		while (!hashMap[student->id%bucketNum]->isFull()) {
			if (!enlarge()) {
				return false;
			}
		}
		hashMap[student->id%bucketNum]->add(student);
		return true;
	}

	bool enlarge() {
		if (bucketNum == 0x10000000)
			return false;
		int oldNum = bucketNum;
		bucketNum <<= 1;

		Bucket** temp = new Bucket*[bucketNum];
		for (int i = 0; i < oldNum; ++i) {
			temp[i] = hashMap[i];
		}
		for (int i = oldNum; i < bucketNum; ++i) {
			temp[i] = new Bucket;
		}
		delete[] hashMap;
		hashMap = temp;

		Bucket* bucket;
		int length;
		Student *student;
		int j ;
		for (int i = 0; i < oldNum; i++) {
			bucket = hashMap[i];
			length = bucket->getLength();
			j = 0;
			while(j < length) {
				student = bucket->get(j);
				//i是id对oldnum的取余，当id&oldNum为真，id对新的bucketNum取余为i+oldNum
				if (student->id&oldNum) {
					bucket->moveTo(j, hashMap[i + oldNum]);
				}
				else {
					++j;
				}
			}
		}
		return true;
	}
};

int main() {

}