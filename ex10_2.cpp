#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	vector<string> v;
	string i = 0, k = "hjq";
	while(cin >> i){
		v.push_back(i);
	}
	auto res = count(v.begin(), v.end(), k);
	cout << res << endl;
	return 0;
}
