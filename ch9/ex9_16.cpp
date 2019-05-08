#include <iostream>
#include <vector>
#include <list>

using namespace std;

int main(){
	list<int> l = {1,2,3};
	vector<int> v = {1,2,4};
	vector<int> vl(l.begin(), l.end());
	cout << (v == vl ? "equal" : "not equal") << endl;
	return 0;
}
