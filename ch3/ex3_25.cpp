#include <iostream>
#include <vector>

using namespace std;

int main(){
	vector<int> v(11,0);
	int i;
	while(cin >> i){
		if(i >= 0 && i <= 100){
			*(v.begin() + i / 10) += 1;	
		}
	}

	for(auto c : v){
		cout << c << endl;
	}
	return 0;
}
