#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <functional>

using namespace std;
using namespace::placeholders;

void elimDups(vector<string> &v){
	sort(v.begin(),v.end());
	auto iter = unique(v.begin(), v.end());
	v.erase(iter, v.end());
}

bool test(const string &s, unsigned i){
	return s.size() > i;
}

void largerThan6(){
	unsigned i = 6;
	vector<string> v = {"hejiaqi", "zhutianqi", "small", "big", "lagertest", "wtf", "nonsence"};
	elimDups(v);
	stable_sort(v.begin(), v.end(), [](const string &a, const string &b) -> bool {return a.size() < b.size();});
	int res = count_if(v.begin(), v.end(), bind(test, _1, i));
	cout << res << endl;
	return;
}

int main(){
	largerThan6();
	return 0;
}

