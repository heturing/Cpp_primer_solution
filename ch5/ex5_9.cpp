#include <iostream>

using namespace std;

int main(){
	string s = "";
	int vCount = 0;
	while(cin >> s){
		for(auto c : s){
			if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'){
				++vCount;
			}
		}
	}
	cout << "There are " << vCount << " vowels in text" << endl;
	return 0;
}
