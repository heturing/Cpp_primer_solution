#include <iostream>
#include <deque>
#include <list>

using namespace std;

int main(){
	list<int> l = {1,2,3,4,5,6,7,8};
	deque<int> even, odd;
	for(auto c : l){
		if(c / 2 == 0){
			even.push_back(c);
		}
		else{
			odd.push_back(c);
		}
	}
	return 0;
}
