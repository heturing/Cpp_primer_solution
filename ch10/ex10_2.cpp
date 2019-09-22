#include <iostream>
#include <string>
#include <list>
#include <algorithm>

using namespace std;

int main(){
	string s = "", k = "hjq";
	list<string> v;
	while(cin >> s){
		v.push_back(s);
	}
	auto res = count(v.begin(), v.end(), k);
	cout << res << endl;
	return 0;
}
