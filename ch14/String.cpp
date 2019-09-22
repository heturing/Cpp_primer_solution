#include "./String.h"
#include <vector>


void String::reallocate(){
	auto n = size() ? 2 * size() : 1;
	auto new_element = alloc.allocate(n);
	auto new_first_free = new_element;
	for(auto it = begin(); it != end(); it++){
		alloc.construct(new_first_free++, std::move(*it));
	}

	free();
	elements = new_element;
	first_free = new_first_free;
	cap = elements + n;
}

void String::free(){
	if(elements){
		for(auto p = first_free; p != elements;){
			alloc.destroy(--p);
		}
		alloc.deallocate(elements, cap - elements);
		elements = first_free = cap = nullptr;
	}
}

std::pair<char*, char*> String::alloc_n_copy(const char *p1, const char *p2){
	auto data = alloc.allocate(p2 - p1);
	return {data, std::uninitialized_copy(p1, p2, data)};
}

String::String(char *c, size_t sz) : String() {
	for(auto it = c; it != c + sz; it++){
		push_back(*it);
	}
} 

String::String(std::initializer_list<char> il) : String(){
	for(auto i : il){
		push_back(i);
	}
}

void String::push_back(const char c){
	chk_n_alloc();
	alloc.construct(first_free++, c);
}

String::String(const String &s){
	std::cout << "copy constructor of String" << std::endl;
	auto newData = alloc_n_copy(s.begin(), s.end());
	elements = newData.first;
	first_free = cap = newData.second;
}

String::String(String&& s) noexcept : elements(s.elements), first_free(s.first_free), cap(s.cap){
	std::cout << "move constructor of String" << std::endl;
	s.elements = s.first_free = s.cap = nullptr;
}

String& String::operator=(const String& s){
	std::cout << "copy assignment of String" << std::endl;
	auto newData = alloc_n_copy(s.begin(), s.end());
	free();
	elements = newData.first;
	first_free = cap = newData.second;
	return *this;
}

String& String::operator=(String &&s) noexcept{
	std::cout << "move assignment of String" <<std::endl;
	if(this != &s){
		elements = s.elements;
		first_free = s.first_free;
		cap = s.cap;
		s.elements = s.first_free = s.cap = nullptr;
	}
	return *this;
}

String::~String(){
	free();
}

std::ostream& operator<<(std::ostream &os, const String &s){
	for(auto it = s.begin(); it != s.end(); it++){
		os << *it;
	}
	return os;
}

bool operator==(const String &s1, const String &s2){
	if(s1.size() != s2.size()){
		return false;
	}

	return std::equal(s1.begin(), s1.end(), s2.begin(), [](char c1, char c2) -> bool {return c1 == c2;});
//	for(auto it1 = s1.begin(), it2 = s2.begin(); it1 != s1.end(); it1++, it2++){
//		if(*it1 != *it2){
//			return false;
//		}
//	}
//	return true;
}

bool operator!=(const String &s1, const String &s2){
	return !(s1 == s2);
}

bool operator<(const String &s1, const String &s2){
	return std::lexicographical_compare(s1.begin(), s1.end(), s2.begin(), s2.end());
}

char& String::operator[](std::size_t sz){
	if(sz >= size()){
		throw std::out_of_range("index out of range.");
	}
	return *(elements + sz);
}

const char& String::operator[](std::size_t sz) const{
	if(sz >= size()){
		throw std::out_of_range("index out of range.");
	}
	return *(elements + sz);
}
