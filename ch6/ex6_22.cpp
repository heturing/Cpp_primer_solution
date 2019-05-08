#include <iostream>

using namespace std;

int swap(int *&a, int *&b){
	cout << "before swapping" << endl;
	cout << a << " " << b << endl;
	auto temp = a;
	a = b;
	b = temp;
	return 0;
}

int main(){
	int c = 1, d = 0;
	int *a = &c, *b = &d;
	swap(a,b);
	cout << "after swapping:" << endl;
	cout << a << " " << b << endl;
	return 0;
}
