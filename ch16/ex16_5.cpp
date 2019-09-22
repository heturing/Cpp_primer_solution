#include <iostream>

using namespace std;

template<typename T, unsigned N> void print(const T (&p)[N]){
	for(unsigned u = 0; u < N; u++){
		cout << *(p + u) << " ";
	}
}

int main(){
	int a[10] = {1,2,3,4,5,6,7,8,9,10};
	print(a);
	cout << endl;
	return 0;
}
