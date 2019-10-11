#ifndef SCREEN
#define SCREEN

#include <iostream>
#include <string>

using pos = std::string::size_type;

template<pos H, pos W> class Screen;

template <pos H, pos W> std::ostream& operator<<(std::ostream &os, const Screen<H,W> &s);
template <pos H, pos W> std::istream& operator>>(std::istream &is, Screen<H,W> &s);

template <pos H, pos W> class Screen{
friend std::ostream& operator<<<H,W>(std::ostream &os, const Screen<H,W> &s);
friend std::istream& operator>><H,W>(std::istream &is, Screen<H,W> &s);
public:
	Screen() : height(H), width(W) {}
	void get_height() const;
	void get_width() const;
private:
	pos height;
	pos width;
};


template <pos H, pos W> void Screen<H,W>::get_height() const{
	std::cout << height << std::endl;
}

template <pos H, pos W> void Screen<H, W>::get_width() const{
	std::cout << width << std::endl;
}

template <pos H, pos W> std::ostream& operator<<(std::ostream &os, const Screen<H,W> &s){
	os << s.height << " " << s.width;
	return os;
}

template <pos H, pos W> std::istream& operator>>(std::istream &is, Screen<H,W> &s){
	is >> s.height >> s.width;
	return is;
}



#endif
