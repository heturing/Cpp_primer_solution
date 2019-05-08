#include <iostream>

using namespace std;

class HasPtr{
public:
	HasPtr(const string &s = string()) : ps(new string(s)), i(0), use(new size_t(1)) {}
	HasPtr(const HasPtr &hp) : ps(hp.ps), i(hp.i), use(hp.use) {++*use;}
	HasPtr& operator=(const HasPtr &hp);
	~HasPtr();
private:
	string *ps;
	int i;
	size_t *use;
};

HasPtr& HasPtr::operator=(const HasPtr &hp){
	++*hp.use;
	if(--*use == 0){
		delete ps;
		delete use;
	}

	ps = hp.ps;
	i = hp.i;
	use = hp.use;
	return *this;
}

HasPtr::~HasPtr(){
	if(--*use == 0){
		delete ps;
		delete use;
	}
}
