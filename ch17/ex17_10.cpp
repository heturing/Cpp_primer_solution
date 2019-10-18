#include <iostream>
#include <bitset>

using namespace std;

int main(){
	bitset<32> b1("00000000001000000010000100101110");
	bitset<32> b2;
	b2.set(1);
	b2.set(2);
	b2.set(3);
	b2.set(5);
	b2.set(8);
	b2.set(13);
	b2.set(21);
	cout << ((b1 == b2) ? "good" : "bad") << endl;
	return 0;
}
