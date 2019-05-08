#include <iostream>
#include <vector>

using namespace std;

int print(vector<int> v){
	if(v.size() == 1){
		cout << v[0] << endl;
		return 0;
	}
	else{
		vector<int> v1(v.begin(), v.begin()+1);
		vector<int> v2(v.begin()+1, v.end());
		print(v1);
		print(v2);
		return 0;
	}
}

int main(){
	vector<int> v = {1,2,3,4,5};
	print(v);
	return 0;
}
