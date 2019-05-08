#include <iostream>
#include <string>

using namespace std;

string make_plural(size_t ctr, const string &word, const string &ending = "s"){
	return (ctr > 1) ? word + ending : word;
}

int main(){
	string s1 = "success", s2 = "failure";
	cout << make_plural(7, s1, "") << endl;
	cout << make_plural(7, s1) << endl;
	cout << make_plural(7, s2, "") << endl;
	cout << make_plural(7, s2) << endl;
	return 0;
}
