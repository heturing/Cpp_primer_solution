#include <iostream>
#include <vector>

using namespace std;

bool find_int(vector<int> v, int i){
	for(auto beg = v.begin(); beg != v.end(); beg++){
		if(*beg == i){
			return true;
		}
	}
	return false;
}

int main(){
	vector<int> v = {1,2,3,4,5,6};
	int i = 6;
	cout << find_int(v,i) << endl;
	return 0;
}
