#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

int main(){
	list<int> l = {1,2,3,4,5,0,5,4,3,2,1};
	auto it = find(l.rbegin(), l.rend(), 0);
	if(it != l.rbegin()){
		int dis = distance(it.base(), l.begin());
		cout << dis << "th" << endl;
	}
	else{
		cout << "no 0" << endl;
	}
	return 0;
}
