#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	vector<int> v;
	int i = 0, k = 1;
	while(cin >> i){
		v.push_back(i);
	}
	auto res = count(v.begin(), v.end(), k);
	cout << res << endl;
	return 0;
}
