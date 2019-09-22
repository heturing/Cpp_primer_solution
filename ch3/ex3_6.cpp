#include <iostream>

using namespace std;

int main(){
	string s = "hejiaqi";
	for(auto &c : s){
		c = 'X';
	}
	cout << s << endl;
	return 0;
}
