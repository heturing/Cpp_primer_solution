#include <iostream>

using namespace std;

int main(){
	int sum = 0, val = 10;
	while(val > 0){
		sum += val;
		--val;
	}
	cout << "the sum of 10 to 1 inclusive is " << sum << endl;
	return 0;
}
