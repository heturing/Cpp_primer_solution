#include <iostream>
#include <iterator>

using namespace std;

int main(){
	int arr1[3] = {0,0,1};
	int arr2[3] = {0,0,0};

	if((end(arr1) - begin(arr1)) != (end(arr2) - begin(arr2))){
		cout << "Not Equal" << endl;
	}
	else{
		int *pbegin1 = begin(arr1);
		int *pbegin2 = begin(arr2);
		int *pend1 = end(arr1);

		while(pbegin1 != pend1){
			if(*pbegin1 != *pbegin2){
				cout << "Not Equal" << endl;
				break;
			}
			else{
				pbegin1++;
				pbegin2++;
			}
		}
	}
	return 0;
}
