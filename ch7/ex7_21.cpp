#include "ex7_21.h"

using std::cin;
using std::cerr;
using std::cout;
using std::endl;

int main(){
	Sales_data total(cin);
	if(total.isbn() != ""){
		istream &is = cin;
		while(is){
			Sales_data trans(is);
			if(!is){
				break;
			}
			if(total.isbn() == trans.isbn()){
				total.combine(trans);
			}
			else{
				print(cout, total);
				total = trans;
			}
		}
		print(cout, total);
	}
	else{
		cerr << "No data?!" << endl;
	}
}
