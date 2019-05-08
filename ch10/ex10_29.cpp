#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
	istream_iterator<string> is_iter(cin);
	istream_iterator<string> eof;
	ostream_iterator<string> os_iter(cout, " ");
	vector<string> v(is_iter, eof);
	for(auto c : v){
		*os_iter++ = c;
	}
	cout << endl;
	return 0;
}
