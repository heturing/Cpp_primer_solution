#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main(){
	map<string, vector<string>> families;
	string last_name;
	cin >> last_name;
	families[last_name] = {"jiaqi", "tianqi"};

	for(auto f : families){
		cout << f.first << " ";
		for(auto s : f.second){
			cout << s << " ";
		}
		cout << endl;
	}
}
