#include <iostream>
#include <iterator>

using namespace std;

int main(){
	int arr[10] ={1,1,1,1,1,1,1,1,1,1};
	int *pbegin = begin(arr), *pend = end(arr);
	while(pbegin != pend){
		*pbegin = 0;
		++pbegin;
	}
	for(auto i : arr){
		cout << i << endl;
	}
	return 0;
}
