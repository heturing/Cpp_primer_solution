#include "Sales_item.h"
#include <algorithm>
#include <vector>
#include <numeric>

using namespace std;

int main(){
	vector<Sales_item> v;
	v.push_back(Sales_item("123"));
	v.push_back(Sales_item("123"));
//	istream_iterator<Sales_item> is_iter(cin), eof;
//	v.push_back(*is_iter++);

	sort(v.begin(), v.end(), [](const Sales_item &s1, const Sales_item &s2) -> bool { return s1.isbn() < s2.isbn();});
	auto psum = v.begin();
	auto sum = *psum;
	vector<Sales_item>::iterator p;
	while((p = find(psum + 1, v.end(), sum)) != v.end()){
		cout << accumulate(psum, p, Sales_item(psum -> isbn())) << endl;
		sum = *++psum;
	}
	
	ostream_iterator<Sales_item> os_iter(cout, " ");
	return 0;
}	
		
