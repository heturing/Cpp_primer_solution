#include <iostream>
#include <vector>

using namespace std;

int main(){
	vector<int> v{5,4,3,2,1};
	cout << * v.begin() + 1 << endl;

	auto iter = v.begin();
	while(iter != v.end()){
		cout << *iter++ << endl;
	}
	int i = 2, j = 5;
	double slope = static_cast<double>(j/i);
	cout << slope << endl;
	return 0;
}
