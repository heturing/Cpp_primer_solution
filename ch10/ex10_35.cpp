#include <iostream>
#include <vector>

using namespace std;

int main(){
	vector<int> v = {1,2,3,4,5,6,7,8,9};
	for(auto iter = v.end() - 1; iter != v.begin() - 1; iter--){
		cout << *iter << endl;
	}
	return 0;
}
