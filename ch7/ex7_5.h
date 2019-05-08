#include <iostream>

using std::string;
using std::istream;
using std::ostream;
using std::endl;

struct Person{
    string name;
 	string address;
	string get_name() const {return name;}
	string get_address() const {return address;}
};

istream &read(istream &is, Person &p){
	is >> p.name >> p.address;
	return is;
}

ostream &print(ostream &os, const Person &p){
	os << p.name << " " << p.address << endl;
	return os;
}	
