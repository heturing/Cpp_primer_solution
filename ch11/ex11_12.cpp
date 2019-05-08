#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int main(){
	vector<pair<string,int>> v;
	string s;
	int i;
	while(cin >> s && cin >> i){
		v.push_back(make_pair(s,i));
	}

	for(auto c : v){
		cout << c.first << " " << c .second << endl;
	}
	return 0;

}
