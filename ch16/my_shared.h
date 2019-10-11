#ifndef MY_SHARED
#define MY_SHARED

#include <iostream>

template <typename T> class my_shared{

public:
	using Del_type = void (*)(T*);
	
	my_shared() = default;
	my_shared(T *t) : count(1), data(t), del(nullptr) {}
	~my_shared(){
		if(--count == 0){
			del ? del(data) : delete(data);
		}
	}
private:
	std::size_t count;
	T *data;
	Del_type del;
};



#endif
