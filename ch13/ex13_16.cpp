#include <iostream>

using namespace std;

class numbered{
friend void f(const numbered &s);
public:
	numbered() : mysn(i++) {} 
	numbered(const numbered &) : mysn(i++) {}
private:
	static int i;
	int mysn;
};

int numbered::i = 0;

void f(const numbered &s){
	cout << s.mysn <<endl;
}

int main(){
	numbered a, b = a, c = b;
	f(a);
	f(b);
	f(c);
	return 0;
}
