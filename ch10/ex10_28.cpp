#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

void print(ostream &os, vector<int> v){
	for(auto c : v){
		os << c << " ";
	}
	cout << endl;
	return;
}

int main(){
	vector<int> v0 = {1,2,3,4,5,6,7,8,9};
	vector<int> v1,v2,v3;
//	copy(v0.begin(), v0.end(), front_inserter(v1));
	copy(v0.begin(), v0.end(), inserter(v2, v2.begin()));
	copy(v0.begin(), v0.end(), back_inserter(v3));
//	print(cout,v1);
	print(cout,v2);
	print(cout,v3);
	return 0;
}	
