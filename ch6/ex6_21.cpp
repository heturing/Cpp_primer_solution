#include <iostream>

using namespace std;

int large(int a, const int *b){
	if(*b > a){
		return *b;
	}
	else{
		return a;
	}
}

int main(){
	cout <<"input two numbers:" << endl;
	int a =0, b = 0;
	cin >> a >> b;
	cout << large(a,&b) << endl;
	return 0;
}
