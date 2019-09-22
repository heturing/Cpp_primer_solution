#include <iostream>

using namespace std;

class A{
protected:
	int i = 0;
};

class B : public A{
	public:
		void f() {cout << i << endl;}
};

class C : public B{
	public:
		void g() {cout << i << endl;}
};

int main(){
	C c;
	c.g();
	return 0;
}
