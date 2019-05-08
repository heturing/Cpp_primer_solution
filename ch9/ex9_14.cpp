#include <iostream>
#include <list>
#include <vector>
#include <string>

using namespace std;

int main(){
	list<const char*> l = {"he", "jia", "qi"};
	vector<string> v(l.begin(), l.end());
	for(auto c : v){
		cout << c << endl;
	}
	return 0;
}
