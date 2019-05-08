#include <iostream>
#include <list>

using namespace std;

void elimDup(list<int> &l){
	l.sort();
	l.unique();
	return;
}

int main(){
	list<int> l = {1,5,6,6,9,9,2,2,2,4,1,0,2,0};
	elimDup(l);
	for(auto c : l){
		cout << c << endl;
	}
	return 0;
}	

