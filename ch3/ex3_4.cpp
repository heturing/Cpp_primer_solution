#include <iostream>
#include <string>

using std::string;
using std::cin;
using std::cout;
using std::endl;

int main(){
	string str1;
	string str2;
	getline(cin, str1);
	getline(cin, str2);

	if(str1 > str2){
		cout << "first is larger" << endl;
	}
	else if(str1 < str2){
		cout << "second is larger" << endl;
	}
	else{
		cout << "they are equal" << endl;
	}

	if(str1.size() < str2.size()){
		cout << "second is longer" << endl;
	}
	else if(str1.size() > str2.size()){
		cout << "first is longer" << endl;
	}
	else{
		cout << "equal length" <<endl;
	}

	return 0;
}

