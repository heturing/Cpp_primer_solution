#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

int main(){
	int arr[10] = {0,0,0,0,0,0,0,0,0,0};
	vector<int> v(arr, end(arr));
	for(auto c: v){
		cout << c << endl;
	}
	return 0;
}
