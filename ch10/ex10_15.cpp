#include <iostream>

using namespace std;

int main(){
	int i;
	cin >> i;
	auto f = [i](int j) -> int {return i+j;};
	cout << f(2) << endl;
	return 0;
}
