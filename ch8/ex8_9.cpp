#include <iostream>
#include <sstream>
using namespace std;

istream &test(istream & is){
	string s;
	while(is >> s){
		cout << s << endl;
	}
	cout << "before resetting: " << is.good() << endl;
	is.clear();
	cout << "after resetting: " << is.good() << endl;
	return is;
}

int main(){
	istringstream iss("he jia qi niu bi");
	test(iss);
}
