#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using namespace std::placeholders;

int main(){
	vector<int> v{2,3,5,7,11,13,17,19};
	int n;
	cin >> n;
	auto it = find_if_not(v.begin(), v.end(), bind(modulus<int>(), n, _1));
	if(it != v.end()){
		cout << *it << endl;
	}
	else{
		cout << "no" << endl;
	}
	return 0;
}
