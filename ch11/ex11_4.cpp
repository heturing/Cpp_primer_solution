#include <iostream>
#include <map>
#include <set>

using namespace std;

int main(){
	map<string, size_t> m;
	set<string> s = {"The", "But", "And", "Or", "An", "A", "the", "but", "and", "or", "an", "a"};
	set<char> sc = {',', '.'};
	string word;
	while(cin >> word){
		if(s.find(word) == s.end()){
			if(sc.find(word.back()) != sc.end()){
				word.pop_back();
			}
			word.front() = tolower(word.front());
			m[word]++;
		}
	}

	for(const auto &c : m){
		cout << c.first << " " << c.second << endl;
	}
	return 0;
}
	
