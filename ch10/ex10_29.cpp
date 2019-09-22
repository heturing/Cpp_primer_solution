#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

int main(){
	ifstream inf("./ex10_29.txt");
	istream_iterator<string> is_iter(inf);
	istream_iterator<string> eof;
	ostream_iterator<string> os_iter(cout, " ");
	vector<string> v(is_iter, eof);
	for(auto c : v){
		*os_iter++ = c;
	}
	cout << endl;
	return 0;
}
