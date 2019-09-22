#include <iostream>
#include <fstream>
#include <iterator>
#include <algorithm>
using namespace std;

class TestLength{
	public:
		TestLength(size_t l, size_t u) : lower(l), upper(u) {}
		bool operator()(const string s) const{
			return ((lower <= s.size()) && (s.size() <= upper)) || (s.size() > upper);
		}
	private:
		size_t lower;
		size_t upper;
};

int main(){
	ifstream ifs("./ex14_38.txt");
	istream_iterator<string> ii(ifs), eof;
	cout << count_if(ii, eof, TestLength(1,9)) << endl;
	return 0;
}
