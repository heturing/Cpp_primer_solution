#include <iostream>

using namespace std;

void print(const int ia[10]){
	for(size_t i = 0; i != 10; ++i){
		cout << ia[10] << endl;
	}
}

int main(){
	const char *c = "hejiaqi";

	cout << *c << endl;
	return 0;
}
