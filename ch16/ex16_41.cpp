#include <iostream>

using namespace std;

template <typename T1, typename T2> auto sum(T1 t1, T2 t2) -> decltype(t1 + t2){
	return t1 + t2;
}


int main(){
	auto a = 10000000000000;
   	auto b = 20000000000000;
	cout << sum(a, b) << endl;
	return 0;
}
