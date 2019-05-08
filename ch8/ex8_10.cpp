#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

int main(int argc, char* argv[]){
	ifstream ifs(argv[1]);
	string s;
	vector<string> v;
	while(getline(ifs, s)){
		v.push_back(s);
	}

	for(auto c : v){
		istringstream iss(c);
		while(iss >> s){
			cout << s << endl;
		}
	}
	return 0;
}
