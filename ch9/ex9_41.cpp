#include <iostream>
#include <vector>

using namespace std;

int main(){
	vector<char> v = {'h','e','j','i','a','q','i'};
	string s(v.begin(), v.end());
	cout << s << endl;
	return 0;
}
