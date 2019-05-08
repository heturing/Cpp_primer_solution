#include <iostream>
#include <cctype>

using namespace std;

int main(){
	string last = "", current = "";
	while(cin >> current){
		if(!isupper(current[0])){
			continue;
		}
		if(current == last){
			cout << current << " repeat" << endl;
			return 0;
		}
		last = current;
	}
	cout << "no repetition" << endl;
	return 0;
}
