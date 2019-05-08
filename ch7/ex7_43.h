#include <iostream>

using namespace std;

class NoDefault{
public:
	NoDefault(int i) : data(i) {}
private:
	int data;
};

class C{
public:
	C() : nd(0) {}
private:
	NoDefault nd;
};
