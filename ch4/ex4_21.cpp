#include <iostream>
#include <vector>

using namespace std;

int main(){
	vector<int> v{1,2,3,4,5,6,7,8,9};
	for(auto &c : v){
		c = (c % 2 == 0 ? c : c * 2);
	}
	for(auto c : v){
		cout << c << endl;
	}
	return 0;
}
