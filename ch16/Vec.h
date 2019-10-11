#ifndef VEC
#define VEC

#include <iostream>
#include <string>
#include <initializer_list>

using std::string;
using std::allocator;
using std::pair;
using std::initializer_list;
using std::size_t;


//some restriction on type T:
//1. the pointer of type T must can be applied to subtraction. (as size() and capacity())

template <typename T> class Vec{
public:
	using size_type = size_t;
	//constructor
	Vec() : elements(nullptr), first_free(nullptr), cap(nullptr) {}
	Vec(initializer_list<T> il);
	
	//copy control
	Vec(const Vec &v);
	Vec& operator=(const Vec &v);

	//move control
	Vec(Vec &&v) noexcept;
	Vec& operator=(Vec &&v) noexcept;

	//destructor
	~Vec();

	//member functions
	void push_back(const T &t);
	size_type size() const {return first_free - elements;}	
	size_type capacity() const {return cap - elements;}
	bool empty() const {return first_free == elements;}
	T& operator[](size_type i){
		if(i >= size()){
			throw std::out_of_range("out of range");
		}
		return *(elements + i);
	}

	T* begin() {return elements;}
	const T* cbegin() {return elements;}
	const T* begin() const {return elements;}
	T* end() {return first_free;}
	const T* cend() {return first_free;}
	const T* end() const {return first_free;}

	T& front() {return *elements;}
	const T& front() const {return *elements;}

private:
	//used to allocate new memory;
	allocator<T> alloc;

	//an auxiliary function to check if we need to reallocate.
	void chk_n_alloc(){
		if(size() == capacity()){
			reallocate();
		}
	}

	//copy [*tp1, *tp2) into new memory, free old memory, and return a pair to indicate the beg and end to our new space
	pair<T*, T*> alloc_n_copy(const T *tp1, const T *tp2);

	//reallocate space
	void reallocate();

	//free space
	void free();

	//pointer to first element
	T *elements;
	
	//pointer to one past the last of element
	T *first_free;

	//pointer to one past the last of all element
	T *cap;
};

template <typename T> pair<T*, T*> Vec<T>::alloc_n_copy(const T *tp1, const T *tp2){
	auto p = alloc.allocate(tp2 - tp1);
	return {p, std::uninitialized_copy(tp1, tp2, p)};
}

template <typename T> void Vec<T>::free(){
	if(elements){
		for(auto p = first_free; p != elements;){
			alloc.destroy(--p);
		}
		alloc.deallocate(elements, cap - elements);
	}
}

template <typename T> void Vec<T>::reallocate(){
	auto newsize = size() ? 2 * size() : 1;
   	auto p = alloc.allocate(newsize);
	auto dest = p;
	auto elem = elements;

	for(auto i = 0; i != size(); i++){
		alloc.construct(dest++, std::move(*elem++));
	}
	free();

	elements = p;
	first_free = dest;
	cap = p + newsize;
}

template <typename T> Vec<T>::Vec(initializer_list<T> il){
	auto newdata = alloc_n_copy(il.begin(), il.end());
	elements = newdata.first;
	cap = first_free = newdata.second;
}

template <typename T> Vec<T>::Vec(const Vec &v){
	auto newdata = alloc_n_copy(v.begin(), v.end());
	elements = newdata.first;
	cap = first_free = newdata.second;
}

template <typename T> Vec<T>& Vec<T>::operator=(const Vec &v){
	auto newdata = alloc_n_copy(v.begin(), v.end());
	free();
	elements = newdata.first;
	cap = first_free = newdata.second;
	return *this;
}

template <typename T> Vec<T>::Vec(Vec &&v) noexcept : elements(v.elements), first_free(v.first_free), cap(v.cap) {
	v.elements = v.first_free = v.cap = nullptr;
}

template <typename T> Vec<T>& Vec<T>::operator=(Vec &&s) noexcept{
	if(this != &s){
		free();
		elements = s.elements;
		first_free = s.first_free;
		cap = s.cap;
		s.elements = s.first_free = s.cap = nullptr;
	}
	return *this;
}

template <typename T> Vec<T>::~Vec(){
	free();
}

template <typename T> void Vec<T>::push_back(const T &t){
	chk_n_alloc();
	alloc.construct(first_free++, t);
}

#endif
