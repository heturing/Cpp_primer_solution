#ifndef SALES_DATA
#define SALES_DATA

#include <iostream>
#include <stdexcept>

class Sales_data{
friend Sales_data add(const Sales_data &lhs, const Sales_data &rhs);
friend std::istream& read(std::istream &is, Sales_data &s);
friend std::ostream& print(std::ostream *os, const Sales_data &s);

public:
	Sales_data() = default;
	Sales_data(const std::string &s, unsigned n, double p) : bookNo(s), units_sold(n), revenue(n*p) {}
	Sales_data(const std::string &s) : bookNo(s) {}
	Sales_data(std::istream &is);
	std::string isbn() const {return bookNo;}
	Sales_data& combine(const Sales_data &rhs);

	
private:
	double avy_price() const;

	std::string bookNo = "";
	unsigned units_sold = 0;
	double revenue = 0.0;
};

Sales_data add(const Sales_data &lhs, const Sales_data &rhs);
std::istream& read(std::istream &is, Sales_data &s);
std::ostream& print(std::ostream *os, const Sales_data &s);
#endif
