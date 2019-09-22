#include <iostream>
#include <memory>

using namespace std;

int main(){
	allocator<string> alloc;
	auto const p = alloc.allocate(10);
	auto q = p;
	int j = 0;
	while(j < 10){
		alloc.construct(q++, "hejiaqi");
		j++;
	}
	int i = 0;
	while(i < 10){
		cout << *(p + i) << endl;
		i++;
	}

	while(q != p){
		alloc.destroy(--q);
	}
	alloc.deallocate(p,10);

	return 0;
}
