#include <iostream>
#include <list>
#include <vector>

using namespace std;

int main(){
	int ia[] = {0,1,1,2,3,5,8,13,21,55,89};
	list<int> l(begin(ia), end(ia));
	vector<int> v(begin(ia), end(ia));
	auto it = l.begin();
	while(it != l.end()){
		if(*it % 2){
			it = l.erase(it);
		}
		else{
			it++;
		}
	}

	auto iter = v.begin();
	while(iter != v.end()){
		if(!(*iter % 2)){
			iter = v.erase(iter);
		}
		else{
			iter++;
		}
	}
	cout << "list " << endl;
	for(auto c : l){
		cout << c << endl;
	}
	cout << "vector" << endl;
	for(auto c : v){
		cout << c << endl;
	}
	return 0;
}
