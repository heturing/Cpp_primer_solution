#include "./Quote.h"

using namespace std;

int main(){
	Limit_quote lq("789", 30, 10, 0.1);
	print_total(cout, lq, 5);
	print_total(cout, lq, 20);
	return 0;
}
