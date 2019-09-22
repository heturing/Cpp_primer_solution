#include <iostream>

using namespace std;

int fact(int n){
	int res = 1;
	while(n != 0){
		res *= n--;
	}
	return res;
}

int main(){
	int num = 0;
	cout << "input a number" << endl;
	cin >> num;
	int res = fact(num);
	cout << "result is " << res << endl;
	return 0;
}
