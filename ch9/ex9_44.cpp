#include <iostream>
#include <string>

using namespace std;

string my_replace(string s, const string oldVal, const string newVal){
	auto oldValLen = oldVal.size();
	for(size_t i = 0; i <= s.size() - oldValLen; i++){
		string sub = s.substr(i, oldValLen);
		if(sub == oldVal){
			s.replace(i, oldValLen, newVal);
			i += newVal.size() - 1;
		}
	}
	return s;
}

int main(){
	string s = "abhecdhe";
	string s1 = my_replace(s,"he", "jia");
	cout << s1 << endl;
	return 0;
}
