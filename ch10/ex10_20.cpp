#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

void elimDups(vector<string> &v){
	sort(v.begin(),v.end());
	auto iter = unique(v.begin(), v.end());
	v.erase(iter, v.end());
}

void largerThan6(){
	vector<string> v = {"hejiaqi", "zhutianqi", "small", "big", "lagertest", "wtf", "nonsence"};
	elimDups(v);
	stable_sort(v.begin(), v.end(), [](const string &a, const string &b) -> bool {return a.size() < b.size();});
	int res = count_if(v.begin(), v.end(), [](const string &a) -> bool {return a.size() > 6;});
	cout << res << endl;
	return;
}

int main(){
	largerThan6();
	return 0;
}

