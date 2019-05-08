#include <iostream>

using namespace std;

int main(){
	string s = "This asdakdaldnasndasndqbwdnsajdnkewnenlandiasfjrl\nsdnajdbsjvnowyueonuww\nsdkawb	oxcsnca   asdiwbn	nasldw  \nasduwba,d  		adadn";
	int bCount = 0, tCount = 0, nCount = 0;
	for(auto c : s){
		switch(c){
			case ' ':
				++bCount;
				break;
			case '	':
				++tCount;
				break;
			case '\n':
				++nCount;
				break;
			default:
				;
		}
	}
	cout << bCount << " " << tCount << " " << nCount << endl;
	return 0;
}
