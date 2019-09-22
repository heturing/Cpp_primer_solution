#include <iostream>

using namespace std;

template<typename T, unsigned N> T* my_begin(T (&p)[N]){
	return p;
}

template<typename T, unsigned N> T* my_end(T (&p)[N]){
	return p + N;
}

int main(){
	int a[2] = {1,2};
	my_begin(a);
	my_end(a);
	return 0;
}
