#include <iostream>
using std::string;
using std::istream;
using std::ostream;
using std::cout;
using std::endl;

class Sales_data;
istream &read(istream &, Sales_data &);

class Sales_data{
friend istream &read(istream &, Sales_data &);
friend ostream &print(ostream &, const Sales_data &);
friend Sales_data add(const Sales_data &, const Sales_data &);
public:
	Sales_data(const string &s, unsigned n, double p) : bookNumber(s), units_solds(n), revenue(n*p) {cout << "3 parameter" << endl;}
	Sales_data() : Sales_data("", 0, 0) {cout << "no parameter" << endl;}
	Sales_data(const string &s) : Sales_data(s, 0, 0) {cout << "1 parameter" << endl;}
	Sales_data(istream &is) : Sales_data() {read(is, *this); cout << "instream" << endl;}
	string isbn() const {return bookNumber;}
	Sales_data& combine(const Sales_data&);
private:
	string bookNumber;
	unsigned units_solds = 0;
	double revenue = 0.0;
	double avg_price() const;
};

Sales_data& Sales_data::combine(const Sales_data &rhs){
    units_solds += rhs.units_solds;
	revenue += rhs.revenue;
 	return *this;
}	

inline double Sales_data::avg_price() const{
	if(units_solds){
		return revenue / units_solds;
	}
	else{
		return 0;
	}
}

istream &read(istream &is, Sales_data &item){
	double price = 0.0;
	is >> item.bookNumber >> item.units_solds >> price;
	item.revenue = item.units_solds * price;
	return is;
}

ostream &print(ostream &os, const Sales_data &item){
	os << item.isbn() << " " << item.units_solds << " " << item.revenue << " " << item.avg_price();
	return os;
}

Sales_data add(const Sales_data &lhs, const Sales_data &rhs){
	Sales_data sum = lhs;
	sum.combine(rhs);
	return sum;
}

bool compareIsbn(const Sales_data &s1, const Sales_data &s2){
	return s1.isbn() < s2.isbn();
}