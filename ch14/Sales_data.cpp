#include "./Sales_data.h"
#include <stdexcept>

using namespace std;

ostream& operator<<(ostream &os, const Sales_data &sd){
	os << sd.isbn() << " " << sd.units_sold << " " << sd.revenue << " " << sd.avg_price();
	return os;
}

istream& operator>>(istream &in, Sales_data &sd){
	double price;
	in >> sd.bookNo >> sd.units_sold >> price;
	if(in){
		sd.revenue = sd.units_sold * price;
	}
	else{
		sd = Sales_data();
	}
	return in;
}

Sales_data& Sales_data::operator+=(const Sales_data &sd){
	if(this->isbn() != sd.isbn()){
		throw runtime_error("Cannot add two book with different isbn.");
	}
	this->units_sold += sd.units_sold;
	this->revenue += sd.revenue;
	return *this;
}

Sales_data operator+(const Sales_data& sd1, const Sales_data &sd2){
	Sales_data temp = sd1;
	temp += sd2;
	return temp;
}

Sales_data& Sales_data::operator=(std::string s){
	this->bookNo = s;
	this->units_sold = 0;
	this->revenue = 0.0;
	return *this;
}
