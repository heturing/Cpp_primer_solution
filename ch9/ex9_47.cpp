#include <iostream>
#include <string>

using namespace std;

void find1(const string s){
	string numbers("0123456789");
	string alphabet("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");
	string::size_type pos = 0;
	while((pos = s.find_first_of(numbers,pos)) != string::npos){
		cout << s[pos] << " is a numeric character." << endl;
		pos++;
	}
	pos = 0;
	while((pos = s.find_first_of(alphabet, pos)) != string::npos){
		cout << s[pos] << " is a alphabetic character." << endl;
		pos++;
	}
	return;
}

void find2(const string s){
	string numbers("0123456789");
	string alphabet("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");
	string::size_type pos = 0;
	while((pos = s.find_first_not_of(alphabet, pos)) != string::npos){
		cout << s[pos] << " is a numeric character." << endl;
		pos++;
	}
	pos = 0;
	
	while((pos = s.find_first_not_of(numbers, pos)) != string ::npos){
		cout << s[pos] << " is a alphabetic character." << endl;
		pos++;
	}
	return;
}

int main(){
	string s = "ab2c3d7R4E6";
	find1(s);
	find2(s);
	return 0;
}

