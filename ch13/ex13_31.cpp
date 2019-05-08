#include "ex13_30.h"
#include <vector>
#include <algorithm>

int main(){
	HasPtr hp1("a"), hp2("b"), hp3("c");
	vector<HasPtr> v{hp3, hp2, hp1};
	sort(v.begin(), v.end());
	for(auto &c : v){
		c.show();
	}
	return 0;

}
