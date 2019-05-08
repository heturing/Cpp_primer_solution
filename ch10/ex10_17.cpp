#include <iostream>
#include "ex10_12.h"
#include <vector>

using std::vector;

int main(){
	vector<Sales_data> v;
	v.push_back(Sales_data("123"));
	v.push_back(Sales_data("124"));
	v.push_back(Sales_data("345"));

	sort(v.begin(), v.end(), [](const Sales_data &s1, const Sales_data &s2) -> bool {return s1.isbn() < s2.isbn();});
	for(auto c :v){
		cout << c.isbn() << endl;
	}
	return 0;
}