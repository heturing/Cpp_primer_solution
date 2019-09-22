#ifndef SALES_DATA
#define SALES_DATA 

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>

/* Sales_data.h */
class Sales_data;
std::istream &read(std::istream &, Sales_data &);

class Sales_data {
  friend Sales_data add(const Sales_data &, const Sales_data &);
  friend std::istream &read(std::istream &, Sales_data &);
  friend std::ostream &print(std::ostream &, const Sales_data &);
  friend std::istream& operator>> (std::istream &, Sales_data &);
  friend std::ostream& operator<< (std::ostream &, const Sales_data &);
  friend Sales_data operator+(const Sales_data &, const Sales_data &);
public:
  Sales_data() : Sales_data("", 0, 0.0) {}
  explicit Sales_data(const std::string &no) : Sales_data(no, 0, 0.0) {}
  Sales_data(const std::string &no, unsigned us, double price)
      : bookNo(no), units_sold(us), revenue(price * us) {}
  explicit Sales_data(std::istream &is) : Sales_data() { read(is, *this); }

  Sales_data& operator=(std::string s);
  Sales_data& operator+=(const Sales_data &);

  explicit operator std::string() const {return bookNo;}
  explicit operator double() const {return revenue;}

  std::string isbn() const { return bookNo; }
  Sales_data &combine(const Sales_data &);

private:
  double avg_price() const;
  std::string bookNo;
  unsigned units_sold = 0;
  double revenue = 0.0;
};

std::istream& operator>> (std::istream &, const Sales_data &);
std::ostream& operator<< (std::ostream &, const Sales_data &);
Sales_data operator+(const Sales_data &, const Sales_data &);

#endif
