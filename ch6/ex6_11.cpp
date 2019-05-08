#include <iostream>

using namespace std;

int reset(int &a){
	a = 0;
	return 0;
}

int main(){
	int num = 42;
	reset(num);
	cout << num << endl;
	return 0;
}
