#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void elimDups(vector<string> &v){
	sort(v.begin(),v.end());
	auto iter = unique(v.begin(), v.end());
	v.erase(iter, v.end());
}

void biggies(vector<string> &words, vector<string>::size_type sz){
	elimDups(words);
	stable_sort(words.begin(), words.end(), [](const string &a, const string &b) -> bool {return a.size() < b.size();});
	auto wc = find_if(words.begin(), words.end(), [sz](const string &a) -> bool {return a.size() >= sz;});
	auto count = words.end() - wc;
	auto f = [](int i, const string &a, const string &b) -> string {return (i ? a+b : a);};
	cout << count << " " << f(count, "word", "s") << " of length " << sz << " or longer" << endl;
	for_each(wc, words.end(), [](const string &s) -> void {cout << s << " "; return;});
	cout << endl;
	return;
}

int main(){
	vector<string> v = {"hejiaqi", "zhutianqi", "int", "double", "small", "big"};
	biggies(v,5);
	return 0;
}
