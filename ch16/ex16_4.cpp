#include <iostream>
#include <vector>
#include <list>
#include <functional>

using namespace std;

template<typename I, typename V> I my_find(const I &beg, const I &end, const V &v){
	auto b = beg;
	while(not_equal_to<V>()(*b, v) && (b != end)){
		b++;
	}
	return b;
}

int main(){
	vector<int> v{1,2,3,4,5,6};
	list<string> l{string("he"), string("jia"), string("qi")};

	cout << *my_find(v.begin(), v.end(), 5) << endl;
	cout << *my_find(l.begin(), l.end(), string("jia")) << endl;
	return 0;
}
