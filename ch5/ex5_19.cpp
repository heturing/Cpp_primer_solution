#include <iostream>
#include <string>

using namespace std;

int main(){
	string s1,s2;
	cout << "Input two strings:" << endl;
	cin >> s1 >> s2;
	if(s1.size() < s2.size()){
		cout << "s1 is less" << endl;
	}
	else{
		cout << "s2 is less" << endl;
	}
	return 0;
}	
