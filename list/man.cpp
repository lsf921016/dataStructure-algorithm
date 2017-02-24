#include"List.h"


using namespace std;

	int main() {
	List *a = new ArrayList;
	for(int i=0;i<25;i++)
		a->insert(i, i);
	a->display();
	a->insert(1, 1000);
	a->display();
	cout << a->findByKey(1000) << endl;
	return 0;
}