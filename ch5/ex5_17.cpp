#include <iostream>
#include <vector>

using namespace std;

int main(){
	vector<int> v1 = {0,1,1,2};
	vector<int> v2 = {0,1,1,2,3,5,8};
	
	auto iter1 = v1.begin();
	auto iter2 = v2.begin();
	while(iter1 != v1.end()){
		if(*iter1 != *iter2){
			cout << "false" << endl;
			return 0;
		}
		++iter1;
		++iter2;
	}
	cout << "true" << endl;
	return 0;
}

