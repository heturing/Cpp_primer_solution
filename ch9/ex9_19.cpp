#include <iostream>
#include <list>

using namespace std;

int main(){
	string s;
	list<string> d;
	while(cin >> s){
		d.push_back(s);
	}

	cout << "the content is " << endl;
	for(list<string>::iterator iter = d.begin(); iter != d.end(); iter++){
	   cout << *iter << endl;
	}
	return 0;
}
