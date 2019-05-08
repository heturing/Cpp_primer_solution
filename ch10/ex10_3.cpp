#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

int main(){
	vector<int> v = {1,2,3,4,5,6,7,8,9};
	auto res = accumulate(v.cbegin(), v.cend(), 0);
	cout << res << endl;
	return 0;
}
