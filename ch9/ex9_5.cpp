#include <iostream>
#include <vector>

using namespace std;

vector<int>::iterator find_int(vector<int> v, int i){
	for(auto beg = v.begin(); beg != v.end(); beg++){
		if(*beg == i){
			return beg;
		}
	}
	return v.end();
}

int main(){
	vector<int> v = {1,2,3,4,5,6};
	int i = 6;
	auto res = (find_int(v,i));
	if(res == v.end()){
		cout << "no match " << endl;
	}
	else{
		cout << *res << endl;
	}
	return 0;
}
