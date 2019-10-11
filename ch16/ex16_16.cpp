#include "./Vec.h"

using namespace std;

int main(){
	Vec<string> v;
	string s = "hejiaqi";
	v.push_back(s);
	cout << v[0] << endl;
	
	Vec<int> vi;
	vi.push_back(1);
	cout << vi[0] << endl;
	return 0;
}
