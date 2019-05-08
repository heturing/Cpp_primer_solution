#include <iostream>

using namespace std;

struct Sales_data{
	std::string bookNumber;
	unsigned units_solds = 0;
	double revenue = 0.0;
};

int main(){
	Sales_data total;
	if(cin >> total.bookNumber >> total.units_solds >> total.revenue){
		Sales_data trans;
		while(cin >> trans.bookNumber >> trans.units_solds >> trans.revenue){
			if(total.bookNumber == trans.bookNumber){
				total.units_solds += trans.units_solds;
				total.revenue += trans.revenue;
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
