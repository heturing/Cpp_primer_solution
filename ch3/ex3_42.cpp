#include <iostream>
#include <vector>
#include <iterator>
#include <cstddef>

using namespace std;

int main(){
	vector<int> v(10,1);
	int arr[10];
	for(auto i = 0; i != 10; i++){
		arr[i] = v[i];
	}
	for(auto c: arr){
		cout << c << endl;
	}
	return 0;
}	
