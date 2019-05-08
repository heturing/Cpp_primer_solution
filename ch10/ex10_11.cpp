#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isShorter(const string &s1, const string &s2){
	return s1.size() < s2.size();
}

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
	stable_sort(v.begin(),v.end(),isShorter);
	for(auto c : v){
		cout << c << endl;
	}
	return 0;
}
