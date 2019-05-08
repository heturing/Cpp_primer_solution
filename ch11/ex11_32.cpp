#include <iostream>
#include <map>
#include <set>

using namespace std;

int main(){
	multimap<string, string> m = {{"zhu", "zz"}, {"he","sci"}, {"zhu","zzz"}};
	multiset<string> mss1, mss2;

	for(const auto &lf : m){
		mss1.insert(lf.first);
		mss2.insert(lf.second);
	}

	for(const auto &c : mss1){
		cout << c << endl;
	}

	for(const auto &c : mss2){
		cout << c << endl;
	}
	return 0;
}
