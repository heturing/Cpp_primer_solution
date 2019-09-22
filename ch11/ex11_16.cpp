#include <iostream>
#include <map>
#include <iterator>
#include <utility>

using namespace std;

int main(){
	map<string, int> m;
	auto it = inserter(m, m.end());
	string s;
	while(cin >> s){
		it = make_pair(s,1);
	}

	for(auto c : m){
		cout << c.first << " " << c.second << endl;
	}
	return 0;
}
