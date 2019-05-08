#include <iostream>

using namespace std;

class Debug{
public:
	constexpr Debug(bool b = true) : hw(b), io(b), others(b) {}
	constexpr Debug(bool h, bool i, bool o) : hw(h), io(i), others(o) {}
	constexpr bool any() const {return hw || io || others;}
	void set_io(bool b){ io = b;}
	void set_hw(bool b){ hw = b;}
	void set_others(bool b){ others = b;}
private:
	bool hw;
	bool io;
	bool others;
};
