#include <iostream>
#include <vector>

using namespace std;

int main(){
	vector<int> v;
	cout << v.at(0) << " " << v[0] << " " << v.front() << " " << *v.begin() << endl;
	return 0;
}
