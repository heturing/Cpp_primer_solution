#include <iostream>
#include <vector>

using namespace std;

int main(){
	vector<int> v(10,2);
	for(auto it = v.begin(); it != v.end(); it++){
		*it *= 2;
	}
	for(auto c : v){
		cout << c << endl;
	}
	return 0;
}
