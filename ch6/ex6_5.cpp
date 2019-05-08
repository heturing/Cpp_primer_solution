#include <iostream>

using namespace std;

int abs(int n){
	if(n < 0){
		return -n;
	}
	return n;
}

int main(){
	int num = 0;
	cout << "input a number" << endl;
	cin >> num;
	int res = abs(num);
	cout << "result is " << res << endl;
	return 0;
}
