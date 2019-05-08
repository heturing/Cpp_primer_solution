#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	string word;
	vector<string> v;
	while(cin >> word){
		if(find(v.begin(), v.end(), word) == v.end()){
			v.push_back(word);
		}
	}
	for(auto c : v){
		cout << c << endl;
	}
}
