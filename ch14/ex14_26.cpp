#include "./String.h"
#include "./StrVec.h"

using namespace std;

int main(){
	String s{'h', 'e'};
	s[0] = 'j';
	cout << s << endl;

	StrVec sv{"he", "jia", "qi"};
	sv[0] = "zhu";
	cout << sv[0] << endl;
	return 0;
}
