#include<iostream>

using namespace std;

int main(){
	int sum = 0, val;
	while(cin >> val){
		sum += val;
	}
	cout << "the sum of all input is " << sum << endl;
	return 0;
}
