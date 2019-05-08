#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main(){
	stack<char> ps;
	string s = "((()))";
	for(auto iter = s.begin(); iter != s.end(); iter++){
		if(*iter == '('){
			ps.push(*iter);
		}
		else if(*iter == ')'){
			if(ps.empty()){
				cout << "bad expression" << endl;
				return -1;
			}
			else{
				ps.pop();
			}
		}
	}
	cout << "good expression" << endl;
	return 0;
}
