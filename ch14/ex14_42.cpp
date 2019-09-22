#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
using namespace std::placeholders;

int main(){
	vector<int> v{1010, 1020, 1030, 1040, 1050};
	vector<string> vs{"pooh", "hejiaqi", "pool", "zhu"};
	cout << count_if(v.begin(), v.end(), bind(greater<int>(), _1, 1024)) << endl;
	cout << *find_if(vs.begin(), vs.end(), bind(not_equal_to<string>(), _1, "pooh")) << endl;
	transform(v.begin(), v.end(), v.begin(), bind(multiplies<int>(), _1, 2));
	for(auto c : v){
		cout << c << endl;
	}
	return 0;
}
