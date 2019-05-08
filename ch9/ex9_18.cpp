#include <iostream>
#include <deque>

using namespace std;

int main(){
	string s;
	deque<string> d;
	while(cin >> s){
		d.push_back(s);
	}

	cout << "the content is " << endl;
	for(deque<string>::iterator iter = d.begin(); iter != d.end(); iter++){
	   cout << *iter << endl;
	}
	return 0;
}
