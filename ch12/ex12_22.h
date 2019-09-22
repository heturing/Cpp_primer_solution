#include <iostream>
#include <memory>
#include <new>
#include <vector>
#include <initializer_list>
#include <string>
#include <stdexcept>

class ConstStrBlobPtr;

class StrBlob{
friend class ConstStrBlobPtr;
public:
	using size_type = std::vector<std::string>::size_type;
	StrBlob();
	StrBlob(std::initializer_list<std::string> il);
	size_type size() const {return data -> size();}
	bool empty() const {return data->empty();}
	void push_back(const std::string &s) {data->push_back(s);}
	void pop_back();
	std::string& front();
	const std::string& front() const;
	std::string& back();
	const std::string& back() const;
	ConstStrBlobPtr begin() const;
	ConstStrBlobPtr end() const;
private:
	std::shared_ptr<std::vector<std::string>> data;
	void check(size_type i, const std::string &msg) const;
};

StrBlob::StrBlob() : data(std::make_shared<std::vector<std::string>>()) {}

StrBlob::StrBlob(std::initializer_list<std::string> il) : data(std::make_shared<std::vector<std::string>>(il)) {}

void StrBlob::check(size_type i, const std::string &msg) const {
	if(i >= data->size()){
		throw std::out_of_range(msg);
	}
}

std::string& StrBlob::front(){
	check(0, "front of empty StrBlob");
	return data->front();
}

const std::string& StrBlob::front() const{
	check(0, "front of empty StrBlob");
	return data->front();
}

std::string& StrBlob::back(){
	check(0, "back on empty StrBlob");
	return data->back();
}

const std::string& StrBlob::back() const{
	check(0, "back on empty StrBlob");
    return data->back();
}

void StrBlob::pop_back(){
	check(0, "pop_back on empty StrBlob");
	return data->pop_back();
}


class ConstStrBlobPtr{
public:
	ConstStrBlobPtr() : curr(0) {}
	ConstStrBlobPtr(const StrBlob &a, std::size_t sz = 0) : wptr(a.data), curr(sz) {}

private:
	std::shared_ptr<std::vector<std::string>> check(std::size_t, const std::string &) const;
	std::weak_ptr<std::vector<std::string>> wptr;
	std::size_t curr;
};
