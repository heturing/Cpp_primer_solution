#include <iostream>

using namespace std;

class Employee{
public:
	Employee();
	Employee(const string);
	Employee(const Employee &) = delete;
	Employee& operator=(const Employee &) = delete;
	int id() {return identifier;}	
private:
	string name;
	int identifier;
	static int i;
};

int Employee::i = 0;

Employee::Employee() : name(""), identifier(i++) {}

Employee::Employee(const string s) : name(s), identifier(i++) {}


