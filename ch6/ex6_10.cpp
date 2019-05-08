#include <iostream>

using namespace std;

int swap(int *a, int *b){
	cout << "before swapping, a is " << *a << ", b is " << *b << endl;
	int temp = *a;
	*a = *b;
	*b = temp;
	return 0;
}

int main(){
	int a, b;
	cout << "input two numbers:" << endl;
	cin >> a >> b;
	swap(&a, &b);
	cout << "after swapping, a is " << a << ", b is " << b << endl;
	return 0;
}
