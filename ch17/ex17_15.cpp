#include <iostream>
#include <regex>
#include <stdexcept>

using namespace std;

int main(){
	string s("[[:alnum:]]*[^c]ie[[:alnum:]]*");
	regex r(s);
	string temp;
	cin >> temp;
	if(regex_search(temp, r)){
		cout << "bad string" << endl;
	}
	else{
		cout << "good string" << endl;
	}
	return 0;
}
