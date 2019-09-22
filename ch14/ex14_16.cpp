#include "./String.h"

using namespace std;

int main(){
	String s1{'h', 'e'}, s2{'z', 'h', 'u'}, s3{'h', 'e'};
	cout << (s1 == s2) << endl;
	cout << (s1 == s3) << endl;
	cout << (s1 != s2) << endl;
	return 0;
}
