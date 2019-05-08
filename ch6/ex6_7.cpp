#include <iostream>

using namespace std;

int generate_number(){
	static int count = 0;
	return count++;
}

int main(){
	for(int i = 0; i < 10; i++){
		cout << generate_number() << endl;
	}
	return 0;
}
