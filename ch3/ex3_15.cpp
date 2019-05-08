#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;
using std::cin;
using std::cout;
using std::endl;

int main(){
	vector<string> v;
	string str;
	while(cin >> str){
		v.push_back(str);
	}
	cout << "out of loop." << endl;
	return 0;
}
