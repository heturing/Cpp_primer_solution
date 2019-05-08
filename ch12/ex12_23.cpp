#include <iostream>
#include <new>
#include <memory>

using namespace std;

int main(){
	string s1("hejiaqi"), s2("zhutianqi");
	unique_ptr<char []> uc(new char[s1.size() + s2.size()]);
	for(size_t i = 0; i < s1.size() + s2.size(); i++){
		uc[i]=(s1+s2)[i];
	}

	for(size_t i = 0; i < s1.size() + s2.size(); i++){
		cout << uc[i];
	}
	cout << endl;
	return 0;
}
