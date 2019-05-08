#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	istream_iterator<int> is_iter(cin), eof;
	ostream_iterator<int> os_iter(cout, " ");

	vector<int> v(is_iter, eof);

	sort(v.begin(), v.end());
	unique_copy(v.begin(), v.end(), os_iter);
	return 0;
}
