#include <iostream>

using namespace std;

class HasPtr{
public:
	HasPtr() :i(0), ps(new string) {}
	HasPtr(const string s) : i(0), ps(new string(s)) {}
	HasPtr(const HasPtr &hp) : i(hp.i), ps(new string(*hp.ps)) {}
	HasPtr& operator=(const HasPtr &hp){
		string *temp = new string(*hp.ps);
		delete ps;
		ps = temp;
		i = hp.i;
		return *this;
	}
	~HasPtr(){
		delete ps;
	}
private:
	int i;
	string *ps;
};
