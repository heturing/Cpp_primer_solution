#include <iostream>
#include <vector>

using namespace std;

struct X{
	X(){
		cout <<  "constructor X()" << endl;
	}
	X(const X &y){
		cout << "copy constructor X(const X &)" << endl;
	}

	X& operator =(const X &x){
		cout << "copy assignment =(const X &)" << endl;
		return *this;
	}

	~X(){
		cout << "destructor ~X()" << endl;
	}
};

void test(){
	X x0;
	X x1(x0);
	X x2;
	x2 = x1;
	vector<X> vx;
   	vx.push_back(x2);	
	return;
}

int main(){
	test();
	return 0;
}
