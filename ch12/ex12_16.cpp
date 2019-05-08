#include <iostream>
#include <memory>

using namespace std;

int main(){
	unique_ptr<int> u(new int(1));
	unique_ptr<int> u1;
	u1 = u;
	unique_ptr<int> u2(u);
	return 0;
}
