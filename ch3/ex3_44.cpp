#include <iostream>
#include <iterator>

using namespace std;
using int_array = int[4];

int main(){
	int ia[3][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
	for(int_array *p = begin(ia); p != end(ia); p++){
		for(int *q = begin(*p); q != end(*p); q++){
			cout << *q << endl;
		}
	}
	return 0;
}
