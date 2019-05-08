#include <iostream>
#include <string>

using namespace std;

string pre_and_suf(string name, const string pre, const string suf){
	name.insert(0, pre);
	name.insert(name.size(),suf);
	return name;
}

int main(){
	string p = "Mr.", s = "III", name = "hejiaqi";
	string new_name = pre_and_suf(name,p,s);
	cout << new_name << endl;
	return 0;
}
