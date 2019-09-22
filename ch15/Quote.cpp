#include "./Quote.h"

using namespace std;

double print_total(std::ostream &os, const Quote &item, std::size_t sz){
	double ret = item.net_price(sz);
	os << "ISBN: " << item.isbn() << " # sold: " << sz << " total due: " << ret << endl;
	return ret;
}

void Quote::debug() const {
	cout << "bookNo: " << bookNo << " price: " << price;
}

double Bulk_quote_direct::net_price(size_t sz) const{
	if(sz >= quantity){
		return sz * (1 - discount) * price;
	}
	else{
		return sz * price;
	}
}




//Bulk_quote::Bulk_quote(const string &s, double p, size_t sz, double d) : Disc_quote(s, p, sz, d) {cout << " Bulk_quote user define constructor" << endl;}

double Bulk_quote::net_price(size_t sz) const{
	if(sz >= quantity){
		return sz * (1 - discount) * price;
	}
	else{
		return sz * price;
	}
}

void Bulk_quote::debug() const {
	this->Quote::debug();
	cout << " min_qty: " << quantity << " discount: " << discount; 
}


Limit_quote::Limit_quote(const string &s, double p, size_t sz, double d) : Disc_quote(s, p ,sz, d) {cout << " Limit_quote user define constructor" << endl;}

double Limit_quote::net_price(size_t sz) const{
	if(sz <= quantity){
		return sz * (1-discount) * price;
	}
	else{
		return sz * price;
	}
}

void Limit_quote::debug() const {
	this->Quote::debug();
	cout << " max_qty: " << quantity << " discount: " << discount;
}


double bucket::total_receipt(ostream &os) const{
	double sum = 0.0;
	for(auto iter = items.cbegin(); iter != items.cend(); iter = items.upper_bound(*iter)){
		sum += print_total(os, **iter, items.count(*iter));
	}
	os << "Total sale: " << sum << endl;
	return sum;
}
