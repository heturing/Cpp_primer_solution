#include <iostream>
#include <vector>

using std::string;
using std::ostream;
using std::vector;

class Screen;

class Window_mgr{
public:
	using ScreenIndex = vector<Screen>::size_type;
   	void clear(ScreenIndex);
private:
	vector<Screen> screens;	
};

class Screen{
	friend void Window_mgr::clear(ScreenIndex);
public:
	typedef string::size_type pos;
	Screen() = default;
	Screen(pos h, pos w) : height(h), width(w), contents(h*w, ' ') {}
	Screen(pos h, pos w, char c) : height(h), width(w), contents(h*w, c) {}
	Screen &move(pos h, pos w);
	char get(pos r, pos c) const;
	char get() const {return contents[cursor];}
	Screen &set(char);
	Screen &set(pos, pos, char);
	Screen &display(ostream &os){do_display(os); return *this;}
	const Screen &display(ostream &os) const {do_display(os); return *this;}
private:
	void do_display(ostream &os) const {os << contents;}
	pos cursor = 0;
	pos height = 0;
	pos width = 0;
	string contents;
};

inline Screen &Screen::move(pos h, pos w){
	pos row = h * width;
	cursor = row + w;
	return *this;
}

inline char Screen::get(pos r, pos c) const{
	pos row = r * width;
	return contents[row+c];
}

inline Screen &Screen::set(char c){
	contents[cursor] = c;
	return *this;
}

inline Screen &Screen::set(pos r, pos col, char c){
	contents[r * width + col] = c;
	return *this;
}

inline void Window_mgr::clear(ScreenIndex i){
	Screen &s = screens[i];
	s.contents = string(s.height * s.width, ' ');
}
