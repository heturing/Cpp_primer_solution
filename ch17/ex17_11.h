#ifndef EX17_11
#define EX17_11

#include <iostream>
#include <bitset>

template <unsigned N> class Response{
public:
	Response(std::string s) : b(s) {} 
private:
	std::bitset<N> b;
};

#endif
