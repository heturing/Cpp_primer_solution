#include <iostream>

using namespace std;

class HasPtr{
friend void swap(HasPtr&, HasPtr&);
friend bool operator<(const HasPtr&, const HasPtr&);
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
	void show() {cout << *ps << endl;}
	~HasPtr(){
		delete ps;
	}
private:
	int i;
	string *ps;
};

void swap(HasPtr &hp1, HasPtr &hp2){
	using std::swap;
	swap(hp1.ps, hp2.ps);
	swap(hp1.i, hp2.i);
	cout << "swap is executed" << endl;
}

bool operator<(const HasPtr &hp1, const HasPtr &hp2){
	return *hp1.ps < *hp2.ps;
}
