#ifndef MY_STRING
#define MY_STRING
#include <iostream>
#include <memory>


class String{
friend std::ostream& operator<<(std::ostream &os, const String &s);
friend bool operator==(const String &s1, const String &s2);
friend bool operator!=(const String &s1, const String &s2);
friend bool operator<(const String &s1, const String &s2);
public:
	String() : elements(nullptr), first_free(nullptr), cap(nullptr) {}
	String(char*, size_t sz);
	String(std::initializer_list<char> il);
	String(const String&);
	String(String &&) noexcept;
	String& operator=(const String&);
	String& operator=(String &&) noexcept;
	char& operator[](std::size_t sz);
	const char& operator[](std::size_t sz) const;
	~String();
	void push_back(const char); //Add a char to the end of a string.
	size_t size() const {return first_free - elements;}
	size_t capacity() const {return cap - elements;}
	char* begin() const {return elements;}
	char* end() const {return first_free;}

private:
	std::allocator<char> alloc;
	void reallocate();
	void free(); //Release memory
	void chk_n_alloc(){if(size() == capacity())	reallocate();} //Check whether there is space. If not, reallocate.
	std::pair<char*, char*> alloc_n_copy(const char*, const char*); //Allocate memory to hold some char
	char *elements;
	char *first_free;
	char *cap;
};

std::ostream& operator<<(std::ostream &os, const String &s);
bool operator==(const String &s1, const String &s2);
bool operator!=(const String &s1, const String &s2);
bool operator<(const String &s1, const String &s2);
#endif
