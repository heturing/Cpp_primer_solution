#include <iostream>
#include <memory>

using namespace std;

class String{
public:
	String() : elements(nullptr), first_free(nullptr), cap(nullptr) {}
	String(const String&);
	String& operator=(const String&);
	~String();
	void push_back(const char); //Add a char to the end of a string.
	size_t size() const {return first_free - elements;}
	size_t capacity() const {return cap - elements;}
	char* begin() const {return elements;}
	char* end() const {return first_free;}

private:
	allocator<char> alloc;
	void reallocate();
	void free(); //Release memory
	void chk_n_alloc(){if(size() == capacity())	reallocate();} //Check whether there is space. I f not, reallocate.
	pair<char*, char*> alloc_n_copy(const char*, const char*); //Allocate memory to hold some char
	char *elements;
	char *first_free;
	char *cap;
};


