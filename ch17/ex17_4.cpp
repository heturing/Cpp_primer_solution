#include <iostream>
#include <tuple>
#include "../ch14/Sales_data.h"
#include <vector>
#include <algorithm>

using namespace std;

typedef tuple<vector<Sales_data>::size_type, vector<Sales_data>::const_iterator, vector<Sales_data>::const_iterator> matches;

vector<matches> findBook(const vector<vector<Sales_data>> &files, const string &book){
	vector<matches> ret;
	for(auto it = files.cbegin(); it != files.cend(); it++){
		auto found = equal_range(it->cbegin(), it->cend(), book, compareIsbn);
	   	if(found.first != found.second){
			ret.push_back(make_tuple(it - files.cbegin(), found.first, found.second));
		}
	}
	return ret;	
}
