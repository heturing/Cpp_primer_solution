#include <iostream>
#include <vector>
#include <cctype>

using namespace std;

int main(){
	vector<string> v{"hejiaqi", "next", "", "zhutianqi"};
	for(auto it = v.begin(); it != v.end() && !it->empty(); it++){
		for(auto &c : *it){
			c = toupper(c);
		}
	}

	for(auto s: v){
		cout << s << endl;
	}
	return 0;
}
