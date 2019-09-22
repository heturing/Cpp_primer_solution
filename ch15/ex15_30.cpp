#include "./Quote.h"
#include <vector>
using namespace std;

int main(){
	bucket b;
	int i = 5;
	while(i > 0){
		b.add_item(Quote("123", 10));
		b.add_item(Bulk_quote_direct("456", 10, 5, 0.1));
		i--;
	}
	b.total_receipt(cout);
	return 0;

}
