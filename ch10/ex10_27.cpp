#include <iostream>
#include <algorithm>
#include <vector>
#include <list>

using namespace std;

int main(){
	vector<int> v = {10,20,20,20,30,30,20,20,10};
	list<int> l(v.size());
	sort(v.begin(), v.end());
	list<int>::iterator it = unique_copy(v.begin(), v.end(), l.begin());
	l.resize(distance(l.begin(), it));

	for(auto c : l){
		cout << c << " ";
	}
	cout << endl;
	return 0;
}
