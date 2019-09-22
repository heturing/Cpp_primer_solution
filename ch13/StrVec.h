#ifndef STRVEC
#define STRVEC
#include <iostream>
#include <string>
#include <initializer_list>

using std::string;
using std::allocator;
using std::pair;
using std::initializer_list;

class StrVec{
public:
	StrVec() : elements(nullptr), first_free(nullptr), cap(nullptr) {}
	StrVec(initializer_list<string> il);
	StrVec(const StrVec&);
	StrVec& operator=(const StrVec &);
	StrVec(StrVec &&) noexcept;
	StrVec& operator=(StrVec &&s) noexcept;
	~StrVec();
	void push_back(const string &);
	size_t size() const {return first_free - elements;}
	size_t capacity() const { return cap - elements;}
	string* begin() const {return elements;}
	string* end() const {return first_free;}
	void reverse(size_t new_sz);
	void resize(size_t sz);
	void resize(size_t sz, const string &s);
private:
	allocator<string> alloc;
	void chk_n_alloc(){
		if(size() == capacity()) 
			reallocate();
	}
	pair<string*, string*> alloc_n_copy(const string*, const string*);
	void free();
	void reallocate();
	string *elements;
	string *first_free;
	string *cap;
};

#endif
