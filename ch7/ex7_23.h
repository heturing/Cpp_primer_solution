#include <iostream>

using std::string;

class Screen{
public:
	typedef string::size_type pos;
	Screen() = default;
	Screen(pos h, pos w) : height(h), width(w), contents(h*w, ' ') {}
	Screen(pos h, pos w, char c) : height(h), width(w), contents(h*w, c) {}
private:
	pos cursor = 0;
	pos height = 0;
	pos width = 0;
	string contents;
};
