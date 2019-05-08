#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void elimDups(vector<string> &v){
	sort(v.begin(),v.end());
	auto iter = unique(v.begin(), v.end());
	v.erase(iter, v.end());
}

int main(){
	vector<string> v;
	string s;
	while(cin >> s){
	   v.push_back(s);
	}
	elimDups(v);
	for(auto c : v){
		cout << c << endl;
	}
	return 0;
}
