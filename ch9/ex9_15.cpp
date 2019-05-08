#include <iostream>
#include <vector>

using namespace std;

int main(){
	vector<int> v1 = {1,2,3};
	vector<int> v2 = {1,2,4};

	cout << (v1 > v2 ? "v1 larger" : "v2 larger") << endl;
	return 0;
}
