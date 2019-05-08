#include "ex12_19.h"
#include <fstream>

using namespace std;

int main(){
	ifstream ifs("./ex12_20.txt");
	string s;
	StrBlob sb;
	StrBlobPtr sbp = sb.begin();
	while(getline(ifs, s)){
		sb.push_back(s);
	}
	
	cout << sb.size() << endl;	

	cout << "print with weak_ptr" << endl;
	while(sbp != sb.end()){
		cout << sbp.deref() << endl;
		sbp = sbp.incr();
	}
	return 0;	
}
