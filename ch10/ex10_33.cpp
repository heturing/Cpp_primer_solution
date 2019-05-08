#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char *argv[]){
	if(argc != 4){
		cerr << " Wrong input files" << endl;
		return -1;
	}
	
	ifstream ifs(argv[1]);
	ofstream ofs1(argv[2]), ofs2(argv[3]);

	istream_iterator<int> is_iter(ifs), eof;
	vector<int> v(is_iter, eof);

	ostream_iterator<int> os_iter1(ofs1, " "), os_iter2(ofs2, "\n");
	auto it = partition(v.begin(), v.end(), [](int i) -> bool { return i % 2 == 0;});
	copy(v.begin(), it, os_iter1);
	copy(it, v.end(), os_iter2);
	return 0;
}
	
