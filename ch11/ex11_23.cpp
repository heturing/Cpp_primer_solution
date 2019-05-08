#include <iostream>
#include <map>

using namespace std;

int main(){
	multimap<string, string> mm;
	string s1, s2;
	while(cin >> s1 >> s2){
		mm.insert({s1,s2});
	}

	for(auto c : mm){
		cout << c.first << " " << c.second << endl;
	}
	return 0;

}
