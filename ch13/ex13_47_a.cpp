#include "ex13_47.h"
#include <vector>

void String::push_back(const char c){
	chk_n_alloc(); //Check whether there is room for new character.
	alloc.construct(first_free++, c);
}

pair<char*, char*> String::alloc_n_copy(const char* c1, const char* c2){
	auto data = alloc.allocate(c2 - c1);
	return {data, uninitialized_copy(c1, c2, data)};
}

void String::free(){
	if(elements){
		alloc.deallocate(elements, cap - elements);
	}
}


String::String(const String &s){
	cout << "copy construct" << endl;
	auto newData = alloc_n_copy(s.begin(), s.end());
	elements = newData.first;
	first_free = cap = newData.second;
}

String::~String(){
	free();
}

String& String::operator=(const String &s){
	cout << "copy assignment construct" << endl;
	auto data = alloc_n_copy(s.begin(), s.end());
	free();
	elements = data.first;
	first_free = cap = data.second;
	return *this;
}

void String::reallocate(){
	auto newcapacity = size() ? 2 * size() : 1;
	auto newData = alloc.allocate(newcapacity);
	auto dest = newData;
	free();
	elements = newData;
	first_free = dest;
	cap = elements + newcapacity;
}

int main(){
	vector<String> v;
	v.push_back(String());
	auto s = String();
	v.push_back(s);
	return 0;
}
