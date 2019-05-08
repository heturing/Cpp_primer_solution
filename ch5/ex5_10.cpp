#include <iostream>

using namespace std;

int main(){
	string s = "";
	int aCount = 0, eCount = 0, iCount = 0, oCount = 0, uCount = 0;
	while(cin >> s){
		for(auto c : s){
			switch(c){
				case 'a': case 'A':
					++aCount;
					break;
				case 'e': case 'E':
					++eCount;
					break;
				case 'i': case 'I':
					++iCount;
					break;
				case 'o': case 'O':
					++oCount;
					break;
				case 'u': case 'U':
					++uCount;
					break;
				default:
					;
			}
		}
	}
	cout << aCount << " " << eCount << " " << iCount << " " << oCount << " " << uCount << endl;
	return 0;
}
