#include <iostream>
#include <vector>

using namespace std;

int add(int i, int j){
	return i + j;
}

int sub(int i, int j){
	return i - j;
}

int mul(int i, int j){
	return i * j;
}

int divi(int i, int j){
	return i / j;
}

int main(){
	using f = int (*)(int, int);
	vector<f> funcs = {add, sub, mul, divi};

	for(auto c : funcs){
		cout << c(4, 2) << endl;;
	}

	return 0;
}
