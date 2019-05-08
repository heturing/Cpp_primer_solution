#include <iostream>
#include <vector>

using namespace std;

int add(const int i, const int j){
	return i+j;
}

int sub(const int i, const int j){
	return i-j;
}

int mul(const int i, const int j){
	return i*j;
}

int divide(const int i, const int j){
	return i/j;
}

int main(){
	typedef int (*F)(int, int);
	vector<F> v = {add, sub, mul, divide};
	int a = 2, b = 1;
	for(auto c : v){
    cout<< c(a,b) << endl;

	}
	return 0;
}
