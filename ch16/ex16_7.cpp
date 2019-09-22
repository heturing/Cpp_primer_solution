#include <iostream>

using namespace std;

template<typename T, unsigned N> constexpr unsigned arr_szie(const T (&p)[N]){
	return N;
}

int main(){
	int a[2] = {1,2};
	cout << arr_szie(a) << endl;
	return 0;

}
