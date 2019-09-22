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
		word[0] = tolower(word[0]);
		string punc = ".,";
		auto pos = word.find_first_of(punc);
		string newWord(word, 0, pos);
		if(s.find(newWord) == s.end()){
			m[newWord]++;
		}
	}

	for(const auto &c : m){
		cout << c.first << " " << c.second << endl;
	}
	return 0;
}
	
