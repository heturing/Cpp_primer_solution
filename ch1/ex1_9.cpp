#include <iostream>

using namespace std;

int main(){
	int sum = 0, val = 50;
	while(val <= 100){
		sum += val;
		++val;
	}
	cout << "the sum of 50 to 100 inclusive is " << sum << endl;
	return 0;
}
