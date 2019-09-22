#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <iterator>

using namespace std;

int main(){
	vector<int> v = {10,20,20,20,30,30,20,20,10};
	list<int> l;
	sort(v.begin(), v.end());
	unique_copy(v.begin(), v.end(), back_inserter(l));

	for(auto c : l){
		cout << c << " ";
	}
	cout << endl;
	return 0;
}
