#include <iostream>
#include <map>

using namespace std;

int main(){
	multimap<string, string> m{{"he","scientist"},{"zhu","peasent"},{"zhu","student"}};
	auto it = m.find("zhu");
	auto c = m.count("zhu");
	cout << c << endl;
	while(c){
		it = m.erase(it);
		c--;
	}

	for(auto lf : m){
		cout << lf.first << " " << lf.second << endl;
	}
	return 0;
}
