#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class TestEqual{
	public:
		TestEqual(int i) : old(i) {}
		bool operator()(const int j){
			return old == j;
		}
	private:
		int old;
};

int main(){
	vector<int> v{1,2,3,4,5,6};
	int oldV = 1;
	int newV = 10;
	replace_if(v.begin(), v.end(), TestEqual(oldV), newV);

	for(auto c : v){
		cout << c << endl;
	}
	return 0;
}
