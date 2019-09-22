#include "./ex13_48.h"
#include <vector>

using namespace std;

int main(){
	String s1{'h', 'e', 'j', 'i', 'a', 'q', 'i'};
	String s2{'h', 'e', 'j', 'i', 'a', 'q', 'i'};
	String s3{'h', 'e', 'j', 'i', 'a', 'q', 'i'};

//	String s1, s2, s3;

//	String s4{'h', 'e', 'j', 'i', 'a', 'q', 'i'};
	vector<String> v;
	v.push_back(s1);   // copy constructor once, l1
	v.push_back(s2);   // copy constructor 3 times, s1 + move s1 and construct s2 
//	v.push_back(s3);

	return 0;
}
