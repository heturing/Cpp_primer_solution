#include "./Quote.h"

using namespace std;

int main(){
	Quote q("123", 10);
	Bulk_quote bq("456", 20, 10, 0.1);
	Limit_quote lq("789", 20, 10, 0.1);

	q.debug();
	cout << endl;
	bq.debug();
	cout << endl;
	lq.debug();
	cout << endl;
	return 0;

}
