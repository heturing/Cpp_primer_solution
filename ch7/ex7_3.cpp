#include "ex7_2.h"

using std::cin;
using std::cerr;
using std::cout;
using std::endl;

int main(){
	Sales_data total;
	if(cin >> total.bookNumber >> total.units_solds >> total.revenue){
		Sales_data trans;
		while(cin >> trans.bookNumber >> trans.units_solds >> trans.revenue){
			if(total.isbn() == trans.isbn()){
				total.combine(trans);
			}
			else{
				cout << total.bookNumber << " " << total.units_solds << " "<< total.revenue << endl;
				total = trans;
			}
		}
		cout << total.bookNumber << " " << total.units_solds << " "<< total.revenue << endl;
	}
	else{
		cerr << "No data?!" << endl;
	}
}
