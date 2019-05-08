#include <iostream>
#include <list>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	vector<int> v = {1,2,3,4,5,6,7,8,9,0};
	list<int> l(5);
	copy(v.rbegin()+3, v.rend() - 2, l.begin());
	for(auto c : l){
		cout << c << endl;
	}
	return 0;
}
