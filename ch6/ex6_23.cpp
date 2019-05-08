#include <iostream>
#include <iterator>

using namespace std;

int print(const int *beg, const int* end){
	while(beg != end){
		cout << *beg++ << endl;
	}
	return 0;
}

int print(const int a[], size_t size){
	for(size_t i = 0; i != size; i++){
		cout << a[i] << endl;
	}
	return 0;
}

int main(){
	int i = 0;
	int j[2] = {0,1};
	print(&i, 1);
	print(begin(j), end(j));
	return 0;
}

