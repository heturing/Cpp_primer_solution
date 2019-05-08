#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>

using namespace std;

int main(){
	vector<int> v = {1,2,3,4,5,6,7,8,9};
	fill_n(v.begin(), v.size(), 0);
	for(auto c : v){
		cout << c << endl;
	}
	return 0;
}
