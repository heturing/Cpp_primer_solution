#include <iostream>

using namespace std;

int main(){
	int i;
	while(cin >> i){
		if(i % 2 == 0){
			cout << i << " is an even." << endl;
		}
		else{
			cout << i << " is an odd." << endl;
		}
	}
	return 0;
}
