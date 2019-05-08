// This file is used to test whether my idea is right.
#include <iostream>

int a;
int main(){
	std::cout << a <<std::endl;
	std::string str;
	std::cout << str <<std::endl;
	int i = 100, sum = 0;
	for(int i = 0; i != 10; i++){
		sum += i;
	}
	std::cout << i << " " << sum <<std::endl;

	int h1 = 0, &r1 = h1;
	double h2 = 0, &r2 = h2;
	r1 = h2;
	std::cout << r1 << std::endl;

	int j, &rj = j;
	j = 5; 
	rj = 10;
	std::cout << j << " " << rj <<std::endl;

	double dval = 3.141;
	const int &tes = dval;
	std::cout << tes << std::endl;

	const int &aa = 0;
	std::cout << aa << std::endl;

	using std::cin;
	using std::cout;
	int mynum = 0;
	while(cin >> mynum){
		cout << mynum <<std::endl;
	}
	return 0;
}
