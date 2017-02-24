#include<stdio.h>
#include<iostream>
#include<string>
using namespace std;

void reverse(char s[]) {
	int len = 0;
	int i = 0;
	while (s[i] != '\0') {
		++len;
		++i;
	}

	for (int j = 0; j < len / 2; ++j) {
		char temp;
		temp = s[j];
		s[j] = s[len - 1 - j];
		s[len - 1 - j] = temp;
	}
	s[len] = '\0';
}

int main(){
	char s[] = "china";

	reverse(s);
	cout << s;

	return 0;
}


