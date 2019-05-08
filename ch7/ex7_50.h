#include <iostream>

using std::string;
using std::istream;
using std::ostream;
using std::endl;

class Person{
friend istream &read(istream &, Person &);
friend ostream &print(ostream &, const Person &);
public:
	Person() = default;
	Person(const string &n, const string &add) : name(n), address(add) {}
	explicit Person(istream &);
	string get_name() const {return name;}
	string get_address() const {return address;}
private:
    string name;
 	string address;
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
