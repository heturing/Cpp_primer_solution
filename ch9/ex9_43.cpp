#include <iostream>
#include <string>

using namespace std;

string my_replace(string s, const string oldVal, const string newVal){
	auto oldValLen = oldVal.size();
	for(auto iter = s.begin(); iter <= s.end() - oldValLen; iter++){
		string sub(iter, iter + oldValLen);
		if(sub == oldVal){
			s.erase(iter, iter + oldValLen);
			s.insert(iter, newVal.begin(), newVal.end());
			iter += newVal.size() - 1;
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
