#include <iostream>
#include <new>
#include <memory>

using namespace std;

int main(){
	string s;
	cin >> s;
	unique_ptr<char []> str(new char[s.size() + 1]);
	for(size_t sz = 0; sz < s.size(); sz++){
		str[sz] = s[sz];
	}
	str[s.size()] = '\0';

	for(size_t sz = 0; sz < s.size(); sz++){
		cout << str[sz];
	}
	cout << endl;
	return 0;
}
