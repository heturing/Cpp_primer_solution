#include <iostream>

using namespace std;

class Point{
	public:
		Point() = default;
		Point(int a, int b) : x(a), y(b) {}
		Point(const Point &p) : x(p.x), y(p.y) {cout << "1" << endl;}
		Point& operator=(const Point &p){x = p.x; y = p.y; cout << "2" << endl; return *this;}
	private:
		int x = 0;
		int y = 0;
};

int main(){
	Point p(1,1);
	Point local = p, *heap = new Point(p);
	*heap = local;

	return 0;
}
