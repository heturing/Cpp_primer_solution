#ifndef EX7_6
#define EX7_6

#include <iostream>

class Sales_data{

	private:
		std::string bookNo = "";
		unsigned units_sold = 0;
		double revenue = 0.0;
};

Sales_data add(const Sales_data &lhs, const Sales_data &rhs);	

#endif
