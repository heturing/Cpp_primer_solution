#include <iostream>
#include <cstring>

using namespace std;

int main(){
	string s1 = "hejiaqi", s2 = "zhutianqi";
	char cs1[] = "hejiaqi";
	char cs2[] = "zhutianqi";

	cout << "compare s1 and s2" << (s1 < s2) << endl;
	cout << "compare cs1 and cs2" << strcmp(cs1, cs2) << endl;
	return 0;
}
