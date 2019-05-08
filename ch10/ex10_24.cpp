#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <functional>

using namespace std;
using namespace::placeholders;

bool check_size(const string &s, string::size_type sz){
	return s.size() < sz;
}

int main(){
	vector<int> v = {1,2,3,4,5,6,7,8,9};
	string s = "hejiaqi";
	auto iter = find_if(v.begin(), v.end(), bind(check_size, s, _1));
	if(iter != v.end()){
		cout << *iter << endl;
	}
	return 0;
}	
