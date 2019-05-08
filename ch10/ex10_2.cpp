#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	string s = "", k = "hjq";
	vector<string> v;
	while(cin >> s){
		v.push_back(s);
	}
	auto res = count(v.begin(), v.end(), k);
	cout << res << endl;
	return 0;
}
