#include <iostream>
#include <functional>
#include <map>

using namespace std;

int add(int i, int j){
	return i + j;
}

auto mod = [](int i, int j) -> int {return i % j;};

class divi{
	public:
		int operator()(int i, int j) {return i / j;}
};

int main(){
	map<string, function<int(int, int)>> binops = {{"+", add}, {"-", minus<int>()}, {"/", divi()}, {"*", [](int i, int j) -> int {return i * j;}}, {"%", mod}};
	cout << binops["+"](10, 5) << endl;
	cout << binops["-"](10, 5) << endl;;
	cout << binops["*"](10, 5) << endl;
	cout << binops["/"](10, 5) << endl;
	cout << binops["%"](10, 5) << endl;
	return 0;
}
