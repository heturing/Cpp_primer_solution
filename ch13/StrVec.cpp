#include "./StrVec.h"
#include <utility>

void StrVec::push_back(const string &s){
	chk_n_alloc();
	alloc.construct(first_free++, s);
}

pair<string*, string*> StrVec::alloc_n_copy(const string *s1, const string *s2){
	auto data = alloc.allocate(s2 - s1);
	return {data, uninitialized_copy(s1, s2, data)};
}

void StrVec::free(){
	if(elements){
		for(auto p = first_free; p != elements;)
			alloc.destroy(--p);
		alloc.deallocate(elements, cap - elements);
	}
}

StrVec::StrVec(initializer_list<string> il){
	auto newData = alloc_n_copy(il.begin(), il.end());
	elements = newData.first;
	first_free = cap = newData.second;
}

StrVec::StrVec(const StrVec &s){
	std::cout << "copy constructor of StrVec" << std::endl;
	auto newData = alloc_n_copy(s.begin(), s.end());
	elements = newData.first;
	first_free = cap = newData.second;
}

StrVec::~StrVec(){
	free();
}

StrVec& StrVec::operator=(const StrVec &s){
	std::cout << "copy assignemnt of StrVec" << std::endl;
	auto data = alloc_n_copy(s.begin(), s.end());
	free();
	elements = data.first;
	first_free = cap = data.second;
	return *this;
}

StrVec::StrVec(StrVec &&s) noexcept : elements(s.elements), first_free(s.first_free), cap(s.cap) {
	std::cout << "move constructor of StrVec" << std::endl;
	s.elements = s.first_free = s.cap = nullptr;
}

StrVec& StrVec::operator=(StrVec &&s) noexcept{
	std::cout << "move assignment of StrVec" << std::endl;
	if(this != &s){
		elements = s.elements;
		first_free = s.first_free;
		cap = s.cap;
		s.elements = s.first_free = s.cap = nullptr;
	}
	return *this;
}

void StrVec::reallocate(){
	auto newCapacity = size() ? 2 * size() : 1;
	auto newData = alloc.allocate(newCapacity);
	//auto dest = newData;
	//auto elem = elements;
	//for(size_t i = 0; i != size(); i++){
	//	alloc.construct(dest++, std::move(*elem++));
	//}
	
	auto dest = std::uninitialized_copy(std::make_move_iterator(begin()), std::make_move_iterator(end()), newData);
	free();
	elements = newData;
	first_free = dest;
	cap = elements + newCapacity;
}

void StrVec::reverse(size_t new_sz){
	if(new_sz <= capacity())
		return;
	else{
		auto newData = alloc.allocate(new_sz);
		auto dest = newData;
		auto elem = elements;
		for(size_t i = 0; i != size(); i++){
			alloc.construct(dest++, std::move(*elem++));
		}
		free();
		elements = newData;
		first_free = dest;
		cap = elements + new_sz;
	}
}

void StrVec::resize(size_t sz, const string &s){
	if(sz == size()) return;
	if(sz > size()){
		if(sz > capacity()){
			reverse(2*sz);
		}
		for(size_t i = size(); i != sz; i++){
			alloc.construct(first_free++, s);
		}
	}
	else{
		while(first_free != elements + sz){
			alloc.destroy(--first_free);
		}
	}
}

void StrVec::resize(size_t sz){
	resize(sz, string());
}

