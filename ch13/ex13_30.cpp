#include "./ex13_30.h"
#include <vector>
using namespace std;

int main(){
	HasPtr h1("A"), h2("B"), h3("a");
	vector<HasPtr> v{h1, h3, h2};
	sort(v.begin(), v. end());

	return 0;
}
