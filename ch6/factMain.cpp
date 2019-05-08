#include <iostream>
#include "Chapter6.h"

using namespace std;

int main(){
	int num = 0;
	cout << "input a number" << endl;
	cin >> num;
	int res = fact(num);
	cout << "result is " << res << endl;
	return 0;
}
