#include <iostream>
#include <map>
#include <set>

using namespace std;

int main(){
	map<string, size_t> m;
	set<string> s = {"The", "But", "And", "Or", "An", "A", "the", "but", "and", "or", "an", "a"};
	string word;
	while(cin >> word){
		if(s.find(word) == s.end()){
			auto res = m.insert({word,1});
			if(!res.second){
				++res.first -> second;
			}
		}
	}

	for(const auto &c : m){
		cout << c.first << " " << c.second << endl;
	}
	return 0;
}
	
