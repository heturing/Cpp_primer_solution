#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

int main(){
	string candidate = "aceimnorsuvwxz";
	ifstream ifs("./ex9_49.txt");
	string longest = "";
	if(ifs){
		string curr = "";
		string::size_type pos = 0;
		while(ifs >> curr){
			if(((pos = curr.find_first_not_of(candidate, pos)) == string::npos) && longest.size() < curr.size()){
				longest = curr;
			}
		}
	}
	cout << longest << endl;
	return 0;
}

