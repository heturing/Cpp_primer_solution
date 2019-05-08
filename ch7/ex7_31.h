#include <iostream>

class Y;

class X{
public:
	Y *ptry = nullptr;
};

class Y{
public:
	X objx;
};
