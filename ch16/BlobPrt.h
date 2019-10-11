#ifndef BLOBPTR
#define BLOBPTR

#include <iostream>
#include <vector>
#include "./Blob.h"

template <typename T> bool operator==(const BlobPtr<T>&, const BlobPtr<T>&);

// BlobPtr is a pointer of Blob
template <typename T> class BlobPtr{
friend bool operator==<T> (const BlobPtr&, const BlobPtr&); 
public:
	BlobPtr() : curr(0) {}
	BlobPtr(Blob<T> &a, size_t sz = 0) : wptr(a.data), curr(sz) {}
	T& operator*() const{
		auto p = check(curr, "deference past end");
		return (*p)[curr];
	}

	BlobPtr& operator++();
	BlobPtr& operator--();
	BlobPtr operator++(int);
	BlobPtr operator--(int);
private:
	std::shared_ptr<std::vector<T>> check(std::size_t, const std::string&) const;
	std::weak_ptr<std::vector<T>> wptr;
	std::size_t curr;
};

template <typename T> BlobPtr<T>& BlobPtr<T>::operator++(){
	auto p = check(curr, "add on last index");
	curr++;
	return *this;
}

template <typename T> BlobPtr<T>& BlobPtr<T>::operator--(){
	if(curr == 0){
		throw std::runtime_error("subtract on first index");
	}
	curr--;
	return *this;
}

template <typename T> BlobPtr<T> BlobPtr<T>::operator++(int){
	BlobPtr res = *this;
	++*this;
	return res;
}

template <typename T> BlobPtr<T> BlobPtr<T>::operator--(int){
	BlobPtr res = *this;
	--*this;
	return res;
}

template <typename T> std::shared_ptr<std::vector<T>> BlobPtr<T>::check(std::size_t sz, const std::string& s) const{
	auto p = wptr.lock();
	if(!p){
		throw std::runtime_error(s);
	}
	if(sz >= p->size()){
		throw std::out_of_range(s);
	}
	return p;
}

template <typename T> bool operator==(const BlobPtr<T> &bp1, const BlobPtr<T> &bp2){
	return *bp1 == *bp2;
}


#endif
