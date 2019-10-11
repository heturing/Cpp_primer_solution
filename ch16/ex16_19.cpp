#include <iostream>
#include <vector>

using namespace std;

template <typename C> void print(const C &v){
	using size_type = typename C::size_type;
	for(size_type i = 0; i < v.size(); i++){
		cout << v[i] << " ";
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
