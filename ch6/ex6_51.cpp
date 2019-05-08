#include <iostream>

using namespace std;

void f(){
	cout << "version of no parameter" << endl;
	return;
}
void f(int i){
	cout << "version of one int parameter" << endl;
    return;
}

void f(int i, int j){
	cout << "version of two int parameters" << endl;
	return;
}

void f(double i, double j = 3.14){
	cout << "version of two double parameters" << endl;
	return;
}

int main(){
	//f(2.56, 42);
	f(42);
	f(42,0);
	f(2.56, 3.14);
	return 0;
}
