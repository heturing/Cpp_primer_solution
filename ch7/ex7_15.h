#include <iostream>

using std::string;
using std::istream;
using std::ostream;
using std::endl;

struct Person{
	Person() = default;
	Person(const string &n, const string &add) : name(n), address(add) {}
	Person(istream &);
    string name;
 	string address;
	string get_name() const {return name;}
	string get_address() const {return address;}
};

istream &read(istream &is, Person &p){
	is >> p.name >> p.address;
	return is;
}

Person::Person(istream &is){
	read(is, *this);
}

ostream &print(ostream &os, const Person &p){
	os << p.name << " " << p.address << endl;
	return os;
}	
