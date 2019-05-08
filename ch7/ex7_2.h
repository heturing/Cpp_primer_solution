#include <iostream>
using std::string;

struct Sales_data{
	string bookNumber;
	unsigned units_solds = 0;
	double revenue = 0.0;
	string isbn() const {return bookNumber;}
	Sales_data& combine(const Sales_data&);
};

Sales_data& Sales_data::combine(const Sales_data &rhs){
    units_solds += rhs.units_solds;
	revenue += rhs.revenue;
 	return *this;
}	
