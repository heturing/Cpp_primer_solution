#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int main(int argc, char *argv[]){
	vector<string> v;
	string s;
	for(auto p = argv + 1; p != argv + argc; p++){
		ifstream ifs(*p);
		if(ifs){
			while(getline(ifs, s)){
				v.push_back(s);
			}
		}
		else{
			cerr << "error in creating ifstream object" << endl;
		}
	}
	cout << "length of vector: " << v.size() << endl;
	for(auto c :v){
		cout << c << endl;
	}
	return 0;
}
