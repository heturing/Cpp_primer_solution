#include <iostream>

using namespace std;

int main(){
	int i = 5;
	auto f = [&i]() -> bool {return (i != 0 ? --i : i);};
	while(f()){
		cout << i << endl;
	}
	return 0;
}
