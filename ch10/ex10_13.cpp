#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

bool longString(const string s){
	return s.size() >= 5;
}

int main(){
	vector<string> words = {"hejiaqi", "zhutianqi", "small", "big", "long", "int", "double", "unsigned"};
   	auto iter = partition(words.begin(), words.end(), longString);
	auto it = words.begin();
	while(it != iter){
		cout << *it++ << endl;
	}
	return 0;
}	
