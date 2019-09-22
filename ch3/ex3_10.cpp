#include <iostream>
#include <cctype>
using namespace std;

int main(){
	string s;
	cin >> s;
	for(auto &c : s){
		if(!ispunct(c)){
			cout << c;
		}
	}
	cout << endl;
	return 0;
}
