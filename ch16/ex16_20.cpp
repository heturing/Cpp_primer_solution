#include <iostream>
#include <vector>

using namespace std;

template <typename C> void print(const C &v){
	for(auto beg = v.begin(); beg != v.end(); beg++){
		cout << *beg << " ";
	}
	cout << endl;
	return;
}

int main(){
	vector<int> vi{1,2,3,4,5};
	print(vi);

	vector<char> vc{'a', 'b', 'c'};
	print(vc);

	return 0;
}
