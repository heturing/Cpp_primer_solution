#include <iostream>

using namespace std;

int main(){
	cout << sizeof(char) << endl;
	cout << sizeof(int) << endl;
	cout << sizeof(long) << endl;
	cout << sizeof(double) << endl;
	cout << sizeof(float) << endl;
	int *p = 0;
	cout << sizeof(p) << endl;
	return 0;
}
