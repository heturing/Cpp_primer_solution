#include <iostream>

int main(){
	int *p = nullptr, i = 1;
	p = &i;
	std::cout << p << " " << *p << std::endl;
	*p = 2;
	std::cout << p << " " << *p << std::endl;
	return 0;
}
