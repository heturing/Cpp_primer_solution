#include <iostream>
#include <vector>
#include <string>
#include <cctype>

using namespace std;

int main(){
	string s;
	vector<string> v;
	while(cin >> s){
		v.push_back(s);
	}
	for(auto &w : v){
		for(auto &q : w){
			q = toupper(q);
		}
	}
	int count = 0;
	for(auto w :v){
		if(count == 8){
			cout << endl;
			count = 0;
		}
		else{
			cout << w << " ";
			count++;
		}
	}
	return 0;
}
