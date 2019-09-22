#include <iostream>

using namespace std;

int main(){
	string last = "", current = "";
	bool rep = false;
	while(cin >> current){
		if(current == last){
			cout << current << " repeat" << endl;
			rep = true;
			break;
		}
		last = current;
	}
	if(!rep){
		cout << "no repetition" << endl;
	}
	return 0;
}
