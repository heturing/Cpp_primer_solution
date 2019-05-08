#include <iostream>
#include <string>

using std::string;
using std::cin;
using std::cout;
using std::endl;

int main(){
	string str;
	while(getline(cin, str)){
		cout << str << endl;
		if(str == "exit getline"){
			break;
		}
	}

	while(cin >> str){
		cout << str << endl;
	}
	return 0;

}
