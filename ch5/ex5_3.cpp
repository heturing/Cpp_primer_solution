#include <iostream>

using namespace std;

int main(){
	int sum = 0, a = 1;
	while(sum += a, a++, a <= 10);
	cout << "Sum of 1 to 10 exclusive is " << sum << endl;
	return 0;
}
