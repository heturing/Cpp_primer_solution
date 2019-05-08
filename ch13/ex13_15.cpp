#include <iostream>

using namespace std;

class numbered{
friend void f(numbered s);
public:
	numbered() : mysn(i) {i++;} 
	numbered(const numbered &n){
		mysn = n.i + 1;
		i++;
	}
private:
	static int i;
	int mysn;
};

int numbered::i = 0;

void f(numbered s){
	cout << s.mysn <<endl;
}

int main(){
	numbered a, b = a, c = b;
	f(a);
	f(b);
	f(c);
	return 0;
}
