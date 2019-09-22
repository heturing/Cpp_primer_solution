#include "./Quote.h"

using namespace std;

int main(){
	Quote q("123", 10);
	Bulk_quote bq("456", 20, 5, 0.1);
	print_total(cout, q, 10);
	print_total(cout, bq, 10);
	return 0;
}
