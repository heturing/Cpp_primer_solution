#include "ex12_30.h"

void runQueries(ifstream &infile){
	TextQuery tq(infile);

	while(true){
		cout << "enter the word to look for, or q to quit" << endl;
		string s;
		if(!(cin >> s) || s == "q") break;
		print(cout, tq.query(s)) << endl;
	}
}

int main(){
	ifstream ifs("./ex12_28.txt");
	runQueries(ifs);
	return 0;
}
