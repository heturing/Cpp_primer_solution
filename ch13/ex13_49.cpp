#include "./message.h"
#include "./StrVec.h"
#include "./String.h"
#include <vector>

using namespace std;

int main(){
	vector<Message> vm;
	Message m1("hejiaqi");
	Message m2 = std::move(m1);
	vm.push_back(m2);

	vector<StrVec> vs;
	StrVec s1{"hejiaqi", "zhutianqi"};
	StrVec s2 = std::move(s1);
	vs.push_back(s2);

	vector<String> vstr;
	String str1{'h', 'e'};
	String str2 = std::move(str1);
	vstr.push_back(str2);
	return 0;	
	
}
