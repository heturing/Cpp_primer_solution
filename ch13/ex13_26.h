#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <initializer_list>
#include <stdexcept>

class StrBlobPtr;

class StrBlob{
friend class StrBlobPtr;
public:
	using size_type = std::vector<std::string>::size_type;
	StrBlob();
	StrBlob(std::initializer_list<std::string> il);
	StrBlob(const StrBlob &sb) : data(std::make_shared<std::vector<std::string>>(*sb.data)) {}
	StrBlob& operator=(const StrBlob &sb);
	size_type size() const {return data -> size();}
	bool empty() const {return data->empty();}
	void push_back(const std::string &s) {data->push_back(s);}
	void pop_back();
	std::string& front();
	const std::string& front() const;
	std::string& back();
	const std::string& back() const;
	StrBlobPtr begin();
	StrBlobPtr end();
private:
	std::shared_ptr<std::vector<std::string>> data;
	void check(size_type i, const std::string &msg) const;
};

StrBlob::StrBlob() : data(std::make_shared<std::vector<std::string>>()) {}

StrBlob::StrBlob(std::initializer_list<std::string> il) : data(std::make_shared<std::vector<std::string>>(il)) {}

StrBlob& StrBlob::operator=(const StrBlob &sb){
	data = std::make_shared<std::vector<std::string>>(*sb.data);
	return *this;
};

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


class StrBlobPtr{
public:
	StrBlobPtr() : curr(0) {}
	StrBlobPtr(StrBlob &a, size_t sz = 0) : wptr(a.data), curr(sz) {}
	std::string& deref() const;
	StrBlobPtr& incr();
	bool operator!=(const StrBlobPtr &sbp1){
		return sbp1.curr != curr || *(sbp1.wptr.lock()) != *(wptr.lock());
	}

private:
	std::shared_ptr<std::vector<std::string>> check(std::size_t, const std::string&) const;
	std::weak_ptr<std::vector<std::string>> wptr;
	size_t curr;	
};


std::shared_ptr<std::vector<std::string>> StrBlobPtr::check(std::size_t i, const std::string &msg) const{
	auto ret = wptr.lock();
	if(!ret){
		throw std::runtime_error("Unbound StrBlobPtr");
	}
	if(i >= ret->size()){
		throw std::out_of_range(msg);
	}
	return ret;
}

std::string& StrBlobPtr::deref() const{
	auto p = check(curr, "dereference past end");
	return (*p)[curr];
}

StrBlobPtr& StrBlobPtr::incr(){
	check(curr, "increment past end of StrBlobPtr");
	++curr;
	return *this;
}

//class Strblob's function
StrBlobPtr StrBlob::begin(){
	return *this;
}

StrBlobPtr StrBlob::end(){
	return StrBlobPtr(*this, data->size());
}
