#include <iostream>
#include <string>
#include <cctype>

using namespace std;

bool check_capital(const string &s){
	for(auto c : s){
		if(isupper(c)){
			cout << "has Capital" << endl;
			return true;
		}
	}
	cout << "no capital" << endl;
	return false;
}

int to_lowercase(string &s){
	for(auto &c : s){
		c = tolower(c);
	}
	return 0;
}

int main(){
	string s = "Hejiaqi";
	check_capital(s);
	to_lowercase(s);
	cout << s << endl;
	return 0;
}
