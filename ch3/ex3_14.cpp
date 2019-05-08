#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;
using std::cin;
using std::cout;
using std::endl;

int main(){
	vector<int> v;
	int i;
	while(cin >> i){
		v.push_back(i);
	}
	cout << "out of loop." << endl;
	return 0;
}
