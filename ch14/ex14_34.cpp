#include <iostream>

using namespace std;

class ITE{
	public:
		string operator()(bool cond, const string &s1, const string &s2){
			if(cond){
				return s1;
			}
			return s2;
		}
};

int main(){
	ITE ite;
	cout << ite(1, "true", "false") << endl;
	return 0;
	
}
