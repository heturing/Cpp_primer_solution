#include "../ch7/ex7_26.h"
#include <fstream>

using std::ifstream;
using std::cout;
using std::endl;
using std::cerr;

int main(int argc, char *argv[]){
	ifstream ifs(argv[1]);
	Sales_data total;
	if(read(ifs, total)){
		Sales_data trans;
		while(read(ifs, trans)){
			if(total.isbn() == trans.isbn()){
				total.combine(trans);
			}
			else{
				print(cout, total) << endl;
				total = trans;
			}
		}
		print(cout, total) << endl;
	}
	else{
		cerr << " No Data?!" << endl;
	}
}
