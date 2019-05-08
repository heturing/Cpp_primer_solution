#include <iostream>
#include <list>
#include <forward_list>

using namespace std;

void func1(list<int> &l){
	auto iter = l.begin();
	while(iter != l.end()){
		if(*iter % 2){
			iter = l.insert(iter, *iter);
			++iter;
			++iter;
		}
		else{
			iter = l.erase(iter);
		}
	}
}

void func2(forward_list<int> &fl){
	auto curr = fl.begin();
	auto prev = fl.before_begin();
	while(curr != fl.end()){
		if(*curr % 2){
			curr = fl.insert_after(prev, *curr);
			++curr;
			++curr;
			++prev;
			++prev;
		}
		else{
			curr = fl.erase_after(prev);
		}
	}
}

int main(){
	list<int> l = {1,2,3,4,5,6,7,8};
	forward_list<int> fl = {1,2,3,4,5,6,7,8};
	func1(l);
	func2(fl);
	cout << "list" << endl;
	for(auto c : l){
		cout << c << endl;
	}
	cout << "forward_list" << endl;
	for(auto c : fl){
		cout << c << endl;
	}
	return 0;
}
