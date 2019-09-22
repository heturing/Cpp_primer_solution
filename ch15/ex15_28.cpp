#include "./Quote.h"
#include <vector>
using namespace std;

int main(){
	vector<Quote> v;
	v.push_back(Quote("123", 10));
	v.push_back(Bulk_quote("456", 10, 5, 0.1));

	cout << v.front().net_price(10) << endl;
	cout << v.back().net_price(10) << endl;

	return 0;

}
