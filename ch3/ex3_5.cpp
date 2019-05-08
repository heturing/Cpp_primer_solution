#include <iostream>
#include <string>

using namespace std;

int main(){
	string str1, str2;
	getline(cin, str1);
	getline(cin, str2);
	cout << str1 + str2 << endl;
	
	string temp = str1 + str2;
	string s = "";
	for(string::size_type i = 0; i < temp.size(); i++){
		if(temp[i] == ' '){
		   cout << s << endl;
		   s = "";
		}
		else{
 		s += temp[i];
		}
	}
	cout << s << endl;
	return 0;
}	
