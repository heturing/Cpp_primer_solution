#ifndef QUOTE
#define QUOTE

#include <iostream>
#include <memory>
#include <set>

class Quote{
friend double print_total(std::ostream &os, const Quote &item, std::size_t sz);
public:
	Quote() {
		std::cout << "quote default constructor" << std::endl;
	}
	Quote(const std::string &s, double sales_price) : bookNo(s), price(sales_price) {
		std::cout << "quote user defined constructor" << std::endl;
	}
	Quote(const Quote &q) : bookNo(q.bookNo), price(q.price) {
		std::cout << "quote copy constructor" << std::endl;
	}
	Quote& operator=(const Quote &q) {
		bookNo = q.bookNo; 
		price = q.price; 
		std::cout << "quote copy assignment" << std::endl; return *this;
	}
	virtual Quote* clone() const & {return new Quote(*this);}
	virtual Quote* clone() const && {return new Quote(std::move(*this));}
	std::string isbn() const {return bookNo;}
	virtual double net_price(std::size_t n) const {return n * price;}
	virtual void debug() const;
	virtual ~Quote() {
		std::cout << "quote destructor" << std::endl;
	}
	
private:
	std::string bookNo;
protected:
	double price = 0.0;
};

double print_total(std::ostream &os, const Quote &item, std::size_t sz);

class Bulk_quote_direct : public Quote{
public:
	Bulk_quote_direct() = default;
	Bulk_quote_direct(const std::string &s, double p, std::size_t sz, double d) : Quote(s, p), quantity(sz), discount(d) {}
	Bulk_quote_direct* clone() const & override {return new Bulk_quote_direct(*this);}
	Bulk_quote_direct* clone() const && override {return new Bulk_quote_direct(std::move(*this));}
	double net_price(std::size_t n) const override;
private:
	std::size_t quantity = 0;
	double discount = 0.0;
};

class Disc_quote : public Quote{
public:
	Disc_quote() : Quote() {
		std::cout << "Disc_quote default constructor" << std::endl;
	}
	Disc_quote(const std::string &s, double price, std::size_t qty, double disc) : Quote(s, price), quantity(qty), discount(disc) {
		std::cout << "Disc_quote user define constructor" << std::endl;
	}
	Disc_quote(const Disc_quote &dq) : Quote(dq), quantity(dq.quantity), discount(dq.discount) {
		std::cout << "Disc_quote copy constructor" << std::endl;
	}
	Disc_quote& operator=(const Disc_quote &dq) {
		std::cout << "Disc_quote copy assignemnt" << std::endl;
		Quote::operator=(dq); 
		quantity = dq.quantity; 
		discount = dq.discount; 
		return *this; 
	}
	virtual ~Disc_quote(){
		std::cout << "Disc_quote destructor" << std::endl;
	}
	double net_price(std::size_t sz) const = 0;
	void debug() const = 0;
protected:
	std::size_t quantity = 0;
	double discount = 0.0;

};



class Bulk_quote : public Disc_quote{
public:
	//Bulk_quote() : Disc_quote() {
	//	std::cout << "Bulk_quote default constructor" << std::endl;
	//}
	//Bulk_quote(const std::string &s, double p, std::size_t sz, double d);
	using Disc_quote::Disc_quote;
	Bulk_quote(const Bulk_quote &bq) : Disc_quote(bq) {
		std::cout << " Bulk_quote copy constructor" << std::endl;
	}
	Bulk_quote& operator=(const Bulk_quote &bq){
		std::cout << " Bulk_quote copy assignment" << std::endl;
		Disc_quote::operator=(bq);
		return *this;
	}
	virtual ~Bulk_quote() {
		std::cout << "Bulk_quote destructor" << std::endl;
	}
	double net_price(std::size_t n) const override;
	void debug() const override;
};

class Limit_quote : public Disc_quote{
public:
	Limit_quote() :Disc_quote() {
		std::cout << "Limit_quote default constructor" << std::endl;
	}
	Limit_quote(const std::string &s, double p, std::size_t sz, double d);
	Limit_quote(const Limit_quote &lq) : Disc_quote(lq){
		std::cout << " Limit_quote copy constructor" << std::endl;
	}
	Limit_quote& operator=(const Limit_quote &lq){
		std::cout << " Limit_quote copy assignment" << std::endl;
		Disc_quote::operator=(lq);
		return *this;
	}
	virtual ~Limit_quote(){
		std::cout << "Limit_quote destructor" << std::endl;
	}
	double net_price(std::size_t n) const override;
	void debug() const override;
};

class bucket{
public:
	void add_item(const Quote& sale) {items.insert(std::shared_ptr<Quote>(sale.clone()));}
	void add_item(Quote &&sale) {items.insert(std::shared_ptr<Quote>(std::move(sale).clone()));}
	double total_receipt(std::ostream &) const;
private:
	static bool compare(const std::shared_ptr<Quote> &lhs, const std::shared_ptr<Quote> &rhs){
		return lhs->isbn() < rhs->isbn();
	}
	std::multiset<std::shared_ptr<Quote>, decltype(compare)*> items{compare};

};

#endif
