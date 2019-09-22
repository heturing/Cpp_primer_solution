#include "Sales_data.h"

using namespace std;

Sales_data::Sales_data(istream &is){
	read(is, *this);
}

Sales_data& Sales_data::combine(const Sales_data &rhs){
	if(isbn() == rhs.isbn()){
		units_sold += rhs.units_sold;
		revenue += rhs.revenue;
		return *this;
	}
	else{
		throw runtime_error("Only book with same ISBN number can be combined.");
	}
}
